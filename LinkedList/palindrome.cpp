#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *reverse(Node *head)
{

    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
bool ispalindrome(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow->next;
    mid = reverse(mid);
    while (mid != NULL)
    {
        if (head->data != mid->data)
        {
            return false;
        }
        head = head->next;
        mid = mid->next;
    }
    return true;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout << "Is palindrome: " << (ispalindrome(head) ? "Yes" : "No") << endl;
    return 0;
}