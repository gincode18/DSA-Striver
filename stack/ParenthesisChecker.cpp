//{ Driver Code Starts
#include <iostream>
#include <stack>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '(' || x[i] == '[' || x[i] == '{')
            {
                s.push(x[i]);
            }
            if (x[i] == ')' || x[i] == ']' || x[i] == '}')
            {
                if (s.empty() || (x[i] == ')' && s.top() != '(') || (x[i] == ']' && s.top() != '[') || (x[i] == '}' && s.top() != '{'))
                    return false;
                s.pop();
            }
        }

        return s.empty();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    string a = "([])";

    Solution obj;
    if (obj.ispar(a))
        cout << "balanced" << endl;
    else
        cout << "not balanced" << endl;
}
// } Driver Code Ends