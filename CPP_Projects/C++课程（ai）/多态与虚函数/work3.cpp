#include <iostream>

// 类 A：无虚函数
class A {
public:
    void func() {}
};

// 类 B：含虚函数
class B {
public:
    virtual void func() {}
    virtual void another() {}
};

int main() {
    std::cout << "sizeof(A) = " << sizeof(A) << std::endl;   // 通常为 1（空类最小 1 字节）
    std::cout << "sizeof(B) = " << sizeof(B) << std::endl;   // 通常为 8（64位系统）或 4（32位系统）

    /*
     * 解释：类 A 不含虚函数，是一个空类，编译器会分配 1 字节占位（使每个对象有唯一地址）。
     * 类 B 含有虚函数，编译器会隐含添加一个指向虚函数表（vtable）的指针（称为 vptr），
     * 该指针的大小在 64 位系统上为 8 字节，在 32 位系统上为 4 字节。
     * 因此 sizeof(B) = 指针大小 + 可能的对齐填充（但此处无其他成员，故就是指针大小）。
     * 多出来的字节正是 vptr。
     */

    // 尝试观察 vptr 的内容（类型双关，实现相关，仅作演示）
    B b;
    // 将对象地址解释为 void* 指针的起始地址（即 vptr 的地址）
    void** vptr_addr = reinterpret_cast<void**>(&b);
    std::cout << "Address of object b: " << &b << std::endl;
    std::cout << "Address of vptr (first 8 bytes): " << vptr_addr << std::endl;
    std::cout << "Value of vptr (points to vtable): " << *vptr_addr << std::endl;

    // 注意：这是未定义行为，且依赖于编译器实现，仅用于说明概念。
    // 实际上，vptr 是对象内存布局的第一个成员（通常如此），但标准未规定。
    // 生产代码中绝不应该这样操作。

    return 0;
}