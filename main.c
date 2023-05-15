#include <stdio.h>
#include "BinaryTree.h"

int main() {

    BinaryTree tree = NewTree(
            10,
            NewTree(
                    7,
                    NULL,
                    NULL
            ),
            NewTree(
                    11,
                    NULL,
                    NULL
            )
    );

    printf("%d\n", BinaryTree_Depth(tree));
    BinaryTree_InsertLeaf(&tree, 3, "ll");
    printf("%d\n", BinaryTree_Depth(tree));
    return 0;
}
