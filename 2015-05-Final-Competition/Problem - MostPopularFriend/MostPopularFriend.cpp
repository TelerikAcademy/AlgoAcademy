#include<iostream>
using namespace std;
bool A[64][64];
string s[64];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			if(s[i][j]=='Y')
			{
				A[i][j]=true;
				for(int k=0;k<n;++k)
					if(s[j][k]=='Y')
						A[i][k]=true;
			}
	}
	for(int i=0;i<n;++i)
		A[i][i]=false;
	int mx=-1;
	for(int i=0;i<n;++i)
	{
		int cr=0;
		for(int j=0;j<n;++j)
			if(A[i][j])
				++cr;
		if(mx<cr) mx=cr;
	}
	cout<<mx<<'\n';
}
