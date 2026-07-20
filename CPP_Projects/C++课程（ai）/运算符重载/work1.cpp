#include<iostream>
#include<cstring>

class MyString
{
private:
    char* data;
public:
    MyString():data(nullptr){}

    MyString(char* s){
        if(s){
            data=new char[std::strlen(s)+1];
            std::strcpy(data,s);
        }else{
            data=nullptr;
        }
    }

    MyString(const MyString& other){
        if(other.data){
            data=new char[std::strlen(other.data)+1];
            std::strcpy(data,other.data);
        }else{
            data=nullptr;
        }
    }

    MyString& operator=(const MyString& other){
        if(this==&other)return *this;
        delete[] data;
        if(other.data){
            data=new char[std::strlen(other.data)+1];
            std::strcpy(data,other.data);
        }else{
            data=nullptr;
        }
        return *this;
    }

    ~MyString(){
        delete[] data;
    }

    int size(){
        return std::strlen(data);
    }

    char& operator[](size_t index){
        if(index>size()){
            std::cout<<"index out of range";
        }
        return data[index];
    }

    friend MyString operator+(const MyString& a,const MyString& b);
    friend bool operator==(const MyString& a,const MyStrinf& b);
    friend std::ostream& operator<<(std::ostream& os,const MyString& c);
}

MyString operator+(const MyString& a,const MyString& b){
    int lengtha=std::strlen(a.data);
    int lengthb=std::strlen(b.data);
    int lengthtotal=lengtha+lengthb;

    char* newData=new char[lengthtotal+1];
    if(a.data){
        std::strcpy(newData,a.data);
    }else{
        newData[0]='\0';
    }
    if(b.data){
        std::strcpy(newData+lengtha,b.data);
    }
}

bool operator==(const MyString& a,const MyString& b){
    return std::strcmp(a.data,b.data)==0;
}

bool operator!=(const MyString& a,const MyString& b){
    return !(a==b);
}

std::ostream& operator<<(std::ostream& os,const MyString& c){
    os<<c.data;
    return os;
}

