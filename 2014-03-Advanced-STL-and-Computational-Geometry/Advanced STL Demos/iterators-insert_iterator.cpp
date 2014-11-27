#include<iostream>
#include<iterator>
#include<list>

using namespace std;

int main()
{
    list<string> words;
    words.push_back("|");
    words.push_back("|");

    list<string>::iterator wordsMiddle = words.begin();
    wordsMiddle++;

    front_insert_iterator< list<string> > wordsFrontInserter(words);
    back_insert_iterator< list<string> > wordsBackInserter(words);
    insert_iterator< list<string> > wordsMiddleInserter(words, wordsMiddle);

    for(int i=0; i<3; i++)
    {
        *wordsFrontInserter = "front";

        *wordsMiddleInserter = "middle";

        *wordsBackInserter = "back";
    }

    for(list<string>::iterator wordsIter = words.begin();
        wordsIter != words.end();
        wordsIter++)
    {
        cout<<(*wordsIter)<<" ";
    }
}
