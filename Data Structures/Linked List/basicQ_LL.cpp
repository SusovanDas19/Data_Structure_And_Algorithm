#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next; // ponter to a node

    Node()
    { // default
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "\nDistructor called for: " << this->data << endl;
    };
};

void printLL(Node *&head){
    Node *temp = head;
    if (head == NULL)
    {
        cout << "\nThere is no node" << endl;
        return;
    }
    else
    {
        // cout << "\nElement of linked List: " << endl;
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
    }
    cout << "NULL" << endl;
}

int lengthLL(Node *&head){
    Node *temp = head;
    int length = 0;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cout << "There is no node, so 1st node created" << endl;
        return;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        cout << "New node insert at head" <<" data: "<<data<< endl;
    }
}

void reverseLL(Node* &head){
    cout<<"\nBefore reverse: ";
    printLL(head);
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev; //new Head
    cout<<"\nAfter reverse: ";
    printLL(head);

}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    reverseLL(head);

    return 0;
}