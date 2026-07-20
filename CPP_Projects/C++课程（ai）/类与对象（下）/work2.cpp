#include<iostream>
#include<cstring>

class MyString
{
private:
    char* string;
    static int totalStringCount;
public:
    MyString():string(nullptr){totalStringCount++;}

    MyString(const char* s){
        if(s){
            string=new char[std::strlen(s)+1];
            std::strcpy(string,s);
        }else{
            string=nullptr;
        }
        totalStringCount++;
    }

    MyString(const MyString& other){
        if(other.string){
            string=new char[std::strlen(other.string)+1];
            std::strcpy(string,other.string);
        }else{
            string=nullptr;
        }
        totalStringCount++;
    }

    MyString& operator=(const MyString& other){
        if(this==&other)return *this;
        delete[] string;
        if(other.string){
            string=new char[std::strlen(other.string)+1];
            std::strcpy(string,other.string);
        }
        return *this;
    }

    ~MyString(){
        delete[] string;
        totalStringCount--;
    }

    int size(){
        if(string){
            return std::strlen(string);
        }else{
            return 0;
        }
    }

    void print(){
        if(string){
            std::cout<<string<<std::endl;
        }else{
            std::cout<<"Nullptr"<<std::endl;
        }
    }

    static int getTotalCount(){return totalStringCount;}

    friend MyString concatenate(const MyString& a,const MyString& b);
};

int MyString::totalStringCount=0;

MyString concatenate(const MyString& a,const MyString& b){
    int length1=a.string?strlen(a.string):0;
    int length2=b.string?strlen(b.string):0;
    int totallength=length1+length2;

    char* newData=new char[totallength];
    if(a.string){
        strcpy(newData,a.string);
    }else{
        newData[0]='\0';
    }
    if(b.string){
        strcpy(newData+length1,b.string);
    }
    MyString result;
    result.string=newData;
    return result;
}
