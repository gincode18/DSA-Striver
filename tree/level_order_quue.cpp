#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

void levelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (q.empty())
            {
                break; // Exit the loop if there are no more nodes to process
            }
            cout << "\n";
            q.push(NULL);
            continue;
        }

        cout << curr->key << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->right->left = new Node(50);
    root->right->right = new Node(60);

    cout << "Level order traversal of the tree is: ";
    levelorder(root);

    return 0;
}
