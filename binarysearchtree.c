#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

void free_tree(node *root);
void print_tree(node *root);
bool search_tree(node *root, int number);

int main()
{
    node *tree = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 4;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(tree);
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(tree->left);
        free(tree);
        return 1;
    }
    n->number = 6;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    print_tree(tree);

    if (search_tree(tree, 4))
    {
        printf("Found it!\n");
    }
    else
    {
        printf("Did not find it!!\n");
    }
    free_tree(tree);

    return 0;
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free_tree(root);
}

bool search_tree(node *root, int number)
{
    if (root == NULL)
    {
        return false;
    }
    else if (number < root->number)
    {
        return search_tree(root->left, number);
    }
    else if (number > root->number)
    {
        return search_tree(root->right, number);
    }
    else if (number == root->number)
    {
        return true;
    }
}