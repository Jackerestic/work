#include<iostream>
#include<iomanip>

class Time{
private:
    int hour;
    int minute;
    int second;

    void nominal(){
        if(hour<0||hour>23)hour=0;
        if(minute<0||minute>59)minute=0;
        if(second<0||second>59)second=0;
    }
    
    static int totalObjects;

public:
    Time(int h=0,int m=0,int s=0){
        setTime(h,m,s);
        ++totalObjects;    
    }

    Time(const Time& other)
        :hour(other.hour),minute(other.minute),second(other.second){
            ++totalObjects;
        }

    ~Time(){
        --totalObjects;
    }

    void setTime(int h,int m,int s){
        hour=h;
        minute=m;
        second=s;
        nominal();
    }

    void print24Hour()const{
        std::cout<<std::setfill('0')<<std::setw(2)<<hour<<":"
                 <<std::setw(2)<<minute<<":"
                 <<std::setw(2)<<second<<std::setfill(' ');
    }

    void print12Hour()const{
        int h12=hour;
        std::string period="AM";

        if(hour==0){
            period="AM";
            h12=12;
        }else if(hour>=1&&hour<=11){
            period="AM";
        }else if(hour==12){
            period="PM";
        }else{
            period="PM";
            h12=hour-12;
        }
        std::cout<<std::setfill('0')<<std::setw(2)<<h12<<":"
                 <<std::setw(2)<<minute<<":"
                 <<std::setw(2)<<second<<" "<<period<<std::setfill(' ');   
    }

    static int getTotalObjects(){
        return totalObjects;
    }

    friend bool isEarlier(const Time& t1,const Time& t2);
};

int Time::totalObjects=0;

bool isEarlier(const Time& t1,const Time& t2){
    if(t1.hour!=t2.hour)return t1.hour<t2.hour;
    if(t1.minute!=t2.minute)return t1.minute<t2.minute;
    if(t1.second!=t2.second)return t1.second<t2.second;
    return false;
}