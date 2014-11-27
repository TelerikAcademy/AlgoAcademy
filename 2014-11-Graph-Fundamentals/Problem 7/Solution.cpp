#include <iostream>

#include <vector>

using namespace std;

#define MAX_N 3000
#define OFFSET MAX_N
int n, m;

vector<int> vertices[2 * MAX_N + 1];
bool used[2 * MAX_N + 1];
vector<int> leaves;

void readTree();
void solve();
int calcBestPath(int);
void clearUsed();
int calcPath(int);

int main() {

	readTree();
	solve();
	return 0;
}

void clearUsed(){
	int i;
	for (i = 0; i < 2 * MAX_N + 1; i++){
		used[i] = false;
	}
}

int calcPath(int vertex){
	int i, len, nextVertex;
	used[vertex] = true;
	len = vertices[vertex].size();
	bool isFirstPath = true;
	int bestPath;
	int path;
	for (i = 0; i < len; i++){
		nextVertex = vertices[vertex][i];
		if (!used[nextVertex]){
			int path = calcPath(nextVertex);
			if (isFirstPath){
				bestPath = path;
				isFirstPath = false;
			}
			else if (bestPath < path){
				bestPath = path;
			}
		}
	}
	used[vertex] = false;
	return (isFirstPath) ?
		vertex - OFFSET :
		vertex - OFFSET + bestPath;
}

int calcBestPath(int leave){
	clearUsed();
	int pathLength = calcPath(leave);
	return pathLength;
}

void solve(){
	int i, len;
	len = leaves.size();
	int bestLeave;
	int bestPath;
	bool isFirstPath = true;
	for (i = 0; i < len; i++){
		int pathLength = calcBestPath(leaves[i]);
		if (isFirstPath){
			bestPath = pathLength;
			bestLeave = leaves[i];
			isFirstPath = false;
		}
		else if (bestPath < pathLength){
			bestPath = pathLength;
			bestLeave = leaves[i];
		}
	}
	cout << bestPath<<endl;
}

void readTree(){
	cin >> n >> m;
	vector<int> possibleLeaves;

	int from, to;
	int i;
	for (int i = 0; i < m; i++)
	{
		cin >> from;
		cin >> to;

		from += OFFSET;
		to += OFFSET;

		vertices[from].push_back(to);
		vertices[to].push_back(from);
		possibleLeaves.push_back(to);
	}
	int len = possibleLeaves.size();
	for (i = 0; i < len; i++){
		int possibleLeave = possibleLeaves[i];
		if (vertices[possibleLeave].size() == 1){
			leaves.push_back(possibleLeave);
		}
	}
}