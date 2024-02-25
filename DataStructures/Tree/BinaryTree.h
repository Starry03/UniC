//
// Created by andre on 5/14/2023.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdbool.h>

typedef int TreeType;

typedef struct BinaryTreeNode {
    TreeType info;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

typedef BinaryTreeNode *BinaryTree;

#define TREE_NODE_SIZE 24

BinaryTree InitTreeNode();

BinaryTree NewTree(
        TreeType info,
        BinaryTree left,
        BinaryTree right
);

BinaryTree BinaryTree_Left(BinaryTree tree);

BinaryTree BinaryTree_Right(BinaryTree tree);

TreeType BinaryTree_Value(BinaryTree tree);

BinaryTree GoTo(BinaryTree tree, char *direction);

int BinaryTree_Depth(BinaryTree tree);

int BinaryTree_MaxNodesNumber(int depth);

bool BinaryTree_IsInBinarySearchTree(BinaryTree tree, TreeType value);

void BinaryTree_InsertLeaf(BinaryTree *tree, TreeType info, char *direction);

void BinaryTree_InsertTreeNode(BinaryTree *tree, TreeType value, char *direction);

void BinaryTree_SetLeft(BinaryTree tree, BinaryTree left);

void BinaryTree_SetDeepLeft(BinaryTree* tree, BinaryTree left);

bool IsLeaf(BinaryTree tree);

bool HasTwoNodes(BinaryTree tree);

bool BinaryTree_DeleteTreeNode(BinaryTree *tree, TreeType value);

#endif //BINARYTREE_H
