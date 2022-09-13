#include <common_headers.h>

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		using num_t = int;
		using index_t = int;
		std::unordered_map<num_t, index_t> table;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (table.find(target - nums[i]) != table.end())
			{
				return { table[target - nums[i]], static_cast<int>(i) }; // WARN: shrink
			}
			table[nums[i]] = i;
		}
		std::vector<int> v;
		return v;

	}
};


int main()
{
	Solution solution;

	vector test_1 {2,7,11,15};
	expect(vector{0,1} == solution.twoSum(test_1, 9));

	vector test_2{3,2,4};
	expect(vector{1,2} == solution.twoSum(test_2, 6));

	vector test_3{3,3};
	expect(vector{0,1} == solution.twoSum(test_3, 6));
}
