#include <iostream>

int main()
{
	std::cout << __clang_major__;

	vector<vector<int>> testor;
	testor.push({ 1,6 });
	testor.emplace_back(1, 6);


}