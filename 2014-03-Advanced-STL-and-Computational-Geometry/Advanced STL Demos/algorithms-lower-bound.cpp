#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(4);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(9);
    numbers.push_back(10);

    cout<<*(lower_bound(numbers.begin(), numbers.end(), 4))<<endl;
}
