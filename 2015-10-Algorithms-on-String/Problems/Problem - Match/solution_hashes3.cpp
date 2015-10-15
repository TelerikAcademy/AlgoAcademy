#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int HASHES = 3;
const int BASE[HASHES] {263, 269, 271};
const int MOD[HASHES] {(int)1e9+7, (int)1e9+33, (int)1e9+9};
vector<uint64_t> pow[HASHES] = {{1}, {1}, {1}};

struct hash_t {
	uint64_t hash[HASHES];
	hash_t()
	{
		for(auto &x:hash)
			x = 0;
	}
	void add(char c)
	{
		for(int i=0; i<HASHES; ++i)
			hash[i] = (hash[i] * BASE[i] + c) % MOD[i];
	}
	void rem(char c, int len)
	{
		for(int i=0; i<HASHES; ++i)
			hash[i] = (MOD[i] + hash[i] - c*pow[i][len]%MOD[i]) % MOD[i];
	}
	bool operator<(const hash_t &X)
	const {
		int i=0;
		for(; i < HASHES-1; ++i)
			if(hash[i] != X.hash[i])
				break;
		return hash[i] < X.hash[i];
	}
};

inline bool check(int M, string &A, string &B)
{
	set<hash_t> S;

	hash_t hash;
	for(int i=0; i<M; ++i)
		hash.add(A[i]);
	S.insert(hash);

	for(unsigned i=M; i<A.size(); ++i)
	{
		hash.rem(A[i-M], M-1);
		hash.add(A[i]);
		S.insert(hash);
	}

	hash = hash_t();
	for(int i=0; i<M; ++i)
		hash.add(B[i]);
	if(S.find(hash) != S.end()) return true;

	for(unsigned i=M; i<B.size(); ++i)
	{
		hash.rem(B[i-M], M-1);
		hash.add(B[i]);
		if(S.find(hash) != S.end()) return true;
	}

	return false;
}

int main()
{
	string A, B;
	std::getline(cin, A);
	std::getline(cin, B);

	if(A.size() > B.size())
		swap(A, B);

	for(int k=0; k<HASHES; ++k)
	{
		pow[k].resize(A.size());
		for(unsigned i=1; i<A.size(); ++i)
			pow[k][i] = pow[k][i-1] * BASE[k] % MOD[k];
	}

	int L = 0, R = A.size();
	while(L < R)
	{
		int M = (L + R) / 2;
		if(check(M, A, B))
			L = M + 1;
		else R = M;
	}

	cout << --L << '\n';
}
