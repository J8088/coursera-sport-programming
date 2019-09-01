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

int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");

	int n, m;
	cin >> n >> m;

	vector<vi> a(n + 1, vi(m + 1, 0));
	vector<vi> s(n + 1, vi(m + 1, 0));
	fr(i, 1, n) {
		fr(j, 1, m) {
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}

	int q;
	cin >> q;
	
	I64 total = 0;
	fr2(i, 0, q) {
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;

		I64 ans = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
		//cout << ans << " ";

		total += ans;
	}

	cout << "\n" << total;

	return 0;
}
