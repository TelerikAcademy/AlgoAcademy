#include<map>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    map<string, int> wordOccurences;

    string sentence;
    getline(cin, sentence);

    stringstream ss;
    ss.str(sentence);

    string word;

    while(ss>>word)
    {
        wordOccurences[word]++;
    }

    for(map<string, int>::iterator it = wordOccurences.begin();
        it != wordOccurences.end();
        it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}
