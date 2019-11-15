#indef Queue_h
#define Queue_h
#include <stdlib.h>
//Header file for queue data structure. Provides enqueue and dequeue functions for a queue.

struct Node{
	int data;
	struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x){
	struct Node *t;
	t = (struct Node*)malloc(sizeof(struct Node));
	
	if(t == NULL)
		printf("Queue is FULL\n");
	else{
		t -> data = x;
		t -> next = NULL;

		if(front == NULL)
			front = rear = t;
		else{
			rear -> next = t;
			rear = t;
		}
	}
}

void dequeue(){
	int x = -1;
	struct Node* t;

	if(front == NULL)
		printf("Queue is Empty\n");
	else{
		x = front -> data;
		t = front;
		front = front -> next;
		free(t);
	}
	return x;
	
}

int isEmpty(){
	return front == NULL;
}

#endif