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

const int N = 10007;
vi a(N, 0), b(N, 0);
vector<vi> d(N, vi(N, 0));

void recout(int i, int j) {
	if (d[i][j] == 0) return;

	if (d[i][j] == d[i - 1][j]) {
		recout(i - 1, j);
		return;
	}

	if (d[i][j] == d[i][j - 1]) {
		recout(i, j - 1);
		return;
	}

	recout(i - 1, j - 1);
	cout << a[i] << " ";
}

int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");

	int n, m;
	
	cin >> n;

	fr(i, 1, n) cin >> a[i];

	cin >> m;

	fr(i, 1, m) cin >> b[i];

	fr(i, 1, n) {
		fr(j, 1, m) {
			d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			if (a[i] == b[j]) {
				d[i][j] = max(d[i][j], d[i - 1][j - 1] + 1);
			}
		}
	}

	cout << d[n][m] << "\n";
	recout(n, m);

	return 0;
}
