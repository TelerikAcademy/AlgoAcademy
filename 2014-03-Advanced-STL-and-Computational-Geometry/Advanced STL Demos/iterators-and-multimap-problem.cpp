#include<iostream>
#include<map>

#include <sstream>

using namespace std;

int main()
{
    multimap<string, int> wordPositions;

    ///positions:   0   1  2  3   4   5        6       7      8        9           10
    string text = "This is a ship - shipping ship, shipping shipping ships: http://imgur.com/pB0VXKq";

    stringstream textStream;
    textStream.str(text);


    int position = 0;
    string word;
    while(textStream>>word)
    {
        wordPositions.insert(
        pair<string, int>(word, position)
                             );
        position++;
    }

    pair<
    multimap<string,int>::iterator,
    multimap<string,int>::iterator
    > rangePair =
        wordPositions.equal_range("shipping");

    cout<<"Positions of word ''shipping'':"<<endl;
    multimap<string, int>::iterator rangeIter;
    for(rangeIter = rangePair.first;
        rangeIter != rangePair.second;
        rangeIter++)
    {
        pair<string, int> currentEl = *rangeIter;
        cout<<currentEl.second<<endl;
    }
}
