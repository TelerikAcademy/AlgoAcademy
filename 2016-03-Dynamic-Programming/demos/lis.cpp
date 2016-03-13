#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> set = { 1, 8, 2, 3, 4, 11, 12 };
    std::vector<int> best{ set[0] };
    
    for(int i = 1; i < set.size(); i++)
    {
        auto it = std::lower_bound(best.begin(), best.end(), set[i]);
        
        if(it == best.end())
        {
            best.push_back(set[i]);
        }
        else
        {
            *it = set[i];
        }
    }
    
    std::cout << best.size() << std::endl;
    
    return 0;
}
