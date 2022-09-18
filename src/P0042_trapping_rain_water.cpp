#include <common_headers.h>

class Solution {
public:
	using index = int;
	int get_section_volume(const vector<int>& height, const int top_level, const index left, const index right)
	{
		int current_volume{ 0 };
		for (index i = left + 1; i < right; ++i)
		{
			current_volume += top_level - height[i];
		}
		return current_volume;
	}

	int fill_section_and_get_volume(vector<int>& height, const int top_level, const index left, const index right)
	{
		int current_volume{ 0 };
		for (index i = left + 1; i < right; ++i)
		{
			if (top_level > height[i])
			{
				current_volume += top_level - height[i];
				height[i] = top_level;
			}
		}
		return current_volume;
	}

	int trap(vector<int>&& height) {
		int result{ 0 };
		int puddle_height{numeric_limits<int>::max()};

		index current_max{ 0 };
		const index total_length = static_cast<index>(height.size());
		for (index i = 1; i < total_length; ++i)
		{
			if (height[i] >= height[current_max])
			{
				if (i - current_max > 1)
				{
					result += get_section_volume(height, min(height[current_max], height[i]), current_max, i);
				}
				current_max = i;
			}
			else
			{// this height < height[current_max]
				if (height[i] > puddle_height)
				{
					puddle_height = min(height[current_max], height[i]);
					result += fill_section_and_get_volume(height, puddle_height, current_max, i);
				}
				else
				{
					puddle_height = height[i];
				}
			}
		}
		return result;
	}
};


int main()
{
	Solution solution;
	expect(eq(5, solution.trap({ 0,1,0,2,1,0,1,3 })));
	expect(eq(6, solution.trap({ 0,1,0,2,1,0,1,3,2,1,2,1 })));
	expect(eq(9, solution.trap({ 4,2,0,3,2,5 })));
	expect(eq(5, solution.trap({ 4,2,0,3,2,3 })));
	expect(eq(5, solution.trap({ 4,2,0,3,2,3,2,1,0 })));
	expect(eq(1, solution.trap({ 4,2,3})));
	expect(eq(1, solution.trap({ 5,4,1,2})));
	expect(eq(13, solution.trap({ 5,4,1,2,1,6,3,2,3})));
	expect(eq(16, solution.trap({ 1,1,1,4,2,3,4,4,5,5,4,1,2,1,6,3,2,3})));
	expect(eq(7, solution.trap({ 0,7,1,4,6})));

}