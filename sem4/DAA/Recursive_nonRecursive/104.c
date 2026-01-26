/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) 
{
    int l,r;
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }    
    l =  maxDepth(root->left);
    r =  maxDepth(root->right);
    return l>r ? l + 1 : r + 1;
}
/*
* x(n) => time taken by maxdepth on a tree with n nodes
* x(n) = x(left) + x(right) + c or  x(n) = x(n-k-1) + x(k) + c 
* x(0) = 0
*  k==> no. of left nodes
* ex:
        A
       / \
      B   C                n=6
     / \   \
    D   E   F
        A
       / \
      B   C
     / \   \
    D   E   F
x(6) = x(3) + x(2) + c
x(3) = x(1) + x(1) + c = x(0) + x(0) + c + x(0) + x(0) + c + c = 3c
x(2) = x(0) + x(1) + c = 0 + x(0) + c + c = 2c
=> x(6) = 6c, x(2) = 2c , x(3) = 3c.
=> At each node, the function performs a constant amount of work c.
Since the tree has n nodes and each node is visited exactly once, the total time taken is n × c, which simplifies to O(n).

