#include <common_headers.h>

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> result;
        unordered_map<int, int> record;
        int total_length = static_cast<int>(changed.size());
        for (int i = 0; i < total_length; ++i)
        {
            int current = changed[i];
            if (current % 2 == 1 || record[current] == 0)
            {
                record[current * 2]++;
            }
            else
            {
                result.emplace_back(current / 2);
                record[current]--;
            }
        }

        if (result.size() < total_length / 2 || total_length % 2 == 1)
        {
            return {};
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector input{ 0,0,3 };
    auto output = solution.findOriginalArray(input);
    for (auto item : output)
    {
        cout << item << " ";
    }
}