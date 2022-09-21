#include <common_headers.h>
class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>&& nums, const vector<vector<int>>& queries)
	{
		vector<int> results;
		results.reserve(nums.size());
		int sum{ 0 };
		for (const auto value : nums)
		{
			if (value % 2 == 0)
			{
				sum += value;
			}
		}
		const int total_length = static_cast<int>(queries.size());
		for (const auto& item : queries)
		{
			if (item[0] % 2 == 0 && nums[item[1]] % 2 == 0)
			{
				sum += item[0];
				nums[item[1]] += item[0];
			}
			else if (item[0] % 2 != 0 && nums[item[1]] % 2 != 0)
			{
				nums[item[1]] += item[0];
				sum += nums[item[1]];
			}
			else if (item[0] % 2 != 0 && nums[item[1]] % 2 == 0)
			{
				sum -= nums[item[1]];
				nums[item[1]] += item[0];
			}
			else // if (item[0] % 2 == 0 && nums[item[1]] % 2 != 0)
			{
				nums[item[1]] += item[0];
			}
			results.push_back(sum);
		}
		return results;
	}
};
int main()
{
	Solution solution;
	expect(eq(vector{ 8,6,2,4 },
		solution.sumEvenAfterQueries(vector{ 1,2,3,4 },
			vector{ vector{1, 0}, vector{ -3,1 }, vector{ -4,0 }, vector{ 2,3 } }
	)));

	expect(eq(vector{ 0 },
		solution.sumEvenAfterQueries(vector{ 1 },
			vector<vector<int>>{ vector{ 4, 0 } }
	)));


}