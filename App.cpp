#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  class Solution {
  public:

      int getHeight(TreeNode* root)
      {
          // this is our base case
          // if no root (node), return 0
          if (!root)
          {
              return 0;
          }

          // find height of left subtree
          int leftHeight = getHeight(root->left);

          // find height of right subtree
          int rightHeight = getHeight(root->right);

          // at every node compare heights of subtrees
          int balanceFactor = abs(leftHeight - rightHeight);

          // if at any point the balance factor is greater than 1
          // we know this tree wont be balanced, do not continue
          // if leftHeight or rightHeight is -1 , that subtree is unbalanced
          if (balanceFactor > 1 || leftHeight == -1 || rightHeight == -1)
          {
              return -1;
          }
          // + 1 because you are coming from a level
          return 1 + max(leftHeight, rightHeight);

      }
      bool isBalanced(TreeNode* root) {

          // if no root, return true
          if (!root)
          {
              return true;
          }

          // if getHeight returns -1 , return false
          // otherwise return true
          return getHeight(root) == -1 ? false : true;
      }
  };

int main()
{
    Solution solution;

    TreeNode seven(7);
    TreeNode fifteen(15);
    TreeNode twenty(20, &fifteen, &seven);

    TreeNode nine(9);

    TreeNode root(3, &nine, &twenty);

    cout << "Example One : " << solution.isBalanced(&root) << endl;
	return 0;
}