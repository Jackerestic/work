#include<iostream>
#include<memory>

class DynamicArray{
private:
    int* data;
    int capacity;
    int length;

    DynamicArray(const DynamicArray&)=delete;
    DynamicArray& operator=(const DynamicArray&)=delete;
public:
    DynamicArray(int initialCapacity=4)
        :data(nullptr),capacity(0),length(0)
    {
        if(initialCapacity<=0)initialCapacity=4;
        data=new int[initialCapacity];
        capacity=initialCapacity;
    }
    ~DynamicArray(){
        delete[] data;
    }
    void add(int value){
        if(length==capacity){
            int newCapacity=capacity*2;
            int* newData=new int[newCapacity];

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

    int size(){
        return length;
    }

    void print() const{
        for(int i=0;i<length;i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
    }
};

int main()
{
    DynamicArray arr;
    for(int i=0;i<10;i++){
        arr.add(i*10);
    }
    std::cout<<"Size: "<<arr.size()<<std::endl;
    arr.print();

    return 0;
}