#include<iostream>
using namespace std;

const long long MOD = 1000000033;
const long long MAXF = 1<<17;
long long fact[MAXF+1] = {1, 1};

int main()
{
	int mul, sin;
	cin >> sin >> mul;

	for(long long i=2; i<=MAXF; ++i)
		fact[i] = fact[i-1] * i % MOD;

	long long total = fact[sin+mul];

	for(int i=0; i<mul; ++i)
	{
		int k;
		cin >> k;
		total = total * fact[k] % MOD;
	}

	cout << total << '\n';
	return 0;
}
