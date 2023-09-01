#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr = {1,4,3,5,6,8};
  bool v;
  for (int i = 0; i < arr.size()-1; i++)
  {
     if (arr[i]<=arr[i+1])
     {
       v=1;
     }
    else{
        v=0;
        break;
    }
  }
  cout<<v;
  return 0;
}