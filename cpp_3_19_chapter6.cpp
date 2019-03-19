#include <iostream>
#include <initializer_list>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void exercise6_10(int *pA, int *pB)
{ // 指针交换两个int的值
    int nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

void exercise6_12(int &nA, int &nB)
{ // 引用交换两个int的值
    int nTemp = nA;
    nA = nB;
    nB = nTemp;
}

void exercise6_27(std::initializer_list<int> il)
{ // 使用 initializer_list计算列表的元素和
    int nResult{0};
    for(auto beg = il.begin(); beg != il.end(); ++beg)
    {
        nResult += *beg;
    }
    cout << nResult << endl;
}

void test1(std::initializer_list<string> sl)
{ // 查看elem的类型
    for(const auto &elem : sl)
        cout << elem << endl;
}

int main(int argc, char const *argv[])
{
    // int nA = 1, nB = 2;

    // exercise6_10(&nA, &nB);
    // cout << nA << "\t" << nB << endl;

    // exercise6_12(nA, nB);
    // cout << nA << "\t" << nB << endl;

    // exercise6_27({1, 2, 3, 4, 5});

    test1({"a", "b", "cd", "efg"});

    return 0;
}
