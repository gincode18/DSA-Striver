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
    if (arr[i] > arr[max]) {

      max = i;
    }
    if (arr[i] < arr[min]) {

      min = i;
    }
  }
  arr.erase(arr.begin()+max);
    if (min > max) {
    min--;
  }
  arr.erase(arr.begin()+min);
  max=0;
  min=0;

  for (int i = 0; i < arr.size(); i++)
  {
   if (arr[i] > arr[max]) {

      max = i;
    }
    if (arr[i] < arr[min]) {

      min = i;
    }
  }
  vector<int> v ={arr[max],arr[min]};
  cout<<arr[max]<<arr[min];

}