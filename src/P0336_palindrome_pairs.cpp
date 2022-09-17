#include <common_headers.h>

class Solution {
	bool static isPalindrome(const string& str, int i, int j) {
		while (i < j && str[i] == str[j]) ++i, --j;
		return i >= j;
	}

	struct Trie {
		Trie* next[26] = { nullptr };
		int end_index = -1;
		vector<int> palindromeIndexes;

		void insert(string& s, int i) {
			Trie* node = this;
			for (int j = s.size() - 1; j >= 0; --j) {
				if (isPalindrome(s, 0, j)) node->palindromeIndexes.push_back(i); // A[i]'s prefix forms a palindrome
				int c = s[j] - 'a';
				if (!node->next[c]) node->next[c] = new Trie();
				node = node->next[c];
			}
			node->end_index = i;
			node->palindromeIndexes.push_back(i); // A[i]'s prefix is empty string here, which is a palindrome.
		}

	};



public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		Trie* const root = new Trie;
		const int word_num = static_cast<int>(words.size());
		for (int i = 0; i < word_num; ++i) 
			root->insert(words[i], i);

		vector<vector<int>> result;

		for (int i = 0; i < word_num; ++i) {
			auto s = words[i];
			Trie* node = root;
			for (int j = 0; j < s.size() && node; ++j) {
				if (node->end_index != -1 && node->end_index != i && isPalindrome(s, j, s.size() - 1)) result.push_back({ i, node->end_index });
				// words[i]'s prefix matches this word and words[i]'s suffix forms a palindrome
				node = node->next[s[j] - 'a'];
			}
			if (!node) continue;
			for (int j : node->palindromeIndexes) {
				// words[i] is exhausted in the matching above. 
				// If a word whose prefix is palindrome after matching its suffix with words[i], 
				// then this is also a valid pair
				if (i != j) result.push_back({ i, j });
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
	vector<vector<int>> answer_0 = solution.palindromePairs(test_0);
	expect(eq(answer_0.size(), expect_0.size()) >> fatal);
	for (const auto elem : expect_0)
	{
		expect(std::ranges::find(answer_0, elem) != answer_0.end());
	}
}