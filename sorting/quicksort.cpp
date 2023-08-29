#include <iostream>
#include <vector>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (i < j) {
    while (arr[i] <= arr[low] && i <= high - 1) {
      i++;
    }
    while (arr[j] > arr[low] && j >= low +1) {
      j--;
    }
    if(i<j) swap(arr[j],arr[i]);

  }
  swap(arr[j],arr[low]);
  return j;
}
void quicksort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int partitionindex = partition(arr, low, high);
    quicksort(arr, low, partitionindex - 1);
    quicksort(arr, partitionindex + 1, high);
  }
}

int main() {
  vector<int> arr = {12, 3, 21, 23, 13, 12, 22, 4, 11};
  quicksort(arr, 0, arr.size() - 1);
  for (int i = 0; i < 9; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}