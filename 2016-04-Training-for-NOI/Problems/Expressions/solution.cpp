#include <iostream>
#include <cmath>

int sum(std::string& expression, size_t& index);
const int M = 30011;
int quickpow(int n, int p)
{
    if(p == 0)
    {
        return 1;
    }

    if(p & 1)
    {
        return quickpow(n, p - 1) * n % M;
    }

    int s = quickpow(n, p >> 1);

    return s * s % M;
}

int parse(std::string& expression, size_t& index)
{
    int value = 0;

    while(index < expression.size())
    {
        if('0' <= expression[index] && expression[index] <= '9')
        {
            value = 10 * value + (expression[index++] - '0');
        }
        else break;
    }
    return value;
}

int number(std::string& expression, size_t& index)
{
    if(expression[index] == '(')
    {
        int value = sum(expression, ++index);

        ++index;

        return value;
    }

    if(expression[index] == '|')
    {
        int value = std::abs(sum(expression, ++index));

        ++index;

        return value;
    }

    if(expression[index] == '~')
    {
        int value = ~number(expression, ++index);

        return value;
    }

    int value = parse(expression, index);

    return value;
}

int bitwise(std::string& expression, size_t& index)
{
    int value = number(expression, index);

    while(index < expression.size())
    {
        if(expression[index] == '>')
        {
            value >>= number(expression, ++index);
        }
        else if(expression[index] == '<')
        {
            value <<= number(expression, ++index);
        }
        else break;
    }

    return value;
}

int power(std::string& expression, size_t& index)
{
    int value = bitwise(expression, index);

    while(index < expression.size())
    {
        if(expression[index] == '^')
        {
            value = quickpow(value, power(expression, ++index));
        }
        else break;
    }

    return value;
}

int product(std::string& expression, size_t& index)
{
    int value = power(expression, index);

    while(index < expression.size())
    {
        if(expression[index] == '*')
        {
            value *= power(expression, ++index);
        }
        else if(expression[index] == '/')
        {
            int p = power(expression, ++index);
            if(p == 0)
                std::cout<<"tapag";
            value /= p;
        }
        else break;
    }

    return value;
}

int sum(std::string& expression, size_t& index)
{
    int value = product(expression, index);

    while(index < expression.size())
    {
        if(expression[index] == '+')
        {
            value += product(expression, ++index);
        }
        else if(expression[index] == '-')
        {
            value -= product(expression, ++index);
        }
        else break;
    }

    return value;
}

int evaluate(std::string& expression)
{
    size_t index = 0;
    return sum(expression, index);
}

int main()
{
    std::string expression;
    std::cin >> expression;
    std::cout << evaluate(expression) << std::endl;
    return 0;
}
