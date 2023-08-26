#include <iostream>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
void inserrtion(int arr[], int n) {
  for (int i = 0; i <= n-1; i++) {
    int j=i;
    while(arr[j-1]>arr[j]&&j>0){
        swap(arr[j-1],arr[j]);
        j--;
    }
  }
}
int main() {
  int arr[] = {1, 23, 2, 42,2, 4};
  inserrtion(arr, 6);
  for (int i = 0; i < 6; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}