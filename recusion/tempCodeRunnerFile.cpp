#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> &A, int X, int Y) {
vector<int> min_costs(X, INT_MAX);
min_costs[0] = A[0];
for (int i = 1; i < A.size(); i++) {
for (int j = 1; j <= X; j++) {
if (i + Y * (j - 1) < A.size()) {
min_costs[j] = min(min_costs[j], min_costs[j - 1] + A[i]);
}
}
}
return min_costs[X - 1];
}

int main() {
  vector<int> A = {4, 2, 3, 7};
  int X = 2;
  int Y = 2;

  int cost = solution(A, X, Y);
  cout << "The minimum cost is " << cost << endl;

  return 0;
}
