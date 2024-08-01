#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

 struct Node {
  int data;
  struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

bool isEmpty(){
   return front == NULL && rear == NULL;
}

void enqueue(int x){
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));
  node->data = x;
  node->next = NULL;

  if(isEmpty()) {
    front = node;
    rear = node;
  }
  else {
    //normally
    rear->next = node;
    rear = node;
  }
}

void dequeue(){
  if(isEmpty()) {
    printf("Queue is empty\n");
  }
  else {
    struct  Node * temp = front;
    front = front->next;
    free(temp);
  }
}

void display(){
  if(isEmpty()){
    printf("Queue is empty\n");
    return;
  }
  struct  Node * temp = front;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(void) {
   enqueue(2);
   enqueue(4);
   display();
   dequeue();
   display();
   enqueue(4);
   enqueue(5);
   enqueue(25);
   enqueue(15);
   enqueue(35);
   enqueue(45);
   display();
   dequeue();
   dequeue();
   display();
  return 0;
}