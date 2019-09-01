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
string a;
vector<string> ans;

void save_ans() {
	ans.push_back(a);
}

void brute_force(int i, int left) {
	if ((i == n) || (left == 0)) {
		if (left == 0) save_ans();
		return;
	}

	if ((i > 0) && a[i - 1] == '*') {
		a[i] = '.';
		brute_force(i + 1, left);
	} else {
		a[i] = '*';
		brute_force(i + 1, left - 1);
		a[i] = '.';
		brute_force(i + 1, left);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int num;
	cin >> n >> m >> num;
	a = string(n, '.');
	brute_force(0, m);

	fr2(i, 0, n) cout << ans[num - 1][i] << " ";

	return 0;
}
