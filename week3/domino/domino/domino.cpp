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

int sum(int a, int b, int m) {
	return (a % m + b % m) % m;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int a = 1, b = 2;
	fr(i, 3, n) {
		int c = b;
		b = sum(b, a, m);
		a = c;
	}

	cout << b;

	return 0;
}
