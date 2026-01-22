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
    bool hasPathSum(TreeNode* root, int targetSum) {

        bool ans = false;

      solve( root , targetSum , 0 , ans);

      return ans;
        
    }

    void solve( TreeNode* root , int targetSum , int sum , bool &ans){

        if(root == nullptr || ans == true){
            return ;
        }

        sum += root->val;

        solve(root->left , targetSum , sum , ans);

        solve(root->right , targetSum , sum , ans);

        if(sum == targetSum && root->left == nullptr && root->right == nullptr){
            ans = true;
        }

        return ;

        
    }
};