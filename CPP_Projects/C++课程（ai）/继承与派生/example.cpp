#include<iostream>
#include<string>

class Animal{
protected:
    std::string name;
    int age;
public:
    Animal(const std::string& n,int a):name(n),age(a){
        std::cout<<"Animal "<<name<<" constructed\n";
    }
    virtual ~Animal(){
        std::cout<<"Animal "<<name<<" destroyed\n";
    }
    void eat() const{
        std::cout<<name<<" is eating.\n";
    }
    void sleep() const {
        std::cout<<name<<" is sleeping.\n";
    }
};

class Dog:public Animal{
    std::string breed;
public:
    Dog(const std::string& n,int a,const std::string& b)
    :Animal(n,a),breed(b){
        std::cout<<"Dog "<<name<<" constructed\n";
    }
    ~Dog(){
        std::cout<<"Dog "<<name<<" destroyed\n";
    }
    void bark() const{
        std::cout<<"Dog "<<name<<" barks:woof!\n";
    }
    void showBreed() const{
        std::cout<<name<<" is a "<<breed<<".\n";
    }
};

class Cat:public Animal{
    bool isIndoor;
public:
    Cat(const std::string& n,int a,bool indoor)
    :Animal(n,a),isIndoor(indoor){
        std::cout<<"Car "<<name<<" constructed\n";
    }
    ~Cat(){
        std::cout<<"Cat "<<name<<" destroyed\n";
    }
    void meow() const{
        std::cout<<name<<" meows: Meow!\n";
    }
};

int main() {
    Dog buddy("Buddy", 3, "Golden Retriever");
    Cat whiskers("Whiskers", 2, true);

    buddy.eat();
    buddy.bark();
    whiskers.sleep();
    whiskers.meow();

    return 0;
}