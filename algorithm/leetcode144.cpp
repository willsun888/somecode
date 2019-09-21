#include <iostream>
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (p || !s.empty()) {
            while (p) {
                res.push_back(p->val);
                s.push(p);
                if (p->left) {
                    p = p->left;
                }
            }

            bool loop = true;
            while (loop && !s.empty()) {
                TreeNode* t = s.top();
                s.pop();
                if (t->right) {
                    s.push(t->right);
                    loop = false;
                }
            }
        }
        return res;
    }
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        res.push_back(root->val);
        vector<int> left_res;
        if (root->left) {
            left_res = preorderTraversal(root->left);
        }
        vector<int> right_res;
        if (root->right) {
            right_res = preorderTraversal(root->right);
        }
        res.insert(res.end(), left_res.begin(), left_res.end());
        res.insert(res.end(), right_res.begin(), right_res.end());
        return res;
    }
};

int main()
{
    Solution s;
    s.preorderTraversal();
    return 0;
}
