#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <utility>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int m, n;
    std::list<std::pair<char, int>> list;
    std::map<char, int> points;
    std::string input;

    std::cin >> input;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        char c;
        int p;
        std::cin >> c >> p;
        points[c] = p;
    }

    for (auto i : input) {
        list.push_back({i, points[i]});
    }

    std::list<std::pair<char, int>>::iterator l = list.begin(), r = std::prev(list.end());

    int liliPoints = l->second, rainaPoints = r->second;
    l->second = 0;
    r->second = 0;

    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int op;
        std::cin >> op;
        if (op == 1) {
            char dir, girl;
            std::cin >> girl >> dir;
            if (girl == 'L') {
                if (dir == 'S') l--;
                else l++;
                liliPoints += l->second;
                l->second = 0;
            } else {
                if (dir == 'S') r--;
                else r++;
                rainaPoints += r->second;
                r->second = 0;
            }
        } else {
            list.splice(std::next(l), list, std::prev(r));
        }
    }

    for (auto i : list)
        std::cout << i.first;

    std::cout << std::endl;
    std::cout << liliPoints << ' ' << rainaPoints << std::endl;

    return 0;
}

