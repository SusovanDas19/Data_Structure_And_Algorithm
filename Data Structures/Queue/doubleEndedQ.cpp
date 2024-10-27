#include <iostream>
#include <deque> //STL to use double ended queue
using namespace std;

class Deque
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    Deque(int size)
    {
        this->arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushFront(int data)
    {
        if (front == 0 && rear == size - 1 || rear == front - 1)
        {
            cout << "Overflow, queue is full" << endl;
            return;
        }
        else if (front == -1, rear == -1)
        {
            front = rear = 0;
            arr[front] = data;
            cout << data << "Inserted" << endl;
        }
        else
        {
            if (front == 0 && rear != size - 1)
            { // If the front is at the beginning, wrap around
                front = size - 1;
            }
            else
            {
                front--;
            }
            arr[front] = data;
            cout << data << "Inserted" << endl;
        }
    }

    void pushBack(int data)
    {
        if (front == -1 && rear == -1)
        {
            front++, rear++;
            arr[rear] = data;
            cout << "Queue was empty, first ele inserted" << endl;
            return;
        }
        else if (rear == size - 1 && front == 0 || rear == front - 1)
        {
            cout << "Overflow,Queue is full" << endl;
            return;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
            cout << data << " inserted" << endl;
            return;
        }
        else
        {
            rear++;
            arr[rear] = data;
            cout << data << " inserted" << endl;
            return;
        }
    }

    void popFront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow, queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
            cout << "One ele present, deleted" << endl;
            return;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
            cout << "Element Deleted" << endl;
            return;
        }
        else
        {
            arr[front] = -1;
            front++;
            cout << "Element Deleted" << endl;
            return;
        }
    }

    void popBack()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow, queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[rear] = -1;
            front = rear = -1;
            cout << "Poped" << endl;
        }
        else if(rear == 0)
        {
            arr[rear] = -1;
            rear = size-1;
            cout << "Poped" << endl;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }

    ~Deque()
    {
        delete[] arr;
    }
};
int main()
{
    // Using Standard Template Library
    //  deque<int> dq;
    //  dq.push_back(10);
    //  dq.push_back(20);
    //  dq.push_front(200);
    //  dq.push_front(100);

    // dq.pop_back();
    // dq.pop_front();
    // cout<<"Front ele: "<<dq.front()<<endl;
    // cout<<"Back ele: "<<dq.back()<<endl;

    // Implementation
    Deque q(3);
    q.pushBack(20);
    q.pushBack(87);

    q.pushFront(74);
    q.pushFront(4);

    q.popBack();
    q.popFront();

    return 0;
}