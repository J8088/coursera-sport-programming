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

const int S = 100007;
vi p(S, 0);

void recout(int i) {
	if (i == 0) return;

	recout(i - p[i]);
	if (i - p[i] > 0)
		cout << "+";
	cout << p[i];
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;

	vi a(n);
	fr2(i, 0, n) cin >> a[i];

	vi d(s + 1);
	d[0] = 0;
	fr(i, 1, s) {
		d[i] = INT_MAX;
		fr2(j, 0, n) {
			if ((i - a[j] >= 0) && (d[i - a[j]] + 1 < d[i])) {
				d[i] = d[i - a[j]] + 1;
				p[i] = a[j];
			}
		}
	}

	cout << d[s] << "\n";
	recout(s);

	return 0;
}
