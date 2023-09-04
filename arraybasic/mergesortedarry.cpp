#include <iostream>
#include <vector>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
vector <int> removeduplicate(vector<int> arr) {
  vector<int> sum;
  int number = 0;
  for (int i = 0; i < arr.size(); i++) {

    if (number == arr[i]) {
      continue;
    } else
      sum.emplace_back(arr[i]);
    number = arr[i];
  }
  return  sum;
}
int main() {
  vector<int> arr = {3 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,9,9 };
  vector<int> brr = {2 ,4 ,10 ,10 };
  vector<int> temp;
 
  for (int i = 0; i < arr.size() + brr.size(); i++) {
    if (i < arr.size())
      temp.push_back(arr[i]);
    if (i >= arr.size())
      temp.push_back(brr[i-arr.size()]);
  }
   for (int i = temp.size() - 1; i >= 1; i--) {
    for (int j = 0; j < i; j++) {
      if (temp[j] > temp[j + 1])
        swap(temp[j], temp[j + 1]);
    }
  }
  temp=removeduplicate(temp);
  for (int i = 0; i < temp.size(); i++) {
    cout << temp[i] << endl;
  }

  return 0;
}
///better approach
// vector<int> sortedArray(vector<int> arr, vector<int> brr) {
//     vector<int> result;
//     int i = 0, j = 0;

//     while (i < arr.size() && j < brr.size()) {
//         if (arr[i] < brr[j]) {
//             result.push_back(arr[i]);
//             i++;
//         } else if (arr[i] > brr[j]) {
//             result.push_back(brr[j]);
//             j++;
//         } else {
//             // If both elements are equal, push one to the result and move both pointers
//             result.push_back(arr[i]);
//             i++;
//             j++;
//         }
//     }

//     // Append remaining elements from arr and brr (if any)
//     while (i < arr.size()) {
//         result.push_back(arr[i]);
//         i++;
//     }
//     while (j < brr.size()) {
//         result.push_back(brr[j]);
//         j++;
//     }

//     return result;
// }
