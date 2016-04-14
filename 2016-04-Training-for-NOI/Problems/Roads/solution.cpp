#include <iostream>

const int MAXN = 400;
const int MAXM = 800;

int Field[MAXN * MAXM];


int get_parent(int x)
{
    if(Field[x - 1] == x)
        return x;

    Field[x - 1] = get_parent(Field[x - 1]);
    return Field[x - 1];
}


void connect(int x, int y)
{
    x = get_parent(x);
    y = get_parent(y);

    if(x != y)
        Field[x - 1] = y;
}

int main()
{
    //std::cin.tie(0);
    //std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    for(int i = 1; i <= n * m; i++)
    {
        Field[i - 1] = i;
    }

    std::string cmd;
    std::cin >> cmd;
    while(cmd != "END")
    {
        int x, y;
        std::cin >> x >> y;
        if(cmd == "BUILD")
        {
            // std::cout << "building " << std::endl;
            connect(x, y);
        }
        else
        {
            // std::cout << "connecting " << std::endl;
            // std::cout << get_parent(x) << " " << get_parent(y) << std::endl;
            std::cout << (get_parent(x) == get_parent(y) ? "yes" : "no") << std::endl;
        }

        std::cin >> cmd;
    }

    return 0;
}
