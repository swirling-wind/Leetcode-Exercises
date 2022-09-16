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

	int score_helper(int left, int index, vector<int>& nums, vector<int>& multipliers)
	{
		if (index == multipliers.size())
		{
			return 0;
		}
		if (has_cal[left][index])
		{
			return dp[left][index];
		}
		has_cal[left][index] = true;
		int right = left + nums.size() - 1 - index;
		dp[left][index] = max(
			nums[left] * multipliers[index] + score_helper(left + 1, index + 1, nums, multipliers),
			nums[right] * multipliers[index] + score_helper(left, index + 1, nums, multipliers)
		);
		return dp[left][index];
	}
};

int main()
{
	Solution solution;
	{
		vector nums_1{ 1,2,3 };
		vector mult_1{ 3,2,1 };
		cout << solution.maximumScore(nums_1, mult_1) << "\n";
	}
	{
		Solution solution;
		vector nums_1{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		vector mult_1{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		cout << solution.maximumScore(nums_1, mult_1);
	}

}