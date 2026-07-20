#include<iostream>

class Vector
{
private:
    double* elem;
    int sz;
public:
    Vector(int s)
        :elem(new double[s]),sz(s)
    {
        for(int i=0;i<s;i++)
        {
            elem[i]=0;
        }
    }
    Vector(const Vector& other)
        :elem(new double[other.sz]),sz(other.sz)
    {
        for(int i=0;i<sz;i++)
        {
            elem[i]=other.elem[i];
        }
    }
    Vector& operator=(const Vector& other)
    {
        if(this==&other){
            return *this;
        }
        delete[] elem;
        sz=other.sz;
        elem=new double[sz];
        for(int i=0;i<sz;i++)
        {
            elem[i]=other.elem[i];
        }
        return *this;
    }
    ~Vector()
    {
        delete[] elem;
    }
    double& operator[](int i);
    int size()const;
}