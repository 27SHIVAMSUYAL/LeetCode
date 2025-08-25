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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> answer;
            vector<int> temp;
        solve(root , targetSum ,temp , 0 , answer);


        return answer;
        
    }

    void solve(TreeNode* root, int targetSum , vector<int> temp , int sum ,  vector<vector<int>> &answer) {


if(root == nullptr ){
    return;
    }

    sum += root->val;


        temp.push_back(root->val);

    if(sum==targetSum && root->right ==nullptr && root->left ==nullptr){
        answer.push_back(temp);
        return;
    }

    solve(root->left , targetSum , temp , sum , answer);

    solve(root->right , targetSum , temp , sum ,answer);





        return;
    }


};