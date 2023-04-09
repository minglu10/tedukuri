#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
std::string GetTree(const std::string& s) {
	int level = 0;
	int start = 0;
	std::vector<std::string> treestrings;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {
			++level;
		}
		else {
			--level;
		}
		if (level == 0) {
			if (i - 1 > start + 1) {
				treestrings.push_back("0" + GetTree(s.substr(start + 1, i - start - 1)) + "1");
			}
			else {
				treestrings.push_back("01");
			}
			start = i + 1;
		}
	}
	std::sort(treestrings.begin(), treestrings.end());
	std::string ret = "";
	for (int i = 0; i < treestrings.size(); ++i) {
		ret += treestrings[i];
	}
	return ret;
}

int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::string s1;
		std::cin >> s1;
		std::string s2;
		std::cin >> s2;
		auto s1_tree = GetTree(s1);
		auto s2_tree = GetTree(s2);
		if (s1_tree == s2_tree) {
			std::cout << "same" << std::endl;
		}
		else {
			std::cout << "different" << std::endl;
		}

	}


}