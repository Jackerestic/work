#include<iostream>
#include<string>

struct Student{
    int id;
    double score;
};

template <typename T>
void printSize(){
    std::cout<<"sizeof("<<typeid(T).name<<") = "<<sizeof(T)<<std::endl;
}

int main(){
    printSize<int>();
    printSize<double>();
    printSize<char>();
    printSize<std::string>();
    printSize<Student>();

    return 0;
}