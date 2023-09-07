#include <iostream>
#include <vector>
using namespace std;

int main() {
vector<int> arr = {1, 2,4,4, 3,3, 5,5};
    int number=arr[0];

for (int i = 0; i < arr.size(); i++)
{   if (arr[i]==arr[i+1])
{

    i++;
   
}
else{
  
   cout<<arr[i];
}


}


  return 0;
}