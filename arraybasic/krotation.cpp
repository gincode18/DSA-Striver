// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//   vector<int> arr = {1, 2, 2, 42, 1, 2};
//   int first = arr[0];
//   for (int i = 0; i < arr.size() - 1; i++) {
//     arr[i] = arr[i + 1];
//     if (i == arr.size() - 2) {
//       arr[i + 1] = first;
//     }
//   }

//   for (int i = 0; i < arr.size(); i++) {
//     cout << arr[i] << endl;
//   }

//   return 0;
// }

// leetcode
#include <iostream>
#include <vector>
using namespace std;
// void rightrotate(vector<int> &arr) {
//   int last = arr[arr.size() - 1];
//   for (int i = arr.size() - 1; i > 0; i--) {
//     arr[i] = arr[i - 1];
//     if (i == 1) {
//       arr[0] = last;
//     }
//   }
// }
int main() {
  vector<int> arr = {1, 2, 2, 42, 1, 2};
  int k=3;
  vector<int> temp;

for (int i = arr.size()-k; i < arr.size(); i++)
{
  temp.push_back(arr[i]);

}
for (int i = 0; i < arr.size()-k; i++)
{
   temp.push_back(arr[i]);

}
arr=temp;

for (int i = 0; i < arr.size(); i++)
{
    cout<<arr[i]<<" ";
}


  return 0;
}