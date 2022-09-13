#include <common_headers.h>

class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		for (size_t i = 1; i < nums.size(); ++i)
		{
			nums[i] += nums[i - 1];
		}
		return nums;
	}
};

int main()
{
	Solution solution;

	vector test_1 {1,2,3,4};
	expect(vector{1,3,6,10} == solution.runningSum(test_1));

	vector test_2 {1,1,1,1,1};
	expect(vector{1,2,3,4,5} == solution.runningSum(test_2));

	vector test_3 {3,1,2,10,1};
	expect(vector{3,4,6,16,17} == solution.runningSum(test_3));
}

