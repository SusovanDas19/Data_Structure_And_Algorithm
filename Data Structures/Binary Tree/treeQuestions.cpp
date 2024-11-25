#include <iostream>
#include <queue>
#include<map>

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
    int val;
    cin >> val;

    if (val == -1)
    { // BASE CASE
        return NULL;
    }

    // Step1: Create a newnode
    Node *root = new Node(val);

    // Step2: Create left subtree of the root
    root->left = createTree();

    // Step3: Create right subtree of the root
    root->right = createTree();

    // Step4: return the root node
    return root;
}

void levelOrder(Node *root)
{
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

void leftView(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
    return;
}
void rightView(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    rightView(root->right, level + 1, ans);
    rightView(root->left, level + 1, ans);
    return;
}

vector<int> topView(Node* root)
{
    map<int,int> mp;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int lv = temp.second;

        if(mp.find(lv) == mp.end()){ //for lv no entry in map
            mp[lv] = frontNode->data;
        }

        //push left and right child of the front node
        if(frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left,lv-1));
        }

        if(frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, lv+1));
        }
    }

    vector<int> ans;
    for(auto i: mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomView(Node* root)
{
    map<int,int> mp;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int lv = temp.second;

        //overwriting node so that at last the bottom most node of 
        //each level will be pushed in the map;
        mp[lv] = frontNode->data;

        //push left and right child of the front node
        if(frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left,lv-1));
        }

        if(frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, lv+1));
        }
    }

    vector<int> ans;
    for(auto i: mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}


int main()
{
    cout << "Enter the value of the node: ";
    Node *root = createTree();
    cout<<"Tree: "<<endl;
    levelOrder(root);
    cout<<endl;
    // cout<<"Left view: "<<endl;
    // vector<int> ans1;
    // leftView(root,0,ans1);
    // for(auto ele:ans1){
    //     cout<<ele<<" ";
    // }

    // cout<<endl;

    // vector<int> ans2;
    // cout<<"Right view: "<<endl;
    // rightView(root,0,ans2);
    // for(auto ele:ans2){
    //     cout<<ele<<" ";
    // }

    cout<<endl;

    
    cout<<"Top view: "<<endl;
    vector<int> ans3 = topView(root);
    for(auto ele:ans3){
        cout<<ele<<" ";
    }

    cout<<endl;

    
    cout<<"Bottom View: "<<endl;
    vector<int> ans4 = bottomView(root);
    for(auto ele:ans4){
        cout<<ele<<" ";
    }
}