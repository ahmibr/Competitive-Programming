#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <numeric>
#include <queue>

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
#define INF (1200000000)
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

const int MOD = 1000000007;

const int N = 1e5 + 50;

class TheFlippingGame2 {
public:

	deque<ii> deq;

	int sp[22][22];
	vector<string> grid;

	int n, m;

	bool valid(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m && sp[x][y] == INF;
	}

	int MinimumMoves(int n, int m, vector<string> x) {
		this->n = n;
		this->m = m;
		//dq.push
		int ret = INF;
		for (int color = 0; color < 2; ++color) {
			grid = x;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (grid[i][j] == 'e')
						grid[i][j] = !color ? 'b' : 'w';

			for (int stx = 0; stx < n; ++stx)
				for (int sty = 0; sty < m; ++sty) {

					for (int i = 0; i < n; ++i)
						for (int j = 0; j < m; ++j)
							sp[i][j] = INF;

					sp[stx][sty] = 0;
					deq.push_front( { stx, sty });

					int ans = -1;
					while (!deq.empty()) {
						int x = deq.front().first;
						int y = deq.front().second;
						ans = max(ans, sp[x][y]);
						deq.pop_front();
						for (int i = 0; i < 4; ++i)
							if (valid(x + dx[i], y + dy[i])) {
								if (grid[x + dx[i]][y + dy[i]] == grid[x][y])
									sp[x + dx[i]][y + dy[i]] = sp[x][y], deq.push_front({ x + dx[i], y + dy[i] });
								else
									sp[x + dx[i]][y + dy[i]] = sp[x][y] + 1, deq.push_back({ x + dx[i], y + dy[i] });
							}
					}
					ret = min(ret, ans);
				}
		}

		return ret;
	}
};

//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
