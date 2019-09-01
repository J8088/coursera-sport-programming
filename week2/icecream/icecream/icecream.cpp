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

	int n;
	cin >> n;

	vector<string> a(n);
	map<string, int> b;
	fr2(i, 0, n) {
		cin >> a[i];
		b.insert({ a[i], 0 });
	}

	int k = 0;
	fr2(i, 0, n) {
		string s = a[i];
		if (b[s] == k) k++;
		b[s] = k;
	}

	cout << k;

	return 0;
}
