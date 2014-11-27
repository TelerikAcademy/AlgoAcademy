#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

class Entry
{
    map<string, string> propertyValues;
public:
    Entry()
    {
        this->propertyValues = map<string, string>();
    }

    void SetProperty (string name, string value)
    {
        this->propertyValues[name] = value;
    }

    string GetProperty (string name)
    {
        return this->propertyValues[name];
    }
};

bool IsInt (string s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(!isdigit(s[i]))
        {
            if(i!=0 || s[i]!='-')
            {
                return false;
            }
        }
    }

    return true;
}

int ParseInt(string s)
{
    int number = 0;
    //for(int i=s.size() - 1; i>=0; i--)
    for(int i=0; i < s.size(); i++)
    {
        number *= 10;
        number += (s[i]-'0');
    }

    return number;
}

struct EntryComparer
{
private:
    vector<string> compareProps;
    int numCompareProps;
public:
    EntryComparer(vector<string> compareProps)
    {
        this->compareProps = compareProps;
        this->numCompareProps = this->compareProps.size();
    }

    bool operator()(Entry* a, Entry * b)
    {
        for(int propInd = 0; propInd < this->numCompareProps; propInd++)
        {
            string propName = this->compareProps[propInd];

            string aProp = a->GetProperty(propName),
                bProp = b->GetProperty(propName);

            if(IsInt(aProp) && IsInt(bProp))
            {
                int aPropInt = ParseInt(aProp);
                int bPropInt = ParseInt(bProp);
                if(aPropInt < bPropInt)
                {
                    return true;
                }
                else if (bPropInt < aPropInt)
                {
                    return false;
                }
            }
            else if(aProp < bProp)
            {
                return true;
            }
            else if(bProp < aProp)
            {
                return false;
            }
        }

        return false;
    }
};

vector<string> columns;
vector<Entry*> entries;

void InputSpreadsheet()
{
    int numColumns = 0;
    int numEntries = 0;

    cin>>numEntries>>numColumns;


    for(int i=0; i<numColumns; i++)
    {
        string columnName;
        cin>>columnName;
        columns.push_back(columnName);
    }

    for(int entryInd=0; entryInd<numEntries; entryInd++)
    {
        Entry * currentEntry = new Entry();
        entries.push_back(currentEntry);
        for(int columnInd=0; columnInd<numColumns; columnInd++)
        {
            string columnValue;
            cin>>columnValue;

            currentEntry->SetProperty(columns[columnInd], columnValue);
        }
    }
}

void HandleCommands()
{
    string command = "";
    while(command!="end")
    {
        cin>>command;

        if (command == "entry")
        {
            Entry * newEntry = new Entry();
            entries.push_back(newEntry);
            for(int propInd = 0; propInd < columns.size(); propInd++)
            {
                string propVal;
                cin>>propVal;
                newEntry->SetProperty(columns[propInd], propVal);
            }
        }
        else if (command == "column")
        {
            string columnName;
            cin>>columnName;
            columns.push_back(columnName);
        }
        else if (command == "sort")
        {
            int numSortColumns = 0;
            cin>>numSortColumns;

            vector<string> sortColumns;
            for(int i=0; i<numSortColumns; i++)
            {
                string columnName;
                cin>>columnName;
                sortColumns.push_back(columnName);
            }

            sort(entries.begin(), entries.end(), EntryComparer(sortColumns));
        }
        else if (command == "get")
        {
            int entryIndex = 0;
            cin>>entryIndex;
            cout<<entries[entryIndex]->GetProperty(columns[0]);
            for(int i=1; i<columns.size(); i++)
            {
                cout<<" "<<entries[entryIndex]->GetProperty(columns[i]);
            }
            cout<<endl;
        }
        else if (command == "set")
        {
            int entryIndex = 0;
            cin>>entryIndex;
            string entryPropName, entryPropVal;
            cin>>entryPropName>>entryPropVal;

            entries[entryIndex]->SetProperty(entryPropName, entryPropVal);
        }
        else if (command == "print") ///for debugging purposes
        {
            for(int entryInd = 0; entryInd < entries.size(); entryInd++)
            {
                for(int columnInd = 0; columnInd < columns.size(); columnInd++)
                {
                    cout<<entries[entryInd]->GetProperty(columns[columnInd])<<" ";
                }
                cout<<endl;
            }
        }
    }
}

int main()
{
    InputSpreadsheet();

    HandleCommands();
}
