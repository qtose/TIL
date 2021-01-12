#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12917

string solution(string s) {
	string answer = "";

	vector<char> v;

	for (size_t i = 0; i < s.length(); ++i) 
	{
		v.push_back(s[i]);
	}
	
	sort(v.begin(), v.end(), [](char Src, char Dst)
	{
		return Src > Dst;
	});

	for (auto& ch : v) 
	{
		answer += ch;
	}
	
	
	//stringµµ µÈ´Ù....
	//sort(s.begin(), s.end(), greater<char>());
	//return s;

	return answer;
}

int main() {

	solution("Zbcdefg");

	return 0;
}