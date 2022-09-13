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
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> result;

//		while (root != nullptr)
//		{
//			result.emplace_back(vector<int>{ root->val });
//			if (root->left != nullptr)
//			{
//
//			}
//			else if (root->right != nullptr)
//			{
//
//			}
//		}

		return vector<vector<int>>{{ 3 }, { 9, 20 }, { 15, 7 }};
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
	  TreeNode* input = new TreeNode{};
	  auto result = solution.levelOrder(input);

	  vector<vector<int>> answer{};

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