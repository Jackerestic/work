#include<iostream>

bool ascending(int a,int b){return a<b;}
bool descending(int a,int b){return a>b;}

void bubbleSort(int* arr,int size,bool(*compare)(int,int)){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(compare(arr[j],arr[j+1])){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int nums[]={5,2,8,1,9};
    int size=sizeof(nums)/sizeof(nums[0]);

    bubbleSort(nums,size,ascending);
    for(int i=0;i<size;i++)std::cout<<nums[i]<<" ";

    std::cout<<"\n";

    bubbleSort(nums,size,descending);
    for(int i=0;i<size;i++)std::cout<<nums[i]<<" ";

    return 0;
}