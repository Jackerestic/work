#include<iostream>
int main()
{
    int** matrix=new int*[3];

    int sizes[]={2,3,4};
    for(int i=0;i<3;i++)
    {
        matrix[i]=new int[sizes[i]];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<sizes[i];j++){
            matrix[i][j]=(i+1)*10+j;
        }
    }
    std::cout<<"Jagged array contents:\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<sizes[i];j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    for(int i=0;i<3;i++)
    {
        delete[] matrix[i];
    }
    delete matrix;
    return 0;
}