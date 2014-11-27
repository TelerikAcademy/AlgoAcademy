#include<iostream>
#include<iterator>

#include<sstream>

using namespace std;

int main()
{
    stringstream ss;
    ss.str("words divided by spaces");

    istream_iterator<string> stringEOS;
    istream_iterator<string> ssIterator(cin);

    while(ssIterator != stringEOS)
    {
        cout<<(*ssIterator)<<endl;
        ssIterator++;
    }
}
