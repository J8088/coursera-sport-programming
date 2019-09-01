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
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");

	int n;
	cin >> n;

	vi a(n);
	I64 sum = 0;
	fr2(i, 0, n) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a.rbegin(), a.rend());

	I64 s1 = 0;
	fr2(i, 0, n / 2) s1 += a[i];
	I64 s2 = sum - s1;

	cout << abs(s1 - s2) << "\n";

	return 0;
}
