#include <iostream>

class foo
{
    public:
    foo() = default;
    int a;

};

class bar
{
    public:
    bar();
    int b;

};

bar::bar() = default;

int main()
{
    foo a;
    bar b;

    std::cout << a.a << '\t' << b.b;

}
