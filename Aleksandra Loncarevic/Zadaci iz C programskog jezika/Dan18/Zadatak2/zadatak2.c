#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next, *previous;
}Node;

typedef struct dll{
    Node *first, *last;
}DLL;

DLL addElementsInTheList(DLL head, int val);
void writeList(DLL head);
DLL addNewElements(DLL head);

int main() {
    int n;
    printf("Unesite broj elemenata liste: ");
    scanf("%i", &n);
    DLL head = {NULL, NULL};
    for(int i=0; i<n; i++){
        int t = rand()%10;
        head = addElementsInTheList(head, t);
    }
    writeList(head);
    printf("\n");
    head = addNewElements(head);
    writeList(head);

}

DLL addElementsInTheList(DLL head, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    if(head.first == NULL) {
        head.first = newNode;
        head.last = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    if(newNode->value <= head.first->value) {
        Node *temp1 = head.first;
        newNode->next = temp1;
        temp1->previous = newNode;
        newNode->previous = NULL;
        head.first = newNode;
    }else if(newNode->value >= head.last->value) {
        Node *temp2 = head.last;
        newNode->previous = temp2;
        temp2->next = newNode;
        newNode->next = NULL;
        head.last = newNode;
    }else {
        Node *temp = head.first;
        while(temp->value < val) {
            temp = temp->next;
        }
        Node *prev = temp->previous;
        newNode->next = temp;
        temp->previous = newNode;
        newNode->previous = prev;
        prev->next = newNode;
    }
    return head;
}

void writeList(DLL head) {
    Node *temp;
    for(temp=head.first; temp; temp=temp->next) {
        printf("%i ", temp->value);
    }
}

int differenceBetweenTwoElements(Node *n1, Node *n2) {
    return n2->value - n1->value;
}

DLL addNewElements(DLL head) {
    Node *temp = head.first;
    while(temp!=head.last) {
        int n = differenceBetweenTwoElements(temp, temp->next);
        if(n>1){
            int t = temp->value;
            for(int i=0; i<n-1; i++) {
                head = addElementsInTheList(head, ++t);
            }
        }
        temp = temp->next;
    }
    return head;
}

