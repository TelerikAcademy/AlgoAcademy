#include<iostream>
#include<string>
using namespace std;

const int MAXN = 1000042; // slightly > 10^6
const long long MAXK = 1000000000000000042ll; // slightly > 10^18

const int ONE_BLACK = 0;
const int TWO_BLACK = 1;
const int ONE_WHITE = 2;
const int TWO_WHITE = 3;

long long A[MAXN][4];

int main()
{
	int n; // Barcode width
	long long k; // K-th sequence
	cin >> n >> k;

	// fill A array
	A[1][ONE_BLACK] = 1;
	A[1][TWO_BLACK] = 0;
	A[1][ONE_WHITE] = 0;
	A[1][TWO_WHITE] = 0;
	for(int i=1; i<n; ++i)
	{
		A[i+1][ONE_BLACK] = A[i][ONE_WHITE] + A[i][TWO_WHITE];
		A[i+1][TWO_BLACK] = A[i][ONE_BLACK];
		A[i+1][ONE_WHITE] = A[i][ONE_BLACK] + A[i][TWO_BLACK];
		A[i+1][TWO_WHITE] = A[i][ONE_WHITE];

		// prevent overflows
		for(int j=0; j<4; ++j)
			if(A[i+1][j] > MAXK)
				A[i+1][j] = MAXK;
	}
//	cout << "Total: " << A[n][ONE_BLACK]+A[n][TWO_BLACK] << '\n';

	string barcode = "b";
	barcode.reserve(n);

	// build barcode
	for(int i=n-1; i>0; --i)
	{
		// check for repeating letters
		if(barcode.size() >= 2 && barcode[barcode.size() - 2] == barcode[barcode.size() - 1])
		{
			barcode.push_back('b'^'w'^barcode.back());
			continue;
		}
		if(barcode.back() == 'b')
		{
			long long p = A[i][ONE_BLACK];
			if(k > p)
			{
				barcode.push_back('w');
				k -= p;
			}
			else barcode.push_back('b'); // Insert 'w' after "bb"
		}
		else
		{
			long long p = A[i][ONE_BLACK] + A[i][TWO_BLACK];
			if(k > p)
			{
				barcode.push_back('w'); // Insert 'b' after "ww"
				k -= p;
			}
			else barcode.push_back('b');
		}
	}

	cout << barcode << '\n';
}
