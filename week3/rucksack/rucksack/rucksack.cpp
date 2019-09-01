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

const int NMAX = 1007, WMAX = 10007;
vi w(NMAX + 1), c(NMAX + 1);
vector<vi> d(NMAX + 1, vi(WMAX + 1, 0));

void recout(int i, int j) {
	if (d[i][j] == 0) return;

	if (d[i][j] == d[i - 1][j]) {
		recout(i - 1, j);
		return;
	}

	recout(i - 1, j - w[i]);
	cout << i << " ";
}

int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");

	int n, W;
	cin >> n >> W;

	fr(i, 1, n) cin >> w[i] >> c[i];

	fr(i, 1, n) {
		fr(j, 0, W) {
			d[i][j] = d[i - 1][j];
			if (j - w[i] >= 0) {
				d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + c[i]);
			}
		}
	}

	cout << d[n][W] << "\n";
	recout(n, W);

	return 0;
}
