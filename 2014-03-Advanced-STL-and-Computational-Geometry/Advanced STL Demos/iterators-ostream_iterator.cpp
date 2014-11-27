#include<iostream>
#include<iterator>
#include<fstream>

using namespace std;

int main()
{

    //ofstream myfile ("example.txt");
    ostream_iterator<int> outIterator(cout, ", ");

    for(int i=0; i<10; i++)
    {
        *outIterator = i;
    }
}
