#include "binary_tree.h"

//for this coding exploration, binary trees seems like a waste of time. so we will skip to BST
//some quick defs for reference
/* 
* -> We have trees and binary tress (duh)
* -> We have binary trees and binary search trees; where left <= n < right
* -> Balanced vs Unbalanced; where insert and find commands take O(log n). aka not all nodes are just on one side/branch
* -> Complete vs Incoplete BINARY trees; is when at each level we have the max number of nodes 1 -> 2 -> 4 etc untill the last level, which is the exception 
* -> Full BINARY tress; every node has 0 or 2 children except leaves
* -> PERFECT BINARY TREE; both full and complete
*/

//we have defined our std binary tree node, we will use this in all tops of problems hopefully
tree_node * create_binary_tree_node(int val)
{
    tree_node * my_node = (tree_node *) malloc(sizeof(tree_node));
    my_node->val = val;
    my_node->left = NULL;
    my_node->right = NULL;
    return my_node;
}

tree_node * add_to_tree(tree_node * root, int val)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
    {
        return create_binary_tree_node(val);
    }
 
    /* Otherwise, recur down the tree */
    if (val < root->val)
    {
        root->left  = add_to_tree(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = add_to_tree(root->right, val);   
    }
 
    /* return the (unchanged) node pointer */
    return root;
}


tree_node * min_value_tree(tree_node * root)
{
    tree_node * temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    } 
    return temp;     
}



/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
tree_node * delete_from_tree(tree_node * root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->val) root->left = delete_from_tree(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->val) root->right = delete_from_tree(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        //just delete that node a return the child to the last call, and it will think its the original
        if (root->left == NULL)
        {
            tree_node * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tree_node * temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        //or the smallest of the largest nodes to take its place
        tree_node * temp = min_value_tree(root->right);
 
        // Copy the inorder successor's content to this node
        root->val = temp->val;
 
        // Delete the inorder successor
        root->right = delete_from_tree(root->right, temp->val);
    }
    return root;
}


void print_tree_inorder(tree_node * root){
    if(root != NULL){
        print_tree_inorder(root->left); // go left
        printf("%d\n", root->val);
        print_tree_inorder(root->right);//go left
    }
}

void trees_menu()
{
    printf("Hello, welcome to trees!\n");
    //create our root node
    //tree_node * root = create_binary_tree_node(955);
    tree_node * root = NULL;
    root = add_to_tree(root, 64);
    root = add_to_tree(root, 10);
    root = add_to_tree(root, 7);
    root = add_to_tree(root, 8);
    root = delete_from_tree(root, 10);
    print_tree_inorder(root);
}