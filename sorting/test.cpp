#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    const int kMod = 1000000007;
    long share = 0;
    vector<int> dp(n, 0);  // Initialize all elements to 0
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (i - delay >= 0) {
        share += dp[i - delay];
      }
      if (i - forget >= 0) {
        share -= dp[i - forget];
      }
      share = (share + kMod) % kMod;
      dp[i] = share;
    }

    // Manually sum up the last 'forget' days
    long result = 0;
    for (int i = n - forget; i < n; ++i) {
      result = (result + dp[i]) % kMod;
    }
    return result;
  }
};

int main() {
    int n, delay, forget;
    cin >> n >> delay >> forget;

    Solution solution;
    cout << solution.peopleAwareOfSecret(n, delay, forget) << endl;

    return 0;
}
