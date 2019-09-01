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

const int INF = INT_MAX;
vector<vi> a, d;
int n;
vi ap_temp, ans_path;

void recout(int mask, int j) {
	if (mask == 0) return;

	fr2(i, 0, n) {
		if (d[mask][j] == d[mask ^ (1 << j)][i] + a[i][j]) {
			recout(mask ^ (1 << j), i);
			ap_temp.push_back(i);
			if (ap_temp.size() == n) {
				if (!ans_path.size() || ap_temp[1] < ans_path[1]) {
					ans_path = ap_temp;
				}
				ap_temp.clear();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");

	cin >> n;

	a = vector<vi>(n, vi(n, 0));
	fr2(i, 0, n) {
		fr2(j, 0, n) cin >> a[i][j];
	}

	d = vector<vi>(1 << n, vi(n, INF));
	d[0][0] = 0;
	fr2(mask, 0, 1 << n) {
		fr2(i, 0, n) {
			if (d[mask][i] == INF) continue;

			fr2(j, 0, n) {
				if (!(mask & (1 << j))) {
					d[mask ^ (1 << j)][j] = min(d[mask ^ (1 << j)][j], d[mask][i] + a[i][j]);
				}
			}
		}
	}

	cout << d[(1 << n) - 1][0] << "\n";
	recout((1 << n) - 1, 0);

	fr2(i, 0, n) cout << ans_path[i] << " ";

	return 0;
}
