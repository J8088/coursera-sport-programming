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

const int N = 51;
vi a(N);
vector<vector<bool>> d(N);
vector<bool> ans(N);

bool recout(int i, int w) {
	if (i == 0) return true;

	if (d[i][w]) {
		if (recout(i - 1, w + a[i])) {
			ans[i] = false;
			return true;
		}
		if (recout(i - 1, w - a[i])) {
			ans[i] = true;
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");

	int n, x;
	cin >> n >> x;

	int sum = 0;
	fr(i, 1, n) {
		cin >> a[i];
		sum += a[i];
	}

	int b0 = sum;
	fr(i, 1, n) {
		d[i] = vector<bool>(b0 + sum + 1, false);
	}

	d[1][a[1] + b0] = true;
	fr(i, 1, n - 1) {
		fr(w, 0, b0 + sum) {
			if (d[i][w]) {
				d[i + 1][w + a[i + 1]] = true;
				d[i + 1][w - a[i + 1]] = true;
			}
		}
	}

	if (recout(n, x + b0)) {
		ans[1] = true;
		fr(i, 1, n) cout << (ans[i] ? "+" : "-") << a[i];
	} else {
		cout << "No solution";
	}

	return 0;
}
