#include<queue>
#include<iostream>

using namespace std;

int main()
{
    priority_queue<int> q;

    while(true)
    {
        int n;
        cin>>n;

        if(n==0)
        {
            cout<<q.top()<<endl;
            q.pop();
        }
        else
        {
            q.push(n);
        }
    }
}
