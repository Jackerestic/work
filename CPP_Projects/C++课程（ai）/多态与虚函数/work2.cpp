/*
2. 动物园多态
继承第15讲的 Animal 类，将 eat()、sleep() 声明为虚函数，并添加纯虚函数 void makeSound() const = 0。派生 Lion（makeSound 输出 "Roar!"）、Elephant（输出 "Trumpet!"）、Monkey（输出 "Ooh ooh!"）。
用 std::vector<Animal*> 管理若干动物，循环调用三个函数。注意析构函数虚与否的影响。
*/
#include<iostream>
#include<vector>
#include<string>
#include<memory>

class Animal
{
public:
    virtual ~Animal()=default;

    virtual void eat() const{
        std::cout<<"Animal is eating.\n";
    }

    virtual void sleeping() const{
        std::cout<<"Animal is sleeping.\n";
    }

    virtual void makeSound() const =0;
};

class Lion:public Animal
{
public:
    void makeSound() const override{
        std::cout<<"Roar!\n";
    }
};

class Elephant:public Animal
{
public:
    void makeSound() const override{
        std::cout<<"Trumpet!\n";
    }
    void sleeping() const override{
        std::cout<<"Elephant is sleeping standing up.\n";
    }
};

class Monkey:public Animal
{
public:
    void makeSound() const override{
        std::cout<<"Ooh,ooh!\n";
    }

    void eat() const override{
        std::cout<<"Monkey is eating bananas.\n";
    }
};

int main()
{
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Lion>());
    animals.push_back(std::make_unique<Elephant>());
    animals.push_back(std::make_unique<Monkey>());

    std::cout<<"=== 动物园表演 ===\n";
    for(const auto& animal:animals){
        animal->eat();
        animal->sleeping();
        animal->makeSound();
        std::cout<<"-----------\n";
    }

    return 0;
}