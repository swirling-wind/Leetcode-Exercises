#include <common_headers.h>

class Solution {
public:
	int maxArea(vector<int>&& height) {
		const int rightest{ static_cast<int>(height.size()) - 1 };
		int best_i{ 0 }, best_j{ rightest };
		int best_area{ 0 };
		// scope range: [i, j]
		for (int i = 0; i < rightest; ++i)
		{
			if (height[i] > height[best_i] || i == best_i)
			{
				for (int j = rightest; j > 0; --j)
				{
					cout << i << ":" << j << " -- "   << best_area << " -- " << best_i << ":" << best_j << "\n";

					if (height[j] > height[best_j] || j == best_j)
					{
						const int current_area = (j - i) * min(height[i], height[j]);
						//cout << i << ":" << j << " -- " << current_area << " | " << best_area << " -- " << best_i << ":" << best_j << "\n";

						if (current_area > best_area)
						{
							best_area = current_area;
							best_i = i;
							best_j = j;
						}
					}
					cout << i << ":" << j << " -- "  << best_area << " -- " << best_i << ":" << best_j << "\n\n";

				}
			}
		}
		return best_area;
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
}