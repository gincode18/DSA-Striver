#include <iostream>
using namespace std;
#include <vector>
#include <stack>

// } Driver Code Ends

class Solution
{
public:
	// Function to calculate the span of stockâ€™s price for all n days.
	vector<int> calculateSpan(int price[], int n)
	{
		vector<int> x;
		stack<int> s;
		s.push(0);

		for (int i = 0; i < n; i++)
		{
			while (s.empty() == false && price[s.top()] <= price[i])
			{
				s.pop();
			}
			int span = s.empty() ? i + 1 : i - s.top();
			x.push_back(span);
			s.push(i);
		}

		return x;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int i, a[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		Solution obj;
		vector<int> s = obj.calculateSpan(a, n);

		for (i = 0; i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

// } Driver Code Ends