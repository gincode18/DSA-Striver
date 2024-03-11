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
Node *reverseList(Node *head)
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
Node *addTwoLists(Node *first, Node *second)
{
    Node *L1 = reverseList(first);
    Node *L2 = reverseList(second);
    if (first == NULL && second == NULL)
    {
        return new Node(0);
    }
    Node *temp = NULL;
    Node *head = NULL;
    int carry = 0;

    while (L1 != NULL && L2 != NULL)
    {
        int sum = 0;
        sum = L1->data + L2->data + carry;
        carry = sum / 10;
        Node *new_node = new Node(sum % 10);
        if (temp == NULL)
        {
            temp = new_node;
            head = temp;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }

        L1 = L1->next;
        L2 = L2->next;
    }
    if (L1 != NULL)
    {
        while (L1 != NULL)
        {
            int sum = 0;
            sum = L1->data + carry;
            carry = sum / 10;
            Node *new_node = new Node(sum % 10);
            temp->next = new_node;
            temp = temp->next;
            L1 = L1->next;
        }
    }
    else
    {
        while (L2 != NULL)
        {
            int sum = 0;
            sum = L2->data + carry;
            carry = sum / 10;
            Node *new_node = new Node(sum % 10);
            temp->next = new_node;
            temp = temp->next;
            L2 = L2->next;
        }
    }
    if (carry != 0)
    {
        Node *new_node = new Node(carry);
        temp->next = new_node;
        temp = temp->next;
    }
    return head;
}
int main()
{
    Node *x = new Node(5);
    Node *y = new Node(5);
    push(y, 4);
    push(x, 4);
    push(x, 9);
    print(x);
    print(y);
    Node *z = addTwoLists(x, y);
    Node *c = reverseList(z);
    print(c);
    return 0;
}