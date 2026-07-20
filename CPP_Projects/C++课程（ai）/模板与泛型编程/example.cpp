#include<iostream>
#include<stdexcept>

template <typename T>
class Stack{
private:
    T* data;
    int capacity;
    int topIndex;

    void resize(int newCapacity){
        T* newData=new T[newCapacity];
        for(int i=0;i<topIndex;i++){
            newData[i]=data[i];
        }
        delete[] data;
        data=newData;
        capacity=newCapacity;
    }
public:
    Stack(int initiaCapacity=4)
    :capacity(initialCapacity),topIndex(-1),data(new T[initialCapacity]){}

    ~Stack(){
        delete[] data;
    }

    void push(const T& value){
        if(topIndex+1==capacity){
            reside(capacity*2);
        }
        data[++topIndex]=value;
    }

    void pop(){
        if(topIndex>=0)--topIndex;
    }

    T& TOP(){
        if(topIndex<0)throw std::out_of_range("Stack is empty!");
        return data[topIndex];
    }

    bool empty() const {return topIndex==-1;}
    int size() const {return topIndex+1;}
};

int main()
{

}