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
const int M = 1 << 18;
class MajoritySubarray {
public:

	int BIT[M];
	int arr[N];
	int get(int idx) {

		int sum = 0;
		while (idx > 0) {
			sum += BIT[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}

	void add(int idx, int val) {

		while (idx < M) {
			BIT[idx] += val;
			idx += (idx & -idx);
		}
	}

	long long getCount(int n, int seed, int m) {
		for (int i = 0; i < n; ++i) {
			arr[i] = (seed / (1 << 16)) % m;
			seed = (1ll * seed * 1103515245 + 12345) % (1ll << 31);
		}

		cout << endl;
		ll ans = 0;
		for (int x = 0; x < m; ++x) {
			int bal = n;
			mem(BIT, 0);
			for (int i = 0; i < n; ++i) {
				add(bal, 1);

				if (arr[i] == x)
					bal++;
				else
					bal--;

				ans += get(bal - 1);
				
			}

		}

		return ans;
	}

};

//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
