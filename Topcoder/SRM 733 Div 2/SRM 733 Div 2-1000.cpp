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

const int MOD = 1e9 + 7;
const int N = 1e2 + 50;

class HamiltonianPathsInGraph {
public:

	int head = 0, tail = 0;
	int to[N];
	vector<int> findPath(vector<string> X) {
		int n = X.size();
		for (int i = 0; i < n; ++i)
			to[i] = -1;

		for (int i = 1; i < n; ++i) {
			if (X[i][head] == '+') {
				to[i] = head;
				head = i;
			} else if (X[tail][i] == '+') {
				to[tail] = i;
				tail = i;
			} else {
				for (int j = 0; j < i; ++j)
					if (X[j][i] == '+' && X[i][to[j]] == '+') {
						to[i] = to[j];
						to[j] = i;
						break;
					}
			}
		}
		vector<int> ans;
		int u = head;
		while (u != -1) {
			ans.pb(u);
			u = to[u];
		}
		return ans;
	}
};

//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
