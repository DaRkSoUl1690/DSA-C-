#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List Node */
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int data);
};

Node ::Node(int data)
{
    prev = NULL;
    this->data = data;
    next = NULL;
}

/* Representation of the stack data structure
that supports findMiddle() in O(1) time.
The Stack is implemented using Doubly Linked List.
It maintains pointer to head node, pointer to
middle node and count of nodes */
class Stack
{
public:
    Node *top;
    Node *mid;
    int count;

    Stack();
    void push(int data);
    int pop();
    int findMiddle();
    int deleteMiddle();
};

/* Function to create the stack data structure */
Stack::Stack()
{
    count = 0;
    top = NULL;
    mid = NULL;
}

/* Function to push an element to the stack */
void Stack ::push(int data)
{
    /* Allocate current Node with data */
    Node *curr = new Node(data);

    /* Adding a node after the top */
    curr->prev = top;

    /* Increment count of items in stack */
    count += 1;

    /* Move top to point to the current Node */
    if (top)
        top->next = curr;
    top = curr;

    /* Change mid pointer in two cases
1) Linked List is empty
2) Number of nodes in linked list is even */
    if (count == 1)
        mid = curr;
    else if (count % 2 == 0)
        mid = mid->next;
}

/* Function to pop an element from stack */
int Stack::pop()
{
    /* Stack underflow */
    if (count == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    // Node *temp = top;
    int data = top->data;
    top = top->prev;

    /* Decrement count of items in stack */
    count--;

    /* Update the mid pointer when odd
elements are left in stack */
    if (count % 2 != 0)
        mid = mid->prev;

   // delete temp;
    delete top->next;

    return data;
}

// Function for finding middle of the stack
int Stack::findMiddle()
{
    if (count == 0)
    {
        cout << "Stack is empty now\n";
        return -1;
    }

    return mid->data;
}

// Function for deleting middle of the stack
int Stack::deleteMiddle()
{
    int data = mid->data;
    Node *temp = mid;

    mid->prev->next = mid->next;
    mid->next->prev = mid->prev;

    /* Decrement count of items in stack */
    count--;

    /* Update the mid pointer when odd
elements are left in stack */
    if (count % 2 != 0)
        mid = mid->prev;
    else
        mid = mid->next;

    delete temp;

    return data;
}

int main()
{
    /* Let us create a stack using push() operation*/
    Stack stk;
    stk.push(11);
    stk.push(22);
    stk.push(33);
    stk.push(44);
    stk.push(55);
    stk.push(66);
    stk.push(77);
    stk.push(88);
    cout << "Item popped is " << stk.pop() << endl;
    cout << "Item popped is " << stk.pop() << endl;
    cout << "Item popped is " << stk.pop() << endl;
    cout << "Item popped is " << stk.pop() << endl;
    cout << "Middle Element is " << stk.findMiddle() << endl;
    cout << "Deleted Middle Element is " << stk.deleteMiddle() << endl;
    cout << "Middle Element is " << stk.findMiddle() << endl;

    return 0;
}