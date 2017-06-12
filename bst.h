
#ifndef BST_H
#define BST_H
void insert (struct bstnode *t,int);
int size(struct bstnode *t);
int maxdepth(struct bstnode *t);
int minvalue(struct bstnode *t);
int maxvalue(struct bstnode *t);
void printree();
void postorder(struct bstnode *t);
int haspathsum(struct bstnode *t,int);
void mirror(struct bstnode *t);
void doubletree(struct bstnode *t);
int sametree(struct bstnode *t);

#endif BST_H
