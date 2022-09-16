#include <common_headers.h>

class Solution
{
public:
	int dp[101][101]{};
	bool has_cal[101][101]{ {false} };
	int maximumScore(vector<int>& nums, vector<int>& multipliers)
	{
		return score_helper(0, 0, nums, multipliers);
	}

	int score_helper(int left, int length, vector<int>& nums, vector<int>& multipliers)
	{
		if (length == multipliers.size())
		{
			return 0;
		}
		if (has_cal[left][length])
		{
			return dp[left][length];
		}
		has_cal[left][length] = true;
		int right = left + nums.size() - 1 - length;
		dp[left][length] = max(
			nums[left] * multipliers[length] + score_helper(left + 1, length + 1, nums, multipliers),
			nums[right] * multipliers[length] + score_helper(left, length + 1, nums, multipliers)
		);
		return dp[left][length];
	}
};

int main()
{
	Solution solution;
	{
		vector nums_1{ 1,2,3 };
		vector mult_1{ 3,2,1 };
		expect(eq(14, solution.maximumScore(nums_1, mult_1)));
	}
	{
		Solution solution;
		vector nums_1{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		vector mult_1{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		expect(eq(-1, solution.maximumScore(nums_1, mult_1)));
	}
}