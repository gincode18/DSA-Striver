#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr = {0, 2,4, 3, 5, 6, 7};
  vector<int> a(arr.size()+1,0);


  for (int i = 0; i < arr.size(); i++) {
    a[arr[i]]=1;
  }
for (int i = 0; i < a.size(); i++)
{
    if (a[i]==0)
    {
        cout<<i;
    }
    
}

  return 0;
}