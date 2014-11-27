// ItemsItemsCPP.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <queue>

using namespace std;

int N,I,O;

int lab[501][501];
int graph[15][15];
int itemRows[15];
int itemCols[15];
int obstacleRowsTop[25];
int obstacleRowsBottom[25];
int obstacleColsLeft[25];
int obstacleColsRight[25];

int distances[15];

int obstacleValue = 999999;

void readInput(){
	cin>>N>>I>>O;
	I+=2;
	itemRows[0] = 0;
	itemCols[0] = 0;
	for (int i = 1; i < I-1; i++)
	{
		cin>>itemRows[i]>>itemCols[i];
	}

	itemRows[I-1] = N-1;
	itemCols[I-1] = N-1;

	for (int o = 0; o < O; o++)
	{
		cin>>obstacleRowsTop[o]>>obstacleColsLeft[o]>>obstacleRowsBottom[o]>>obstacleColsRight[o];
	}	
}

void initLab(){
	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){
			lab[row][col] = 0;
		}
	}

	for(int i = 0; i < I; i++){
		lab[itemRows[i]][itemCols[i]]= -i-1;
	}
	for(int i = 0; i < O; i++){
		for(int row = obstacleRowsTop[i]; row<= obstacleRowsBottom[i]; row++){
			for (int col = obstacleColsLeft[i]; col <= obstacleColsRight[i]; col++) {
				lab[row][col] = obstacleValue;
			}
		}
	}
}

int dirsCount = 4;
int rowDirs[4] = {1, 0, -1, 0};
int colDirs[4] = {0, -1, 0, 1};

void calculateDistances(int vertex){
	std::queue<int> q;
	q.push(itemRows[vertex] * N + itemCols[vertex]);
	lab[itemRows[vertex]][itemCols[vertex]] = 1;

	while(!q.empty()){
		int current = q.front();

		q.pop();
		int row = current/N;
		int col = current%N;

		for(int d = 0 ; d < dirsCount; d++){
			int nextRow = row + rowDirs[d];
			int nextCol = col + colDirs[d];
			if(0 <= nextRow && nextRow < N && 0 <= nextCol && nextCol < N && lab[nextRow][nextCol] <=0){
				if(lab[nextRow][nextCol] < 0){
					int reachedVertex = - lab[nextRow][nextCol] - 1;
					distances[reachedVertex] = lab[row][col];
				}
				lab[nextRow][nextCol]  = lab[row][col] + 1;
				q.push(nextRow * N + nextCol);
			}
		}
	}
}

int labShown = false;
void buildGraph(){
	for (int i = 0; i < I; i++)
	{
		initLab();
		calculateDistances(i);
		for(int j = 0; j < I; j++){
			graph[i][j] = distances[j];
		}
	}
}

int bestTime = 9999999;

int calculateTime(int* perm, int len){
	int time = 0;
	time+= graph[0][perm[0]];
	for(int i = 0; i < len-1; i++){
		time+= graph[perm[i]][perm[i+1]];
	}
	time+= graph[perm[len-1]][I-1];
	return time;
}

void nextPermutation(int* perm, int len, int index){
	if(index>=len-1) {
		int time = calculateTime(perm, len);
		if(bestTime> time){
			bestTime = time;
		}

	}
	else{
		for(int i = index; i < len; i++){
			int temp = perm[index];
			perm[index] = perm[i];
			perm[i] = temp;
			nextPermutation(perm, len, index+1);
			temp = perm[index];
			perm[index] = perm[i];
			perm[i] = temp;
		}
	}
}

int findBestTime(){
	int vertices[15];
	for (int i = 0; i < I-2; i++) {
		vertices[i] = i+1;
	}

	nextPermutation(vertices, I-2, 0);
	return bestTime;
}


int main() {
	readInput();

	buildGraph();

	int bestTime = findBestTime();
	cout<<bestTime<<endl;


	return 0;
}
