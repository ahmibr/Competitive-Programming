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
const int N = 1e3 + 5;

class MinimizeAbsoluteDifferenceDiv2 {
public:
	vector<int> findTriple(int x0, int x1, int x2) {
		double ans = INF;

		vector<int> vec;
		vec.pb(x0);
		vec.pb(x1);
		vec.pb(x2);
		vector<int> ret(3);
		for (int i = 0; i < vec.size(); ++i)
			for (int j = 0; j < vec.size(); ++j)
				for (int k = 0; k < vec.size(); ++k) {
					if (i == j || j == k || k == i)
						continue;
					if (fabs(1.0 * vec[i] / vec[j] - vec[k]) < ans) {
						ans = fabs(1.0 * vec[i] / vec[j] - vec[k]);
						for (int w = 0; w < 3; ++w)
							ret[0] = i, ret[1] = j, ret[2] = k;
					}
				}
		return ret;
	}
};

//<%:testing-code%> 
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
