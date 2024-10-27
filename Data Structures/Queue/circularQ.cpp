#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int size)
    {
        this->arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    void push(int data)
    {
        if (front == -1 && rear == -1)
        {
            front++, rear++;
            arr[rear] = data;
            cout << "Queue was empty, first ele inserted" << endl;
            return;
        }
        else if (rear == size - 1 && front == 0 || rear==front-1)
        {
            cout << "Overflow,Queue is full" << endl;
            return;
        }
        else if(rear == size-1 && front != 0){
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

    void pop()
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
            cout<<"One ele present, deleted"<<endl;
            return;
        }
        else if(front == size-1)
        {
            arr[front] = -1;
            front = 0;
            cout<<"Element Deleted"<<endl;
            return;
        }
        else{
            arr[front] = -1;
            front++;
            cout<<"Element Deleted"<<endl;
            return;
        }
    }

    void print()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            int temp = front;
            while (temp != rear)
            {
                if (temp == size - 1)
                {
                    temp = 0;
                }
                cout << arr[temp] << "__";
                temp++;
            }
            cout << arr[temp] << endl;
        }
    }

    ~Queue()
    {
        delete[] arr;
    }
};
int main()
{
    Queue q(3);
    q.push(10);
    q.push(20);
    q.push(30);

    q.print();

    return 0;
}