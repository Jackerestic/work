#include<iostream>
#include<cmath>

struct Point{
    double x;
    double y;
};

struct Rectangle{
    Point topLeft;
    double width;
    double height;
};

double area(const Rectangle& rect){
    return rect.width*rect.height;
}

bool contains(const Rectangle& rect,const Point& p){
    return p.x>=rect.topLeft.x&&
           p.x<=rect.topLeft.x+rect.width&&
           p.y>=rect.topLeft.y&&
           p.y<=rect.topLeft.y+rect.height;
}

double distance(const Point& a,const Point& b){
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return std::sqrt(dx*dx+dy*dy);
}

int main() {
    Rectangle rect = { {2.0, 3.0}, 5.0, 4.0 };  // 左上角(2,3)，宽5，高4
    Point p1 = {4.0, 5.0};
    Point p2 = {8.0, 2.0};

    std::cout << "Rectangle area: " << area(rect) << "\n";
    std::cout << "Point p1 in rect? " << (contains(rect, p1) ? "Yes" : "No") << "\n";
    std::cout << "Point p2 in rect? " << (contains(rect, p2) ? "Yes" : "No") << "\n";
    std::cout << "Distance p1-p2: " << distance(p1, p2) << "\n";

    return 0;
}