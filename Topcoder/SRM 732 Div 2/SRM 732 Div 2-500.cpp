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

class CubeStackingGame {
public:

	int ans = 1;
	int c[10][10];
	int n;
	void solve(int idx, int mask) {
		ans = max(ans, idx);
		if (idx == n)
			return;

		for (int rot = 0; rot < 8; ++rot) {

			bool ok = true;

			for (int j = 0; j < idx; ++j) {
				if (c[idx][rot] & c[j][0b111 & (mask >> 0b11 * j)]) {
					ok = false;
					break;
				}
			}

			if (ok)
				solve(idx + 1, mask | (rot << 0b11 * idx));

		}

	}

	int MaximumValue(int n, vector<int> c1, vector<int> c2, vector<int> c3,vector<int> c4) {
		this->n = n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (j == 4)
					swap(c2[i], c4[i]);
				c[i][j] |= (1 << ((c1[i] - 1) + 8 * j));
				c[i][j] |= (1 << ((c2[i] - 1) + 8 * ((j + 1) % 4)));
				c[i][j] |= (1 << ((c3[i] - 1) + 8 * ((j + 2) % 4)));
				c[i][j] |= (1 << ((c4[i] - 1) + 8 * ((j + 3) % 4)));
			}
		}

		solve(0, 0);
		return ans;
	}
};

//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
