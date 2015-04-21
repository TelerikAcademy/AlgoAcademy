#include<iostream>
using namespace std;
int n;
struct{
	int x, y1, y2;
}A[1<<20];
int minn = 2000000042;
int main()
{
	cin>>n;
	for(int i=0; i<n; ++i)
		cin >> A[i].x >> A[i].y1 >> A[i].y2;
	for(int i=0; i<n; ++i)
		for(int j=0; j<i; ++j)
			if((A[j].y1 <= A[i].y1 && A[i].y1 < A[j].y2) || (A[i].y1 <= A[j].y1 && A[j].y1 < A[i].y2))
				minn = min(minn, A[i].x>A[j].x?A[i].x-A[j].x:A[j].x-A[i].x);
	if(minn == 2000000042)
		cout << "--\n";
	else cout << minn << '\n';
}
