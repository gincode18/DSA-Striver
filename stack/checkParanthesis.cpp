#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); // Dummy element to mark the start
    int max_len = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else { // s[i] == ')'
            st.pop();
            if (!st.empty()) {
                max_len = max(max_len, i - st.top());
            } else {
                st.push(i); // Replacing the popped element
            }
        }
    }
    
    return max_len;
}

int main() {
    // string input1 = "()()";
    // cout << "Input1: " << input1 << endl;
    // cout << "Output1: " << longestValidParentheses(input1) << endl;

    string input2 = "(((())()(()";
    cout << "Input2: " << input2 << endl;
    cout << "Output2: " << longestValidParentheses(input2) << endl;

    return 0;
}
