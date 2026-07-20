#include<iostream>
#include<string>

template<typename T>
void swapValues(T& a,T& b){
    T temp=a;
    a=b;
    b=temp;
}

template<typename T>
int findIndex(const T* arr,int size,const T& target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main() {
    // ---------- 测试 int ----------
    int a = 10, b = 20;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapValues(a, b);
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;

    int intArr[] = {5, 3, 8, 1, 9};
    int sizeInt = sizeof(intArr) / sizeof(intArr[0]);
    int targetInt = 8;
    int idx = findIndex(intArr, sizeInt, targetInt);
    std::cout << "Index of " << targetInt << " in intArr: " << idx << std::endl;

    // ---------- 测试 std::string ----------
    std::string s1 = "Hello", s2 = "World";
    std::cout << "\nBefore swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    swapValues(s1, s2);
    std::cout << "After swap:  s1 = " << s1 << ", s2 = " << s2 << std::endl;

    std::string strArr[] = {"apple", "banana", "cherry", "date"};
    int sizeStr = sizeof(strArr) / sizeof(strArr[0]);
    std::string targetStr = "cherry";
    int idxStr = findIndex(strArr, sizeStr, targetStr);
    std::cout << "Index of \"" << targetStr << "\" in strArr: " << idxStr << std::endl;

    // 测试未找到的情况
    int notFound = findIndex(intArr, sizeInt, 100);
    std::cout << "Index of 100 in intArr: " << notFound << std::endl;

    return 0;
}