#include<iostream>
#include<string>

class Printable
{
public:
    virtual std::string Getclassname()=0;
};

class Entity:public Printable
{
public:
    virtual std::string Getname(){return "Entity";};
    std::string Getclassname() override {return "Entity";}
};

class Player :public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        :m_Name(name){}
    std::string Getname() override {return m_Name;}
    std::string Getclassname() override {return "Player";}
};

void Printname(Entity *e)
{
    std::cout<<e->Getname()<<std::endl;
}

void Print(Printable* obj)
{
    std::cout<<obj->Getclassname()<<std::endl;
};

int main()
{
    Entity* e=new Entity();
    //Printname(e);

    Player* p=new Player("Cherno");
    //Printname(p);

    Print(e);
    Print(p);

    std::cin.get();
}