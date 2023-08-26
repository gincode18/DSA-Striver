#include <iostream>

using namespace std;
void insertionsort(int arr[],int n){
    
    int temp;
    for (int i = 0; i <= n-2; i++)
    {  int min=i;
         for (int j = i; j <= n-1; j++)
        {
            if (arr[min]>arr[j])
            {
                min=j;
            }
            
        }
         temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    
}

int main() {
    int arr[5]={1,5,3,4,2};
    insertionsort(arr,5);    
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;

}