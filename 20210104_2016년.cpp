#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12901

string solution(int a, int b) {
	string answer = "";
	
	vector<int> v = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	int iDay = 0;
	
	for (int i = 0; i < a - 1; ++i)
		iDay += v[i];

	iDay += b;

	int iWeek = iDay % 7;

	//1¿ù 1ÀÏ iWeek = 1 / case 1 = FRI
	switch (iWeek) {
	case 0:
		answer = "THU";
		break;
	case 1:
		answer = "FRI";
		break;
	case 2:
		answer = "SAT";
		break;
	case 3:
		answer = "SUN";
		break;
	case 4:
		answer = "MON";
		break;
	case 5:
		answer = "TUE";
		break;
	case 6:
		answer = "WED";
		break;
	}

	return answer;
}

int main() {

	solution(1, 1);

	return 0;
}
