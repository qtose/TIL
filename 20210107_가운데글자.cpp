#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12903

string solution(string s) {
	string answer = "";

	int iLength = s.length();

	int iIndex = iLength / 2;

	if (iLength % 2 == 1)  {
		answer = s[iIndex];
	}

	else {
		answer = s[iIndex - 1];
		answer += s[iIndex];
	}

	return answer;
}

int main() {
	solution("qwer");

	return 0;
}