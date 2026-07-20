#include<iostream>
#include<string>

class Shape{
protected:
    std::string color;
public:
    Shape():color("unknown"){}

    std::string getColor() const{
        return color;
    }
};

class Circle:public Shape{
private:
    double radius;
public:
    Circle(const std::string& c,double r):radius(r){
        color=c;
    }

    void printInto() const{
        std::cout<<"Circle: color= "<<color
                 <<",radius = "<<radius<<std::endl;
    }
};

class Rectangle:public Shape{
private:
    double width,height;
public:
    Rectangle(const std::string& c,double w,double h):width(w),height(h){
        color=c;
    }
    void printInto() const {
        std::cout<<"Rectangle: color = "<<color
                 <<",width = "<<width
                 <<",height = "<<height<<std::endl;
    }
};

int main()
{
    Circle circle("red",5.0);
    Rectangle rect("blue",4.0,6.0);

    std::cout<<"Circle's color(via getColor): "<<circle.getColor()<<std::endl;
    std::cout<<"Rectangle's color(via getColor):"<<rect.getColor()<<std::endl;

    circle.printInto();
    rect.printInto();

    return 0;
}