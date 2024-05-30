#include <iostream>
using namespace std;
void insertAtEnd(int arr[], int sizeOfArray, int element)
{
    sizeOfArray--;
    arr[sizeOfArray] = element;
}
void insertAtIndex(int arr[], int sizeOfArray, int index, int element)
{

    int temp = arr[index];
    arr[index] = element;

    for (int i = index + 1; i < sizeOfArray ; i++)
    {
        int x = arr[i];
        arr[i] = temp;
        temp = x;
    }
}
int main()
{
    int arr[] = {7, 7, 1, 1};
    insertAtIndex(arr, 5, 3, 3);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}