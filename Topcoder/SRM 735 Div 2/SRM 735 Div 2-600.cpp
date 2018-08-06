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
int sp[55][55];
class TeleportationMaze {
public:
	int n, m;
	vector<string> a;
	bool valid(int i, int j) {

		return i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.';
	}
	int pathLength(vector<string> a, int r1, int c1, int r2, int c2) {
		n = a.size();
		m = a[0].size();
		this->a = a;
		for (int i = 0; i < 50; ++i)
			for (int j = 0; j < 50; ++j)
				sp[i][j] = INF;
		priority_queue<pair<int, ii>, vector<pair<int, ii> >,
				greater<pair<int, ii> > > pq;
		pq.push( { 0, { r1, c1 } });
		sp[r1][c1] = 0;

		while (!pq.empty()) {
			pair<int, ii> tp = pq.top();
			pq.pop();

			int cost = tp.first;
			int r = tp.second.first;
			int c = tp.second.second;

			if (r == r2 && c == c2)
				break;
			if (cost > sp[r][c])
				continue;

			for (int i = r + 1; i < n; ++i)
				if (a[i][c] == '.') {
					if (i == r + 1 || sp[i][c] < cost + 2)
						break;
					sp[i][c] = cost + 2;

					pq.push( { sp[i][c], { i, c } });
					break;
				}

			for (int i = r - 1; i > -1; --i)
				if (a[i][c] == '.') {
					if (i == r - 1 || sp[i][c] < cost + 2)
						break;
					sp[i][c] = cost + 2;
					pq.push( { sp[i][c], { i, c } });
					break;
				}

			for (int i = c + 1; i < m; ++i)
				if (a[r][i] == '.') {
					if (i == c + 1 || sp[r][i] < cost + 2)
						break;
					cout << "GO TO " << r << " " << i << " " << cost + 2
							<< endl;
					sp[r][i] = cost + 2;
					cout << pq.size() << endl;
					pq.push( { sp[r][i], { r, i } });
					cout << pq.size() << endl;
					break;
				}

			for (int i = c - 1; i > -1; --i)
				if (a[r][i] == '.') {
					if (i == c - 1 || sp[r][i] < cost + 2)
						break;
					sp[r][i] = cost + 2;
					pq.push( { sp[r][i], { r, i } });
					break;
				}

			for (int i = 0; i < 4; ++i) {
				if (valid(r + dx[i], c + dy[i])
						&& sp[r + dx[i]][c + dy[i]] > cost + 1) {
					sp[r + dx[i]][c + dy[i]] = cost + 1;
					pq.push( { cost + 1, { r + dx[i], c + dy[i] } });
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				if (a[i][j] == '#')
					cout << '#';
				else if (sp[i][j] == INF)
					cout << '*';
				else
					cout << sp[i][j];
			cout << endl;
		}
		if (sp[r2][c2] == INF)
			return -1;
		else
			return sp[r2][c2];
	}
}
;

//<%:testing-code%> 
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
