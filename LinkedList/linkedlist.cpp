#include <iostream>
using namespace std;
class Node
{
private:
    /* data */
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        next = nullptr;
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
        cout << temp->data;
        temp = temp->next;
    }
   
}

int main()
{
    Node *x = new Node(10);
    push(x, 2);
    push(x, 3);
    push(x, 4);
    print(x);
    return 0;
}
