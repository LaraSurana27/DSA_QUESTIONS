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
    int minDepth(TreeNode* root) {

        /*
        Agar ek node ka sirf ek hi child hai (dusra null), to us node ko leaf nahi maan sakte — warna wrong answer aayega.
        Example 2 dekho:
    2
     \
      3
       \
        4
         \
          5
           \
            6

        Yaha 2 ka left child null hai, lekin 2 leaf nahi hai kyunki right child hai. Isliye seedha min(left, right) nahi le sakte — agar ek side null hai to us side ki depth ignore karni hai.

        Logic:
Agar root == null → return 0
Agar left == null → sirf right subtree explore karo: 1 + minDepth(right)
Agar right == null → sirf left subtree explore karo: 1 + minDepth(left)
Agar dono hain → 1 + min(minDepth(left), minDepth(right))
        */
     if(root == NULL) return 0;

     if(root -> left == NULL) return 1 + minDepth(root -> right);
     if(root -> right == NULL) return 1 + minDepth(root -> left);

     return 1 + min(minDepth(root -> left), minDepth(root -> right));   
    }
};

/* 
Time: O(n) 
Space: O(h) due to recursion 
*/