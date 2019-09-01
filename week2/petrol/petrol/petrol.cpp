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

	int n, d, p;
	cin >> n >> d >> p;

	vi a(n + 1);
	fr2(i, 0, n) cin >> a[i];
	a[n] = d;

	int c = 0, m = 0;
	fr(i, 0, n) {
		int k = i;
		while (k <= n && a[k] - c <= p) k++;
		if (k > n) break;
		i = k - 1;
		c = a[i];
		m++;
	}

	cout << m;

	return 0;
}
