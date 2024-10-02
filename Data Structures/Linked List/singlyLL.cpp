#include <iostream>
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
        cout << "\nElement of linked List: " << endl;
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

void insertAtTail(Node *&head, Node *&tail, int data){
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cout << "No node present, so 1st node created" << endl;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        cout << "New node inseted at tail" <<" data: "<<data<< endl;
    }
}

void insertAtPos(Node *&head, Node *&tail, int data, int pos){
    int length = lengthLL(head);
    if (head == NULL)
    {
        cout << "There is no node, create first" << endl;
        return;
    }
    else if (pos < 1 || pos > length + 1)
    {
        cout << "Give a valid position" << endl;
        return;
    }
    else if (pos == length + 1)
    {
        insertAtTail(head, tail, data);
        return;
    }
    else if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        Node *prev = head;
        while (pos != 2)
        {
            prev = prev->next;
            pos--;
        }
        newNode->next = prev->next;
        prev->next = newNode;
        cout << "New node inseted at position" <<" data: "<<data<< endl;
    }
}

void deleteAtHead(Node *&head, Node *&tail){
    Node *temp = head;
    if (head == NULL)
    {
        cout << "There is no node"<<endl;
    }
    else if (head == tail)
    {
        delete (temp);
        head = tail = NULL;
        cout << "Head node deleted [one node was present]"<<endl;
        return;
    }
    else
    {
        head = head->next;
        delete (temp);
        cout << "Head node deleted" << endl;
    }
}

void deleteAtTail(Node *&head, Node *&tail){
    Node *temp = head;
    if (head == NULL)
    {
        cout << "There is no node" << endl;
    }
    else if (head == tail)
    {
        delete (temp);
        head = tail = NULL;
        cout << "Tail node deleted [one node was present]";
        return;
    }
    else
    {
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        temp = tail->next;
        tail->next = NULL;
        delete (temp);
        cout << "Tail node deleted" << endl;
    }
}

void deleteAtPosition(Node *&head, Node *&tail, int position){
    int length = lengthLL(head);

    if (head == NULL)
    {
        cout << "There is no node" << endl;
    }
    else if (position < 1 || position > length)
    {
        cout << "Please give a valid position" << endl;
        return;
    }
    else if (position == 1)
    {
        deleteAtHead(head, tail);
        return;
    }
    else if(position == length){
        deleteAtTail(head,tail);
        return;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete(curr);
        cout<<"Node deleted at given position"<<endl;

    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 70);
    insertAtTail(head, tail, 700);
    insertAtPos(head, tail, 50, 2);
    printLL(head);
    deleteAtTail(head, tail);
    printLL(head);
    insertAtTail(head,tail,89);
    printLL(head);
    return 0;
}