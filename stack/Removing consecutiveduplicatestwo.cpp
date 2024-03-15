//{ Driver Code Starts
#include <iostream>
#include <stack>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to remove pair of duplicates from given string using Stack.
    string removePair(string str)
    {
       
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