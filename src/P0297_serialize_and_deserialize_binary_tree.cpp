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

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		serialize_helper(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return deserialize_helper(in);
	}

private:
	void serialize_helper(TreeNode* root, ostringstream& out)
	{
		if (root != nullptr)
		{
			out << root->val << " ";
			serialize_helper(root->left, out);
			serialize_helper(root->right, out);
		}
		else
		{
			out << "N ";
		}
	}

	TreeNode* deserialize_helper(istringstream& in)
	{
		string current_val;
		in >> current_val;
		if (current_val == "N")
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(stoi(current_val));
		root->left = deserialize_helper(in);
		root->right = deserialize_helper(in);
		return root;
	}
};


class WrongCodec {
	// using BFS but access violation
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {

		if (root == nullptr)
		{
			return "";
		}
		string result;
		queue<TreeNode*> nodes_queue;
		nodes_queue.push(root);
		nodes_queue.push(nullptr);

		string same_depth;

		TreeNode* empty = new TreeNode{ 1001 };

		while (!nodes_queue.empty())
		{
			TreeNode* current{ nodes_queue.front() };
			nodes_queue.pop();

			if (current == nullptr)
			{
				result.append(same_depth);
				same_depth.clear();
				if (!nodes_queue.empty())
				{
					nodes_queue.push(nullptr);
				}
			}
			else
			{
				same_depth.append(" " + to_string(current->val));
				if (current != empty)
				{
					nodes_queue.push(current->left != nullptr ? current->left : empty);
					nodes_queue.push(current->right != nullptr ? current->right : empty);
				}
			}
		}
		return result;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty())
		{
			return nullptr;
		}

		std::stringstream ss(data);
		std::istream_iterator<std::string> begin_str(ss), end_str;
		vector split_str(begin_str, end_str);

		vector<int> nodes_num;
		nodes_num.reserve(split_str.size());
		for (const auto& str : split_str)
		{
			nodes_num.emplace_back(std::stoi(str));
		}

		vector<TreeNode*> nodes_ptr(nodes_num.size(), nullptr);
		nodes_ptr[0] = new TreeNode{ nodes_num[0] };
		if (nodes_num[1] <= 1000)
		{
			nodes_ptr[1] = new TreeNode{ nodes_num[1] };
			nodes_ptr[0]->left = nodes_ptr[1];
		}
		if (nodes_num[2] <= 1000)
		{
			nodes_ptr[2] = new TreeNode{ nodes_num[2] };
			nodes_ptr[0]->right = nodes_ptr[2];
		}

		int total_num = static_cast<int>(nodes_num.size());
		if (total_num >= 3)
		{
			for (int i = 3; i < total_num; ++i)
			{
				if (nodes_num[i] <= 1000)
				{
					if (i % 2 == 1)
					{//
						int base_index = (i - 1) / 2;
						nodes_ptr[i] = new TreeNode{ nodes_num[i] };
						nodes_ptr[base_index]->left = nodes_ptr[i];
					}
					else
					{
						int base_index = (i - 2) / 2;
						nodes_ptr[i] = new TreeNode{ nodes_num[i] };
						nodes_ptr[base_index]->right = nodes_ptr[i];
					}
				}
			}
		}
		return nodes_ptr[0];
	}
};

int main()
{
	vector<TreeNode*> test_roots;
	test_roots.emplace_back(new TreeNode{ 3,
		new TreeNode{ 9 },
			new TreeNode{ 20,new TreeNode{ 15 }, new TreeNode{ 7 }} });

	test_roots.emplace_back(new TreeNode{ 1,
		new TreeNode{2, new TreeNode{4}, nullptr},
								new TreeNode{3, nullptr, new TreeNode{5}} });

	test_roots.emplace_back(new TreeNode{ -1,
		new TreeNode{-2},
		new TreeNode{3, new TreeNode{-4}, new TreeNode{-5}} });

	test_roots.emplace_back(nullptr);

	test_roots.emplace_back(new TreeNode{ 5 });

	test_roots.emplace_back(new TreeNode{ -3, nullptr, new TreeNode{1} });

	test_roots.emplace_back(new TreeNode{ 1, new TreeNode{2},
		new TreeNode{3, new TreeNode{4, new TreeNode{6}, new TreeNode{7}}, new TreeNode{5}} });

	Codec codec;
	for (size_t i = 0; i < test_roots.size(); ++i)
	{
		test("Test_" + std::to_string(i)) = [i, &codec, &test_roots]
		{ // 3 tests
			string got_str = codec.serialize(test_roots[i]);
			std::cout << got_str << "END\n\n";
			string repeat_str = codec.serialize(codec.deserialize(codec.serialize(test_roots[i])));
			expect(eq(got_str, repeat_str));
		};
	}
}