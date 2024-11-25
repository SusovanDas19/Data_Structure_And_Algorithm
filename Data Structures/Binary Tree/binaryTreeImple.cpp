#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter the value of the node: ";
    int val;
    cin >> val;

    if (val == -1)
    { // BASE CASE
        return NULL;
    }

    // Step1: Create a newnode
    Node *root = new Node(val);

    // Step2: Create left subtree of the root
    cout << "Left node of: " << root->data << endl;
    root->left = createTree();

    // Step3: Create right subtree of the root
    cout << "Right node of: " << root->data << endl;
    root->right = createTree();

    // Step4: return the root node
    return root;
}

void preOrderTraversal(Node *root)
{
    // Base case
    if (root == NULL)
        return;

    // Step1: Print Current Node=> N
    cout << root->data << " ";

    // Step2: Go to print left Node=> L
    preOrderTraversal(root->left);

    // Step3: Go to print Right Node=> R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    // Base case
    if (root == NULL)
        return;

    // Step1: Go to print left Node=> L
    inOrderTraversal(root->left);

    // Step2: Print Current Node=> N
    cout << root->data << " ";

    // Step3: Go to print Right Node=> R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // Base case
    if (root == NULL)
        return;

    // Step1: Go to print left Node=> L
    postOrderTraversal(root->left);

    // Step2: Go to print Right Node=> R
    postOrderTraversal(root->right);

    // Step3: Print Current Node=> N
    cout << root->data << " ";
}

void levelOrder(Node *root){
    queue<Node *> q;
    vector<int> ans;
    q.push(root);
    q.push(NULL);
    cout << endl;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

void getLeftBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    ans.push_back(root->data);
    if (root->left != NULL)
    {
        getLeftBoundary(root->left, ans);
    }
    else
    {
        getLeftBoundary(root->right, ans);
    }
}

void getLeafBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }

    getLeafBoundary(root->left, ans);
    getLeafBoundary(root->right, ans);
}

void getRightBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right != NULL)
    {
        getRightBoundary(root->right, ans);
    }
    else
    {
        getRightBoundary(root->left, ans);
    }

    ans.push_back(root->data);
}

void boundaryTraversal(Node *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        for (auto ele : ans)
        {
            cout << ele << " ";
        }
        return;
    }

    if (root->left != NULL)
    {
        getLeftBoundary(root->left, ans);
    }

    getLeafBoundary(root, ans);

    if (root->right != NULL)
    {
        getRightBoundary(root->right, ans);
    }

    for (auto ele : ans)
    {
        cout << ele << " ";
    }
}

int main()
{
    Node *root = createTree();

    cout << "Pre Order: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Inorder: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post Order: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "level Order BFS: ";
    levelOrder(root);
    cout << endl;

    cout << "Boundary Traversal: ";
    boundaryTraversal(root);
    cout << endl;
}