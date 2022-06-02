#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* newNode(int data)
{
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = newNode(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

Node* addTwoLists(Node* first, Node* second)
{
	Node* res = NULL;
	Node *temp, *prev = NULL;
	int carry = 0, sum;

	while (first != NULL || second != NULL) {
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
		carry = (sum >= 10) ? 1 : 0;
		sum = sum % 10;
		temp = newNode(sum);
		if (res == NULL)
			res = temp;
		else
			prev->next = temp;
	
		prev = temp;

		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}
	if (carry > 0)
		temp->next = newNode(carry);
	return res;
}

Node* reverse(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	Node* rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

void printList(Node* node)
{
	while (node != NULL) {
		printf("%d",node->data);
		node = node->next;
	}
}

int main(void)
{
	Node* res = NULL;
	Node* first = NULL;
	Node* second = NULL;

    int m, n, buff;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        scanf("%d", &buff);
        push(&first, buff);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &buff);
        push(&second, buff);
    }

	res = addTwoLists(first, second);

	res = reverse(res);
    printf("[");
	printList(res);
    printf("]");
	return 0;
}
