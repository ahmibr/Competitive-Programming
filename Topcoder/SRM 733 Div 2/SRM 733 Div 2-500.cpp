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

const int MOD = 987654323;
const int N = 1e3 + 50;

class BuildingSpanningTreesDiv2 {
public:

	int par[N];
	int siz[N];
	void init() {
		for (int i = 0; i < N; ++i)
			par[i] = i, siz[i] = 1;

	}

	int getpar(int u) {
		if (u == par[u])
			return u;
		return par[u] = getpar(par[u]);
	}

	bool merge(int u, int v) {
		u = getpar(u);
		v = getpar(v);
		if (u == v)
			return false;
		if (siz[u] < siz[v])
			swap(u, v);
		par[v] = u;
		siz[u] += siz[v];
		return true;
	}

	int getNumberOfSpanningTrees(int n, vector<int> x, vector<int> y) {
		init();
		int m = x.size();

		for (int i = 0; i < m; ++i)
			if (!merge(x[i], y[i]))
				return 0;

		map<int, int> mp;

		for (int i = 1; i <= n; ++i)
			mp[getpar(i)]++;

		int ans = 0;

		auto it = mp.begin();
		int a = it->second;
		int b = (++it)->second;
		int c = (++it)->second;

		ll ab = a * b;
		ll bc = b * c;
		ll ca = c * a;

		
		ans = (ab * bc % MOD + ab * ca % MOD + ca * bc % MOD) % MOD;
		return ans;
	}
};

<%:testing-code%> //
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
