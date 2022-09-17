#include <common_headers.h>

class Solution {

	bool static is_palindrome(const string& word, int left, int right)
	{
		while (left < right)
			if (word[left++] != word[right++])
				return false;

		return true;
	}


	class Trie {
	public:
#define ALPHABET_SIZE 26
		Trie* next[ALPHABET_SIZE]{ nullptr };
		vector<int> palin_word;
		int word_end_index{ -1 };


		Trie() = default;

		void insert(const string& word, int word_index) {
			Trie* current = this;
			for (int i = word.size() - 1; i >= 0; --i)
			{
				int offset = word[i] - 'a';
				if (current->next[offset] == nullptr)
				{
					current->next[offset] = new Trie;
				}
				if (is_palindrome(word, 0, i))
				{
					current->palin_word.emplace_back(word_index);
				}
				current = current->next[offset];
			}
			current->palin_word.emplace_back(word_index);
			current->word_end_index = word_index;
		}
	};

public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		Trie* const root = new Trie;
		int total_length = static_cast<int>(words.size());
		for (int i = 0; i < total_length; ++i)
		{
			root->insert(words[i], i);
		}


		vector<vector<int>> result;
		for (int i = 0; i < total_length; ++i)
		{
			const string& present_str = words[i];
			Trie* node = root;
			for (int j = 0; j < present_str.size() && node != nullptr; ++j)
			{
				if (node->word_end_index != -1 &&
					node->word_end_index != i &&
					is_palindrome(present_str, j, present_str.size() - 1))
				{
					result.emplace_back(i, node->word_end_index);
				}
				node = node->next[present_str[j] - 'a'];
			}
			if (node == nullptr) continue;
			for (const int index : node->palin_word)
			{
				if (index != i)
				{
					result.emplace_back(i, index);
				}
			}
		}

		return result;
	}
};

int main()
{
	Solution solution;
	vector<string> test_0{ "abcd", "dcba", "lls", "s", "sssll" };
	vector<vector<int>> expect_0{ {0, 1}, { 1,0 }, { 3,2 }, { 2,4 } };
	auto answer_0 = solution.palindromePairs(test_0);
	expect(eq(answer_0.size(), expect_0.size()) >> fatal);
	for (size_t i = 0; i < expect_0.size(); ++i)
	{
		expect(eq(answer_0[i], expect_0[i]));
	}

}