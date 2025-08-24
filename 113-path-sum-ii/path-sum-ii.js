/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {number[][]}
 */
 var pathSum = function(root, targetSum) {
    // Handle null root case
    if (root === null) {
        return [];
    }
    
    const result = [];
    
    function dfs(node, currentSum, path) {
        // Base case: if node is null
        if (node === null) {
            return;
        }
        
        const newSum = currentSum + node.val;
        
        // Add current node value to path
        path.push(node.val);
        
        // Check if current node is a leaf
        const isLeaf = node.left === null && node.right === null;
        
        if (isLeaf) {
            // If it's a leaf and sum matches target, add path to result
            if (newSum === targetSum) {
                result.push([...path]); // Create a copy of the path
            }
        } else {
            // Continue DFS on children
            dfs(node.left, newSum, path);
            dfs(node.right, newSum, path);
        }
        
        // Backtrack: remove current value from path
        path.pop();
    }
    
    dfs(root, 0, []);
    return result;
};