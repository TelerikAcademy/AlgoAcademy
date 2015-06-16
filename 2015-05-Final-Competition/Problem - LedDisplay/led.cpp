#include<iostream>

int bar[7];
int A[7][11] = {
	{1,0,1,1,0,1,1,1,1,1},
	{1,0,0,0,1,1,1,0,1,1},
	{1,1,1,1,1,0,0,1,1,1},
	{0,0,1,1,1,1,1,0,1,1},
	{1,0,1,0,0,0,1,0,1,0},
	{1,1,0,1,1,1,1,1,1,1},
	{1,0,1,1,0,1,1,0,1,1}
};

int digits[10];
int mx[10], mxlen;

inline void reduce(int r, int c)
{
	for(int i=0;i<7;++i)
	{
		if(i==r) continue;
		int k=A[i][c];
		for(int j=0;j<11;++j)
			A[i][j]=A[i][j]*A[r][c]-A[r][j]*k;
	}
}
inline bool find(int r, int c)
{
	int k=A[r][10]-A[r][0]*digits[0]-A[r][2]*digits[2]-A[r][6]*digits[6];
	if(k%A[r][c]!=0) return false;
	digits[c]=k/A[r][c];
	return digits[c]>=0;
}

inline void printmax()
{
	for(int d=9;d>=0;--d)
		for(int i=0;i<mx[d];++i)
			std::cout<<d;
	std::cout<<'\n';
}
inline bool cmpmx(int len)
{
	if(mxlen<len) return true;
	if(mxlen>len) return false;
	for(int d=9;d>0;++d)
	{
		if(mx[d]<digits[d]) return true;
		if(mx[d]>digits[d]) return false;
	}
	return mx[0]<digits[0];
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	for(int i=0;i<7;++i)
	{
		std::cin>>bar[i];
		A[i][10]=bar[i];
	}

	reduce(0,3);
	reduce(1,4);
	reduce(2,1);
	reduce(3,5);
	reduce(4,8);
	reduce(5,7);
	reduce(6,9);

	for(int i=0;i<=bar[4];++i)
		for(int j=0;i+j<=bar[4];++j)
			for(int k=0;i+j+k<=bar[4];++k)
			{
				digits[0]=i; digits[2]=j; digits[6]=k;

				if(!find(0,3)) continue;
				if(!find(1,4)) continue;
				if(!find(2,1)) continue;
				if(!find(3,5)) continue;
				if(!find(4,8)) continue;
				if(!find(5,7)) continue;
				if(!find(6,9)) continue;

				int len=0;
				for(int d=0;d<10;++d)
					len+=digits[d];
				if(cmpmx(len))
				{
					mxlen=len;
					for(int i=0;i<10;++i)
						mx[i]=digits[i];
				}
			}
	printmax();
}
