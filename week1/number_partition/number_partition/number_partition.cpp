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
vector<vi> ans;

void save_ans(int i) {
	ans.push_back(vi(a.begin(), a.begin() + i));
}

void brute_force(int i, int sum, int last) {
	if (sum == n) {
		save_ans(i);
		return;
	}

	fr(j, last, n - sum) {
		a[i] = j;
		brute_force(i + 1, sum + j, j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int num;
	cin >> n >> num;
	a = vi(n);
	brute_force(0, 0, 1);

	vi res = ans[num - 1];
	fr2(i, 0, res.size() - 1) cout << res[i] << "+";
	cout << res[res.size() - 1];

	return 0;
}
