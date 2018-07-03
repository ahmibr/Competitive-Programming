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

const int MOD = 1000000007;
const int N = 5e5 + 50;

int f[N];
void buildF(string str) {
	int l;
	f[0] = 0;
	for (int i = 1; i < str.size(); ++i) {
		l = f[i - 1];

		while (l && str[i] != str[l])
			l = f[l - 1];
		if (str[i] == str[l])
			++l;

		f[i] = l;
	}
}

vector<int> kmp(string text, string patt) {
	buildF(patt);
	vector<int> occ;
	int l = 0;
	for (int i = 0; i < text.size(); ++i) {

		if (text[i] == patt[l])
			l++;

		else {
			while (l && text[i] != patt[l])
				l = f[l - 1];
			if (text[i] == patt[l])
				l++;
		}

		if (l == patt.size()) {
			occ.push_back(i - l + 1);
			l = f[l - 1];
			continue;
		}
	}

	return occ;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif

	string text;
	string patt;
	vector<int> occ;

	//*********Test Case 1****************************
	text = "ABABDABACDABABCABAB";
	patt = "ABABCABAB";

	occ = kmp(text, patt);

	for (int i = 0; i < occ.size(); ++i)
		cout << occ[i] << " \n"[i == occ.size() - 1];

	//*********Test Case 2****************************
	text = "THIS IS A TEST TEXT";
	patt = "TEST";

	occ = kmp(text, patt);

	for (int i = 0; i < occ.size(); ++i)
		cout << occ[i] << " \n"[i == occ.size() - 1];

	//*********Test Case 3****************************
	text = "AABAACAADAABAABA";
	patt = "AABA";

	occ = kmp(text, patt);

	for (int i = 0; i < occ.size(); ++i)
		cout << occ[i] << " \n"[i == occ.size() - 1];


	return 0;

}
