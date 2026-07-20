#include<iostream>
#include<memory>

int main()
{
    int n;
    std::cout<<"Number of Students: ";
    std::cin>>n;

    auto scores=std::make_unique<double[]>(n);
    for(int i=0;i<n;i++){
        std::cout<<"Score "<<(i+1)<<"\n";
        std::cin>>scores[i];
    }

    double sum=0.0;
    for(int i=0;i<n;i++)sum+=scores[i];
    std::cout<<"Average: "<<sum/n<<"\n";

    return 0;
}