#include<algorithm>
#include<iterator>

#include<iostream>

#include<vector>
#include<list>

using namespace std;


int main()
{
    vector<int> numbersVect;
    numbersVect.push_back(1);
    numbersVect.push_back(2);
    numbersVect.push_back(3);

    list<double> numbersList;
    numbersList.push_front(-3);
    numbersList.push_front(-2);
    numbersList.push_front(-1);

    swap_ranges(numbersVect.begin(), numbersVect.end(),
          numbersList.begin());

    cout<<"vector:"<<endl;
    copy(numbersVect.begin(), numbersVect.end(),
         ostream_iterator<int>(cout, " "));
    cout<<endl;

    cout<<"list:"<<endl;
    copy(numbersList.begin(), numbersList.end(),
         ostream_iterator<int>(cout, " "));
}
