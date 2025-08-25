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

        bool answer = false;

        solve(root , targetSum , 0 ,answer);

        return answer;


    }

    void solve (TreeNode* root, int targetSum , int sum , bool &answer){

        if(answer ==true){return;}

        if(root ==nullptr){return;}

        sum += root->val;

        if(sum==targetSum && root->left ==nullptr && root->right ==nullptr){
                answer = true;
                return;
        }

        solve(root->left , targetSum , sum , answer);
            solve(root->right , targetSum , sum , answer);

            return;
        
    }
};