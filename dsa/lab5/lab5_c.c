#include <stdio.h>
#include <stdlib.h>


struct RandomListNode {
	int label;
	struct RandomListNode *next;
	struct RandomListNode *random;
};

struct RandomListNode* head;

void push(struct RandomListNode	**head, int data)
{
	struct RandomListNode *temp;
	temp = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
	temp->label = data;
	temp->next = *head;
	if(temp->next!=NULL)
	temp->random= temp->next->next;
	else
	temp->random= temp;

	*head = temp;

	//printf("hii\n" );
}
typedef struct RandomListNode randomlistnode;
randomlistnode* copyRandomList(randomlistnode * head)
{
	//node insertion
	randomlistnode  *current = head;

	while (current != NULL) {
		randomlistnode* temp = (randomlistnode*)(malloc(sizeof(randomlistnode)));

		temp->label = current->label;
		temp->next = current->next;
		current->next = temp;
		current = temp->next;
	}

	//copy random pointer
	current = head;
	while (current != NULL) {
		randomlistnode* temp = current->next;
		if (current->random != NULL)
			temp->random = current->random->next;
		current = temp->next;
	}

	//restoring thr original andcopied linked list
	current = head;
	randomlistnode* copy = head == NULL ? NULL : head->next;
	while (current != NULL) {
		randomlistnode* temp = current->next;
		current->next = temp->next;
		if (temp->next != NULL)
			temp->next = temp->next->next;
		current = current->next;
	}
	return head;
}

int main()
{
	randomlistnode* head2 = NULL;

	for (int i = 5; i >= 1; i--)
		push(&head2, i);
	randomlistnode* head = copyRandomList(head2);
	randomlistnode* current = head;

	while (current!=NULL) {

		printf("%d ", current->label);
		current = current->next;
}
}
