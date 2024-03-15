//{ Driver Code Starts
#include <iostream>
#include <stack>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string s)
    {
        stack<char> st;
        string ans = "";

        // Iterate through the string
        for (int i = 0; i < s.length(); i++)
        {

            if (st.empty() || s[i] != st.top())
            {
                st.push(s[i]);
                ans += s[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    string s = "aaaaaabaabccccccc";

    Solution obj;
    cout << obj.removeConsecutiveDuplicates(s) << endl;

    return 0;
}
// } Driver Code Ends