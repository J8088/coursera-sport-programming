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

	int n;
	cin >> n;

	vi a(n);
	fr2(i, 0, n) cin >> a[i];

	vi d(n), c(n);
	fr2(i, 0, n) {
		d[i] = 1;
		c[i] = 1;
		fr2(j, 0, i) {
			if (a[j] < a[i]) {
				if (1 + d[j] > d[i]) {
					d[i] = 1 + d[j];
					c[i] = c[j];
				} else if (1 + d[j] == d[i]) {
					c[i] += c[j];
				}
			}
		}
	}

	I64 ans = 0, cans = 0;
	fr2(i, 0, n) {
		if (d[i] > ans) {
			ans = d[i];
			cans = c[i];
		} else if (d[i] == ans) {
			cans += c[i];
		}
	}

	cout << ans << " " << cans << "\n";

	return 0;
}
