#include<iostream>
#include<string>
using namespace std;
void complete(string &p, string &q);
string add(string p, string q);
string sub(string p, string q);
string mul(string p, string q);
string smul(string p, string q);
int main() {
	string p;
	string q;
	cin >> p >> q;
	cout << "ADD:  " << add(p, q) << endl;
	cout << "SUB:  " << sub(p, q) << endl;
	cout << "MUL:  " << mul(p, q) << endl;
	system("pause");
	return 0;
}
void complete(string &p, string &q) {
	if (p.size() > q.size()) {
		q = string(p.size() - q.size(), '0') + q;
	}
	else p = string(q.size() - p.size(), '0') + p;
}
string add(string p, string q) {
	int flag = 0;
	string result;
	if (q[0] == '-'&&p[0]=='-') {
		q.erase(0, 1);
		p.erase(0, 1);
		flag = 1;
	}
	else if (q[0] == '-') {
		q.erase(0, 1);
		return sub(p, q);
	}
	else if (p[0] == '-') {
		p.erase(0, 1);
		return sub(q, p);
	}
	else;
	complete(p, q);
	reverse(p.begin(), p.end());
	reverse(q.begin(), q.end());
	for (int i = 0; i < p.size(); ++i) {
		p[i] = p[i] - '0';
	}
	for (int i = 0; i < q.size(); ++i) {
		q[i] = q[i] - '0';
	}
	for (int i = 0; i < p.size(); ++i) {
		result.append(1,(p[i] + q[i]) % 10);
		if (i < p.size() - 1) {
			p[i + 1] += (p[i] + q[i]) / 10;
		}
		else if ((p[i] + q[i]) / 10) {
			result.append(1, 1);
		}
	}
	reverse(result.begin(), result.end());
	for (int i = 0; i < result.size(); ++i) {
		result[i] += '0';
	}
	result.insert(0, flag, '-');
	return result;
}
string sub(string p, string q) {
	string result;
	int flag = 0;
	if (p[0] == '-'&&q[0] == '-') {
		p.erase(0, 1);
		q.erase(0, 1);
		return sub(q, p);
	}
	else if (p[0] == '-') {
		p.erase(0, 1);
		return result = "-" + add(p, q);
	}
	else if (q[0] == '-') {
		q.erase(0, 1);
		return add(p, q);
	}
	else;
	complete(p, q);
	if (p < q)return result = "-" + sub(q, p);
	else {
		reverse(p.begin(), p.end());
		reverse(q.begin(), q.end());
		for (int i = 0; i < p.size(); ++i) {
			if (i < p.size() - 1) {
				if (p[i] < q[i]) {
					--p[i + 1];
					result.append(1, 10 + p[i] - q[i]);
				}
				else result.append(1, p[i] - q[i]);
			}
			else {
				result.append(1, p[i] - q[i]);
			}
		}
		for (int i = result.size() - 1; i >= 0; --i) {
			if (result[i] == 0) {
				result.erase(i, 1);
			}
			else break;
		}
		if (result.size()) {
			reverse(result.begin(), result.end());
			for (int i = 0; i < result.size(); ++i) {
				result[i] += '0';
			}
			return result;
		}
		else return "0";
	}
}
string mul(string p, string q) {
	int flag = 0;
	string result;
	if (p[0] == '-') {
		++flag;
		p.erase(0, 1);
	}
	if (q[0] == '-') {
		++flag;
		q.erase(0, 1);
	}
	complete(p, q);
	result = smul(p, q);
	for (int i = 0; i < result.size(); ++i) {
		if (result[i] == '0') {
			result.erase(i, 1);
		}
		else break;
	}
	result.insert(0, flag % 2, '-');
	return result;
}
string smul(string p, string q) {
	int x;
	string y;
	string a;
	string b;
	string c;
	string d;
	string ac;
	string bd;
	string abcd;
	string result1;
	string result2;
	string result3;
	if (p.size() > 1) {
		a.assign(p, 0, p.size() / 2);
		b.assign(p, p.size() / 2);
		c.assign(q, 0, q.size() / 2);
		d.assign(q, q.size() / 2);
		ac = smul(a,c);
		bd = smul(b,d);
		abcd = mul(sub(a, b), sub(d, c));
		result1 = add(ac + string(p.size() - p.size() / 2, '0') + string(p.size() - p.size() / 2, '0'), ac + string(p.size() - p.size() / 2, '0'));
		result3 = add(bd + string(p.size() - p.size() / 2, '0'), bd);
		result2 = add(abcd + string(p.size() - p.size() / 2, '0'), result3);
		return add(result1, result2);
	}
	else {
		x = (p[0] - '0') * (q[0] - '0');
		if (x >= 10)y.append(1, x / 10 + '0');
		y.append(1, x % 10 + '0');
		return y;
	}
}