#include<iostream>
#include<string>

int main()
{
    std::string s="STL";
    for(char ch:s){
        std::cout<<ch<<" ";
    }
    std::cout<<"\n";

    for(char& ch:s){
        ch=std::toupper(ch);
    }

    return 0;
}