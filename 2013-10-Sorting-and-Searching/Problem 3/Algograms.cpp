#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector <string> list;
	string word;
	cin>>word;

	while (word != "-1")
	{
		list.push_back(word);
		cin >> word;
	}

    for (int i = 0; i < list.size(); i++)
    {
        sort(list[i].begin(), list[i].end());
    }

    sort(list.begin(), list.end());

    int answer = 0;
    string compare("");

    for (int i = 0; i < list.size(); i++)
    {
        if (compare != list[i])
        {
            answer++;
        }
        compare = list[i];
    }

    cout << answer;
}
