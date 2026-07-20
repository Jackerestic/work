#include<iostream>

struct Entity
{
    int* data;
    int capacity;
    int size;
    Entity()
        :data(nullptr),capacity(0),size(0){}
    ~Entity(){
        delete[] data;
    }
    void add(int value){
        if(size==capacity){
            int newcapacity=(capacity==0)?1:capacity*2;
            int* newdata=new int[newcapacity];

            for(int i=0;i<size;i++){
                newdata[i]=data[i];
            }

            delete[] data;

            data=newdata;
            capacity=newcapacity;
        }
        data[size]=value;
        size++;
    }
    void print()
    {
        for(int i=0;i<size;i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
    }
};

int main() {
    Entity arr;
    for (int i = 1; i <= 10; ++i) {
        arr.add(i);
        arr.print();
    }
    // 析构函数自动释放内存
    return 0;
}