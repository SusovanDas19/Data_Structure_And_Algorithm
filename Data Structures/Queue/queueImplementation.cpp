#include<iostream>
#include<queue>
using namespace std;


class Queue{
public:
    int* arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        this->arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }


    void enQueue(int data)
    {
        if(rear == size-1)
        {
            cout<<"OverFlow, Queue is full"<<endl;
            return;
        }
        else if(front == -1 && rear == -1)
        {
            front++ , rear++;
            arr[rear] = data;
            cout<<data<<" inserted into queue"<<endl;
        }
        else{
            rear++;
            arr[rear] = data;
            cout<<data<<" inserted into queue"<<endl;
        }

    }

    void deQueue()
    {
        if(front == -1)
        {
            cout<<"Underflow, Queue is empty"<<endl;
            return;
        }
        else if(front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
            cout<<"One element present, Dequeue done"<<endl;
        }
        else{
            arr[front] = -1;
            front++;
            cout<<"Dequeue done"<<endl;
        }
    }

    void isEmpty()
    {
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue is not empty"<<endl;
        }
    }

    void isFull()
    {
        if(rear == size-1){
            cout<<"Queue is full"<<endl;
        }
        else{
            cout<<"Queue is not full"<<endl;
        }
    }
    void getFront()
    {
        if(front == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Front element of queue is: "<<arr[front]<<endl;
        }
    }
    void getRear()
    {
        if(rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Rear element of queue is: "<<arr[rear]<<endl;
        }
    }
    void print(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue is: "<<endl;
            int temp = front;
            while(temp != rear){
                cout<<arr[temp]<<"__";
                temp++;
            }
            cout<<arr[temp]<<endl;
        }
    }

    ~Queue()
    {
        delete[] arr;
    }
};
int main()
{   //Usng STL
    // queue<int> q; //Creation

    // q.push(10); //Insertion
    // q.push(20);
    // q.push(30);

    // q.pop(); //deletion


    // cout<<"Is queue empty: "<<q.empty()<<endl;
    // cout<<"Queue size: "<<q.size()<<endl;
    // cout<<"Front element of Queue is: "<<q.front()<<endl; //Front/Head
    // cout<<"Last element of Queue is: "<<q.back()<<endl; //Rear/back/Tail

    //Implementation
    Queue q(3);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
  

    q.print();
    
    q.getFront();
    q.getRear();
    q.isEmpty();

    return 0;
}