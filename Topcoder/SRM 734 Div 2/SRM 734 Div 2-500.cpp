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

class TheSquareCityDiv2 {
public:
	int cnt[25][25];
	vector<int> find(int r, vector<int> t) {

		bool change = true;
		int n = sqrt(t.size());
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cnt[i][j] = 1;

		while (change) {
			change = false;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					if (!cnt[i][j])
						continue;
					int MX = t[i * n + j];
					int toi, toj;
					for (int k = 0; k < n; ++k)
						for (int w = 0; w < n; ++w)
							if (t[k * n + w] > MX
									&& abs(i - k) + abs(j - w) <= r)
								MX = t[k * n + w], toi = k, toj = w;
					if (MX != t[i * n + j]) {
						cnt[toi][toj] += cnt[i][j];
						cnt[i][j] = 0;
						change = true;
					}

				}
		}

		int a = 0, b = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				a += cnt[i][j] != 0, b = max(b, cnt[i][j]);

		vector<int> ret;
		ret.pb(a);
		ret.pb(b);
		return ret;
	}
}
;

//<%:testing-code%>						
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
