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
int arr[N];
ll seg[4 * N], lazy[4 * N];
int n;

void propagate(int father, int leftson, int rightson) {
	seg[leftson] += lazy[father];
	seg[rightson] += lazy[father];
	lazy[leftson] += lazy[father];
	lazy[rightson] += lazy[father];
	lazy[father] = 0;
}

void build(int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		seg[idx] = arr[l];
		lazy[idx] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(idx * 2, l, mid);
	build(idx * 2 + 1, mid, r);
	seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
}

void update(int x, int y, int val, int id = 1, int l = 0, int r = n) {
	if (x >= r || y <= l)
		return;

	if (l >= x && r <= y) {
		seg[id] += val;
		lazy[id] += val;
		return;
	}

	propagate(id, id * 2, id * 2 + 1);
	int mid = (l + r) / 2;

	update(x, y, val, id * 2, l, mid);

	update(x, y, val, id * 2 + 1, mid, r);

	seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

int getMin(int x, int y, int id = 1, int l = 0, int r = n) {
	if (x >= r || y <= l)
		return 0;
	if (l >= x && r <= y) {
		return seg[id];
	}

	propagate(id, id * 2, id * 2 + 1);

	int mid = (l + r) / 2;
	return min(getMin(x, y, id * 2, l, mid), getMin(x, y, id * 2 + 1, mid, r));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	return 0;

}

