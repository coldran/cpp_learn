#include <iostream>
#include <string>
#include <vector>

void test1()
{
    int i{1}, *p{&i};
    decltype(*p) c = i; // 解指针的类型为引用 所以c是i的引用
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
{ // 十进制数字转成十六进制
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
{ // 输入字符串 转成全部为'x'
    std::string s;
    std::cin >> s;
    for (auto &x : s)
        x = 'x';
    std::cout << s << std::endl;
}

void exercise3_7()
{ // 输入字符串 转成全部为'x' 循环控制变量的类型为char
    std::string s;
    std::cin >> s;
    for (char &x : s)
        x = 'x';
    std::cout << s << std::endl;
}

void exercise3_10()
{ // 输入字符串 去掉标点输出
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
{ // const string内的控制变量类型是const char
    const std::string s = "keep";
    for (auto &x : s)
    {
        // char &x1{x}; // type of x is const char
        const char &x2{x};
        std::cout << x2;
    }
}

void test3_3()
{ // 定义vector的对象不能为引用，引用不是对象
    int a{1}, &b{a};
    // std::vector<decltype((a))> c{b}; // 引用不是对象
    std::vector<int> d{a};
    std::cout << b << std::endl;
}

void exercise3_14()
{ // 向vector添加元素 int
    std::vector<int> num;
    int n;
    while (std::cin >> n)
        num.push_back(n);
    for (auto x : num)
        std::cout << "val = " << x << std::endl;
}

void exercise3_15()
{ // 向vector添加元素 string
    std::vector<std::string> s;
    std::string n;
    while (std::cin >> n)
        s.push_back(n);
    for (auto x : s)
        std::cout << "val = " << x << std::endl;
}

void exercise3_17()
{ // 输入string 变为大写输出
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
{ // 输入数字，相邻两个相加输出
    std::vector<int> num;
    int n;
    while (std::cin >> n)
        num.push_back(n);
    for (decltype(num.size()) i = 1; i < num.size(); i++)
    {
        std::cout << num[i - 1] + num[i] << std::endl;
    }
}

void exercise3_20_2()
{ // 输入数字，第i个和倒数第i个相加输出
    std::vector<int> num;
    int n;
    while (std::cin >> n)
        num.push_back(n);
    for (decltype(num.size()) i = 0; i < num.size(); i++)
    {
        std::cout << num[i] + num[num.size() - i - 1] << std::endl;
    }
}

void exercise3_21()
{ // 迭代器输出输入的数字
    std::vector<int> num;
    int n;
    while (std::cin >> n)
        num.push_back(n);
    for (auto it = num.cbegin(); it != num.cend(); ++it)
        std::cout << *it << std::endl;
}

void test4()
{ // 测试 it->empty() (*it).empty()
    std::vector<int>::iterator a;
    std::vector<char>::iterator b;
    std::vector<std::string>::iterator c;

    // a-> //不存在
    // b-> //不存在
    c->empty(); // 是迭代器解引用后的 对象（string） 的 成员， int char 没有成员
    (*c).empty();
}

void exercise3_23()
{ // 输出int的vector对象 元素变为原来的2倍
    std::vector<int> num(10, 5);
    for (auto it = num.begin(); it != num.cend(); ++it)
        *it *= 2;
    for (auto x : num)
        std::cout << x << "\t";
}

void test5()
{ //测试 非常量表达式作为维度定义数组; 错误 
    // unsigned cnt = 42;
    // std::vector<int> l;
    // int a[cnt];
    // int b[l.size()];
    // std::cout << a << b << std::endl;
}

void exercise3_43()
{ // 输出二位数组的不同方式
    int ia[3][4]{0, 1, 2, 3, 4, 5, 6, 7};

    // for (auto &p : ia) // ia的元素是长度为4的int数组，所以是这个4长度数组赋值给p，又因为数组赋值给auto会转化成指针,所以p会被赋值为指针，则在内部循环中，指针没有end，出错
    //     for (auto q : p)
    //         std::cout << q << " ";

    for (int (&p)[4] : ia) // 定义p为4长度数组的引用，进行范围for
        for (int q : p) // q为4长度数组内元素，进行范围for
            std::cout << q << " ";
    std::cout << std::endl;

    for (size_t i{0}; i < 3; ++i) // 定义下标类型i，外层循环
        for (size_t j{0}; j < 4; ++j) // 定义下标类型j，内层循环
            std::cout << ia[i][j] << " ";
    std::cout << std::endl;

    typedef int (*point_arry)[4]; // 定义指向4长度int数组的指针
    for (point_arry p = std::begin(ia); p != std::end(ia); p++) // p为指向4长度int数组的指针，从ia中循环读取4长度数组的地址
        for (int *q = std::begin(*p); q != std::end(*p); q++) // q为指向int的指针，从4长度数组中循环读取
            std::cout << *q << " ";
    std::cout << std::endl;
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
    // exercise3_20_2();
    // exercise3_21();
    // exercise3_23();
    // test5();
    // exercise3_43();
    return 0;
}
