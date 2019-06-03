#include <iostream>
#include <stdio.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* p = head;
    while (p) {
        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
}

void removeLastKth(Node** head, int k)
{
    Node** p = head;
    Node** q = NULL;
    Node** bq = NULL;
    int count = 0;
    while (*p) {
        count++;
        *p = *p->next;
        if (k+1 == count) {
            bq = head;
        } else if (k == count) {
            q = *head;
        }
        if (q) {
            q = q->next;
        }
        if (bq) {
            bq = bq->next;
        }
        cout << "count:" << count;
        if (bq) {
            cout << ", bq:" << bq->data;
        } else {
            cout << ", bq:0";
        }
        if (q) {
            cout << ", q:" << q->data;
        } else {
            cout << ", q:0";
        }
        cout << endl;
    }
    cout << "haha, k:" << k
            << ", bq:" << bq->data
            << ", q:" << q->data << endl;
    if (q) {
        if (q == *head) {
            *head = q->next;
        } else {
            bq->next = q->next;
        }
        free(q);
    }
}

Node* newNode(int data, Node* next) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

int main(int argc, char** argv)
{
    Node* head = newNode(1,
                newNode(2,
                newNode(3,
                newNode(4,
                newNode(5,
                newNode(6, NULL))))));
    printList(head);
    removeLastKth(&head, atoi(argv[1]));
    printList(head);
    return 0;
}
