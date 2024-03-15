//{ Driver Code Starts
// Initial template for C++

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        int count = 0;
        if (sizeOfStack % 2 == 0)
        {
            count = (sizeOfStack / 2) - 1;
        }
        else
        {
            count = sizeOfStack / 2;
        }
        vector<int> arr;
        for (int i = 0; i < count; i++)
        {
            int x = s.top();
            s.pop();
            arr.push_back(x);
        }
        for (int i = 0; i <= count; i++)
        {
            s.push(arr[i]);
        }
    }
};

//{ Driver Code Starts.
int main()
{

    int sizeOfStack = 5;

    stack<int> myStack;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeOfStack; i++)
    {
        myStack.push(arr[i]);
    }

    Solution ob;
    ob.deleteMid(myStack, myStack.size());
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}

// } Driver Code Ends