#include <common_headers.h>

class Solution {
public:
	short dp[101][101]{};
	// -1: not checked yet
	//  0: not a palindromic
	//  1: is a palindromic
	short is_palindromic(const string& s, int x, int y)
	{
		if (dp[x][y] != -1)
		{
			return dp[x][y];
		}
		dp[x][y] = s[x] == s[y] && is_palindromic(s, x + 1, y - 1) == 1 ? 1 : 0;
		return dp[x][y];
	}

	string longestPalindrome(string s) {
		memset(dp, -1, sizeof dp);
		int total_length = static_cast<int>(s.size());
		for (int index = 0; index < total_length; ++index)
		{
			dp[index][index] = 1;
			dp[index + 1][index] = 1;
		}

		pair sub_index{0,0};
		for (int row = 0; row < total_length; ++row)
		{
			for (int col = row + 1; col < total_length; ++col)
			{
				if (is_palindromic(s, row, col) == 1 && col - row > sub_index.second - sub_index.first)
				{
					sub_index.first = row;
					sub_index.second = col;
				}
			}
		}
		return s.substr(sub_index.first, sub_index.second - sub_index.first + 1);
	}
};

int main()
{
	Solution solution;
	expect(eq(string{ "bab" }, solution.longestPalindrome("babad")) or eq(string{ "aba" }, solution.longestPalindrome("babad")));
	expect(eq(string{ "bb" }, solution.longestPalindrome("cbbd")));
	expect(eq(string{ "aasaa" }, solution.longestPalindrome("ctebaasaadf")));
	expect(eq(string{ "aasaa" }, solution.longestPalindrome("]8;d5$w9v2~3r%8v3s8+^z3t&|g[8*r9h2(dc56sctebaasaadf")));

}