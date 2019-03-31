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


void addEntry(struct node * head, char* name, char* amount){
	struct node * current = head; 

	while (current->next != NULL){
		current = current->next;
	}

	struct node * newNode = malloc(sizeof(struct node));

	current->next = newNode;
	newNode->next = NULL;
	strcpy(newNode->name, name);
	strcpy(newNode->amount, amount);


}

int loadList(struct node *temp)
{
	FILE *ifp;
	char buffer[1024];
	memset(buffer, 0, 1024);

	if ((ifp = fopen(INPUTFILE, "r")) == NULL) {
		printf("\nError with the input file: %s", INPUTFILE);
		puts("\nPress enter to continue...");
		getchar();
		return 1;
	}

	if (fgets(buffer, 1024, ifp) == NULL) {
		fclose(ifp);
		printf("\nThe input file is empty: %s", INPUTFILE);
		puts(".\nPress enter to continue...");
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
	}

fclose(ifp);

return 0;
}


void saveList(struct node *head ){
	FILE *ifp;
	struct node *current;
	current = malloc(sizeof(struct node));
	current = head;

	if((ifp = fopen(OUTPUTFILE, "w")) == NULL){
		printf("Error with outputfile \n" );
	} else {
		while(current != NULL){

			char outputstr[50];
			strcpy(outputstr, "");

			strcpy(outputstr,current->name);
			strcpy(outputstr, ";");
			
			strcpy(outputstr, current->amount);
			printf("%s",current->name);
		    fputs(outputstr, ifp);

			current = current->next;
		}
		fclose(ifp);
	}
}


int main(void) {

	struct node *temp;
	temp = malloc(sizeof(struct node));
	head = temp;

	if (loadList(head) != 0) {
		printf("\nThe list was not loaded from the input file: %s", INPUTFILE);
		puts(".\nPress enter to continue...");
		getchar();
		return 1;
	}
	addEntry(head, "Alex", "55555");
	
	saveList(head);

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