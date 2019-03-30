#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUTFILE "accountHistory.txt" 
#define OUTPUTFILE "accountHistory.txt" 


struct node {
char name[50];
char amount[12];
struct node *next;
}*head;

int main(void) {

	struct node *temp, *last;
	temp = malloc(sizeof(struct node));
	last = malloc(sizeof(struct node));
	head = temp;

	FILE *ifp;
	char buffer[1024];
	memset(buffer, 0, 1024);

	if ((ifp = fopen(INPUTFILE, "r")) == NULL){
		printf("\nError with the input file: %s", INPUTFILE);
		puts("\nPress enter to continue...");
		getchar();
		return 1;
	}

	if (fgets(buffer, 1024, ifp)==NULL) {
		fclose(ifp);
		printf("\nThe input file is empty: %s", INPUTFILE);
		puts("\nPress enter to continue...");
		getchar();
		return 1;
	}

	strcpy(temp->name, buffer);
	strcpy(temp->name, strtok(buffer, ";"));
	strcpy(temp->amount, strtok(NULL, ";"));
	temp->next = NULL;


	while (fgets(buffer, 1024, ifp)) {
		temp->next = malloc(sizeof(struct node));
		temp = temp->next;
		strcpy(temp->name, buffer);
		strcpy(temp->name, strtok(buffer, ";"));
		strcpy(temp->amount, strtok(NULL, ";"));
		temp->next = NULL;
		last = temp;
	}

	struct node * newNode = malloc(sizeof(struct node));
	newNode->next = NULL;
	strcpy(newNode->name, "Alex Cottow");
	strcpy(newNode->amount, "555");
	last -> next = newNode;

	fclose(ifp);



	printf("\nSCANNING THE LIST\n");
	temp = head;
	int i = 0;
	while (temp != NULL) {
		i ++ ;
		printf("#%d, Name:%s, Amount:%s", i, temp->name, temp->amount);
		//	total += n->balance;
		temp = temp->next;
	}


	printf("\n");
	getchar();
	return 0;
}