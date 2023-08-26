#include <iostream>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
void bubble(int arr[], int n) {
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
}
int main() {
  int arr[] = {1, 23, 2, 42,2, 4};
  bubble(arr, 6);
  for (int i = 0; i < 6; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}