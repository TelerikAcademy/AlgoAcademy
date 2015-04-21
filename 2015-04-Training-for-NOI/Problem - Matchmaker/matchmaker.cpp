//
//  main.cpp
//  Matchmaker
//
//  Created by Doncho Minkov on 4/16/15.
//  Copyright (c) 2015 Doncho Minkov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <ctime>

using namespace std;

map<string, set<string> > vertices;
set<string> guys;
set<string> girls;
void readInput();
void printGraph();
void solve();
void fakeInput();

int main() {
    clock_t begin = clock();

    readInput();
    solve();
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    // cout<<"Time elapsed: "<<elapsed_secs<<endl;
    // printf("%f\n", elapsed_secs);    

    return 0;
}

void fakeInput(){
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
}

void readInput(){
    // fakeInput();
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
    	string name;
    	string gender;
    	int m;
    	cin>>name>>gender>>m;
    	vector<string> interests;
    	for(int j = 0; j < m; j++){
    		string interest;
    		cin>>interest;
    		interests.push_back(interest);
    	}
    	for(int j = 0; j < m; j++){
    		string from;
    		string to;
    		if(gender == "m"){
    			from = name;
    			to = interests[j];
    			guys.insert(from);
    		}
    		else{
    			from = interests[j];
    			to = name;
                girls.insert(name);
    		}
    		vertices[from].insert(to);
    	}
    }
}

void solve(){
    set<string> used;
    map<string, int> matches;
    int bestMatch = 0;
    string bestGuy;
    string bestGirl;
    for(auto guy: guys){
        used.clear();
        matches.clear();
        queue<string> nextVertices;
        nextVertices.push(guy);
        while(!nextVertices.empty()){
            string v = nextVertices.front();
            nextVertices.pop();
            used.insert(v);
            if(girls.find(v) != girls.end()){
                if(matches.find(v) == matches.end()){
                    matches[v] = 0;
                }
                matches[v] ++;
            }
            else{
                for(auto next: vertices[v]){
                    if(used.find(next) != used.end()){
                        continue;
                    }
                    nextVertices.push(next);
                }
            }
        }
        for(auto match:matches){
            if(bestMatch < match.second){
                bestGuy = guy;
                bestGirl = match.first;
                bestMatch = match.second;
            }
        }
    }
    if(bestMatch == 1){
        cout << bestGuy << " and " << bestGirl << " have " << bestMatch << " common interest!"<<endl;
    }
    else{
        cout << bestGuy << " and " << bestGirl << " have " << bestMatch << " common interests!"<<endl;
    }
}

void printGraph(){
	for(auto vertex:vertices){
		cout<<vertex.first<<" -> ";
		for(auto to: vertex.second){
			cout<<to<<", ";
		}
		cout<<endl;
	}
}

