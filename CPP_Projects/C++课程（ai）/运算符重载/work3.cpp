#include<iostream>
#include<stdexcept>
#include<algorithm>

class Vector
{
private:
    int* data;
    size_t length;
public:
    Vector(size_t len,int initVal=0)
        :data(nullptr),length(len){}

    Vector(const Vector& other){
        length=other.length;
        if(other.data){
            data=new int[other.length];
            for(size_t i=0;i<other.length;i++)
            {
                data[i]=other.data[i];
            }
        }else{
            data=nullptr;
        }
    }

    Vector& operator=(const Vector& other){
        if(this==&other)return *this;
        delete[] data;
        length=other.length;
        if(other.data){
            data=new int[other.length];
            for(size_t i=0;i<other.length;i++){
                data[i]=other.data[i];
            }
        }else{
            data=nullptr;
        }
        return *this;
    }

    ~Vector(){
        delete[] data;
    }

    friend Vector operator+(const Vector& a,const Vector& b);
    friend int operator*(const Vector& a,const Vector& b);
    friend std::ostream& operator<<(std::ostream& os,const Vector& v);
};

Vector operator+(const Vector& a,const Vector& b){
    if(a.length!=b.length){
        throw std::runtime_error("Vector size mismatch");
    }
    Vector result(a.length);
    for(size_t i=0;i<a.length;i++){
        result.data[i]=a.data[i]+b.data[i];
    }
    return result;
}

int operator*(const Vector& a,const Vector& b){
    if(a.length!=b.length)throw std::runtime_error("Vector size mismatch");
    int sum=0;
    for(size_t i=0;i<a.length;i++){
        sum+=a.data[i]*b.data[i];
    }
    return sum;
}

std::ostream& operator<<(std::ostream& os,const Vector& v){
    os<<"[";
    for(size_t i=0;i<v.length;i++){
        os<<v.data[i];
        if(i!=v.length-1)os<<" ";
    }
    os<<"]";
    return os;
}
