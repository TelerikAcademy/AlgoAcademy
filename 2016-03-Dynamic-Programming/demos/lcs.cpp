#include <iostream>
#include <stack>

const int MAX_L = 1024;
int memory[MAX_L][MAX_L];

void solve(std::string& first, std::string& second)
{
    size_t l1 = first.size(), l2 = second.size();
    
    for(size_t i = 1; i <= l1; i++ )
    {
        for(size_t j = 1; j <= l2; j++ )
        {
            if(first[i - 1] == second[j - 1])
            {
                memory[i][j] = memory[i - 1][j - 1] + 1;
            }
            else
            {
                memory[i][j] = std::max(memory[i - 1][j], memory[i][j - 1]);
            }

            std::cout << memory[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void print_solution(std::string& first, std::string& second)
{
    int i = first.size(), j = second.size();
    std::cout << "Length: " << memory[i][j] << " ";
    
    std::stack<char> answer;
    while (i > 0 || j > 0)
    {
        if(first[i - 1] == second[j - 1])
        {
            answer.push(first[i - 1]);
            i--;
            j--;
        }
        else if(memory[i - 1][j] >= memory[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    
    std::cout << "The solution is ";
    
    while(!answer.empty())
    {
        std::cout << answer.top();
        answer.pop();
    }
}

int main()
{    
    std::string first, second;
    std::cin >> first >> second;
    
    solve(first, second);
    
    print_solution(first, second);
    
    return 0;
}

