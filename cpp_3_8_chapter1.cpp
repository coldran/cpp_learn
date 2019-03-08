#include <iostream>

int main(int argc, char const *argv[])
{
    // int value = 0, sum = 0;
    // while(std::cin >> value){
    //     sum += value;
    // }
    // std::cout << "sum = " << sum << std::endl;

    int a{1};
    int &b{a};
    int *p{&a};
    int &q{*p};

    std::cout << b << std::endl;
    return 0;
}
