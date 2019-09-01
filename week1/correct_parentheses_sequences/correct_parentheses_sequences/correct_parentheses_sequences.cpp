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
string s;
vector<string> ans;

void save_ans() {
	ans.push_back(s);
}

void brute_force(int i, int c) {
	if (i == 2 * n) {
		if (c == 0) save_ans();
		return;
	}
	
	if (c > n) return;

	s[i] = '(';
	brute_force(i + 1, c + 1);
	
	if (c == 0) return;

	s[i] = ')';
	brute_force(i + 1, c - 1);
}

int main() {
	ios_base::sync_with_stdio(false);

	int num;
	cin >> n >> num;
	s = string(2 * n, '(');
	brute_force(0, 0);

	cout << ans[num - 1];

	return 0;
}
