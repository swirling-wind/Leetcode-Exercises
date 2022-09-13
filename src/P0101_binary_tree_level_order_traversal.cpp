#include <common_headers.h>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
	{
	}
};

class Solution
{// BFS
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> result;
		if (root == nullptr)
		{
			return result;
		}

		vector<int> this_depth;
		queue<TreeNode*> nodes_queue;
		nodes_queue.push(root);
		nodes_queue.push(nullptr);
		// In the nodes_queue, each depth is divided and flagged with a nullptr
		while (!nodes_queue.empty())
		{
			TreeNode* current = nodes_queue.front();
			nodes_queue.pop();

			if (current == nullptr)
			{
				result.emplace_back(this_depth);
				this_depth.clear();
				if (!nodes_queue.empty())
				{
					nodes_queue.push(nullptr);
				}
			}
			else
			{
				this_depth.emplace_back(current->val);
				if (current->left != nullptr)
				{
					nodes_queue.push(current->left);
				}
				if (current->right != nullptr)
				{
					nodes_queue.push(current->right);
				}
			}
		}
		return result;
	}
};

class DFS_Solution
{ //DFS
public:
	vector<vector<int>> result;

	void scan_per_depth(TreeNode* current_root, int current_depth)
	{
		if (current_root == nullptr)
		{
			return;
		}
		if (static_cast<int>(result.size()) == current_depth)
		{
			result.emplace_back(vector<int>());
		}
		result[current_depth].emplace_back(current_root->val);
		scan_per_depth(current_root->left, current_depth + 1);
		scan_per_depth(current_root->right, current_depth + 1);
	}

	vector<vector<int>> levelOrder(TreeNode* root)
	{
		scan_per_depth(root, 0);
		return result;
	}
};

int main()
{
	"1st test"_test = []
	{
	  Solution solution;
	  TreeNode* input = new TreeNode{ 3,
									  new TreeNode{ 9 }, new TreeNode{ 20,
																	   new TreeNode{ 15 }, new TreeNode{ 7 }}
	  };
	  auto result = solution.levelOrder(input);

	  vector<vector<int>> answer{{ 3 }, { 9, 20 }, { 15, 7 }};

	  expect(answer.size() == result.size() >> fatal);

	  for (size_t i = 0; i < answer.size(); ++i)
	  {
		  expect(result[i].size() == answer[i].size() >> fatal);
		  ut::log << "when i:" << i << "\n";
		  for (size_t j = 0; j < answer.size(); ++j)
			  expect(result[i][j] == answer[i][j]);
	  }

	};

	"2nd test"_test = []
	{
	  Solution solution;
	  TreeNode* input = new TreeNode{ 1 };
	  auto result = solution.levelOrder(input);

	  vector<vector<int>> answer{{ 1 }};

	  expect(answer.size() == result.size() >> fatal);

	  for (size_t i = 0; i < answer.size(); ++i)
	  {
		  expect(result[i].size() == answer[i].size() >> fatal);
		  ut::log << "when i:" << i << "\n";
		  for (size_t j = 0; j < answer.size(); ++j)
			  expect(result[i][j] == answer[i][j]);
	  }

	};

	"3rd test"_test = []
	{
	  Solution solution;
	  TreeNode* input = nullptr;
	  auto result = solution.levelOrder(input);

	  vector<vector<int>> answer;

	  expect(answer.size() == result.size() >> fatal);

	  for (size_t i = 0; i < answer.size(); ++i)
	  {
		  expect(result[i].size() == answer[i].size() >> fatal);
		  ut::log << "when i:" << i << "\n";
		  for (size_t j = 0; j < answer.size(); ++j)
			  expect(result[i][j] == answer[i][j]);
	  }

	};
}