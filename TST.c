#include <stdio.h>
#include <stdlib.h>
#include "TST.h"
#define MAX 50
void newNode(char data,Node** node)
{
    *node = (Node*) malloc(sizeof( Node ));
    (*node)->data = data;
    (*node)->isEndOfString = FALSE;
    (*node)->left = (*node)->eq = (*node)->right = NULL;
}
void insert(Node **root, char *word)
{
    if (!(*root))  newNode(*word,root);
    if ((*word) < (*root)->data)  insert(&( (*root)->left ), word);
    else if ((*word) > (*root)->data)  insert(&( (*root)->right ), word);
    else
    {
        if (*(word+1))
            insert(&( (*root)->eq ), word+1);
        else
            (*root)->isEndOfString = TRUE;
    }
}
void _traverseTST(Node *root, char *buffer, int depth)
{
    if (root)
    {
        _traverseTST(root->left, buffer, depth);
        buffer[depth] = root->data;
        if (root->isEndOfString == TRUE)
        {
            buffer[depth+1] = '\0';
            printf( "%s\n", buffer);
        }
        _traverseTST(root->eq, buffer, depth + 1);
        _traverseTST(root->right, buffer, depth);
    }
}
void traverseTST(Node* root)
{
    char buffer[MAX];
    _traverseTST(root, buffer, 0);
}
void _search(Node *root, char *word,TST_Bool *found)
{
    if(!root) return;
    if (*word < (root)->data){
        _search(root->left, word,found);
	return;
    }
    else if (*word > (root)->data){
        _search(root->right, word,found);
    	return;
    }
    else{
        if (root->isEndOfString == TRUE){ 
		*found = TRUE;
		return;
	}
        _search(root->eq, word+1,found);
    }
}
void search(Node *tree, char *word){
    TST_Bool found = FALSE;
    _search(tree,word,&found);
    printf("%s %sencontrado\n",word,found==FALSE?"nao ":"");
}
