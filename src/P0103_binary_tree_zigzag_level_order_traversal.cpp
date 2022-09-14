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

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr)
		{
			return result;
		}

		queue<TreeNode*> nodes_queue;
		nodes_queue.push(root);
		nodes_queue.push(nullptr);

		vector<int> same_depth;

		while (!nodes_queue.empty())
		{
			TreeNode* current{ nodes_queue.front() };
			nodes_queue.pop();

			if (current == nullptr)
			{
				result.emplace_back(same_depth);
				same_depth.clear();
				if (!nodes_queue.empty())
				{
					nodes_queue.push(nullptr);
				}
			}
			else
			{// point to a num
				same_depth.emplace_back(current->val);
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
		for (int i = 0; i < result.size(); ++i)
		{
			if (i % 2 == 1 && result[i].size() > 1)
			{
				std::reverse(result[i].begin(), result[i].end());
			}
		}
		return result;
	}
};

int main()
{

	"1st test"_test = []
	{
		Solution solution;
		TreeNode* input = new TreeNode{ 3,
										new TreeNode{ 9 }, new TreeNode{ 20,new TreeNode{ 15 }, new TreeNode{ 7 }}
		};
		auto result = solution.zigzagLevelOrder(input);

		vector<vector<int>> answer{ { 3 }, { 20, 9 }, { 15, 7 } };

		expect(answer.size() == result.size() >> fatal);

		for (size_t i = 0; i < answer.size(); ++i)
		{
			expect(eq(result[i].size(), answer[i].size()) >> fatal);
			for (size_t j = 0; j < answer[i].size(); ++j)
				expect(eq(result[i][j], answer[i][j]));
		}

	};

	"2nd test"_test = []
	{
		Solution solution;
		TreeNode* input = new TreeNode{ 1 };
		auto result = solution.zigzagLevelOrder(input);

		vector<vector<int>> answer{ { 1 } };

		expect(answer.size() == result.size() >> fatal);

		for (size_t i = 0; i < answer.size(); ++i)
		{
			expect(eq(result[i].size(), answer[i].size()) >> fatal);
			for (size_t j = 0; j < answer[i].size(); ++j)
				expect(eq(result[i][j], answer[i][j]));
		}

	};

	"3rd test"_test = []
	{
		Solution solution;
		TreeNode* input = nullptr;
		auto result = solution.zigzagLevelOrder(input);

		vector<vector<int>> answer;

		expect(answer.size() == result.size() >> fatal);

		for (size_t i = 0; i < answer.size(); ++i)
		{
			expect(eq(result[i].size(), answer[i].size()) >> fatal);
			for (size_t j = 0; j < answer[i].size(); ++j)
				expect(eq(result[i][j], answer[i][j]));
		}
	};

	"4th test"_test = []
	{
		Solution solution;
		TreeNode* input = new TreeNode{ 1,
			new TreeNode{2, new TreeNode{4}, nullptr}, new TreeNode{3, nullptr, new TreeNode{5}} };
		auto result = solution.zigzagLevelOrder(input);

		vector<vector<int>> answer{ {1}, {3,2}, {4,5} };

		expect(answer.size() == result.size() >> fatal);

		for (size_t i = 0; i < answer.size(); ++i)
		{
			expect(eq(result[i].size(), answer[i].size()) >> fatal);
			for (size_t j = 0; j < answer[i].size(); ++j)
				expect(eq(result[i][j], answer[i][j]));
		}
	};
}