#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    map<string, int> peopleAges;

    peopleAges["Joro"] = 22;
    peopleAges.insert(pair<string, int>("Petya", 20));

    cout<<peopleAges["Petya"]<<endl;
    peopleAges["Petya"]++;
    cout<<peopleAges["Petya"]<<endl;

    peopleAges.erase("Joro");
    if(peopleAges.find("Joro") == peopleAges.end())
    {
        cout<<"No ''Joro'' key in peopleAges"<<endl;
    }

    cout<<peopleAges["Joro"]<<endl;
}
