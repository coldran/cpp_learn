#include <iostream>
#include <initializer_list>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

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

int exercise6_33(vector<int>::iterator &itBegin, vector<int>::iterator &itEnd)
{ // 递归输出vector对象
    if(itBegin != itEnd)
    {
        cout << *itBegin++ << endl;
        exercise6_33(itBegin, itEnd);
    }
    return 0;
}

int exercise6_33(const vector<int> &vnTest)
{ // 递归输出vector对象
    static auto viBegin = vnTest.begin();
    if(viBegin != vnTest.end())
    {
        cout << *viBegin++ << endl;
        exercise6_33(vnTest);
    }
    return 0;
}

void test2()
{ // 测试，当vector赋值时，begin和end都变化，用第一个vector的迭代器根据第二个vector的值比对，会出现错误，实际上时迭代器会直接++到第二个迭代器的对应值
    int k = 0;
    vector<int> i{1, 2, 3, 4};
    vector<int> j{i};
    auto p = i.begin();
    auto q = j.end();
    while(p != q)
    {
        cout << k++ << "\t" << *p << endl;
        p++;
    }
}

string (&exercise6_36(void))[10]
{ // 返回数组的引用
    static string sTest[10]{"a", "b"};
    return sTest;
}

using strarr = string[10];
strarr &exercise6_37_1(void)
{ // 类型别名
    static string sTest[10]{"a", "b"};
    return sTest;
}

auto exercise6_37_2(void) -> string(&)[10]
{ // 后置返回类型
    static string sTest[10]{"a", "b"};
    return sTest;
}

string nArr[10];
decltype(nArr) &exercise6_37_3(void)
{ // decltype关键字返回
    static string sTest[10]{"a", "b"};
    return sTest;
}

int main(int argc, char const *argv[])
{
    // int nA = 1, nB = 2;

    // exercise6_10(&nA, &nB);
    // cout << nA << "\t" << nB << endl;

    // exercise6_12(nA, nB);
    // cout << nA << "\t" << nB << endl;

    // exercise6_27({1, 2, 3, 4, 5});

    // test1({"a", "b", "cd", "efg"});

    // vector<int> vnTest{1, 2, 3, 4, 5, 6, 7};
    // auto Begin = vnTest.begin();
    // auto End = vnTest.end();
    // exercise6_33(Begin, End);
    // exercise6_33(vnTest);

    // test2();

    // string (&sReturn)[10] = exercise6_36();
    // for(auto i : sReturn)
    //     cout << i << endl;

    // string (&sReturn)[10] = exercise6_37_1();

    // string (&sReturn)[10] = exercise6_37_2();

    // string (&sReturn)[10] = exercise6_37_3();

    return EXIT_SUCCESS;
}
