#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<string> orderedStrings;

    orderedStrings.insert("the");
    orderedStrings.insert("quick");
    orderedStrings.insert("brown");
    orderedStrings.insert("fox");
    orderedStrings.insert("jumps");
    orderedStrings.insert("over");
    orderedStrings.insert("the");
    orderedStrings.insert("lazy");
    orderedStrings.insert("dog");

    for(set<string>::iterator iter = orderedStrings.begin();
        iter != orderedStrings.end();
        iter++)
    {
        cout<<(*iter)<<endl;
    }
}
