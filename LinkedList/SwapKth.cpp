#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        next = NULL;
    }
};
void push(Node *&head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *swapkth(Node *head, int num, int K)
{
    if (K > num)
    {
        return head;
    }
    if (2*K-1==num)
    {
       return head;
    }
    
    int count = 1;
    Node *curr = head;
    Node *first, *second = NULL;

    while (curr != NULL)
    {
        if (count == K)
        {
            first = curr;
        }
        if (count == num - K+1)
        {
            second = curr;
        }
        count++;
        curr = curr->next;
    }
    int temp=first->data;
    first->data=second->data;
    second->data=temp;
    return head;

}
int main()
{
    Node *x = new Node(2);
    push(x, 4);
    push(x, 3);
    push(x, 2);
    push(x, 1);
    print(x);
    Node*y=swapkth(x,5,3);
    print(y);
    
    return 0;
}