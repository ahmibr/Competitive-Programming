#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();i++)
#define mem(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define EPS      1e-9
#define F        first
#define S        second
#define sc(x)     scanf("%d",&x)
#define scl(x)     scanf("%I64d",&x)
#define sq(x)     (x)*(x)
#define INF (1000000000)
#define oo (1ll<<60)
#define PI acos(-1)
#define POW(x) ((x)*(x))

typedef stringstream ss;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, int> ii;
typedef vector<int> rows;
typedef vector<rows> matrix;

const int dx[] = { 0, 0, -1, 1, 1, -1, -1, 1 };
const int dy[] = { -1, 1, 0, 0, -1, 1, -1, 1 };

class TheRectangularCityDiv2 {
public:

	int n, m;
	map<pair<ii, int>, int> mp;
	vector<string> city;

	bool valid(int i, int j) {
		return i >= 0 && i < n && j >= 0 && j < m && city[i][j] != '#';
	}

	long long solve(int r, int c, int mask) {

		if (mask == (1 << n * m) - 1) {
			return r == 0 || r == n - 1 || c == 0 || c == m - 1;
		}

		if (mp.count( { { r, c }, mask }))
			return mp[ { { r, c }, mask }];

		ll ret = 0;
		for (int i = 0; i < 4; ++i) {
			int newi = r + dx[i];
			int newj = c + dy[i];
			if (valid(newi, newj) && !(mask & (1 << newi * m + newj)))
				ret += solve(newi, newj, mask | (1 << newi * m + newj));
		}
		mp[ { { r, c }, mask }] = ret;
		return ret;
	}

	long long find(vector<string> city) {
		this->city = city;
		n = city.size();
		m = city[0].size();
		int mask;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (city[i][j] == '#')
					mask |= 1 << (i * m + j);

		ll ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && valid(i, j))
					ans += solve(i, j, mask | (1 << m * i + j));
		return ans;
	}
};

//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
