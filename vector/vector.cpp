#include <iostream>
using namespace std;
#include <vector>
int main() {
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  cout << v[0] << endl;
  cout << v[1] << endl;
  cout << v[2] << endl;
  cout << v.size() << endl;
  cout << *(v.begin()) << endl;

  return 0;
}