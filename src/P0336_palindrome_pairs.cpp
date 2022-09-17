#include <common_headers.h>

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {

    }
};

int main()
{
    Solution solution;
    vector<string> test_0{ "abcd", "dcba", "lls", "s", "sssll" };
    expect(eq(vector<vector<int>>{ {0, 1}, { 1,0 }, { 3,2 }, { 2,4 }}, solution.palindromePairs(test_0)));


}