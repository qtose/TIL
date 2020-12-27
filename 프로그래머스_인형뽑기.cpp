#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/64061

//세로 행 row
//가로 열 column


//board[] : 행
//board[][] : 원소
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	vector<int> vecResult;

	//moves로 board의 열을 순회
	for (auto& Elem : moves) {
		int iSize = board.size();
		for (int i = 0; i < iSize; i++) {
			if (0 != board[i][Elem - 1]) {
				vecResult.push_back(board[i][Elem - 1]);
				board[i][Elem - 1] = 0;
				break;
			}
		}
	}

	bool bIsFin = false;

	while (!bIsFin) {
	int iSize = vecResult.size();
	bIsFin = true;
		for (int i = 0; i < iSize - 1; i++) {
			if (vecResult[i] == vecResult[i + 1]) {
				auto& iter = vecResult.begin();
				vector<int>::iterator iter = vecResult.begin();
				iter += i;
				iter = vecResult.erase(iter);
				iter = vecResult.erase(iter);
				answer += 2;
				bIsFin = false;
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	int answer = solution(board, moves);

	cout << answer << endl;
}
