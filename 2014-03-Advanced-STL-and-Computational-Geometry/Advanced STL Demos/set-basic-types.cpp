#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<int> uniqueNumbers;

    uniqueNumbers.insert(3);
    uniqueNumbers.insert(7);
    uniqueNumbers.insert(2);
    uniqueNumbers.insert(7);

    multiset<string> uniqueStrings;

    uniqueStrings.insert("quick");
    uniqueStrings.insert("brown");
    uniqueStrings.insert("fox");
    uniqueStrings.insert("brown");

    while(!uniqueNumbers.empty())
    {
        cout<<(*uniqueNumbers.begin())<<endl;

        uniqueNumbers.erase(uniqueNumbers.begin());
    }

    while(!uniqueStrings.empty())
    {
        cout<<(*uniqueStrings.begin())<<endl;

        uniqueStrings.erase(uniqueStrings.begin());
    }
}
