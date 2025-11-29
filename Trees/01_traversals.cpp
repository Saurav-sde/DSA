#include<bits/stdc++.h>
using namespace std;


// inorder traversal
/*
class Solution {
    private:
    void rec(TreeNode* root, vector<int>& ans)
        {
            if(!root)
            return;
            rec(root->left, ans); // left
            ans.push_back(root -> val); // root
            rec(root -> right, ans);  // right  
        }
        public:
		vector<int> inorderTraversal(TreeNode* root){
	        vector<int> ans;
            rec(root, ans);
            return ans;
		}
    };
*/


// preorder 
/*
class Solution {
    public:
    private:
    void rec(TreeNode* root, vector<int>& ans)
    {
        if(!root)
        return;
        ans.push_back(root -> val); // root
        rec(root->left, ans); // left
        rec(root -> right, ans);  // right  
    }
	public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        rec(root, ans);
        return ans;
    }
};

*/


// postorder

/*
class Solution {
private:
    void recursivePostorder(TreeNode* root, vector<int>& ans)
        {
            if(!root)
                return;
            recursivePostorder(root -> left, ans);
            recursivePostorder(root -> right, ans);
            ans.push_back(root -> val);
        }

	public:
		vector<int> postorderTraversal(TreeNode* root){
	        vector<int> ans;
            recursivePostorder(root, ans);
            return ans;
		}
};
*/