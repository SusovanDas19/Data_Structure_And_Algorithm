#include <iostream>
using namespace std;

class Kqueue
{
public:
    int n, k, freeSpotIndex;
    int *arr, *next, *rear, *front;
    // n = size of the array,  k = number of queue implementing on n size array
    // freeSpotIndex = current free index in n size array

    Kqueue(int _n, int _k) : n(_n), k(_k), freeSpotIndex(0)
    {
        arr = new int[n];
        next = new int[n];
        rear = new int[k];
        front = new int[k];

        // assign -1 to  front and rear of all k number of queue
        for (int i = 0; i < k; i++)
        {
            rear[i] = front[i] = -1;
        }

        // assign next spot of each index in n size array
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1; // assigning last index of array to -1 as next element of last index is nothing
    }

    bool push(int ele, int k)
    { // ele = element tobe push, k = number of queue

        // overflow
        if (freeSpotIndex == -1)
        {
            return false; // no free spot , array is full
        }

        int index = freeSpotIndex;   // curr free spot index;
        freeSpotIndex = next[index]; // assigning next free spot of index

        if (front[k] == -1)
        { // kth number of queue is empty
            front[k] = index;
        }
        else
        {
            next[rear[k]] = index; // assigning next of last element (rear) of kth queue to the current index where ele will be push
        }

        next[index] = -1; // current index where ele will push , the next of this index is nothing now

        /// updating rear of kth queue
        rear[k] = index;
        arr[index] = ele;
        cout<<"Pushed: "<<ele<<" isTrue: ";
        return true;
    }

    int pop(int k)
    {
        // underflow check

        if (front[k] == -1)
        {
            return -1; // no element in kth queue
        }

        int index = front[k]; // index to pop , menas poping fist element of kth queue

        front[k] = next[index]; // updating front of kth queue, by assinging next element of curr front element

        next[index] = freeSpotIndex; // assinging curr free spot index to the next of popoing element's index

        freeSpotIndex = index; // curr popoing element index is now new free spot
        
        cout<<"POP: ";
        return arr[index];
    }

    ~Kqueue()
    {
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] rear;
    }
};

int main()
{

    Kqueue q(8,3);   //in 8 size array, 3 queue 
    
    cout<<q.push(1,0)<<endl; //push 1 in 0th queue
    cout<<q.push(2,0)<<endl;
    cout<<q.push(3,0)<<endl;
    cout<<q.push(5,1)<<endl;
    cout<<q.push(6,1)<<endl;
    cout<<q.pop(0)<<endl; //pop fron 0th queue;
    cout<<q.pop(0)<<endl; 
    cout<<q.pop(1)<<endl; 
    cout<<q.pop(1)<<endl; 
    cout<<q.pop(2)<<endl; 


    return 0;
}
