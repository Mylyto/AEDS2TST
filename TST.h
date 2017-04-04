#ifndef TST_H_INCLUDED
#define TST_H_INCLUDED
typedef enum{ FALSE, TRUE} TST_Bool;
typedef struct _Node{
	char key;
	TST_Bool isEndOfString;
	struct _Node *lower, *equal, *higher;
} Node;
void insert(Node **root, char *word);
void _traverseTST(Node *root, char *buffer, int depth);
void traverseTST(Node *root);
void search(Node *tree, char *word);
void _search(Node *tree, char *word,TST_Bool *found);
#endif
