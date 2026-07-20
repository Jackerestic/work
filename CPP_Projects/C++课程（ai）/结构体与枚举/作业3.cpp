#include<iostream>
#include<string>
#include<algorithm>

struct Student{
    std::string name;
    int id;
    double score;
};

enum class SortBy{Name,ID,Score};

bool compareByName(const Student& a,const Student& b){
    return a.name<b.name;
}

bool compareByID(const Student& a,const Student& b){
    return a.id<b.id;
}

bool compareByScore(const Student& a,const Student& b){
    return a.score>b.score;
}

bool(*getComparator(SortBy sortby))(const Student&,const Student&){
    if(sortby==SortBy::Name)return compareByName;
    if(sortby==SortBy::ID)return compareByID;
    if(sortby==SortBy::Score)return compareByScore;
    return nullptr;
}

int main()
{
    int n;
    std::cout<<"请输入学生人数:";
    std::cin>>n;

    Student* students=new Student[n];
    for(int i=0;i<n;i++){
        std::cout<<"输入姓名，学号，成绩： ";
        std::cin>>students[i].name>>students[i].id>>students[i].score;
    }
    
    int choice;
    std::cout<<"排序依据（1-姓名，2-学号，3-成绩）：";
    std::cin>>choice;
    SortBy sortby=static_cast<SortBy>(choice);

    auto comp=getComparator(sortby);
    if(comp==nullptr){
        std::cout<<"无效选择\n";
        delete[] students;
        return 1;
    }

    std::sort(students,students+n,comp);

    for(int i=0;i<n;i++){
        std::cout<<students[i].name<<" "
                 <<students[i].id<<" "
                 <<students[i].score<<std::endl;
    }

    delete[] students;
    return 0;
}