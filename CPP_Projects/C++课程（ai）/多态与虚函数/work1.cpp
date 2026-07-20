/*
1. 图形绘制系统
创建一个抽象基类 Graphic，包含纯虚函数 void draw() const = 0。派生 Line（接收起点终点坐标，画线用 cout 输出 "Draw line from (x1,y1) to (x2,y2)" 模拟）和 Text（接收一个字符串和坐标，输出 "Draw text '...' at (x,y)"）。
在 main 中，用 std::vector<Graphic*> 存储多个不同图形的指针，循环调用 draw()。要求：使用原始指针并手动释放，或使用智能指针练习。
*/
#include<iostream>
#include<vector>
#include<string>
#include<memory>

class Graphic
{
public:
    virtual void draw() const = 0;
};

class Line:public Graphic
{
    double x1,y1,x2,y2;
public:
    Line(double x1_,double y1_,double x2_,double y2_)
    :x1(x1_),y1(y1_),x2(x2_),y2(y2_){}

    void draw() const override{
        std::cout<<"Draw line from ("<<x1<<","<<y1<<") to ("<<x2<<","<<y2<<")\n";
    }
};

class Text:public Graphic
{
    std::string text;
    double x,y;
public:
    Text(std::string t,double x_,double y_)
    :text(t),x(x_),y(y_){}

    void draw() const override{
        std::cout<<"Draw text '"<<text<<"' at ("<<x<<","<<y<<")\n";
    }
};

int main()
{
    std::vector<std::unique_ptr<Graphic>> graphics;
    graphics.push_back(std::make_unique<Line>(0,0,10,10));
    graphics.push_back(std::make_unique<Text>("Hello",5,5));
    graphics.push_back(std::make_unique<Line>(1,2,3,4));

    for(const auto& ptr:graphics){
        ptr->draw();
    }

    return 0;
}