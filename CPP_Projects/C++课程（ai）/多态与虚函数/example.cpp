#include<iostream>
#include<vector>
#include<cmath>
#include<memory>

class Shape
{
public:
    virtual double area() const =0;
    virtual void describe() const =0;
    virtual ~Shape(){}
};

class Circle:public Shape
{
    double radius;
public:
    Circle(double r):radius(r){}
    double area() const override{
        return 3.14159265*radius*radius;
    }
    void describe() const override{
        std::cout<<"Circle,radius "<<radius<<",area "<<area()<<"\n";
    }

};

class Rectangle:public Shape
{
    double width,height;
public:
    Rectangle(double w,double h):width(w),height(h){}
    double area() const override{
        return width*height;
    }
    void describe() const override{
        std::cout<<"Rectabgle, "<<width<<"X"<<height<<",area "<<area()<<"\n";
    }
};

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(3.0,4.0));
    shapes.push_back(std::make_unique<Circle>(2.5));

    double totalArea=0.0;
    for(const auto& s:shapes){
        s->describe();
        totalArea+=s->area();
    }
    std::cout<<"Total area: "<<totalArea<<"\n";

    return 0;
}