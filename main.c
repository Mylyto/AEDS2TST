#include <stdio.h>
#include <stdlib.h>
#include "TST.h"

int main()
{
    Node *root = NULL;

    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");

    printf("Following is traversal of ternary search tree\n");
    traverseTST(root);

    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    search(root, "cats");
    search(root, "bu");
    search(root, "cat");

    return 0;
}
