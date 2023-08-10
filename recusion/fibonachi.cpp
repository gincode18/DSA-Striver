#include<iostream>
using namespace std;

int f(int n){
    
    if(n==0||n==1){
       
        return n;
    }
    return f(n-1)+f(n-2);
}
int sumf(int n){
    if (n==0)
    {
        return 0;
    }
    return f(n)+sumf(n-1);
}
int main(){
    // for (int i = 0; i < 8; i++)
    // {
    //     cout<<f(i)<<" ";
    //     /* code */
    // }
    cout<<sumf(5);
    
    return 0;
}