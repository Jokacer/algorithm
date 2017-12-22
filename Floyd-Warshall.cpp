#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
void pathshow(int i, int j, vector<vector<int >>,vector<int>&);
void printpath(vector<int >);
int main() {
	vector<vector<int>>d;
	vector<vector<int>>pai;
	vector<int > path;
	int v, e;
	int select;
	int begin, end, w;
	cin >> v >> e;
	for (int i = 0; i < v; ++i) {
		d.push_back(vector<int>(v, 0));
		pai.push_back(vector<int>(v, 0));
		for (int j = 0; j < v; ++j) {
			if (i == j)d[i][j] = 0;
			else d[i][j] = 10000;//勉强代表∞吧
			pai[i][j] = -1;
		}
	}
	for (int i = 0; i < e; ++i) {
		cin >> begin >> end >> w;
		d[begin][end] = w;
		pai[begin][end] = begin;
	}
	for (int k = 0; k < v; ++k) {
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < v; ++j) {
				if (i != j) {
					select = d[i][k] + d[k][j];
					if (d[i][j] > select) {
						d[i][j] = select;
						pai[i][j] = pai[k][j];
					}
				}
			}
		}
	}
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			cout << setw(3) << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			cout << setw(3) << pai[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			if (i == j)continue;
			cout << "点" << i << "到点" << j << "最短路径为：";
			path.push_back(i);
			path.push_back(j);
			pathshow(i, j, pai, path);
			printpath(path);
			cout << "距离为:" << d[i][j] << endl;
			path.clear();
		}
	}
	system("pause");
	return 0;
}
void pathshow(int i, int j, vector<vector<int >> pai,vector<int>& path) {
	if (pai[i][j] == i) return;
	else {
		path.insert(path.begin() + 1, pai[i][j]);
		pathshow(i, pai[i][j], pai, path);
	}
}
void printpath(vector<int >path) {
	for (vector<int>::iterator ite = path.begin(); ite != path.end(); ++ite) {
		cout << *ite<<" ";
	}
}
/*
5 9
0 1 3
0 2 8
0 4 -4
1 3 1
1 4 7
2 1 4
3 0 2
3 2 -5
4 3 6
*/