#include<set>

#include<iostream>

using namespace std;

int main()
{
    set<int> numbers;

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int input;
        cin>>input;

        numbers.insert(input);
    }

    for(set<int>::iterator it = numbers.begin();
        it != numbers.end();
        it++)
    {
        cout<<*it<<endl;
    }
}
