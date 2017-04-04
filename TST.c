// C program to demonstrate Ternary Search Tree (TST) insert, travese
// and search operations
#include <stdio.h>
#include <stdlib.h>
#include "TST.h"
#define MAX 50

// A utility function to create a new ternary search tree node
void newNode(char data,Node** node)
{
    *node = (Node*) malloc(sizeof( Node ));
    (*node)->data = data;
    (*node)->isEndOfString = 0;
    (*node)->left = (*node)->eq = (*node)->right = NULL;
}

// Function to insert a new word in a Ternary Search Tree
void insert(Node **root, char *word)
{
    // Base Case: Tree is empty
    if (!(*root))
        newNode(*word,root);

    // If current character of word is smaller than root's character,
    // then insert this word in left subtree of root
    if ((*word) < (*root)->data)
        insert(&( (*root)->left ), word);

    // If current character of word is greate than root's character,
    // then insert this word in right subtree of root
    else if ((*word) > (*root)->data)
        insert(&( (*root)->right ), word);

    // If current character of word is same as root's character,
    else
    {
        if (*(word+1))
            insert(&( (*root)->eq ), word+1);

        // the last character of the word
        else
            (*root)->isEndOfString = TRUE;
    }
}

// A recursive function to traverse Ternary Search Tree
void _traverseTST(Node *root, char *buffer, int depth)
{
    if (root)
    {
        // First traverse the left subtree
        _traverseTST(root->left, buffer, depth);

        // Store the character of this node
        buffer[depth] = root->data;
        if (root->isEndOfString)
        {
            buffer[depth+1] = '\0';
            printf( "%s\n", buffer);
        }

        // Traverse the subtree using equal pointer (middle subtree)
        _traverseTST(root->eq, buffer, depth + 1);

        // Finally Traverse the right subtree
        _traverseTST(root->right, buffer, depth);
    }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(Node* root)
{
    char buffer[MAX];
    _traverseTST(root, buffer, 0);
}

// Function to search a given word in TST
void _search(Node *root, char *word,TST_Bool *found)
{
    int i = 0;
    printf("0\n");
    if (!root){
        *found = FALSE;
        printf("1\n");
    }
    if (*word < (root)->data){
        _search(root->left, word,found);
        printf("2\n");
    }
    else if (*word > (root)->data)
        _search(root->right, word,found);
    else
    {
        printf("3\n");
        if (root->isEndOfString == TRUE) *found = TRUE;
        printf("4\n");
        _search(root->eq, word+1,found);
    }
}
void search(Node *tree, char *word){
    TST_Bool found;
    _search(tree,word,&found);
    printf("%s %sencontrado",word,found==FALSE?"nao ":"");
}
