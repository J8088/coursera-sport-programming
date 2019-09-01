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
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");

	int n;
	cin >> n;

	vector<pi> a(n);
	fr2(i, 0, n) cin >> a[i].second >> a[i].first;

	sort(a.begin(), a.end());

	set<pi> s;
	vector<int> result;
	for (int i = n - 1; i >= 0; --i) {
		int t = a[i].first - (i ? a[i - 1].first : 0);
		s.insert(make_pair(a[i].second, i));
		while (t && !s.empty()) {
			auto it = s.begin();
			if (it->first <= t) {
				t -= it->first;
				result.push_back(it->second);
			}
			else {
				s.insert(make_pair(it->first - t, it->second));
				t = 0;
			}
			s.erase(it);
		}
	}

	cout << result.size() << "\n";
	for (size_t i = 0; i < result.size(); ++i)
		cout << result[i] << ' ';

	return 0;
}
