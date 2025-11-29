#include<bits/stdc++.h>
using namespace std;

// Maximum Depth of Binary Tree
/*
class Solution {
    public:
    int maxDepth(TreeNode* root) {
        if(!root)
        return 0;
        
        // simply get the no of level of the BT, level order traversal
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp -> left)
                q.push(temp -> left);
                if(temp -> right)    
                q.push(temp -> right);
            }
        }
        return level;
    }
};
*/

// Symmetric Tree
/*
class Solution {
    public:
    bool recSymmetry(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == nullptr && root2 == nullptr)
        return true;
        
        if(root1 == nullptr || root2 == nullptr)    
        return false;
        
        if(root1 -> val != root2 -> val)    
        return false;
        
        return recSymmetry(root1 -> left, root2 -> right) && recSymmetry(root1 -> right, root2 -> left);     
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
        return true;
        
        return recSymmetry(root -> left, root -> right);
    }
};
*/


// same tree
/*
class Solution {
    public:
    bool recursivePreorder(TreeNode*p, TreeNode* q)
    {
        if(!p && !q)  // both are null
        return true;
        if(!p || !q)    // either one tree reaches the end , and the other is still having some nodes
        return false;
        
        if(p -> val != q -> val) // node value is not same 
        return false;
        
        return recursivePreorder(p -> left, q -> left) && recursivePreorder(p -> right, q -> right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) { 
        return recursivePreorder(p,q);
    }
};
*/


// Invert Binary Tree
/*
class Solution {
    public:
    void mirror(TreeNode * root)
    {
        if(!root)
        return;
        TreeNode* temp = root -> right;
        root -> right = root -> left;
        root -> left = temp;
        mirror(root -> left);
        mirror(root -> right);    
    }
    
    TreeNode* invertTree(TreeNode* root) {
        mirror(root);
        return root;
    }
};
*/


// Balanced Binary Tree
/*
class Solution {
    public:
    int height(TreeNode *root, int &valid)
    {
        if(!root)
        return 0;
        int left = height(root -> left, valid);
        int right = height(root -> right, valid);    
        
        if(abs(left - right) > 1)
        valid = 0;
        return 1 + max(left, right);    
    }
    
    bool isBalanced(TreeNode* root) {
        int valid = 1;
        height(root,valid);
        return valid;
    }
};
*/

// mionimum Depth of Binary Tree
/*
class Solution {
    public:
    void rec(TreeNode* root, int &mini, int level)
    {
        if(!root)
        return ;
        if(!root -> left && !root -> right)   
        mini =  min(mini, level);
        
        rec(root -> left, mini, level+1);
        rec(root -> right, mini, level+1);
    }
    
    int minDepth(TreeNode* root) {  
        if(!root)
        return 0;
        int mini = INT_MAX;
        rec(root, mini, 1);
        return mini;
    }
};
*/

// Path Sum
/*
class Solution {
    public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
        return false;
        
        if(!root -> left && !root -> right)    // leaf node reached
        return targetSum == root -> val;
        
        return hasPathSum(root -> left, targetSum - root -> val) || hasPathSum(root -> right, targetSum - root -> val)  ;      
    }
};
*/


// Merge Two Binary Trees
/*
class Solution {
    public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(!r1)
        return r2;
        if(!r2)    
        return r1;
        r1 -> val += r2 -> val;
        r1 -> left = mergeTrees(r1 -> left, r2 -> left);
        r1 -> right = mergeTrees(r1 -> right, r2 -> right);
        return r1; 
    }
};
*/

// Sum of left Leaves
/*
class Solution {
    public:
    
    int rec(TreeNode *root, bool isLeftChild)
    {
        if(!root)  
        return 0;
        if(isLeftChild && !root -> left && !root -> right)    
        return root -> val;
        
        return rec(root -> left, true) + rec(root -> right, false);    
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return rec(root, false);
    }
};
*/


// Subtree of Another Tree
/*
class Solution {
    public:
    bool isSame(TreeNode *t1, TreeNode* t2)
    {
        if(!t1 && !t2)  
        return true;
        if(!t1 || !t2)    
        return false;
        if(t1 -> val != t2 -> val)
        return false;
        return isSame(t1->left, t2->left) && isSame(t1->right, t2-> right);    
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
    // get the node where the first value is same , and then simply check is it same or not
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode * temp = q.front();
            q.pop();
            if(temp -> val == subRoot -> val)
            {
                if(isSame(temp, subRoot))
                return true;
            }
            
            if(temp -> left)
            q.push(temp -> left);
            if(temp -> right)
            q.push(temp -> right);    
        }
    }

        return false;
    }
};
*/


// Diameter of Bianry Tree
/*
class Solution {
    public:
    int height(TreeNode* root, int & diameter)
    {
        if(!root)
        return 0;
        int left = height(root -> left, diameter);
        int right = height(root -> right, diameter);
        
        diameter = max(diameter, left + right);
        return 1 + max(left, right) ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
*/

// Range Sum of BST 
/*
class Solution {
    public:
    void rec(TreeNode* root, int low, int high, int &sum)
    {
        if(!root)
            return ;
            if(root -> val >= low && root -> val <= high)    
            sum += root -> val;   
            rec(root -> left, low, high, sum);
            rec(root -> right, low, high, sum);
        }
        int rangeSumBST(TreeNode* root, int low, int high) {
            int sum = 0;
            rec(root, low, high, sum);
            return sum;
        }
    };
*/