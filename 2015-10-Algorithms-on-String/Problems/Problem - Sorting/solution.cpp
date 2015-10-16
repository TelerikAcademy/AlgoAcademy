#include <iostream>
#define SYMBOLS_COUNT 256

int main()
{
    int counts[SYMBOLS_COUNT];
    int n;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
	int c;
	std::cin >> c;
	++counts[c];
    }
    counts[(int)'x'] = 0;

    for (int i = 0; i < 26; ++i) {
	for (int j = 0; j < counts['A' + i]; ++j)
	    std::cout << (char)('A' + i);
	for (int j = 0; j < counts['a' + i]; ++j)
	    std::cout << (char)('a' + i);
    }

    for (int i = 1; i < 10; ++i)
	for (int j = 0; j < counts['0' + i]; ++j)
	    std::cout << (char)('0' + i);
    for (int j = 0; j < counts[(int)'0']; ++j)
	std::cout << '0';
    std::cout << '\n';
}
