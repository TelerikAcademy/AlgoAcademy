#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);

    vector<int>::iterator numsIter = numbers.begin();

    cout<<*numsIter<<endl;
    numsIter++;
    cout<<*numsIter<<endl;
}
