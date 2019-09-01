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
stack<char> bs;
vector<string> ans;

void save_ans() {
	ans.push_back(s);
}

void brute_force(int i) {
	if (i == 2 * n) {
		if (bs.empty()) save_ans();
		return;
	}

	if (bs.size() > n) return;

	if (bs.empty()) {
		s[i] = '(';
		bs.push(s[i]);
		brute_force(i + 1);
		bs.pop();

		s[i] = '[';
		bs.push(s[i]);
		brute_force(i + 1);
		bs.pop();
	} else  if (bs.top() == '(') {
		s[i] = '(';
		bs.push(s[i]);
		brute_force(i + 1);
		bs.pop();
		
		s[i] = ')';
		bs.pop();
		brute_force(i + 1);
		bs.push('(');
		
		s[i] = '[';
		bs.push(s[i]);
		brute_force(i + 1);
		bs.pop();
	} else if (bs.top() == '[') {
		s[i] = '(';
		bs.push(s[i]);
		brute_force(i + 1);
		bs.pop();

		s[i] = '[';
		bs.push(s[i]);
		brute_force(i + 1);
		bs.pop();
		
		s[i] = ']';
		bs.pop();
		brute_force(i + 1);
		bs.push('[');
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int num;
	cin >> n >> num;
	s = string(2 * n, '(');
	brute_force(0);

	cout << ans[num - 1];

	return 0;
}
