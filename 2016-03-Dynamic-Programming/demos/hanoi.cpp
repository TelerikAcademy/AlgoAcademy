#include <iostream>

void hanoi(int n, char src, char mid, char dest)
{
    if(n == 1)
    {
        std::cout << "Moving " << n << " from " << src << " to " << dest << std::endl;
        return;
    }
    
    hanoi(n - 1, src, dest, mid);
    std::cout << "Moving " << n << " from " << src << " to " << dest << std::endl;
    hanoi(n - 1, mid, src, dest);
}

int main()
{
    int n;
    std::cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}