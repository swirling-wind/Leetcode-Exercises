#include <common_headers.h>

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		const int total_num{ static_cast<int>(s.size()) };

		int longest_length{ 0 };
		int distinct_num{ 0 };
		vector<int> no_repeat_map(128, 0);

		for (int left = 0, right = 0; right < total_num; ++right)
		{
			++no_repeat_map[s[right]]; //Just load this current char

			if (no_repeat_map[s[right]] == 1)
			{// Lucky! it's a brand-new char. Now record it as distinct.
				longest_length = max(right - left + 1, longest_length);
				++distinct_num;
			}
			else
			{// Sadly... it's a repeated char and needs to shrink
				while (distinct_num < right - left + 1)
				{
					if (no_repeat_map[s[left]] == 1)
					{ // Terribly, when shrinking, we meet a distinct char and have no choice but to dispose it
						--distinct_num;
					}
					--no_repeat_map[s[left]];
					++left;
				}
			}
		}
		return longest_length;

	}
};
//					cout << "[REPEAT: "<< s[right] << "] left/right: [" << left << " : " << right << "], Length: " << right - left + 1 << ", Distinct: "
//						 << distinct_num << ", Longest: " << longest_length << "\n";

//					cout << "\t1. MOVE LEFT: "<< s[left] << "] left/right: [" << left << " : " << right << "], Length: " << right - left + 1 << ", Distinct: "
//						 << distinct_num << ", Longest: " << longest_length << "\n";

int main()
{
	Solution solution;
	expect(3_i == solution.lengthOfLongestSubstring("abcabcbb"));
	expect(1_i == solution.lengthOfLongestSubstring("bbbbb"));
	expect(1_i == solution.lengthOfLongestSubstring("b"));
	expect(0_i == solution.lengthOfLongestSubstring(""));
	expect(3_i == solution.lengthOfLongestSubstring("pwwkew"));
	expect(2_i == solution.lengthOfLongestSubstring("pwwew"));
	expect(3_i == solution.lengthOfLongestSubstring("abcabcabcabc"));
	expect(3_i == solution.lengthOfLongestSubstring("wwwwwllkwwwwwlwpwwwew"));

}