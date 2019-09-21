#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {}
};
class Codec {
public:
    inline string itos(int i) {
        ostringstream os;
        os << i;
        return os.str();
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        deque<TreeNode*> s;
        s.push_back(root);
        _serialize(root, s);
        string data;
        while (!s.empty()) {
            TreeNode* node = s.back();
            s.pop_back();
            if (data != "") {
                data = "," + data;
            }
            if (node) {
                data = itos(node->val) + data;
            } else {
                data = "null" + data;
            }
        }
        return data;
    }

    void _serialize(TreeNode* root, deque<TreeNode*>& s) {
        if (!root) {
            return;
        }
        if (root->left || root->right)
            s.push_back(root->left);
        if (root->right)
            s.push_back(root->right);
        bool empty_left = false;
        if (root->left) {
            size_t s1 = s.size();
            _serialize(root->left, s);
            if (s.size() == s1) {
                empty_left = true;
            }
        }
        deque<TreeNode*> sright;
        if (root->right) {
            _serialize(root->right, sright);
        }
        cout << "size:" << sright.size() << endl;
        if (sright.size()) {
            if (empty_left) {
                s.push_back(NULL);
                s.push_back(NULL);
            }
        }
        while (!sright.empty()) {
            s.push_back(sright.front());
            sright.pop_front();
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return NULL;
    }
};

int test1()
{
    Codec codec;
    TreeNode* node = new TreeNode(1,
            new TreeNode(2, NULL , NULL),
            new TreeNode(3,
                new TreeNode(4, NULL, NULL),
                new TreeNode(5, NULL, NULL)
        ));
    cout << codec.serialize(node) << endl;
    return 0;
}
int test2()
{
    Codec codec;
    TreeNode* node = new TreeNode(1,
            new TreeNode(3,
                new TreeNode(4, NULL, NULL),
                new TreeNode(5, NULL, NULL)
            ),
            new TreeNode(2, NULL , NULL)
        );
    cout << codec.serialize(node) << endl;
    return 0;
}
int test3()
{
    Codec codec;
    TreeNode* node = new TreeNode(1,
            NULL,
            new TreeNode(3,
                new TreeNode(4, NULL, NULL),
                new TreeNode(5, NULL, NULL)
            )
        );
    cout << codec.serialize(node) << endl;
    return 0;
}
int main()
{
    test1();
    test2();
    test3();
    return 0;
}
