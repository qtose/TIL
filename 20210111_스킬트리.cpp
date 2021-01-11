#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	vector<char> vecSkill;

	for (size_t i = 0; i < skill.size(); ++i)
		vecSkill.push_back(skill[i]);

	for (auto& user : skill_trees) {
		int iIndex = 0;
		bool bCheck = false;
		
		for (size_t i = 0; i < user.size(); ++i) {
			for (size_t j = 0; j < vecSkill.size(); ++j) {
				if (user[i] == vecSkill[j]) {
					if (j > iIndex) {
						bCheck = true;
						break;
					}
					else
						++iIndex;
				}
			}
			
			if (bCheck == true)
				break;
		}

		if (bCheck == false)
			++answer;
	}

	return answer;
}

int main() {
	vector<string> v = { "BACDE", "CBADF", "AECB", "BDA" };

	solution("CBD", v);

	return 0;
}