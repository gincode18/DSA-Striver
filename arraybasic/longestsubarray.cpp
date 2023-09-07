#include <iostream>
#include <vector>
using namespace std;

int main() {
  int j;
  int k = 3;
  vector<int> len;

  vector<int> arr = {1 ,2 ,3 ,1 ,1, 1 ,1};
  for (int i = 0; i < arr.size(); i++) {
    j = i;
    vector<int> temp;
    int sum = 0;
    while (j < arr.size() && sum <= k) {
      if (sum <= k) {
        sum = sum + arr[j];
        temp.push_back(arr[j]);

        if (sum != k) {
          j++;
        }
      }
      if (sum == k) {
        len.push_back(temp.size());
        j++;
      }
    }
  }
  int max=0;
  for (int i = 0; i < len.size(); i++)
  {
    if (len[i]>max)
    {
        max=len[i];
    }
    
  }
  cout<<max;
  

  return 0;
}