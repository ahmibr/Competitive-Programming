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

const int INF = 1e9;
class BinaryCalculator {
public:
	int minimumSteps(int a, int b) {
		int ans = INF;
		for (int i = 0; i <= 100; ++i)
			for (int j = 0; j <= 100; ++j)
				if (a - 2 * i + 3 * j == b)
					ans = min(ans, i + j);

		return ans;
	}
};

//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
