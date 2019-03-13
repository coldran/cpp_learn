#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void test1()
{ // 测试，decltype作用于表达式获得一个引用类型
    int *a;
    int c;
    decltype(*a) b{c};
    std::cout << b << std::endl;

    int i{1};
    std::cout << i << std::endl;
    // std::cout << i++ << " " << ++i << " " << (i++) << std::endl; // 何时对运算对象求值是未定义的，由编译器决定，是错误的语句，加上()来确定
}

void exercise4_4()
{ // 计算运算
    std::cout << (12 / 3 * 4 + 5 * 15 + 24 % 4 / 2) << std::endl;

    std::cout << (-30 * 3 + 21 / 5) << '\n'
              << (-30 + 3 * 21 / 5) << '\n'
              << (30 / 3 * 21 % 5) << '\n'
              << (-30 / 3 * 21 % 4) << std::endl;
}

void exercise4_6()
{ // 判断整数为奇数还是偶数
    int nA;
    std::cin >> nA;
    if (nA % 2)
        std::cout << "ji" << std::endl;
    else
        std::cout << "ou" << std::endl;
}

void exercise4_10()
{ // 输入数字 42时停止
    int nA;
    while (cin >> nA && nA != 42)
        cout << nA << endl;
}

void exercise4_11()
{ // 测试4个值 确保a大于b，b大于c， c大于d
    vector<int> vTest;
    int nTemp;
    for (int i = 0; i < 4; ++i)
    {
        cin >> nTemp;
        vTest.push_back(nTemp);
    }
    for (auto j = vTest.begin() + 1; j != vTest.end(); ++j)
    {
        if (*(j - 1) > *j)
        {
            cout << "wrong" << endl;
            return;
        }
    }
    cout << "right" << endl;
}

void test2()
{ // 判断 i!=j<k
    // int i = 1;
    // int j = 2;
    // int k = 3;
    // cout << (i != j < k) << endl;
}

void test3()
{ // 测试int char 大小
    cout << sizeof(int) << " " << sizeof(char) << endl;
}


int main(int argc, char const *argv[])
{
    // test1();
    // exercise4_4();
    // exercise4_6();
    // exercise4_10();
    // exercise4_11();
    // test2();
    test3();

    return 0;
}
