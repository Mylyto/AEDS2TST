#ifndef TST_H_INCLUDED
#define TST_H_INCLUDED
typedef enum{ FALSE, TRUE} TST_Bool;
typedef struct _Node{
	char key;
	TST_Bool isEndOfString;
	struct _Node *lower, *equal, *higher;
} Node;
void insert(Node **root, char *word);
void traverseTSTUtil(Node *root, char *buffer, int depth);
void traverseTST(Node *root);
TST_Bool search(Node *tree, char *word);
#endif
