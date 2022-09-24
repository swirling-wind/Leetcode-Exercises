#include <common_headers.h>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//class Solution {
//public:
//	vector<vector<int>> pathSum(TreeNode* root, int sum) {
//		vector<vector<int> > paths;
//		vector<int> path;
//		findPaths(root, sum, path, paths);
//		return paths;
//	}
//private:
//	void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
//		if (!node) return;
//		path.push_back(node->val);
//		if (!(node->left) && !(node->right) && sum == node->val)
//			paths.push_back(path);
//		findPaths(node->left, sum - node->val, path, paths);
//		findPaths(node->right, sum - node->val, path, paths);
//		path.pop_back();
//	}
//};

class Solution {
	vector<vector<int>> all_paths_;
	vector<int> current_;
	void find_path(const TreeNode* node, const int sum)
	{
		if (node != nullptr) 
		{
			current_.push_back(node->val);
			if (node->left == nullptr && node->right == nullptr && sum == node->val)
			{
				all_paths_.emplace_back(current_);
			}
			find_path(node->left, sum - node->val);
			find_path(node->right, sum - node->val);
			current_.pop_back();
		}
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, const int targetSum)
	{
		find_path(root, targetSum);		
		return all_paths_;
	}
};


int main()
{
	Solution solution;
	const auto output = solution.pathSum(new TreeNode{ 5,
		                                     new TreeNode{4,
			                                     new TreeNode{11, new TreeNode{7}, new TreeNode{2}},
			                                     nullptr},
		                                     new TreeNode{8,
			                                     new TreeNode{13},
			                                     new TreeNode{4, new TreeNode{5}, new TreeNode{1}}}
	                                     }, 22);


	for (const auto& outer : output)
	{
		for (const int val : outer)
		{
			cout << val << " ";
		}
		cout << "\n";
	}
}