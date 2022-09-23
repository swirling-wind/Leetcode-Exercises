#include <common_headers.h>

class Solution {
public:
	int concatenatedBinary(const int n) {
		constexpr int64_t mod = 1e9 + 7;
		int64_t result{ 0 };
		int64_t length{ 0 };
		for (int64_t i = 1; i <= n; ++i)
		{
			if ((i & (i - 1)) == 0)
				++length;

			result = ((result << length) % mod + i) % mod;
		}
		return static_cast<int>(result);
	}
};

int main()
{
	Solution solution;
	expect(eq(1, solution.concatenatedBinary(1)));
	expect(eq(27, solution.concatenatedBinary(3)));
	expect(eq(505379714, solution.concatenatedBinary(12)));

}