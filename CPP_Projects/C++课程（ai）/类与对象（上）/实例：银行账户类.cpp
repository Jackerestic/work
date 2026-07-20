#include<iostream>
#include<string>

class BankAccount{
private:
    std::string owner;
    double balance;
public:
    BankAccount(const std::string& name,double initialDeposit=0.0)
        :owner(name),balance(initialDeposit){}
    
    void deposit(double amount){
        if(amount>0)balance+=amount;
    }

    bool withdraw(double amount){
        if(amount>0&&balance>=amount){
            balance-=amount;
            return true;
        }
        return false;
    }

    double getBalance()const{
        return balance;
    }

    void display()const{
        std::cout<<"Owner: "<<owner<<", Balance: "<<balance<<"\n";
    }
};

int main()
{
    BankAccount alice("Alice",1000.0);
    alice.deposit(500.0);
    alice.withdraw(200.0);
    alice.display();

    const BankAccount bob("Bob",500.0);
    bob.display();
    std::cout<<bob.getBalance()<<"\n";

    return 0;
}