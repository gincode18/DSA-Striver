#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> &A, int X, int Y) {
int minCost = 50;
int N = A.size();

for (int i = N - 1; i >= 0; i--) {
int currentCost = 0;
int daysLeft = X;

for (int j = i; j >= 0 && daysLeft > 0; j -= Y) {
currentCost += A[j];
daysLeft--;
}

if (daysLeft == 0) {
minCost = min(minCost, currentCost);
}
}

return minCost;

}

int main() {
    vector<int> A1 = {4, 2, 3, 7};
    int X1 = 2, Y1 = 2;
    cout << "Test Case 1 - Minimum cost: " << solution(A1, X1, Y1) << endl; // Output: 7

    vector<int> A2 = {10, 3, 4, 7};
    int X2 = 2, Y2 = 3;
    cout << "Test Case 2 - Minimum cost: " << solution(A2, X2, Y2) << endl; // Output: 17

    vector<int> A3 = {4, 2, 5, 4, 3, 5, 1, 4, 2, 71};
    int X3 = 3, Y3 = 2;
    cout << "Test Case 3 - Minimum cost: " << solution(A3, X3, Y3) << endl; // Output: 6

    return 0;
}
