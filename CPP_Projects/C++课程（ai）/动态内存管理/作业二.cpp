#include<iostream>
#include<memory>

struct Entity{
    std::unique_ptr<int[]> data;
    int capacity;
    int size;
    Entity():data(nullptr),capacity(0),size(0){}
    void add(int value){
        if(size==capacity){
            int newcapacity=(capacity==0)?1:capacity*2;
            std::unique_ptr<int[]> newdata=std::make_unique<int[]>(newcapacity);

            for(int i=0;i<size;i++){
                newdata[i]=data[i];
            }

            data=std::move(newdata);
            capacity=newcapacity;
        }
        data[size]=value;
        size++;
    }
    void print(){
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