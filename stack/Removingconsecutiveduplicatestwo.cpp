//{ Driver Code Starts
#include <iostream>
#include <stack>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to remove pair of duplicates from given string using Stack.
    string removePair(string s)
    {
        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
                continue;
            }
          

            if (st.top() == s[i])
            {
                st.pop();
                continue;
            }
            else
            {
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            char x = st.top();
            st.pop();
            ans += x;
        }
        string rev_ans = "";
        for (int i = ans.length() - 1; i >= 0; --i)
        {
            rev_ans += ans[i];
        }
        return rev_ans;
    }
};

//{ Driver Code Starts.

int main()
{

    string s = "aaabbaaccd";

    Solution obj;
    string ans = obj.removePair(s);
    if (ans == "")
        cout << "Empty String" << endl;
    else
        cout << ans << endl;

    return 0;
}
// } Driver Code Ends