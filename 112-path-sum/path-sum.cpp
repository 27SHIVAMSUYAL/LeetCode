/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = false;
    bool hasPathSum(TreeNode* root, int targetSum ) {

        if( root == nullptr || ans == true){
            return ans;
        }

        targetSum -= root->val;

        hasPathSum(root->left , targetSum  );

        hasPathSum(root->right , targetSum  );


         if( targetSum == 0 && root->left == nullptr && root->right == nullptr){
            ans = true;
        }

        return ans;


        
    }

    
};