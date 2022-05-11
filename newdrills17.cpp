// Chapter 17, drill自由空间数组A pointer is a variable whose value is the address of another variable指针是一个变量，其值为另一个变量的地址

#include "std_lib_facilities.h"

// 4write an array of ten elements in a to os（编写a中十个元素的数组到os
void print_array10(ostream& os, int* a) {
    for (int i = 0; i < 10; ++i)
        os << a[i] << "\n";
}

// 7与上题不同之处在于 n 个元素
void print_array(ostream& os, int* a, int n) {
    for (int i = 0; i < n; ++i)
        os << a[i] << "\n";
}

// 10编写包含十个元素的数组到os（Repeat five to six eight steps to replace the array with vector
void print_vector(ostream& os, vector<int> v) {
    for (int i = 0; i < v.size(); ++i)
        os << v[i] << "\n";
}

int main()
try {
    // 1使用new分配一个由十个int组成的数组（Use new to allocate an array of ten ints
    int* ip = new int[10];

    // 2用cout打印这十个int值（print these ten int values ​​with cout
    cout << "*** 2 ***\n";
    for (int i = 0; i < 10; ++i)
        cout << ip[i] << "\n";

    // 3释放这个数组
    delete[] ip;

    // 5 10个int组成的数组从100开始；打印数值（Array of 10 ints starts at 100; prints the value
    cout << "*** 5 ***\n";
    int* ip2 = new int[10];
    for (int i = 0; i < 10; ++i)
        ip2[i] = 100 + i;
    print_array10(cout, ip2);
    delete[] ip2;

    // 6 11个
    cout << "*** 6 ***\n";
    int* ip3 = new int[11];
    for (int i = 0; i < 11; ++i)
        ip3[i] = 100 + i;
    print_array10(cout, ip3);
    cout << ip3[10] << "\n";
    delete[] ip3;

    // 8  20个int组 并且第九题是释放这些数组
    cout << "*** 8 ***\n";
    int* ip4 = new int[20];
    for (int i = 0; i < 20; ++i)
        ip4[i] = 100 + i;
    print_array(cout, ip4, 20);
    delete[] ip4;

    // 10 重复568步骤以vector代替数组
    cout << "*** 10 ***\n";
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(100 + i);
    print_vector(cout, v);

    cout << "\n";
    vector<int> v2;
    for (int i = 0; i < 11; ++i)
        v2.push_back(100 + i);
    print_vector(cout, v2);

    cout << "\n";
    vector<int> v3;
    for (int i = 0; i < 20; ++i)
        v3.push_back(100 + i);
    print_vector(cout, v3);

    // second part第二部分
    // 1分配一个int 将他初始化为7地址分配给p1（Allocate an int initialize it to 7 and assign it to p1
    int i1 = 7;
    int* p1 = &i1;

    // 2打印p1的值和他指向的值（print the value of p1 and the value it points to
    cout << "*** 2 ***\n";
    cout << "p1: " << p1 << "\n";
    cout << "*p1: " << *p1 << "\n";

    // 3分配由七个int组成的数组；初始化为1，2，4，8（Allocates an array of seven ints; initialized to 1, 2, 4, 8
    int* p2 = new int[7];
    for (int i = 0; i < 7; ++i)
        p2[i] = pow(2, i);

    // 4 同2
    cout << "*** 4 ***\n";
    cout << "p2: " << p2 << "\n";
    cout << "print_array(cout,p2,7):\n";
    print_array(cout, p2, 7);

    // 5声明p3用p2初始化declare that p3 is initialized with p2
    int* p3 = p2;

    // 6 Assign p1 to p2
    p2 = p1;

    // 7 Assign p3 to p2
    p2 = p3;

    // 8打印p1 p2的值和他们指向的数组
    cout << "*** 8 ***\n";
    cout << "p1: " << p1 << "\n";
    cout << "*p1: " << *p1 << "\n";
    cout << "p2: " << p2 << "\n";
    cout << "*p2: " << *p2 << "\n";

    // 9释放所有从自由空间分配的内存（Free all memory allocated from free space
    delete[] p2;
    p3 = 0;

    // 10分配一个由10个int组成的数组；初始化为1248，地址分配给p1（Allocate an array of 10 ints; initialized to 1248, address assigned to p1
    p1 = new int[10];
    for (int i = 0; i < 10; ++i)
        p1[i] = pow(2, i);

    // 11 将地址赋值给变量p2
    p2 = new int[10];

    // 12将p1指向值复制到p2（Copy the value pointed to by p1 to p2
    cout << "*** 12 ***\n";
    for (int i = 0; i < 10; ++i)
        p2[i] = p1[i];
    print_array(cout, p2, 10);

    // 13以vetor来代替数组重复10-12
    cout << "*** 13 ***\n";
    vector<int> vec1;
    for (int i = 0; i < 10; ++i)
        vec1.push_back(pow(2, i));
    vector<int> vec2;
    for (int i = 0; i < vec1.size(); ++i)
        vec2.push_back(vec1[i]);
    print_vector(cout, vec2);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
