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
Node* delete(Node* head,int numDelete) {
    if (head==NULL || numDelete==0) {
        return head;
    }
    if (head->data==numDelete) {
        Node* temp=head;
        head=head->next;
        free(temp);
    }
    Node* current=head;
    while (current->next!=NULL) {
        if (current->next->data==numDelete) {
            Node* temp=current->next;
            current->next=current->next->next;
            free(temp);
        }else {
            current=current->next;
        }
    }
    return head;
}
int main(void) {
    Node* head=createNode(5);
    Node* Node1=createNode(4);
    Node* Node2=createNode(3);
    Node* Node3=createNode(5);
    Node* Node4=createNode(2);
    Node* Node5=createNode(1);
    Node* Node6=createNode(5);
    head->next=Node1;
    Node1->next=Node2;
    Node2->next=Node3;
    Node3->next=Node4;
    Node4->next=Node5;
    Node5->next=Node6;
    int numDelete;
    printf("Nhap so can xoa: ");
    scanf("%d",&numDelete);
    head=delete(head,numDelete);
    printList(head);
    return 0;
}