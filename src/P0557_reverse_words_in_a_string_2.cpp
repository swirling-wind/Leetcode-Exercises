#include <common_headers.h>

class Solution {
public:
	string reverseWords(const string& s) {
		std::ios::sync_with_stdio(false);
		istringstream in(s);
		ostringstream out;
		string current_val;

		while (true) {
			in >> current_val;
			for (int i = current_val.size() - 1; i >= 0; --i)
			{
				out << current_val[i];
			}
			if (in.eof())
			{
				break;
			}
			out << " ";
		}
		return out.str();
	}
};

int main()
{
	Solution solution;
	cout << solution.reverseWords("Let's take LeetCode contest");
	cout <<"\n" << solution.reverseWords("God Ding");
}