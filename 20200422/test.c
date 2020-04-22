#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* left;
	struct Node* right;
	char val;
}Node;

Node* creatTree(char* str, int* idx) {
	if (str[*idx] != '#') {
		Node* root = (Node*)malloc(sizeof(Node));
		root->val = str[*idx];
		++(*idx);
		root->left = creatTree(str, idx);
		++(*idx);
		root->right = creatTree(str, idx);
		return root;
	}
	else {
		return NULL;
	}
}

void BinaryTreeInOder(Node* root) {
	if (root) {
		BinaryTreeInOder(root->left);
		printf("%c ", root->val);
		BinaryTreeInOder(root->right);
	}
}

int main() {
	char str[101] = { 0 };
	scanf("%s", str);
	int idx = 0;
	Node* root = creatTree(str, &idx);
	BinaryTreeInOder(root);
	printf("\n");
}
//2.删除链表倒数第N个结点(笨办法)
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* cur, *next, *prev;
	prev = (struct ListNode*)malloc(sizeof(struct ListNode));//考虑删除的可能是头结点,设一个头结点
	prev->next = head;
	int count = 0;
	cur = head;
	while (cur) {
		count++;
		cur = cur->next;
	}
	int num = count - n;
	cur = head;
	if (num == 0)
		prev->next = head->next;
	else {
		while (num - 1) {
			cur = cur->next;
			num--;
		}
		next = cur->next;
		cur->next = next->next;
		free(next);
	}
	return prev->next;
}
//利用快慢指针删除倒数第N个结点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* slow, *fast;
	slow = fast = head;
	for (int i = 0; i < n; i++) {
		fast = fast->next;
	}
	if (fast == NULL) {
		head = head->next;
	}
	else {
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		slow->next = slow->next->next;
		return head;
	}
}
struct ListNode* returnNthFromEnd(struct ListNode* head, int k) {
	struct ListNode* slow, *fast;
	slow = fast = head;
	for (int i = 0; i < k; i++) {
		if (fast == NULL)
			return NULL;
		fast = fast->next;
	}
	while (fast) {
		slow = slow->next;
		fast = fast->next;

	}
	return slow;
}