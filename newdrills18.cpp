#include "std_lib_facilities.h"

// 1 Define a global int array建立了一个函数组里面有十个数
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

//function f that takes array and number of elements（接受数组和元素数量的函数 f
void f(int ai[], int n)
{
    //ai = array instance（数组实例
    //la = local array（本地数组
    int la[10] = { };
    for (int i = 0; i < n; ++i) la[i] = ai[i]; //assign la array to all elements of ai array - ai array is a parameter（将本地数组分配于ai数组

    cout << "Local copy\n";
    for (const auto& a : la)
        cout << a << ' ';
    cout << '\n';

    //allocated n spaces in memory to create array p - a pointer can be dealt with as an array too（在内存中分配 n 个空间来创建数组 p - 指针也可以作为数组处理
    int* p = new int[n]; //new int[n] = allocated number of bytes n in memory分配n个
    for (int i = 0; i < n; ++i) p[i] = ai[i];

    cout << "Pointer to free store\n";
    for (int i = 0; i < n; ++i)
        cout << p[i] << ' ';
    cout << '\n';//(重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，但是它们的参数列表和定义（实现）不相同。An overloaded declaration is a declaration with the same name as a function or method that has been previously declared in that scope, but with a different parameter list and definition (implementation).)

    delete[] p; //deallocating array to prevent memory leak 清空数组
}

int fac(int n) { return n > 1 ? n * fac(n - 1) : 1; } //function to get factorial以阶乘来求得下列两个方程

int main()
try {
    // code
    cout << "Binary array\n";
    f(ga, 10);

    int aa[10] = {};
    for (int i = 0; i < 10; ++i)
        aa[i] = fac(i + 1);

    cout << "Factorial array\n";//分别用local与pointer输出阶乘结果
    f(aa, 10);
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Unknown exception\n";
    return 2;
}
