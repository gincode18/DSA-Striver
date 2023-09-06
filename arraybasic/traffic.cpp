#include <iostream>
#include <vector>
using namespace std;

// int main() {
//   vector<int> arr = {0, 1, 1, 1, 1, 0, 0};
//   int m=3;
//   int sum=0;
//   for (int i = 0; i < arr.size(); i++)
//   { if (arr[i]!=0) sum++;
//     if (m!=0)
//     {
//         if (arr[i]==0)
//         {
//             arr[i]=1;
//             m--;
//             sum++;
//         }
//     }

    
//   }
//   for (int i = 0; i < arr.size(); i++)
//   {
//     cout<<arr[i]<<" ";
//   }
  
//   cout<<sum;
//   return 0;
// }
//better way
int traffic(int n, int k, vector<int> nums) {
	// Write your code here.
	int cnt_zeros = 0;
	int i =0;
	int j = 0;
	int len = 0;

	while(j<n)
	{
		if(nums[j] == 0)
		{
			cnt_zeros++;
		}

		while(cnt_zeros > k)
		{
			if(nums[i] == 0)
			{
				cnt_zeros--;
			}
			i++;
		}
		len = max(len,j-i+1);
		j++;
	}
	return len;
}

