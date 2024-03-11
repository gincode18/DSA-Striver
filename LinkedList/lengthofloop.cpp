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

int lengthofloop(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // Check for loop
        if (fast == slow) {
            int count = 1;
            slow = slow->next;
            while (fast != slow)
            {
                slow = slow->next;
                count++;
            }
            return count;
        }
    }
}
int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    // Creating a loop for testing
    head->next->next->next->next->next = head->next;
    cout << "Length of loop: " << lengthofloop(head) << endl;


    return 0;
}