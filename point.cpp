#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
class Point {
	double x;
	double y;
public:
	Point(double x, double y) : x(x), y(y) {};
	double getx() const{
		return x;
	}
	double gety() const{
		return y;
	}
	~Point() {};
};
class Distance
{
	Point p1, p2;
public:
	double dist();
	void show();
	Distance(Point d1, Point d2) :p1(d1), p2(d2) {};
	~Distance() {};
};

double Distance::dist()
{
	double x1 = p1.getx();
	double x2 = p2.getx();
	double y1 = p1.gety();
	double y2 = p2.gety();
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
void Distance::show() {
	cout << "(" << p1.getx() << "," << p1.gety() << ")" << flush;
	cout << "+(" << p2.getx() << "," << p2.gety() << ")" << endl;
}
bool comp(const Point &a, const Point &b)
{
	return a.getx() < b.getx();
}
void least(vector<Point> &,vector<Distance> &);
void middle(vector<Point> &, vector<Distance> &);
int main() {
	int num;
	double x, y;
	vector<Point> point;
	point.reserve(100*sizeof(Point));
	vector<Distance> least_dist;
	cout << "请输入点个数：" << flush;
	cin >> num;
	cout << "输入各点坐标：" << endl;
	for (int i = 0; i < num; ++i) {
		cin >> x >> y;
		point.push_back(Point(x,y));
	}
	sort(point.begin(), point.end(), comp);
	least(point, least_dist);
	cout << "最近点对为：" << endl;
	for (int i = 0; i < least_dist.size(); ++i) {
		least_dist[i].show();
	}
	cout << "最短距离为：" << least_dist[0].dist() << endl;
	system("pause");
	return 0;
}
void least(vector<Point> &p, vector<Distance> &d) {
	if (p.empty() || p.size() == 1)return ;
	else if(p.size()==2) {
		Distance last(p[0], p[1]);
		if (d.empty()) {
			d.push_back(last);
		}
		else if (last.dist() < d[0].dist()) {
			d.clear();
			d.push_back(last);
		}
		else if (last.dist() == d[0].dist())d.push_back(last);
		else;
		return ;
	}
	else {
		if (p.size() % 2) {
			vector<Point> subp1(p.begin(), p.begin() + p.size() / 2+1);
			vector<Point> subp2(p.begin() + p.size() / 2 + 1, p.end());
			least(subp1, d);
			least(subp2, d);
		}
		else {
			vector<Point> subp1(p.begin(), p.begin() + p.size() / 2);
			vector<Point> subp2(p.begin() + p.size() / 2, p.end());
			least(subp1, d);
			least(subp2, d);
		}	
		middle(p, d);
	}
}
void middle(vector<Point> &p, vector<Distance> &d) {
	vector<Point> ml;
	vector<Point> mr;
	double x ;
	if (p.size() % 2) {
		x = p[p.size() / 2].getx();
		ml.push_back(p[p.size() / 2]);
		int i = 1;
		while (1) {
			if (i <= p.size() / 2) {
				if (x - p[p.size() / 2 - i].getx() <= d[0].dist()) {
					ml.push_back(p[p.size() / 2 - i]);
					++i;
				}
				else break;
			}
			else break;
		}
		i = -1;
		while (1) {
			if (-i < p.size() - p.size() / 2) {
				if (x - p[p.size() / 2 - i].getx() <= d[0].dist()) {
					mr.push_back(p[p.size() / 2 - i]);
					--i;
				}
				else break;
			}
			else break;
		}
	}
	else {
		x = p[p.size() / 2 - 1].getx();
		ml.push_back(p[p.size() / 2 - 1]);
		int i = 1;
		while (1) {
			if (i <= p.size() / 2 - 1) {
				if (x - p[p.size() / 2 - 1 - i].getx() <= d[0].dist()) {
					ml.push_back(p[p.size() / 2 - 1 - i]);
					++i;
				}
				else break;
			}
			else break;
		}
		i = -1;
		while (1) {
			if (-i < p.size() - p.size() / 2 + 1) {
				if (x - p[p.size() / 2 - 1 - i].getx() <= d[0].dist()) {
					mr.push_back(p[p.size() / 2 - 1 - i]);
					--i;
				}
				else break;
			}
			else break;
		}
	}
	
	for (int i = 0; i < ml.size(); ++i) {
		for (int j = 0; j < mr.size(); ++j) {
			Distance s(ml[i], mr[j]);
			if (d.empty()) {
				d.push_back(s);
			}
			else if (s.dist() < d[0].dist()) {
				d.clear();
				d.push_back(s);
			}
			else if (s.dist() == d[0].dist()) {
				d.push_back(s);
			}
			else ;
		}
	}
}


