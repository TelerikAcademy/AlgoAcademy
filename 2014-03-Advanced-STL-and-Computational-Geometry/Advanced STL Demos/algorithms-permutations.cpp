#include<algorithm>
#include<vector>
#include<iostream>

#include<iterator>

using namespace std;

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    while(true)
    {
        cout<<next_permutation(nums.begin(), nums.end())<<endl;

        copy(nums.begin(), nums.end(),
             ostream_iterator<int>(cout, " "));

        cin.get();
    }

}
