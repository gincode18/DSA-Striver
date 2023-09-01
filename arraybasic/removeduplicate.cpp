#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr = {1, 1, 1, 2, 3, 4, 4, 4, 5, 6,7,8,9,9,9,9,9};
 vector <int> sum;
  int number = 0;
  for (int i = 0; i < arr.size(); i++) {

    if (number == arr[i]) {
      continue;
    } else
      sum.emplace_back(arr[i]);
    number = arr[i];
  }
    for (int i = 0; i < sum.size(); i++)
    {
        cout<<sum[i]<<endl;
    }
    

  return 0;
}