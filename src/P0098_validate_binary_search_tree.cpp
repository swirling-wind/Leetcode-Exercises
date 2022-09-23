#include <common_headers.h>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root)
	{
		return validate_helper(root, nullptr, nullptr);
	}

private:
	bool validate_helper(const TreeNode* root, const TreeNode* min_node, const TreeNode* max_node)
	{
		if (root == nullptr)
		{
			return true;
		}
		if ((min_node != nullptr && root->val <= min_node->val) || (max_node != nullptr && root->val >= max_node->val))
		{
			return false;
		}
		return validate_helper(root->left, min_node, root) && validate_helper(root->right, root, max_node);
	}
};
class MaxMinSolution {
	bool validate_helper(const TreeNode* root, const int64_t min_val, const int64_t max_val)
	{
		if (root->val >= max_val || root->val <= min_val)
		{
			return false;
		}
		bool result{ true };
		if (root->left)
		{
			result = result && validate_helper(root->left, min_val, root->val);
		}
		if (root->right)
		{
			result = result && validate_helper(root->right, root->val, max_val);
		}
		return result;
	}

public:
	bool isValidBST(TreeNode* root)
	{
		bool result{ true };
		if (root->left)
		{
			constexpr int64_t current_min{ numeric_limits<int64_t>::min() };
			result = result && validate_helper(root->left, current_min, root->val);
		}
		if (root->right)
		{
			constexpr int64_t current_max{ numeric_limits<int64_t>::max() };
			result = result && validate_helper(root->right, root->val, current_max);
		}
		return result;
	}
};


int main()
{
	Solution solution;
	expect(eq(true, solution.isValidBST(new TreeNode{ 5 })));
	expect(eq(false, solution.isValidBST(
		new TreeNode{ 5,
			new TreeNode{ 1 },
			new TreeNode{ 4, new TreeNode{3}, new TreeNode{6} } }
	)));
	expect(eq(true, solution.isValidBST(
		new TreeNode{ 2,
			new TreeNode{ 1 },
			new TreeNode{ 3 } }
	)));
	expect(eq(false, solution.isValidBST(
		new TreeNode{ 2,
			new TreeNode{ 2 },
			new TreeNode{ 2 } }
	)));
	expect(eq(true, solution.isValidBST(
		new TreeNode{ -2147483648,
			nullptr,
			new TreeNode{ 2147483647 } }
	)));
}