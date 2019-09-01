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

int n, m;
vi a;
vector<vi> ans;

void save_ans() {
	ans.push_back(a);
}

void brute_force(int i) {
	if (i == n) {
		save_ans();
		return;
	}

	fr(j, 1, m) {
		a[i] = j;
		brute_force(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int num;
	cin >> n >> m >> num;
	a = vi(n);
	brute_force(0);

	fr2(i, 0, n) cout << ans[num - 1][i] << " ";

	return 0;
}
