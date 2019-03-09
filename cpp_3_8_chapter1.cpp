#include <iostream>

int main(int argc, char const *argv[])
{
    // int value = 0, sum = 0;
    // while(std::cin >> value){
    //     sum += value;
    // }
    // std::cout << "sum = " << sum << std::endl;

    // int a{1};
    // int &b{a};
    // int *p{&a};
    // int &q{*p};
    // std::cout << b << std::endl;

    int i{10};
    const int &j{i};
    int  &k{i};
    std::cout << i << '\t' << j << '\t' << k << std::endl;
    k = 5;
    std::cout << i << '\t' << j << '\t' << k << std::endl;

    int i2{0};
    const int *const l{&i2};
    printf("%d",*l);

    int n;
    std::cin >> n;
    constexpr int m = 3;
    std::cout << m << std::endl;

    constexpr int *c{0};

    return 0;
}
