#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12915

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;

	map<string, vector<string>> mapStr;

	string strfind = "";

	for (auto& word : strings) 
	{
		strfind = word[n];
		auto iter = mapStr.find(strfind);

		if (iter == mapStr.end()) {
			vector<string> v;
			v.push_back(word);
			mapStr.emplace(strfind, v);
		}

		else {
			(*iter).second.push_back(word);
		}
	}

	for (auto& Pair : mapStr) {
		sort(Pair.second.begin(), Pair.second.end());
		
		for (auto& word : Pair.second)
			answer.push_back(word);
	}


	//완전 충격....
	//int i;
	//
	//bool compare(string a, string b) {
	//	return a[i] == b[i] ? a < b : a[i] < b[i];
	//}
	//
	//vector<string> solution(vector<string> strings, int n) {
	//	i = n;
	//	sort(strings.begin(), strings.end(), compare);
	//	return strings;
	//}

	return answer;
}

int main() {
	vector<string> v = { "sun", "bed", "car" };

	solution(v, 1);

	return 0;
}