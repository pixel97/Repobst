
#include "bst.h"
#include<conio.h>
#include"Common.h"
void main()
{
	int ch, n, a[10], sum;
	struct bstnode* node;
	node = NULL;

	printf("\nOPERATIONS ---");
	printf("\n1 - Insert an element into tree\n");
	printf("2 - Display the size of tree\n");
	printf("3 - Maximum depth of tree\n");
	printf("4 - Minimum value\n");
	printf("5 - Maximum value\n");
	printf("6 -Print tree\n");
	printf("6 -Post order\n");
	printf("6 -Haspath sum\n");
	printf("6 -Mirror\n");
	printf("6 -Double tree\n");
	printf("6 -Same tree\n");
	printf("6 -EXIT\n");



	while (1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the no. of nodes\n");
			scanf("%d", n);
			printf("Enter the values\n");
			for (int i = 0; i < n; i++) {
				scanf("%d", &a[i]);
				insert(node, a[i]);
			}
			break;
		case 2:
			size(node);
			printf("the size is %d", size(node));
			break;
		case 3:
			printf("the max depth of tree is ", maxdepth(node));
			break;
		case 4:
			printf("the mini value of tree is %d", minvalue(node));
			break;
		case 5:
			printf("the max value of tree is %d", maxvalue(node));;
			break;
		case 6:
			printree(); break;
		case 7:
			postorder(node); break;
		case 8:
			printf("enter the sum value");
			scanf("%d", &sum);
			haspathsum(node,sum); break;
		case 9:
			mirror(node); break;
		case 10:
			doubletree(node); break;
		case 11:
			sametree(node); break;
		default:
			printf("Wrong choice, Please enter correct choice  ");
			break;
		}
	}
}