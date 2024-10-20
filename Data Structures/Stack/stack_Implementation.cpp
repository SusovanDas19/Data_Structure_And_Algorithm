#include <iostream>
// #include<stack> //Include the C++ stl header file to use pre define stack

using namespace std;

class Stack
{

public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int ele)
    {
        if (top + 1 == size)
        {
            cout << "Overflow, stack is full" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = ele;
            cout << ele << " inserted into stack" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow, stack is empty" << endl;
            return;
        }
        else
        {
            arr[top] = -1;
            top--;
            cout << "Top element deleted" << endl;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    int getTop()
    {
        if (top == -1)
            cout << "Underflow , no element present" << endl;
        else
        {
            return arr[top];
        }
    }

    void printStack()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "STACK ele: " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    void getSize()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            cout << "Current size of stack is: " << top + 1 << endl;
        }
    }
};
int main()
{
    // //creation
    // stack<int> st;

    // //Insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);

    // //Size
    // cout<<"Size of the stack is: "<<st.size()<<endl;

    // //Deletion
    // st.pop(); //delete top ele

    // //top ele
    // cout<<"Top of stack: "<< st.top()<<endl;

    // //empty
    // if(st.empty()) cout<<"Stack is empty"<<endl;
    // else cout<<"Stack is not empty"<<endl;

    // Stack implementation
    Stack st(3); // static creation

    st.push(10);
    st.push(20);
    st.push(30);

    st.printStack();
    cout << "TOP: " << st.getTop() << endl;
    cout << "is empty: " << (st.isEmpty() ? "YES" : "NO") << endl;

    st.pop();
    st.pop();

    st.getSize();

    return 0;
}