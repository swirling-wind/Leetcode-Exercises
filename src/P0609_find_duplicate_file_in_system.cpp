#include <common_headers.h>

class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>&& paths) {

		unordered_map<string, vector<string>> records;
		for (const auto& path : paths) 
		{
			stringstream ss(path);
			string folder_root;
			getline(ss, folder_root, ' ');

			string str;
			while (getline(ss, str, ' ')) 
			{
				const auto next_bracket = str.find('(');
				string file_name = folder_root + '/' + str.substr(0, next_bracket);
				string file_content = str.substr(next_bracket + 1, str.find(')') - next_bracket - 1);
				records[file_content].push_back(file_name);
			}
		}

		vector<vector<string>> result;
		for (const auto& file : records) {
			if (file.second.size() > 1)
				result.push_back(file.second);
		}
		return result;
	}
};


int main()
{
	Solution solution;
	vector <vector< string >> ans{ {"root/a/2.txt","root/c/d/4.txt","root/4.txt"},{"root/a/1.txt","root/c/3.txt"} };
	auto output = solution.findDuplicate({ "root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)" });
	expect(eq(ans.size(), output.size()) >> fatal);
	for (auto item : output)
		expect(std::find(ans.begin(), ans.end(), item) != ans.end());

}