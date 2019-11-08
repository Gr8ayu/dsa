#include "LinkedList.h"

// void insert(Node* ,int , int );
// void remove(Node* ,int );
// void display(Node*);

Node* insertLL(Node* ll, int position, int value ){

	if(position == -1){
		position = 100000;
	}

	Node* head = ll;
	Node* temp = (Node*) malloc(sizeof(Node));
	temp->data = value;
	temp->next = NULL;

	if(ll == NULL){
		return temp;
	}

	else if(position == 0){
		temp->next = ll;
		return temp;
	}

	for (int i = 1; i<position ; i++ ){
	    if(head->next == NULL){break;}
	    head = head->next;
	}

	temp->next = head->next;
	head->next = temp;
	return ll;

}


Node* removeLL(Node* LL, int position ){
	Node* head = LL;
	Node* temp; // = (Node*) malloc(sizeof(Node));
	// temp->data = value;
	// temp->next = NULL;

	if(LL == NULL){
		return LL;
	}

	else if(position == 0){
		temp = LL->next;
		free(LL);
		return temp;
	}

	for (int i = 1; head->next != NULL && i<position ; ++i, head = head->next);

	if(head->next == NULL){
		printf("\nInvalid Index");
		return LL;
	}

	temp = head->next;
	head->next = temp->next;
	free(temp);
	return LL;

}

int getVal(Node* LL, int position ){
	Node* head = LL;

	if(LL == NULL){
		return -1;
	}

	else if(position == 0){
		return LL->data;
	}

	for (int i = 1; head->next != NULL && i<=position ; ++i, head = head->next);

	if(head->next == NULL){
		printf("\nInvalid Index");
		return -1;
	}

	
	return head->data;

}

void updateVal(Node* LL, int position, int value ){
	Node* head = LL;

	if(LL == NULL){
		return ;
	}

	else if(position == 0){
		 LL->data = value;
	}

	for (int i = 1; head->next != NULL && i<=position ; ++i, head = head->next);

	if(head->next == NULL){
		printf("\nInvalid Index");
		return ;
	}

	
	 head->data = value;

}


void display(Node* LL ){
	// Node* head = LL;

	if(LL == NULL){
		printf("\nEmpty LinkedList");
		return;
	}

	printf("\n| ");
	for (;LL != NULL ; LL = LL->next){
		printf("%d |-->| ",LL->data);

	}
	printf("%s |\n ","NULL");
	

}

