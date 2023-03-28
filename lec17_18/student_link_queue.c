#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentStruct{
    int UIN;
    char *netid; // dynamic mem alloc for string
    float GPA;
    struct StudentStruct *next;
}node;

void printStudents(node *headptr);
void delete_all(node **headptr);

void enqueue(node **headpptr, node *data);
void dequeue(node **headpptr);

int main(){

    node *headptr = NULL;

    node temp;
    temp.UIN = 1234;
    // reserve heap mem (withou actual contents)
    temp.netid = (char*) malloc(sizeof("moon") + 1); //+1 for null character
    strcpy(temp.netid, "moon");
    temp.GPA = 3.0;
    temp.next = NULL;
    //insert_head(&headptr, &temp);
    //insert_sorted_GPA(&headptr, &temp);
	enqueue(&headptr, &temp);
	   
    // second node
    temp.UIN = 2323;
    // reserve heap mem (withou actual contents)
    temp.netid = (char*) malloc(sizeof("AAA") + 1); //+1 for null character
    strcpy(temp.netid, "AAA");
    temp.GPA = 4.0;
    temp.next = NULL;
    //insert_head(&headptr, &temp);
    //insert_sorted_GPA(&headptr, &temp);
    enqueue(&headptr, &temp);

    // third node
    temp.UIN = 5555;
    // reserve heap mem (withou actual contents)
    temp.netid = (char*) malloc(sizeof("BBB") + 1); //+1 for null character
    strcpy(temp.netid, "BBB");
    temp.GPA = 2.0;
    temp.next = NULL;
    //insert_head(&headptr, &temp);
    //insert_sorted_GPA(&headptr, &temp);
	enqueue(&headptr, &temp);

    printStudents(headptr);
	
	dequeue(&headptr);
	
	printStudents(headptr);

    delete_all(&headptr);

}

void printStudents(node *cursor){
    printf("UIN netid GPA\n");
    while(cursor){
        printf("%d %s %f\n", cursor->UIN, cursor->netid, cursor->GPA);
        cursor = cursor->next;
    }
}
void delete_all(node **headpptr){
    node *next;
    while(*headpptr != NULL){
        free((*headpptr)->netid);
        next = (*headpptr)->next;
        free(*headpptr);
        *headpptr = next;
    }
}

void enqueue(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    temp->next = NULL;

    while(*headpptr != NULL)
        headpptr = &((*headpptr)->next);

    *headpptr = temp;
}
void dequeue(node **headpptr){
    node *next;

    if(*headpptr == NULL){
        printf("Queue is empty.\n");
        return;
    }

    next = (*headpptr)->next;
    free((*headpptr)->netid);
    free(*headpptr);
    *headpptr = next;
}



