#include <stdio.h>
#include <stdlib.h>

struct List{
    int data;
    struct List* next;
};
struct List* head=NULL;//this line creates head node of a list, the variable could be given any name,decided to use "head".

//createNode takes in as parameter the head node of a given list then creates a new node and appends it to the end of that list.
struct List* createNode(struct List** hx){
    struct List* newNode=(struct List*)malloc(sizeof(struct List));
    int dTemp;
    printf("Enter data for this node :");
    scanf("%d",&dTemp);
    newNode->data=dTemp;
    if(*hx==NULL){
        newNode->next=*hx;
        *hx=newNode;
    }
    else{
        struct List* temp=*hx;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return newNode;
}
//createNode2 takes in as parameter the head node of a given list and a position then creates a new node and inserts it at the given position.
struct List* createNode2(struct List** hx,int pos){
    struct List* newNode=(struct List*)malloc(sizeof(struct List));
    int dTemp;
    printf("Enter data for this node :");
    scanf("%d",&dTemp);
    newNode->data=dTemp;
    if(pos<2){
        newNode->next=*hx;
        *hx=newNode;
    }
    else{
        struct List* temp=*hx;
        struct List* temp0;
        for(int i=0;i<pos-2;i++){
            temp=temp->next;
        }
        temp0=temp->next;
        temp->next=newNode;
        newNode->next=temp0;
    }
    return newNode;
};
//displayList displays all items in the list, takes in as parameter the head node of the list to be displayed.
void displayList(struct List* hx){
    if(hx==NULL){
        printf("List is empty!\n");
        return;
    }
    struct List* temp1=hx;
    printf("List is :");
    while(temp1!=NULL){
      printf("%d\t", (temp1->data));
      temp1=temp1->next;
    }
    printf("\n");
}
//deleteNode function deletes a node at a given position. Takes in as parameters the position and the head node of the list where deletion is to be carried out
void deleteNode(int pos,struct List** hx){
    if(*hx==NULL){
        printf("Can't delete! List is empty.\n");
        return;
    }
    struct List* temp2=*hx;
    struct List* temp3;
    if(pos<2){
        *hx=temp2->next;
        temp2->next=NULL;
        free(temp2);
        return;
    }
    else{
        for(int i=0;i<pos-2;i++){
        temp2=temp2->next;
        }
        temp3=temp2->next;
        temp2->next=temp3->next;
        temp3->next=NULL;
        free(temp3);
        return;
    }
}

int main(){
    int num;
    printf("How many nodes do you want?");
    scanf("%d",&num);
    displayList(head);
    deleteNode(2,&head);
    for(int i=0;i<num;i++){
        createNode(&head);
    }
    displayList(head);
    createNode2(&head,1);
    //deleteNode(1,&head);
    displayList(head);
    return 0;
}
