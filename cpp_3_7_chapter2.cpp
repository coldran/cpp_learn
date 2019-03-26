#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    int a = argc;
    std::cout << a << std::endl;
    std::string str = "nihao";
    std::cout << "hello world" << std::endl;
    std::cout << str << std::endl;
    int i{1}, *p{&i};
    decltype(*p) c = i;
    c = 2;
    std::clog << "now show" << std::endl;
    std::cout << i << std::endl;
    return 0;
}
