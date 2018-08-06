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

int Lg[N];
int pw[100];
int ST[N][100];
int arr[N];
void init() {
	Lg[0] = -1;
	for (int i = 1; i <= N; i++) {
		Lg[i] = Lg[i - 1] + !(i & (i - 1));
	}
	pw[0] = 1;
	for (int i = 1; i <= 30; i++) {
		pw[i] = pw[i - 1] * 2;
	}
}
void build() {
	for (int i = 0; i < N; i++) {
		ST[i][0] = arr[i];
	}
	for (int i = 1; pw[i] <= N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + pw[i] - 1 >= N)
				break;
			int x = ST[j][i - 1];
			int y = ST[j + pw[i - 1]][i - 1];
			ST[j][i] = min(x, y);
		}
	}
}

int getAns(int l, int r) {
	int len = r - l + 1;
	int i = Lg[len];
	int x = ST[l][i];
	int y = ST[r - pw[i] + 1][i];
	return min(x, y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	return 0;

}

