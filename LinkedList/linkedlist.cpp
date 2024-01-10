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
void push(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    head=temp;
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
int main()
{
    Node *x = new Node(2);
    push(x, 4);
    push(x, 3);
    push(x, 2);
    push(x, 1);
    print(x);
    return 0;
}