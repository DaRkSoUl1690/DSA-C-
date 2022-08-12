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
    vector<vector<int>> levelOrder(TreeNode* root) {
       queue<TreeNode *>q;
        vector<vector<int>> result;
        if(root==NULL) return result;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        while(!q.empty())
        {
            TreeNode *top = q.front();
            q.pop(); 
           if(top==NULL)
            {
                result.push_back(temp);
                temp.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                    continue;
                }
                return result;               
            }
            else temp.push_back(top->val);                            
            
            if(top->left) q.push(top->left);                
               
            if(top->right) q.push(top->right);            
        }
        
        return result;
    }
};