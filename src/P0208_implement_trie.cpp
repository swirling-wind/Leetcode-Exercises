#include <common_headers.h>

class Trie {
#ifndef ALPHABET_SIZE
#define ALPHABET_SIZE 26
	Trie* children_[ALPHABET_SIZE]{ nullptr };
	bool is_end_of_word_{ false };
#endif
public:
	Trie() = default;

	void insert(string word) {
		Trie* current = this;
		for (const char i : word)
		{
			int offset = i - 'a';
			if (current->children_[offset] == nullptr)
			{
				current->children_[offset] = new Trie;
			}
			current = current->children_[offset];
		}
		current->is_end_of_word_ = true;
	}

	bool search(string word) {
		Trie* current = this;
		for (const char i : word)
		{
			int offset = i - 'a';
			if (current->children_[offset] == nullptr)
			{
				return false;
			}
			current = current->children_[offset];
		}
		return current->is_end_of_word_;
	}

	bool startsWith(string prefix) {
		Trie* current = this;
		for (const char i : prefix)
		{
			int offset = i - 'a';
			if (current->children_[offset] == nullptr)
			{
				return false;
			}
			current = current->children_[offset];
		}
		return true;
	}
};

int main()
{
	Trie* trie = new Trie();
	trie->insert("apple");
	expect(trie->search("apple"));   // return True
	expect(!trie->search("app"));     // return False
	expect(trie->startsWith("app")); // return True
	trie->insert("app");
	expect(trie->search("app"));     // return True

}