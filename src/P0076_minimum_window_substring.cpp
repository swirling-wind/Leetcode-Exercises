#include <common_headers.h>

class Solution
{
public:
	string minWindow(string s, string t)
	{
		vector<int> map_for_char(128, 0);
		for (auto ch : t)
		{
			++map_for_char[ch];
		}

		const int total_num{ static_cast<int>(s.size()) };
		int remain_char_num{ static_cast<int>(t.size()) };
		int left{ 0 }, right{ 0 };

		int str_head{ 0 }, str_length{ numeric_limits<int>::max() };

		while (right < total_num)
		{
			//move right
			if (map_for_char[s[right]] > 0)
			{
				--remain_char_num;
			}
			--map_for_char[s[right]];

			// try to move left, after moving right
			while (remain_char_num == 0)
			{
				//adjust str
				if (right - left + 1 < str_length)
				{
					str_head = left;
					str_length = right - left + 1;
				}

				// move left
				{
					++map_for_char[s[left]];
					if (map_for_char[s[left]] > 0)
					{// if this char belongs to "t"
						++remain_char_num;
					}
					++left;
				}
			}
			++right;
		}
		return str_length == numeric_limits<int>::max() ? "" : s.substr(str_head, str_length);
	}
};

class TimeExceedSolution
{
public:
	[[maybe_unused]]string minWindow([[maybe_unused]]string s, [[maybe_unused]]string t)
	{
		const int total_num = static_cast<int>(s.size());
		const int sub_num = static_cast<int>(t.size());
		using ch_position = int;

		auto contains = [](const auto& trunk, auto sub) -> ch_position
		{
		  auto location = std::find(trunk.begin(), trunk.end(), sub);
		  if (location != trunk.end())
		  {
			  return location - trunk.begin();
		  }
		  return -1;
		};

		vector<ch_position> is_covered(sub_num, -1);
		auto get_earliest_same_target =
			[&is_covered, &t, &sub_num](ch_position first_position, const char target) -> ch_position
			{
			  ch_position earliest_pos{ first_position };
			  for (ch_position i = first_position; i < sub_num; ++i)
			  {//loop throught t & is_covered
				  if (t[i] == target && is_covered[i] < is_covered[earliest_pos])
				  {//same char && earlier is_covered[].value
					  earliest_pos = i;
				  }
			  }
			  return earliest_pos;
			};

		ch_position left{ -3 };
		ch_position right{ total_num + 1 };
		for (ch_position i = 0; i < total_num; ++i)
		{
			ch_position first_found = contains(t, s[i]);
			//对于s，每步进一格，①寻找是否在t中有对应char
			if (first_found >= 0)
			{// 若有，则找出最“earliest”的未更新字符所对应的映射位置，进行更新
				is_covered[get_earliest_same_target(first_found, s[i])] = i;

				ch_position current_left{ *std::min_element(is_covered.begin(), is_covered.end()) };
				ch_position current_right{ *std::max_element(is_covered.begin(), is_covered.end()) };
				if (left < 0 || current_right - current_left < right - left)
				{
					left = current_left;
					right = current_right;
				}
			}
		}

		if (left < 0)
		{
			return "";
		}

		return s.substr(left, right - left + 1);
	}
};

int main()
{
	Solution solution;

	expect(string("BANC") == solution.minWindow(string("ADOBECODEBANC"), string("ABC")));
	expect(string("a") == solution.minWindow(string("a"), string("a")));
	expect(string("") == solution.minWindow(string("a"), string("aa")));
	expect(string("") == solution.minWindow(string("ba"), string("aa")));
	expect(string("BAC") == solution.minWindow(string("ABECXYZACUJTIBAC"), string("ABC")));
	expect(string("AIUHINBUINJKC") == solution.minWindow(string("UUAIUHINBUINJKC*&YH"), string("ABC")));
	expect(string("ba") == solution.minWindow(string("bba"), string("ab")));
	expect(string("AB") == solution.minWindow(string("AAAAABBBBBBBBB"), string("BA")));
	expect(string("ABBBC") == solution.minWindow(string("AAAAABBBCCBBBBBBBB"), string("BAC")));
	expect(string("aaa") == solution.minWindow(string("aaflslflsldkalskaaa"), string("aaa")));
	expect(string("acb") == solution.minWindow(string("abflslflslcdkalskacb"), string("abc")));

}

