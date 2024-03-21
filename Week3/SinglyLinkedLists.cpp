// "I pledge my honor that I have abided by the Stevens Honor System" - Justin Ferber

#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* addToEmpty(struct node *head, int data) {
    head = new node();
    head -> data = data;
    head -> next = NULL;
    return head;
};

struct node* addAtEnd(struct node* head, int data) {
    struct node *current = head;
    struct node *nextNode = new node();
    nextNode -> data = data;
    nextNode -> next = NULL;
    while (current -> next != NULL) {
        current = current -> next;
    };
    current -> next = nextNode;
    return head;
};

struct node* addToStart(struct node* head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> next = head;
    newNode -> data = data;
    return newNode;
};

struct node* addAnyPosition(struct node* head, int data, int index) {
    int i = 0;
    struct node *prev = new node();
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *current = head;
    newNode -> data = data;
    if (!index) {
        newNode -> next = head;
        return newNode;
    }
    while (i != index) {
        prev = current;
        current = current -> next;
        i++;
    };
    prev -> next = newNode;
    newNode -> next = current;
    return head;
}

void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << ' ';
        temp = temp -> next;
    };
};

int main() {
    struct node *head = NULL;
    int value, index;
    cout << "Enter an integer value to be added to the empty list: ";
    cin >> value;
    head = addToEmpty(head, value);
    cout << "Enter an integer value to be added to the list: ";
    cin >> value;
    head = addAtEnd(head, value);
    cout << "Enter an integer value to be added to the list: ";
    cin >> value;
    head = addAtEnd(head, value);
    cout << "Enter an integer value to be added to the start of the list: ";
    cin >> value;
    head = addToStart(head, value);
    cout << "Enter an integer value to be added";
    cin >> value;
    cout << "Enter a position to put your last entered number in: ";
    cin >> index;
    head = addAnyPosition(head, value, index);
    cout << "The elements of the list are: ";
    print(head);
    return 0;
};