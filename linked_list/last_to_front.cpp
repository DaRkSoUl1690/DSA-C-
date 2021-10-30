#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

void moveFirstNodeToEnd(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    struct Node *secondLastNode = *head;
    struct Node *lastNode = *head;
    while (lastNode->next != NULL)
    {
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }
    secondLastNode->next = NULL;
    lastNode->next = *head;
    *head = lastNode;
}

void addNewNode(struct Node **head, int new_data)
{
    struct Node *newNode = new Node;
    newNode->data = new_data;
    newNode->next = *head;
    *head = newNode;
}

void printLinkedList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    struct Node *head = NULL;
    addNewNode(&head, 1);
    addNewNode(&head, 2);
    addNewNode(&head, 3);
    addNewNode(&head, 4);
    addNewNode(&head, 5);
    addNewNode(&head, 6);
    addNewNode(&head, 7);
    addNewNode(&head, 8);
    addNewNode(&head, 9);
    moveFirstNodeToEnd(&head);
    printLinkedList(head);
    return 0;
}