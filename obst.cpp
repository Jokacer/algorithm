#include<iostream>
#include<array>
#include<vector>
using namespace std;
int d=0;
void left(int[][5], vector<int>, int);
void right(int[][5], vector<int>, int);
int main() {
	int root[5][5] = { 0 };
	vector<int >arr = { 1,2,3,4,5 };
	for (int i = 0; i < 5; ++i) {
		for (int j = i; j < 5; ++j) {
			cin >> root[i][j];
		}
	}
	cout << "k" << root[0][4] <<" 为根"<< endl;
	left(root, vector<int>(arr.begin(), find(arr.begin(), arr.end(), root[0][4])),root[0][4]);
	right(root, vector<int>(find(arr.begin(), arr.end(), root[0][4]) + 1, arr.end()), root[0][4]);
	system("pause");
	return 0;
 }
void left(int root[5][5], vector<int>arr, int rot) {
	if (arr.size()) {
		cout << "k" << root[arr[0] - 1][arr[arr.size() - 1] - 1] << " 是 k" << rot << " 的左孩子" << endl;
		left(root, vector<int>(arr.begin(), find(arr.begin(), arr.end(), root[arr[0] - 1][arr[arr.size() - 1] - 1])), root[arr[0] - 1][arr[arr.size() - 1] - 1]);
		right(root, vector<int>(find(arr.begin(), arr.end(), root[arr[0] - 1][arr[arr.size() - 1] - 1]) + 1, arr.end()), root[arr[0] - 1][arr[arr.size() - 1] - 1]);
	}
	else {
		cout << "d" << d++ <<" 是 k"<< rot <<" 的左孩子"<< endl;
	}
}
void right(int root[5][5], vector<int>arr, int rot) {
	if (arr.size()) {
		cout << "k" << root[arr[0] - 1][arr[arr.size() - 1]-1] << " 是 k" << rot << " 的右孩子" << endl;
		left(root, vector<int>(arr.begin(), find(arr.begin(), arr.end(), root[arr[0]-1][arr[arr.size() - 1] - 1])), root[arr[0] - 1][arr[arr.size() - 1] - 1]);
		right(root, vector<int>(find(arr.begin(), arr.end(), root[arr[0] - 1][arr[arr.size() - 1] - 1]) + 1, arr.end()), root[arr[0] - 1][arr[arr.size() - 1] - 1]);
	}
	else {
		cout << "d" << d++ <<" 是 k"<< rot <<" 的右孩子"<< endl;
	}
}
/*
1 1 2 2 2
2 2 2 4
3 4 5
4 5
5
*/