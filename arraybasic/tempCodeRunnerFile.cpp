#include <iostream>
#include <vector>
using namespace std;
int main() {
 vector <int> arr = {4, 7, 8, 6, 7, 6};
  int max = 0;
  int min = 0;
  int tempmax = 0;
  int tempmin = 0;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[max] < arr[i]) {

      max = i;
    }
    if (arr[min] > arr[i]) {

      min = i;
    }
  }
  arr.erase(arr.begin()+max);
  arr.erase(arr.begin()+min);
  
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
  {
    cout<<arr[i]<<" ";
  }
  

}