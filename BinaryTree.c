//
// Created by andre on 5/14/2023.
//

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool TreeIsEmpty(BinaryTree tree) {
    return tree == NULL;
}

BinaryTree InitTreeNode() {
    return (BinaryTree) malloc(TREE_NODE_SIZE);
}

BinaryTree NewTree(TreeType info, BinaryTree left, BinaryTree right) {
    BinaryTree tree = InitTreeNode();
    tree->info = info;
    tree->left = left;
    tree->right = right;
    return tree;
}

BinaryTree BinaryTree_Left(BinaryTree tree) {
    return tree->left;
}

BinaryTree BinaryTree_Right(BinaryTree tree) {
    return tree->right;
}

// "l" or "L" == left
// "r" or "R" == right
BinaryTree GoTo(BinaryTree tree, char *direction) {

    direction = strlwr(direction);
    if (strcmp(direction, "l")) return BinaryTree_Left(tree);
    else if (strcmp(direction, "r")) return BinaryTree_Right(tree);
    // invalid direction
    return tree;
}

int BinaryTree_Depth(BinaryTree tree) {
    if (TreeIsEmpty(tree)) return 0;
    int left = BinaryTree_Depth(BinaryTree_Left(tree));
    int right = BinaryTree_Depth(BinaryTree_Right(tree));

    return 1 + ((left > right) ? left : right);
}

int BinaryTree_MaxNodesNumber(int depth) {
    return (int) pow(2, depth) - 1;
}

TreeType BinaryTree_Value(BinaryTree tree) {
    return tree->info;
}

bool BinaryTree_IsInBinarySearchTree(BinaryTree tree, TreeType value) {
    if (TreeIsEmpty(tree)) return false;
    if (value > BinaryTree_Value(tree)) {
        return BinaryTree_IsInBinarySearchTree(BinaryTree_Right(tree), value);
    } else if (value < BinaryTree_Value(tree)) {
        return BinaryTree_IsInBinarySearchTree(BinaryTree_Left(tree), value);
    }
    return true;
}

void BinaryTree_InsertLeaf(BinaryTree *tree, TreeType info, char *direction) {

    if (TreeIsEmpty(*tree)) return;

    if (direction[1] == '\0') {
        if (TreeIsEmpty(*tree)) *tree = NewTree(info, NULL, NULL);
    }
    if (direction[0] == 'l')
        BinaryTree_InsertLeaf(&((*tree)->left), info, direction + 1);
    else if (direction[0] == 'r')
        BinaryTree_InsertLeaf(&((*tree)->right), info, direction + 1);
}

void BinaryTree_InsertTreeNode(BinaryTree *tree, TreeType value, char *direction) {
    if (direction[1] == '\0') {
        if (TreeIsEmpty(*tree)) *tree = NewTree(value, NULL, NULL);
        else if (direction[0] == 'l')
            *tree = NewTree(value, *tree, NULL);
        else if (direction[0] == 'r')
            *tree = NewTree(value, NULL, *tree);

    } else if (direction[0] == 'l')
        BinaryTree_InsertTreeNode(&((*tree)->left), value, direction + 1);
    else if (direction[0] == 'r')
        BinaryTree_InsertTreeNode(&((*tree)->right), value, direction + 1);
}

void BinaryTree_SetLeft(BinaryTree tree, BinaryTree left) {
    tree->left = left;
}

void BinaryTree_SetDeepLeft(BinaryTree *tree, BinaryTree left) {
    if (TreeIsEmpty(*tree)) *tree = left;
    else BinaryTree_SetDeepLeft(&((*tree)->left), left);
}

bool IsLeaf(BinaryTree tree) {
    return TreeIsEmpty(BinaryTree_Left(tree))
           && TreeIsEmpty(BinaryTree_Right(tree));
}

bool HasTwoNodes(BinaryTree tree) {
    return !TreeIsEmpty(BinaryTree_Left(tree))
           && !TreeIsEmpty(BinaryTree_Right(tree));
}

bool BinaryTree_DeleteTreeNode(BinaryTree *tree, TreeType value) {
    if (TreeIsEmpty(*tree)) return false;

    if (BinaryTree_Value(*tree) == value) {
        BinaryTree right = BinaryTree_Right(*tree);
        if (!TreeIsEmpty(right)) BinaryTree_SetDeepLeft(tree, right);
        BinaryTree temp = *tree;
        *tree = BinaryTree_Left(*tree);
        free(temp);
        return true;
    } else
        return BinaryTree_DeleteTreeNode(&((*tree)->left), value) ||
               BinaryTree_DeleteTreeNode(&((*tree)->right), value);
}

void BinaryTree_PrintLevel(BinaryTree tree, int level) {
    if (TreeIsEmpty(tree)) return;
    if (level == 0) printf("%d\n", BinaryTree_Value(tree));
    BinaryTree_PrintLevel(BinaryTree_Left(tree), level - 1);
    BinaryTree_PrintLevel(BinaryTree_Right(tree), level - 1);
}

