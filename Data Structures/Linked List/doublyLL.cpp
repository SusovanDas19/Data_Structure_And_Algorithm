#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "\nDistructor called for: " << this->data << endl;
    };
};

void printLL(Node *&head)
{
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
            cout << temp->data << "<-->";
            temp = temp->next;
        }
    }
    cout << "NULL" << endl;
}

int lengthLL(Node *&head)
{
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
        cout << "There is no node, so 1st node created" << " data: " << data << endl;
        return;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "New node inseted at head" << " data: " << data << endl;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cout << "There is no node, so 1st node created" << " data: " << data << endl;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        cout << "New node inseted at tail" << " data: " << data << endl;
    }
}

void insertAtPos(Node *&head, Node *&tail, int data, int pos)
{
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
        Node *temp = head;
        while (pos != 2)
        {
            temp = temp->next;
            pos--;
        }
        Node *temp2 = temp->next;
        newNode->next = temp2;
        temp2->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        cout << "New node inseted at position" << " data: " << data << endl;
    }
}

void deleteAtHead(Node *&head, Node *&tail)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "There is no node" << endl;
    }
    else if (head == tail)
    {
        delete (temp);
        head = tail = NULL;
        cout << "Head node deleted [one node was present]" << endl;
        return;
    }
    else
    {
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete (temp);
        cout << "Head node deleted" << endl;
    }
}

void deleteAtTail(Node *&head, Node *&tail)
{
    Node *temp = tail;
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
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete (temp);
        cout << "Tail node deleted" << endl;
    }
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
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
    else if (position == length)
    {
        deleteAtTail(head, tail);
        return;
    }
    else
    {
        Node *temp = head;
        while (position != 2)
        {
            temp = temp->next;
            position--;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = NULL;
        temp2->prev = NULL;
        Node *temp3 = temp->next;
        temp3->prev = temp;
        delete (temp2);

        cout << "Node deleted at given position" << endl;
    }
}

void backPrintLL(Node* &head, Node* &tail){
    Node* temp = tail;
    cout<<endl<<endl;
    while(temp != head){
        cout<<temp->data<<" --> ";
        temp = temp->prev;
    }
    cout<<temp->data;
    return;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    printLL(head);
    deleteAtPosition(head, tail, 3);
    printLL(head);
    insertAtHead(head, tail, 7562);
    printLL(head);
    backPrintLL(head,tail);
    return 0;
}