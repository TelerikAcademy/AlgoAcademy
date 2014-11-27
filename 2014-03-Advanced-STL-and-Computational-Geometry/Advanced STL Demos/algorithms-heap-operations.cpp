#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
    vector<int> numbers;

    numbers.push_back(13);
    numbers.push_back(10);
    numbers.push_back(1);
    numbers.push_back(24);
    numbers.push_back(35);
    numbers.push_back(16);
    numbers.push_back(42);
    numbers.push_back(25);

    make_heap(numbers.begin(), numbers.end());

    cout<<numbers[0]<<endl;

    numbers.push_back(36);

    push_heap(numbers.begin(), numbers.end());
}
