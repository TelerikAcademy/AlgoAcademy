#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    multimap<string, string> personNicks;
    personNicks.insert(pair<string, string>("George", "Joro"));
    personNicks.insert(pair<string, string>("George", "Gosho"));
    personNicks.insert(pair<string, string>("George", "Joro"));
    personNicks.insert(pair<string, string>("George", "Gopi"));

    cout<<"George has: "<<personNicks.count("George")<<" nicknames"<<endl;
}
