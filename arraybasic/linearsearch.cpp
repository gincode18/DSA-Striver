#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  vector<int> arr = { 4,3,2,4,3};
 int num=3;
 int temp=0;
  for (int i = 0; i < arr.size(); i++) {
    if(arr[i]==num) temp=i;
  }
  cout<<temp;

  return 0;
}