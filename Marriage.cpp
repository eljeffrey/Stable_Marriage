#include<iostream>
using namespace std;

void move(int q[], int c);
bool ok(int q[], int size);
void print(int q[]);

int main() {
	int q[3] = {};
	move(q, 0);

	return 0;

}

void move(int q[], int c) {
	if (c == 3) {
		print(q);
		return;
	}
	else for (q[c] = 0; q[c] < 3; ++q[c]) {
		if (ok(q, c)) move(q, c+1);
	}
}

bool ok(int q[], int col) {
	static int mp[3][3] = { { 0,2,1 },
	{ 0,2,1 },
	{ 1,2,0 } };

	static int wp[3][3] = { { 2,1,0 },
	{ 0,1,2 },
	{ 2,0,1 } };

	for (int i = 0; i < col; i++) {
		if (q[col] == q[i]) return false;
		if ((mp[i][q[col]]) < (mp[i][q[i]]) && (wp[q[col]][i]) < (wp[q[col]][col]) || (mp[col][q[i]]) < (mp[col][q[col]]) && (wp[q[i]][col]) < (wp[q[i]][i])) return false;
	}

	return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for (int i = 0; i < 3; ++i)
		cout << i << "\t" << q[i] << "\n";
	cout << "\n";
}