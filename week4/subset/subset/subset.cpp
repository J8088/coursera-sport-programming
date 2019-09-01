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

	int n, num;
	cin >> n >> num;

	vector<vi> ans(1 << n);
	fr2(mask, 0, 1 << n) {
		ans[mask] = vi();
		fr2(i, 0, n) {
			if (mask & (1 << (n - i - 1))) {
				ans[mask].push_back(i + 1);
			}
		}
	}

	vi numans = ans[(1 << n) - num];
	cout << "{";
	fr2(i, 0, numans.size()) {
		cout << numans[i] << ((i < numans.size() - 1) ? "," : "");
	}
	cout << "}";

	return 0;
}
