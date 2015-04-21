#include<iostream>
#define MAX_N 10000
using namespace std;

int n;
int heights[MAX_N];
int values[MAX_N];

void readInput();
void solve();

int main(){
	readInput();
	solve();
}

void readInput(){
	// int sampleHeights[] = {3, 2, 5, 3, 1, 3, 3};
	// int sampleValues[] =  {1, 3, 4, 2, 7, 1, 4};

	cin>>n;
	// n = 7;
	for(int i = 0; i < n; i++){
		cin>>heights[i]>>values[i];
		// heights[i] = sampleHeights[i];
		// values[i] = sampleValues[i];
	}
}

int bottoms[MAX_N];
int tops[MAX_N];

void solve(){
	int sums[MAX_N];
	for(int i = 0; i < n; i ++){
		tops[i] = values[i];
		bottoms[i] = values[i];
	}
	int mmax = 0;
	for(int index = 0; index < n; index++){
		for(int i = index - 1; i >= 0; i--){
			if(heights[i] < heights[index]){
				int newSum = bottoms[i] + values[index];
				if(tops[index] < newSum){
					tops[index] = newSum;
				}
				if(newSum > mmax){
					mmax = newSum;
				}
			}
			if(heights[index] < heights[i] ){
				int newSum = tops[i] + values[index];
				if(bottoms[index] < newSum){
					bottoms[index] = newSum;
				}
				if(newSum > mmax){
					mmax = newSum;
				}
			}
		}
	}
	int max = tops[0];
	for(int i = 0; i < n; i++){
		if(max < tops[i]){
			max = tops[i];
		}
		if(max < bottoms[i]){
			max = bottoms[i];
		}
	}
	cout<<max<<endl;
}