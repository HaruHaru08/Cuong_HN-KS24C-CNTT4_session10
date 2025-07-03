#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int date) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=date;
    newNode->next=NULL;
    return newNode;
}
int length(Node* head) {
    int count=0;
    while (head!=NULL) {
        count++;
        head=head->next;
    }
    return count;
}
void printList(Node* head) {
    while (head!=NULL) {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
Node* insertEnd(Node* head,int num) {
    Node* newNode=createNode(num);
    if (head==NULL) {
        return newNode;
    }
    while (head->next!=NULL) {
        head=head->next;
    }
    head->next=newNode;
    return head;
}
int main(void) {
    Node* head=createNode(10);
    Node* Node1=createNode(20);
    Node* Node2=createNode(30);
    Node* Node3=createNode(40);
    Node* Node4=createNode(50);
    head->next=Node1;
    Node1->next=Node2;
    Node2->next=Node3;
    Node3->next=Node4;
    insertEnd(head,60);
    printList(head);
    return 0;
}