#include "bst.h"

#include "Common.h"

struct bstnode
{
	int data;
	struct bstnode *l;
	struct bstnode *r;
};
struct bstnode* newnode(int data) {
	struct bstnode* node = new(struct bstnode);
	node->data = data;
	node->l = NULL;
	node->r = NULL;
	return(node);
}

struct bstnode* insert(struct bstnode* node, int data)
{
	if (node == NULL)return(newnode(data));
	else {
		if (data <= node->data)
			node->l = insert(node->l, data);
		else
			node->r = insert(node->r, data);
		return(node);
	}
}

int size(struct bstnode*node) {
	if (node == NULL)return(0);
	else
		return(size(node->l) + 1 + size(node->r));
}

int maxdepth(struct bstnode* node) {
	if (node == NULL)return(0);
	else {
		int ldepth = maxdepth(node->l);
		int rdepth = maxdepth(node->r);

		if (ldepth > rdepth)return(ldepth + 1);
		else return(rdepth + 1);

	}
}

int minvalvue(struct bstnode* node) {
	struct bstnode* cur = node;
	while (cur->l != NULL)cur = cur->l;
	return(cur->data);
}

int maxvalvue(struct bstnode* node) {
	struct bstnode* cur = node;
	while (cur->r != NULL)cur = cur->r;
	return(cur->data);
}

void printree(struct bstnode*node) {
	if (node == NULL)return;
	printree(node->l);
	printf("%d", node->data);
	printree(node->r);
}

void postorder(struct bstnode*node) {
	if (node == NULL)return;
	printree(node->l);
	printree(node->r);
	printf("%d", node->data);
}

int haspathsum(struct bstnode* node, int sum) {
	if (node == NULL)return(sum == 0);
	else {
		int subsum = sum - node->data;
		return(haspathsum(node->l, subsum) || (node->r, subsum));
	}
}

	void mirror(struct bstnode*node) {
		if (node == NULL)return;
		else {
			struct bstnode* temp;
			mirror(node->l);
			mirror(node->r);
			temp = node->l;
			node->l = node->r;
			node->r = temp;
		}
	}
		
	void doubletree(struct bstnode*node) {
		struct bstnode* oldleft;
		if (node == NULL)return;
		doubletree(node->l);
		doubletree(node->r);
		oldleft = node->l;
		node->l = newnode(node->data);
		node->l->l = oldleft;
	}

	int sametree(struct bstnode*a, struct bstnode* b) {
		if (a == NULL && b == NULL)return(true);
		else if (a != NULL && b != NULL) {
			return(a->data == b->data && sametree(a->l, b->l) && sametree(a->r, b->r));
		}
		else return(false);
	}