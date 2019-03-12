#include <iostream>
#include <string>
#include <vector>

void test1()
{
    int i{1}, *p{&i};
    decltype(*p) c = i;
    c = 2;
    std::clog << "now show" << std::endl;
    std::cout << i << std::endl;
}

void test2()
{
    std::cout << "1 : input line or enter" << std::endl;
    std::string line;
    while (std::getline(std::cin, line)) // getline 读取一整行包括换行符，赋值给目标string不包括换行符
    {
        if (!line.empty()) // string下标
            line[0] = 'a';
        else
            break;

        for (auto c : line) // 基于范围的for语句 遍历序列中每个值进行操作
        {
            std::cout << c << '\t';
        }
        std::cout << std::endl;

        for (auto &c : line) // 改变原来元素的值，使用引用的方式
        {
            c = toupper(c);
        }
        std::cout << line << std::endl;
    }
}

void test3()
{
    std::cout << "2 : input number" << std::endl;
    const std::string hexdigits = "0123456789ABCDEF";
    std::string result;
    std::string::size_type n;
    while (std::cin >> n)
    {
        if (n < hexdigits.size())
            result += hexdigits[n];
    }
    std::cout << result << std::endl;
}

void exercise3_6()
{
    std::string s;
    std::cin >> s;
    for (auto &x : s)
        x = 'x';
    std::cout << s << std::endl;
}

void exercise3_7()
{
    std::string s;
    std::cin >> s;
    for (char &x : s)
        x = 'x';
    std::cout << s << std::endl;
}

void exercise3_10()
{
    std::string s;
    std::getline(std::cin, s);
    std::string result;
    for (auto x : s)
    {
        if (!ispunct(x))
            result += x;
    }
    std::cout << result << std::endl;
}

void exercise3_11()
{
    const std::string s = "keep";
    for (auto &x : s)
    {
        // char &x1{x}; // type of x is const char
        const char &x2{x};
        std::cout << x2;
    }
}

void test3_3()
{
    int a{1}, &b{a};
    // std::vector<decltype((a))> c{b}; // 引用不是对象
    std::vector<int> d{a};
    std::cout << b << std::endl;
}

void exercise3_14()
{
    std::vector<int> num;
    int n;
    while (std::cin >> n)
        num.push_back(n);
    for (auto x : num)
        std::cout << "val = " << x <<std::endl;
}

void exercise3_15()
{
    std::vector<std::string> s;
    std::string n;
    while (std::cin >> n)
        s.push_back(n);
    for (auto x : s)
        std::cout << "val = " << x <<std::endl;
}

void exercise3_17()
{
    std::vector<std::string> line;
    line.push_back("hello");
    std::string s;
    while (std::cin >> s)
        line.push_back(s);
    for (auto x : line)
    {
        for (auto &x2 : x)
            x2 = toupper(x2);
        std::cout << x << std::endl;
    }
}

void exercise3_20()
{
    std::vector<int> num;
    int n;
    while (std::cin >> n)
        num.push_back(n);
    for (decltype(num.size()) i = 1; i < num.size(); i++)
    {
        std::cout << num[i - 1] + num[i] << std::endl;
    }
}

void exercise3_21()
{
    std::vector<int> num;
    int n;
    while (std::cin >> n)
        num.push_back(n);
    for (decltype(num.size()) i = 0; i < num.size(); i++)
    {
        std::cout << num[i] + num[num.size() - i - 1] << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    // test3();
    // exercise3_6();
    // exercise3_7();
    // exercise3_10();
    // exercise3_11();
    // exercise3_14();
    // exercise3_15();
    // exercise3_17();
    // exercise3_20();
    exercise3_21();
    return 0;
}
