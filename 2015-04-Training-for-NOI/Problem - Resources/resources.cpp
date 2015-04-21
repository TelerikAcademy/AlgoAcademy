#include <iostream>
#include<map>
#include<set>
#include<queue>
using namespace std;

int n;
map<string, set<string> > resources;

const string ADD_COMMAND = "add";
const string LOAD_COMMAND = "load";

void solve(){
    cin>>n;
    string command;
    for (int i = 0; i < n; i++) {
        cin>>command;
        if(command == ADD_COMMAND){
            string x;
            string useless;
            string y;
            cin>>x>>useless>>y;
            if(resources.find(x) == resources.end() ){
                set<string> dependecies;
                resources[x] = dependecies;
            }
            if(resources.find(y) == resources.end() ){
                set<string> dependecies;
                resources[y] = dependecies;
            }
            resources[x].insert(y);
        }
        else if(command == LOAD_COMMAND){
            string resource;
            cin>>resource;
            if(resources.find(resource) == resources.end()){
                cout<<"ERROR: No such resource"<<endl;
                continue;
            }
            set<string> loaded;
            queue<string> unusedResources;
            unusedResources.push(resource);
            loaded.insert(resource);
            while(!unusedResources.empty()){
                string current = unusedResources.front();
                unusedResources.pop();
                if(resources.find(current) != resources.end()){
                    for(auto next:resources[current]){
                        if(loaded.find(next) == loaded.end()){
                            loaded.insert(next);
                            unusedResources.push(next);
                        }
                    }
                }
            }
            for(auto r: loaded){
                cout<<r<<endl;
            }
        }
    }
}

int main() {
    solve();
}

