#include<iostream>
#include<string>

struct Student{
    std::string name;
    int ID;
    double Score;
};

void print(const Student& student){
    std::cout<<"Name: "<<student.name<<std::endl;
    std::cout<<"ID: "<<student.ID<<std::endl;
    std::cout<<"Score: "<<student.Score<<std::endl;
}

void sortByScore(Student* arr,int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j].Score<arr[j+1].Score){
                Student temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main() {
    int n;
    std::cout << "请输入学生人数: ";
    std::cin >> n;

    // 动态分配数组（或使用 std::vector）
    Student* students = new Student[n];

    // 输入数据
    for (int i = 0; i < n; ++i) {
        std::cout << "请输入第 " << i + 1 << " 位学生的姓名、学号、成绩: ";
        std::cin >> students[i].name >> students[i].ID >> students[i].Score;
    }

    // 排序
    sortByScore(students, n);

    // 打印排序后的列表
    std::cout << "\n排序后的学生列表（按成绩降序）:\n";
    for (int i = 0; i < n; ++i) {
        print(students[i]);
    }

    // 释放动态内存
    delete[] students;
    return 0;
}