#include <iostream>
// Singly Linked Lists
using namespace std;
void add_node(int n);
void display();

struct node{
    int data;
    int *next;
};

node *head = NULL;

int main()
{
    cout<<"Before any data is entered: ";
    display();
    add_node(1);
    cout<<"After one  data is entered: ";
    display();
    add_node(2);
    cout<<"After two data is entered: ";
    display();
    add_node(7);
    cout<<"After three data is entered: ";
    display();
    return 0;
}

void add_node(int n){
    node *temp = new node;
    node *temp2;
    temp->data = n;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        head->next = NULL;
    }else{
        temp2 = head;
        while(temp2->next != NULL){
            temp2 = temp2->next;
            temp2->next = temp;
        }
    }
}

void display(){
    node *temp;
    temp = head;
     if(temp == NULL){
        cout<<"There is no data \n";
    }else{

    }
    while(temp !=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
    }
}
