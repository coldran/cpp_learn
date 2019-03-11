#include <iostream>

int main(int argc, char const *argv[])
{
    int i{1}, *p{&i};
    decltype(*p) c = i;
    c = 2;
    std::clog << "now show" << std::endl;
    std::cout << i << std::endl;
    return 0;
}
