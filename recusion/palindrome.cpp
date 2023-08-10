// reverse an array
#include <iostream>
using namespace std;
void f(int l, int n, int arr[]) {
  if (l>=n/2)
  {
    cout << "palindrome";
    return;
  }
  
  if (arr[l] != arr[n - l - 1]) {
    cout << "not a palindrome";
    return;
  }
  return f(l+1,n,arr);
}

int main() {
  int n;
  int arr[5];
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }

  f(0, 5, arr);
 

  return 0;
}
