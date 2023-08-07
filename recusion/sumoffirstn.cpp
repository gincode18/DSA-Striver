// sum of first n number 
 #include<iostream>
using namespace std;
void f(int n,int sum){
    if (n==0)
    { cout<<sum;
       return ;
    }
    
  
f(n-1,sum+n);
}
int main(){
int n=0;
f(5,n);

    return 0;}