#include<iostream>

enum class Operation{Add=1,Subtract,Multiply,Devide,Quit};

void display(){
    std::cout<<"1.+"<<std::endl;
    std::cout<<"2.-"<<std::endl;
    std::cout<<"3.*"<<std::endl;
    std::cout<<"4./"<<std::endl;
    std::cout<<"5.quit"<<std::endl;
    std::cout<<"Please choose the operation:"<<std::endl;
}

void calculate(const Operation& op){
    std::cout<<"Enter two numbers:"<<std::endl;
    double x,y;
    std::cin>>x>>y;
    std::cout<<"The result is ";
    switch(op){
        case Operation::Add:
            std::cout<<x+y<<std::endl;
            break;
        case Operation::Subtract:
            std::cout<<x-y<<std::endl;
            break;
        case Operation::Multiply:
            std::cout<<x*y<<std::endl;
            break;
        case Operation::Devide:
            std::cout<<x/y<<std::endl;
            break;
    }
}

int main()
{

    do{
    display();
    int choice;
    std::cin>>choice;

    Operation op=static_cast<Operation>(choice);
    if(op==Operation::Quit){
        break;
    }else{
        calculate(op);
    }

    }while(true);
    
}