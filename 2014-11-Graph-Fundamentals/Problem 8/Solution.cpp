//
//  main.cpp
//  HorseSpread
//
//  Created by Doncho Minkov on 11/25/14.
//  Copyright (c) 2014 Telerik Academy. All rights reserved.
//

#include <iostream>

#include<queue>

using namespace std;

#define MAX_N 1500
#define MAX_M 1000

int matrix[MAX_N+1][MAX_M+1];
int n, m;

void solve(int, int);
void clear();
int encode(int, int);
int decodeRow(int);
int decodeCol(int);
bool inRange(int, int);
void printResult();

int main() {
    cin>>n>>m;
    int row, col;
    cin>>row>>col;
    solve(row, col);
    
    printResult();
    return 0;
}

void solve(int startRow, int startCol){
    int dRow[] = {-2, -1, 1, 2,  2,  1, -1, -2};
    int dCol[] = { 1,  2, 2, 1, -1, -2, -2, -1};

    clear();
    matrix[startRow][startCol] = 1;
    queue<int> q;
    q.push(encode(startRow, startCol));
    int row, col, code, nextRow, nextCol,d;
    while(!q.empty()){
        code = q.front();
        q.pop();
        row = decodeRow(code);
        col = decodeCol(code);
        for ( d = 0; d < 8; d++) {
            nextRow = row + dRow[d];
            nextCol = col + dCol[d];
            if(inRange(nextRow, n) && inRange(nextCol, m) &&
               matrix[nextRow][nextCol] == 0){
                int value = matrix[row][col] + 1;
                matrix[nextRow][nextCol] = value;
                //cout<<value<<endl;
                q.push(encode(nextRow, nextCol));
            }
        }
    }
}

void clear(){
    for (int i = 0; i < n; i++) {
        for (int j= 0; j < m; j++) {
            matrix[i][j] = 0;
        }
    }
}

const int ENCODE_VALUE = MAX_N + 1;

int encode(int row, int col){
    return row * ENCODE_VALUE + col;
}

int decodeRow(int code){
    return code / ENCODE_VALUE;
}

int decodeCol(int code){
    return code % ENCODE_VALUE;
}

bool inRange(int value, int max){
    return 0 <= value && value < max;
}

void printResult(){
    for (int i = 0; i < n; i++) {
        cout<<matrix[i][m/2]<<endl;
    }
//    for (int row = n/2; row < n/2 + 3; row++) {
//        for (int col = m/2; col < m/2 + 3; col++) {
//            cout<<matrix[row][col]<<" ";
//        }
//        cout<<endl;
//    }
}


