#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

void test1()
{ // 测试switch执行中，在某case之前定义变量
    int nA = 3;
    switch (nA)
    {
    case 1:
        int nB;
        nB = 2;
        break;
    case 2:
    {
        int nC;
        nC = 4;
        break;
    }
    default:
        cout << nB << endl;
        // cout << nC << endl; ERROR
        break;
    }
}

void exercise5_23()
{ // 输入两个数字 第二个时0的话异常处理
    int i, j;
    std::runtime_error err{"error 1"};
    std::runtime_error err2{"error 2"};
    while (cout << "input two int" << endl &&
           cin >> i >> j)
    {
        try
        {
            if (j == 0)
                throw std::runtime_error("error 3");
        }
        catch (std::runtime_error err3) // err3 相当于传入参数的变量名
        {
            cout << err2.what() << endl; // 输出err2
            cout << err3.what() << endl; // 输出 throw 的赋值
            cout << "try again?(y/n)" << endl;
            char cF;
            cin >> cF;
            if (cF == 'y')
                continue;
            else
                break;
        }
        cout << "answer is" << static_cast<double>(i) / j << endl;
    }
}

int main(int argc, char const *argv[])
{
    // test1();
    exercise5_23();
    return 0;
}