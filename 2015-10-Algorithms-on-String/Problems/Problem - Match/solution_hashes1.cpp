#include <iostream>
#include <vector>
#include <set>

const int HASHES = 1;
const int BASE[HASHES]{ 263 };
const int MOD[HASHES]{(int)1e9 + 9 };

std::vector<uint64_t> pow[HASHES] = { { 1 } };

struct Hash {
    uint64_t hash[HASHES];
    Hash()
    {
	for (auto& x : this->hash) {
	    x = 0;
	}
    }
    void add(char ch)
    {
	for (int i = 0; i < HASHES; ++i) {
	    this->hash[i] = (this->hash[i] * BASE[i] + ch) % MOD[i];
	}
    }
    void rem(char ch, int len)
    {
	for (int i = 0; i < HASHES; ++i) {
	    this->hash[i] = MOD[i] + this->hash[i] - ch * pow[i][len] % MOD[i];
	    this->hash[i] %= MOD[i];
	}
    }
    bool operator<(const Hash& x)
	const
    {
	for (int i = 0; i < HASHES - 1; ++i) {
	    if (this->hash[i] != x.hash[i]) {
		return this->hash[i] < x.hash[i];
	    }
	}
	return 0;
    }
};

inline bool check(int m, std::string& a, std::string& b)
{
    std::set<Hash> s;

    Hash hash;
    for (int i = 0; i < m; ++i)
	hash.add(a[i]);
    s.insert(hash);

    for (unsigned i = m, len = a.size(); i < len; ++i) {
	hash.rem(a[i - m], m - 1);
	hash.add(a[i]);
	s.insert(hash);
    }

    hash = Hash();
    for (int i = 0; i < m; ++i) {
	hash.add(b[i]);
    }
    if (s.find(hash) != s.end()) {
	return true;
    }

    for (unsigned i = m, len = b.size(); i < len; ++i) {
	hash.rem(b[i - m], m - 1);
	hash.add(b[i]);
	if (s.find(hash) != s.end())
	    return true;
    }

    return false;
}

int main()
{
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    if (a.size() > b.size())
	swap(a, b);

    for (int k = 0; k < HASHES; ++k) {
	pow[k].resize(a.size());
	for (unsigned i = 1, len = a.size(); i < a.size(); ++i) {
	    pow[k][i] = pow[k][i - 1] * BASE[k] % MOD[k];
	}
    }

    int left = 0, right = a.size();
    while (left < right) {
	int middle = (left + right) / 2;
	if (check(middle, a, b)) {
	    left = middle + 1;
	} else {
	    right = middle;
	}
    }

    std::cout << --left << '\n';
}
