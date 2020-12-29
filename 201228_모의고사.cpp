#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42840?language=cpp

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int iSize = answers.size();

	int iNum1 = 0, iNum2 = 0, iNum3 = 3;
	bool bIs2 = true;
	int iNum2Cnt = 0;
	int iNum3Cnt = 0;

	int iCorrect1 = 0, iCorrect2 = 0, iCorrect3 = 0;

	for (int i = 0; i < iSize; i++) {
		//Num1: 1 2 3 4 5
		++iNum1;
		if (5 < iNum1)
			iNum1 = 1;

		if (iNum1 == answers[i])
			++iCorrect1;

		//Num2: 2 1 2 3 2 4 2 5
		if (true == bIs2)
			iNum2Cnt = 2;

		else {
			++iNum2;

			if (2 == iNum2)
				++iNum2;

			if (5 < iNum2)
				iNum2 = 1;

			iNum2Cnt = iNum2;
		}

		bIs2 = !bIs2;
		if (iNum2Cnt == answers[i])
			++iCorrect2;

		//Num3: 3 3 1 1 2 2 4 4 5 5
		if (iNum3Cnt <= 1) {
			++iNum3Cnt;
		}

		else {
			iNum3Cnt = 0;

			switch (iNum3) {
			case 1:
				iNum3 = 2;
				break;
			case 2:
				iNum3 = 4;
				break;
			case 3:
				iNum3 = 1;
				break;
			case 4:
				iNum3 = 5;
				break;
			case 5:
				iNum3 = 3;
				break;
			}

			++iNum3Cnt;
		}

		if (iNum3 == answers[i])
			++iCorrect3;
	}

	//맞춘 수와 번호를 pair로 보관
	vector<pair<int, int>> vecSort;
	vecSort.push_back(make_pair(iCorrect3, 3));
	vecSort.push_back(make_pair(iCorrect2, 2));
	vecSort.push_back(make_pair(iCorrect1, 1));

	//맞춘 수 대로 내림차순, 맞춘 수가 서로 같으면 번호 오름차순
	sort(vecSort.begin(), vecSort.end(), [](pair<int, int> Pair1, pair<int, int> Pair2)
	{
		if (Pair1.first == Pair2.first)
			return Pair1.second < Pair2.second;

		else
			return Pair1.first > Pair2.first;
	});

	//가장 많이 맞춘 수
	int iMax = vecSort.front().first;
	
	// 가장 많이 맞춘 수의 번호를 배열에 담음
	for (auto& Pair : vecSort) {
		if (iMax == Pair.first)
			answer.push_back(Pair.second);
	}

	return answer;
}

int main() {
	//vector<int> answers = { 1, 2, 3, 4, 5 };
	//vector<int> answers = { 1, 3, 2, 4, 2 };

	vector<int> answers = { 1, 3, 2, 4, 2, 1, 2, 3, 5, 4, 2, 1, 3, 3, 1, 1, 3, 5, 2, 1, 1, 4, 4, 5, 2 };

	solution(answers);

	return 0;
}
