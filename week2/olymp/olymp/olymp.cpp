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

	int n, t;
	cin >> n >> t;

	vi a(n);
	fr2(i, 0, n) cin >> a[i];

	sort(a.begin(), a.end());

	I64 sum = 0, tsum = 0;
	int i = 0;
	while (i < n) {
		if (sum + a[i] > t) break;
		sum += a[i];
		tsum += sum;
		i++;
	}

	cout << i << " " << tsum;

	return 0;
}
