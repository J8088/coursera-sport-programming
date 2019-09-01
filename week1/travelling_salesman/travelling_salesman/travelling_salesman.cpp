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

int n;
vi a;
vector<vi> d;
vector<bool> used;
int ans = INT_MAX;
vi ans_path;
bool found_path = false;

void save_ans() {
	ans_path = a;
	found_path = true;
}

void brute_force(int i, int len) {
	if (len >= ans) return;

	if (i == n) {
		int new_ans = len + d[a[i - 1]][0];
		if (new_ans <= ans) {
			if ((new_ans < ans) || !found_path || (a[1] < ans_path[1])) save_ans();
			ans = new_ans;
		}
		return;
	}

	fr(j, 1, n - 1) {
		if (used[j]) continue;

		a[i] = j;
		used[j] = true;
		brute_force(i + 1, len + d[a[i - 1]][j]);
		used[j] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	d = vector<vi>(n);
	fr2(i, 0, n) {
		d[i] = vi(n);
		fr2(j, 0, n) {
			cin >> d[i][j];
		}
	}

	a = vi(n);
	ans_path = vi(n);
	used = vector<bool>(n + 1, false);
	a[0] = 0;
	brute_force(1, 0);

	cout << ans << "\n";
	fr2(i, 0, n) cout << ans_path[i] << " ";

	return 0;
}
