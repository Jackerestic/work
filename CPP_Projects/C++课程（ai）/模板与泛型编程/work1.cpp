#include<iostream>
#include<string>

template<typename T>
class DynamicArray{
private:
    T* data;
    int capacity;
    int length;

    DynamicArray(const DynamicArray&)=delete;
    DynamicArray& operator=(const DynamicArray&)=delete;

public:
    explicit DynamicArray(int initialCapacity=4){
        if(initialCapacity<=0)initialCapacity=4;
        data=new T[initialCapacity];
        capacity=initialCapacity;
        length=0;
    }

    ~DynamicArray(){
        delete[] data;
    }

    void add(const T& value){
        if(length==capacity){
            int newCapacity=capacity*2;
            T* newData=new T[newCapacity];
            for(int i=0;i<length;i++){
                newData[i]=data[i];
            }
            delete[] data;
            data=newData;
            capacity=newCapacity;
        }
        data[length]=value;
        length++;
    }

    T& operator[](int index){
        return data[index];
    }

    const T& operator[](int index)const{
        return data[index];
    }
    
    int size(){
        return length;
    }

    void print(){
        for(int i=0;i<length;i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
    }

};

int main()
{
    DynamicArray<int> intArr;
    intArr.add(10);
    intArr.add(20);
    intArr.add(30);
    std::cout << "intArr: ";
    intArr.print();
    std::cout << "intArr[1] = " << intArr[1] << std::endl;

    // 测试 double
    DynamicArray<double> doubleArr;
    doubleArr.add(1.1);
    doubleArr.add(2.2);
    doubleArr.add(3.3);
    doubleArr.add(4.4);  // 触发扩容
    std::cout << "doubleArr: ";
    doubleArr.print();

    // 测试 std::string
    DynamicArray<std::string> strArr;
    strArr.add("Hello");
    strArr.add("World");
    strArr.add("C++");
    std::cout << "strArr: ";
    strArr.print();

    // 使用 const 下标（只读）
    const DynamicArray<int>& constRef = intArr;
    std::cout << "constRef[0] = " << constRef[0] << std::endl;

    // 修改元素（通过非 const 下标）
    intArr[0] = 100;
    std::cout << "修改后 intArr: ";
    intArr.print();

    return 0;
}