#include<iostream>
#include<string>

class Vehicle{
protected:
    double speed;
    double weight;
public:
    Vehicle(double s,double w):speed(s),weight(w){}

    virtual void run(){
        std::cout<<"Vehicle is running at speed "<<speed<<" km/h.\n";
    }
};

class Car:public Vehicle{
    std::string fuelType;
public:
    Car(double s,double w,const std::string& f)
    :Vehicle(s,w),fuelType(f){}

    void run(){
        std::cout<<"Car is driving at speed "<<speed<<" km/h,fuel:"<<fuelType<<"\n";
    }
};

class Bicycle:public Vehicle{
    bool hasBasket;
public:
    Bicycle(double s,double w,bool h)
    :Vehicle(s,w),hasBasket(h){}

    void run(){
        std::cout<<"Bicycle is cycling at speed "<<speed<<" km/h,basket:"<<(hasBasket?"Yes":"No")<<"\n";
    }
};

int main()
{
    Car car(2.0, 7.0, "ehedai");
    Bicycle bike(15.0, 10.0, true);

    car.run();   
    bike.run();
    
    Vehicle* vPtr = &car; 
    vPtr->run(); 

    return 0;
}