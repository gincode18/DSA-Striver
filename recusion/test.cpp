#include <iostream>
#include <vector>

using namespace std;

int solution(int N, vector<int> &A, vector<int> &B) {
vector<int> degree(N, 0);  // To keep track of the degree of each vertex
vector<bool> removed(N, false);  // To mark removed vertices
int remainingVertices = N;  // To keep track of the remaining vertices

// Calculate the degree of each vertex
for (int i = 0; i < A.size(); ++i) {
degree[A[i]]++;
degree[B[i]]++;
}

int seconds = 0;
while (remainingVertices > 0) {
vector<int> toRemove;  // Store vertices to be removed in this step

// Find vertices with at most one edge
for (int i = 0; i < N; ++i) {
if (!removed[i] && degree[i] <= 1) {
toRemove.push_back(i);
}
}

// If no vertices to remove, exit the loop
if (toRemove.empty()) {
break;
}

// Remove vertices and their edges
for (int vertex : toRemove) {
removed[vertex] = true;
remainingVertices--;

for (int i = 0; i < A.size(); ++i) {
if (A[i] == vertex || B[i] == vertex) {
degree[A[i]]--;
degree[B[i]]--;
}
}
}

seconds++;
}

return seconds;
}

int main() {
    int N = 7;
    vector<int> A = {0, 1, 2, 1, 4, 4};
    vector<int> B = {1, 2, 0, 4, 5, 6};
    cout << solution(N, A, B) << endl;  // Output: 2

    N = 7;
    A = {0, 1, 2, 4, 5};
    B = {1, 2, 3, 5, 6};
    cout << solution(N, A, B) << endl;  // Output: 2

    N = 4;
    A = {0, 1, 2, 3};
    B = {1, 2, 3, 0};
    cout << solution(N, A, B) << endl;  // Output: 0

    return 0;
}
