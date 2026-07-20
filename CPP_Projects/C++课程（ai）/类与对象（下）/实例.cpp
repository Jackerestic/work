#include<iostream>
#include<cstring>

class Time{
private:
    int hour;
    int minute;
    int second;
    char* note;
    static int totalObjects;

public:
    Time():hour(0),minute(0),second(0),note(nullptr){
        ++totalObjects;
    }

    Time(int h,int m,int s,const char* n=nullptr)
        :hour(h),minute(m),second(s)
    {
        if(n){
            note=new char[std::strlen(n)+1];
            std::strcpy(note,n);
        }else{
            note=nullptr;
        }
        ++totalObjects;
        std::cout<<"Copy constructor called.\n";
    }

    Time& operator=(const Time& other){
        std::cout<<"Copy assignment called.\n";
        if(this==&other)return *this;
        delete[] note;
        hour=other.hour;
        minute=other.minute;
        second=other.second;
        if(other.note){
            note=new char[std::strlen(other.note)+1];
            std::strcpy(note,other.note);
        }else{
            note=nullptr;
        }
        return *this;
    }

    ~Time(){
        delete[] note;
        --totalObjects;
    }

    void print() const{
        std::cout<<hour<<":"<<minute<<":"<<second;
        if(note)std::cout<<"["<<note<<"]";
        std::cout<<"\n";
    }

    static int getTotalObjects(){return totalObjects;}

    friend bool isEarlier(const Time& t1,const Time& t2);
};

int Time::totalObjects=0;

bool isEarlier(const Time& t1,const Time& t2){
    if(t1.hour!=t2.hour)return t1.hour<t2.hour;
    if(t1.minute!=t2.minute)return t1.minute<t2.minute;
    return t1.second<t2.second;
}

int main()
{
    std::cout<<"Initial objects: "<<Time::getTotalObjects()<<"\n";
    
    Time t1(14, 30, 0, "Meeting");
    Time t2 = t1;            // 调用拷贝构造函数
    Time t3;
    t3 = t1;                 // 调用拷贝赋值运算符

    t1.print();
    t2.print();
    t3.print();

    std::cout << "t1 earlier than t2? " << isEarlier(t1, t2) << "\n";  // 0 (false, 相等)

    std::cout << "Current objects: " << Time::getTotalObjects() << "\n"; // 3
    return 0;
}