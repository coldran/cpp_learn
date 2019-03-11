#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    // int i{1}, *p{&i};
    // decltype(*p) c = i;
    // c = 2;
    // std::clog << "now show" << std::endl;
    // std::cout << i << std::endl;

    std::string line;
    while (std::getline(std::cin, line))   //getline 读取一整行包括换行符，赋值给目标string不包括换行符
    {
        for (auto c : line)    //基于范围的for语句 遍历序列中每个值进行操作
        {
            std::cout << c << '\t';
        }
        std::cout << line << std::endl;
    }
    return 0;
}
