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

vector<bool> only_zero_pairs;

bool can(int mask, int new_mask) {
	return ((mask & new_mask) == 0) && only_zero_pairs[mask | new_mask];
}

int summod(int a, int b, int m) {
	return (a % m + b % m) % m;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	
	if (n > m) {
		int t = n; n = m; m = t;
	}

	only_zero_pairs = vector<bool>(1 << n, false);
	fr2(mask, 0, 1 << n) {
		int count_zeros = 0;
		fr2(i, 0, n) {
			if (!(mask & (1 << i))) {
				count_zeros++;
			} else if (count_zeros == 1) {
				break;
			}

			if (count_zeros == 2) count_zeros = 0;
		}

		only_zero_pairs[mask] = !count_zeros;
	}

	vector<vi> d(m + 1, vi(1 << n, 0));
	d[0][0] = 1;
	fr2(i, 0, m) {
		fr2(mask, 0, 1 << n) {
			fr2(new_mask, 0, 1 << n) {
				if (can(mask, new_mask)) {
					d[i + 1][new_mask] = summod(d[i + 1][new_mask], d[i][mask], k);
				}
			}
		}
	}

	cout << d[m][0];

	return 0;
}
