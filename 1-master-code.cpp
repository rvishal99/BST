#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
void inOrder(node *&root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
node *insert(node *&root, int key)
{
    if (root == NULL)
    {
        node *temp = new node(key);
        return temp;
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}
bool searchBST(node *root, int k)
{
    if (root == NULL)
    {
        return false;
    }
    if (k = root->data)
    {
        return true;
    }
    else if (k > root->data)
    {
        searchBST(root->right, k);
    }
    else
    {
        searchBST(root->left, k);
    }
}
node *minVAL(node *root)
{
    node *temp = root;

    // Find the leftmost leaf
    while (temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node *deleteNODE(node *&root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deleteNODE(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNODE(root->right, key);
    }
    else
    {
        // if the node is with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // If the node has two children
        node *temp = minVAL(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNODE(root->right, temp->data);
    }
    return root;
}
int main()
{
    node *root = NULL;

    while (1)
    {
        cout << endl;
        cout << "Enter your choice 1: insertion 2: inorder  3:exit  4:BST search" << endl;
        int d;
        cout << "\nEnter choice: " << endl;
        cin >> d;

        switch (d)
        {
        case 1:
        {
            int d;
            cout << "Enter data: " << endl;
            cin >> d;

            root = insert(root, d);
            break;
        }
        case 2:
        {
            inOrder(root);
            break;
        }
        case 3:
        {
            exit(0);
        }
        case 4:
        {
            int k;
            cout << "Enter key to be searc " << endl;
            cin >> k;
            bool res = searchBST(root, k);
            if (res)
            {
                cout << "Key is present" << endl;
            }
            else
            {
                cout << "Key is not present" << endl;
            }
            break;
        }
        default:
        {
            cout << "Invalid character!!!" << endl;
        }
        }
    }
    return 0;
}