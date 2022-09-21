// ReSharper disable CppUseRangeAlgorithm
#include <common_headers.h>

class Solution {
public:
	//int findLength(vector<int>&& A, vector<int>&& B) {
	//	int m = size(A), n = size(B), ans = 0;
	//	for (int i = 0; i < m; i++) {
	//		for (int j = 0; j < n; j++) {
	//			int len = 0;
	//			while (i + len < m and j + len < n and A[i + len] == B[j + len]) 
	//				len++; // get length of longest common subarray starting at A[i] & B[j]
	//			ans = max(ans, len);  // update ans to hold max length found till now
	//		}
	//	}
	//	return ans;
	//}

	int findLength(vector<int>&& nums1, vector<int>&& nums2) {
		if (nums1.size() < nums2.size())
		{
			std::swap(nums1, nums2);
		}

		const int total_nums1{ static_cast<int>(nums1.size()) };
		const int total_nums2{ static_cast<int>(nums2.size()) };
		int result = 0;
		int dp[1001]{ 0 }, prev_dp[1001]{ 0 };

		for (int left = 0; left < total_nums1; ++left)
		{
			for (int right = 0; right < total_nums2; ++right)
			{
				if (nums1[left] == nums2[right])
				{
					dp[right+1] = prev_dp[right] + 1;
				}
				else
				{
					dp[right+1] = 0;
				}
				result = max(result, dp[right+1]);
			}
			std::swap(dp, prev_dp);
		}
		return result;
	}
};

int main()
{
	Solution solution;
	expect(eq(3, solution.findLength(vector{ 1,2,3,2,1 }, vector{ 3,2,1,4,7 })));
	expect(eq(2, solution.findLength(vector{ 9,2,3,2,8 }, vector{ 3,2,1,4,7 })));
	expect(eq(4, solution.findLength(vector{ 43,1,2,3,1,2,1 }, vector{ 8,9,3,1,2,1,4,7 })));

}