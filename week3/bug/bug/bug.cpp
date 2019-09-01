#include <algorithm>
#include <functional>
#include <cmath>
#include <limits>
#include <cfloat>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef int64_t I64;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

const int N = 200;

vector<vector<bool>> p(N, vector<bool>(N, false));

void recout(int i, int j) {
	if ((i == 0) && (j == 0)) return;

	if (p[i][j]) {
		recout(i, j - 1);
		cout << "R";
	} else {
		recout(i - 1, j);
		cout << "D";
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");

	int n, m;
	cin >> n >> m;

	vector<vi> a(n, vi(m, 0));
	fr2(i, 0, n) {
		fr2(j, 0, m) {
			cin >> a[i][j];
		}
	}

	vector<vi> d(n, vi(m, 0));
	fr2(i, 0, n) {
		fr2(j, 0, m) {
			d[i][j] = a[i][j];
			if ((i > 0) && (d[i - 1][j] + a[i][j] > d[i][j])) {
				d[i][j] = d[i - 1][j] + a[i][j];
				p[i][j] = 0;
			}
			if ((j > 0) && (d[i][j - 1] + a[i][j] > d[i][j])) {
				d[i][j] = d[i][j - 1] + a[i][j];
				p[i][j] = 1;
			}
		}
	}

	cout << d[n - 1][m - 1] << "\n";
	recout(n - 1, m - 1);

	return 0;
}
