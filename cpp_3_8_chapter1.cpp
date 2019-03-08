#include <iostream>

int main(int argc, char const *argv[])
{
    int value = 0, sum = 0;
    while(std::cin >> value){
        sum += value;
    }
    std::cout << "sum = " << sum << std::endl;
    return 0;
}
