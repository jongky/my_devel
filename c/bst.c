#include<stdlib.h>
#include<stdio.h>
struct bin_tree {
    int data;
    struct bin_tree *right; 
    struct bin_tree *left;
};
typedef struct bin_tree node;

/*********************************************************/
/* [1.1] Binary Search Tree: insert the list             */
/*********************************************************/
void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

/*********************************************************/
/* [1.2] Binary Search Tree: Print the list pre-order    */
/*********************************************************/
void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

/*********************************************************/
/* [1.3] Binary Search Tree: Print the list in-order     */
/*********************************************************/
void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

/*********************************************************/
/* [1.4] Binary Search Tree: Print the list post-order     */
/*********************************************************/
void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

/*********************************************************/
/* [1.5] Binary Search Tree: Delete the list             */
/*********************************************************/
void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

/*********************************************************/
/* [1.6] Binary Search Tree: Search the list             */
/*********************************************************/
node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

/*********************************************************/
/* [1.7] Binary Search Tree: Calculate Max Depth of Tree */
/*********************************************************/
/* Compute the "maxDepth" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int maxDepth(node* node)
{
    int lDepth, rDepth;

    if (node==NULL)
       return 0;
    else
    {
        /* compute the depth of each subtree */
        lDepth = maxDepth(node->left);
        rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}

/*********************************************************/
/* [1.8] Binary Search Tree: Reverse the Tree            */
/*********************************************************/
reverse(node* root)
{
    if (root == NULL)
        return;
    else
    {
        reverse(root->left);
        reverse(root->right);
        node* temp= root->left;
        root->left=root->right;
        root->right=temp;
        return;
    }
}

/*********************************************************/
/* [1.9] Binary Search Tree: Reverse the Tree            */
/* Given a non-empty binary search tree, 
   return the minimum data value found in that tree      */
/*********************************************************/
int minValue(struct node* node) {
  struct node* current = node;
 
  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return(current->data);
}

/*********************************************************/
/* [1.10] Binary Search Tree: Shuffle Card Algorithm     */
/* Arrange the N elements of ARRAY in random order. Only effective 
   if N is much smaller than RAND_MAX; if this may not be the case, 
   use a better random number generator. */ 
/*********************************************************/
void shuffle(int *array, size_t n) 
{ 
    if (n > 1) 
    { 
        size_t i; 
        for (i = 0; i < n - 1; i++) 
        { 
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1); 
            int t = array[j]; 
            array[j] = array[i]; 
            array[i] = t; 
        } 
    }  
}

/*********************************************************/
/* [1.11] Binary Search Tree: Shuffle Card Algorithm     */
/*********************************************************/
void BubbleSort(int DataArray[], int Length)
{
    int i = 0, j = 0, temp = 0;

    for (i=0; i < Length-1; i++)
    {
        for (j=0; j < Length-(i+1); j++)
        {
            if (DataArray[j] > DataArray[j+1]) {
                temp = DataArray[j+1];
                DataArray[j+1] = DataArray[j];
                DataArray[j] = temp;
            }  
        }
    }
}

/*********************************************************/
/* [1.0] Binary Search Tree: Main                        */
/*********************************************************/
void main()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);

    /* Search node into tree */
    tmp = search(&root, 4);
    if (tmp)
    {
        printf("Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }

    /* Deleting all nodes of tree */
    deltree(root);
}

