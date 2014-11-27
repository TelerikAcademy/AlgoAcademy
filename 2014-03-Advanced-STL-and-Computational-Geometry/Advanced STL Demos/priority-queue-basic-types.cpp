#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    priority_queue<int, vector<int> > numsBySize;
    numsBySize.push(1);
    numsBySize.push(3);
    numsBySize.push(2);

    priority_queue<string> stringsByLex;
    stringsByLex.push("a");
    stringsByLex.push("c");
    stringsByLex.push("b");

    while(!numsBySize.empty())
    {
        cout<<numsBySize.top()<<endl;
        numsBySize.pop();
    }

    while(!stringsByLex.empty())
    {
        cout<<stringsByLex.top()<<endl;
        stringsByLex.pop();
    }
}
