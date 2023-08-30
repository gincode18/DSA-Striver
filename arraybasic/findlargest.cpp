#include<iostream>
using namespace std;
int main(){
    int arr[]={4 ,7 ,8 ,6, 7, 6 };
    int max=0;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        if (arr[max]<arr[i])
        {
            max=i;
        }
        
    }
    cout<<arr[max];
}