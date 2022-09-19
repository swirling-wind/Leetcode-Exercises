#include <common_headers.h>

class Solution {
public:
	int maxArea(vector<int>&& height) {
		int i{ 0 }, j{ static_cast<int>(height.size()) - 1 };
		int area{ 0 };
		// scope range: [i, j]
		while (i < j)
		{
			if (height[i] < height[j])
			{
				area = max(area, (j - i) * height[i]);
				++i;
			}
			else
			{
				area = max(area, (j - i) * height[j]);
				--j;
			}
		}
		return area;
	}
};

int main()
{
	Solution solution;
	expect(eq(49, solution.maxArea({ 1,8,6,2,5,4,8,3,7 })));
	expect(eq(49, solution.maxArea({ 8,6,2,5,4,8,3,7 })));
	expect(eq(49, solution.maxArea({ 1,8,6,2,5,4,8,3,7,1 })));
	expect(eq(998, solution.maxArea({ 1, 999,998,6,2,5,4,8,3,7,1 })));
	expect(eq(998, solution.maxArea({ 7, 4,16, 3, 998,999,6,2,5,4,8,3,7,1 })));
	expect(eq(1200, solution.maxArea({ 100,999,998, 4, 3,6,2,5,4,8,3,7,100,8 })));
	expect(eq(1200, solution.maxArea({ 100,110, 4,110, 3,6,2,5,4,8,3,7,100,8 })));
	expect(eq(1, solution.maxArea({ 1,1 })));
	expect(eq(5, solution.maxArea({ 1,1,1,1,1,1 })));
	expect(eq(24, solution.maxArea({ 8,8,8,8,3,3,3 })));
	expect(eq(24, solution.maxArea({ 3,3,3,8,8,8,8,1 })));
}