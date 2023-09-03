#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  vector<int> arr = { 0, 0, 0,1};
  int zero = 0;
  vector<int> temp;
  for (int i = 0; i < arr.size() ; i++) {
    if (arr[i] == 0) {

      zero++;
    } else {
      temp.push_back(arr[i]);
    }
  }
  for (int i = 0; i < zero; i++)
  {
    temp.push_back(0);
  }
  arr=temp;
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}