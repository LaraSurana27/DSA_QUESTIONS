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

    int result = 0;

    pair<int, int> dfs(TreeNode *node)
    {
        if(!node)
        {
            return {0, 0};
        }
        
        auto left = dfs(node -> left); // auto mtlb pair<int, int> ke badle humne auto use lkiya hai ki vo variable(left, right) ka datatype apne aap (automatically) decode krle
        auto right = dfs(node -> right);

        int sum = left.first + right.first + node -> val;
        int count = left.second + right.second + 1;

        if(sum/count == node -> val)
        {
            result++;
        }
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return result;
    }
};

/* 
Postorder DFS use karo (Left → Right → Current)
Kyun postorder? Kyunki current node ka average nikalne ke liye left aur right subtree ka sum + count pehle se pata hona chahiye
Har recursive call se do values return karo: {sum, count}

algo--
Base case: null node → return {sum=0, count=0}
Left subtree se {leftSum, leftCount} lo (recursive call)
Right subtree se {rightSum, rightCount} lo (recursive call)
Current node ka:
sum = leftSum + rightSum + node->val
count = leftCount + rightCount + 1
Check: sum / count == node->val → true hone par global count++
Return {sum, count} parent ko
*/