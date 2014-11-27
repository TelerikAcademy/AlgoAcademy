#include<algorithm>
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
    numbersList.push_front(3);
    numbersList.push_front(2);
    numbersList.push_front(1);

    bool areEqual =
        equal(numbersVect.begin(), numbersVect.end(),
          numbersList.begin());

    cout<<areEqual<<endl;
}
