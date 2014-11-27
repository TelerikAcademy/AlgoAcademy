#include<iostream>
#include<set>

using namespace std;

struct greaterThan
{
    bool operator ()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    set<int, greaterThan> nums;
    nums.insert(1);
    nums.insert(2);
    nums.insert(3);

    for(set<int>::iterator iter = nums.begin();
            iter != nums.end();
            iter++)
    {
        cout<<*iter<<endl;
    }
}
