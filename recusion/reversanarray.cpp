// reverse an array
#include <iostream>
using namespace std;
void f(int l, int r, int arr[]) {
  if (l >= r) {
    return;
  }
  swap(arr[l], arr[r]);
  f(l + 1, r - 1, arr);
}
void swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
} 
int main() {
  int n;
  int arr[5];
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }

  f(0, 4, arr);
  for (int i = 0; i < 5; i++) {
    cout << arr[i];
  }

  return 0;
}
