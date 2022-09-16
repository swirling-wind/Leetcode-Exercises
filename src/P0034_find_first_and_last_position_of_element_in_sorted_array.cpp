#include <common_headers.h>

class Solution {
public:


	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = static_cast<int>(nums.size()) - 1;
		vector scope(2, -1);
		if (nums.empty())
		{
			return scope;
		}

		while (left < right) 
		{ // find the lower bound
			int divide = (left + right) / 2;

			if (nums[divide] < target)
			{
				left = divide + 1;
			}
			else // if (target <= nums[divide])
			{
				right = divide;
			}
		}

		if (nums[left] != target)
		{
			return scope;
		}
		scope[0] = left;

		right = static_cast<int>(nums.size()) - 1;
		while (left < right)
		{
			int divide = (left + right + 1) / 2;
			if (nums[divide] <= target)
			{
				left = divide;
			}
			else // if (target < nums[divide])
			{
				right = divide - 1;
			}
		}
		scope[1] = right;
		return scope;
	}
};

int main()
{
	Solution solution;

	vector test_0{ 5,7,7,8,8,10 };
	expect(eq(vector{ 3,4 }, solution.searchRange(test_0, 8)));


	vector test_1{ 5,7,7,8,8,8 };
	expect(eq(vector{ 3,5 }, solution.searchRange(test_1, 8)));

	vector<int> test_2;
	expect(eq(vector{ -1,-1 }, solution.searchRange(test_2, 0)));
}