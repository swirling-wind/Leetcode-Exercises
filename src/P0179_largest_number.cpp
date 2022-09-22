#include <common_headers.h>
class Solution {
	[[nodiscard]] constexpr bool less_comp(const string& lhs, const string& rhs) const
	{
		const int min_size = min(static_cast<int>(lhs.size()), static_cast<int>(rhs.size()));
		for (int i = 0; i < min_size; ++i)
		{
			if (lhs[i] < rhs[i])
			{
				return true;
			}
			if (lhs[i] > rhs[i])
			{
				return false;
			}
		}
		if (lhs.size() > rhs.size())
		{
			return less_comp(lhs.substr(rhs.size(), lhs.size() - rhs.size()), rhs);
		}
		if (lhs.size() < rhs.size())
		{
			return less_comp(lhs, rhs.substr(lhs.size(), rhs.size() - lhs.size()));
		}
		return true;
	}

	int partition(vector<string>& arr, const int low, const int high)
	{
		const string pivot = arr[high];
		int i = low - 1; //smaller element index
		for (int j = low; j < high; j++) {
			if (less_comp(pivot, arr[j]))
			{
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]);
		return i + 1;
	}

	void quickSort(vector<string>& arr, const int low, const int high)
	{
		if (low < high) {
			const int pi = partition(arr, low, high);
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
public:
	string largestNumber(const vector<int>& nums) {
		vector<string> str_list;
		str_list.reserve(nums.size());
		for (const auto val : nums)
		{
			str_list.emplace_back(to_string(val));
		}

		quickSort(str_list, 0, str_list.size() - 1);

		if (stoi(str_list[0]) == 0)
		{
			return "0";
		}

		ostringstream out;
		for (const auto& item : str_list)
		{
			out << item;
		}
		return out.str();
	}
};
int main()
{
	Solution solution;
	expect(eq(string("210"), solution.largestNumber({ 10,2 })));
	expect(eq(string("9534330"), solution.largestNumber({ 3,30,34,5,9 })));
	expect(eq(string("53533531"), solution.largestNumber({ 53,531,533 })));
	expect(eq(string("43243432"), solution.largestNumber({ 432,43243 })));
	expect(eq(string("83088308830"), solution.largestNumber({ 8308,8308,830 })));
	expect(eq(string("343234323"), solution.largestNumber({ 34323,3432})));
}