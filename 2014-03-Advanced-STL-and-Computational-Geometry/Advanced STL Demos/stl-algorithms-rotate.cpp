#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    char s[] = "12345678";
    rotate(s+2, s+3, s+6);

    printf("%s\n", s);
}
