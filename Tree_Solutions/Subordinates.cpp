
#include<bits/stdc++.h>
using namespace std;



#define ff              first
#define ss              second
#define int             long long
#define ll long long

#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define all(a)      (a).begin(),(a).end()
#define pb push_back

#define pi 3.1415926535
#define light             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using mii = map<int, int>;
using pii = pair<int, int>;

const long long   M = 1e9 + 7;
void io() {
#ifndef  ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
}

void dfs(int node, vi &vis, vi graph[], vi &subord) {
	subord[node] = 1;

	for (auto i : graph[node])
	{

		//cout << node << " " << i << endl;
		dfs(i, vis, graph, subord);
		subord[node] += subord[i];

	}
	//cout << node << " " << subord[node] << endl;
}
void solve()
{

	int n;
	cin >> n;
	vi graph[n + 1];
	int i;

	for (i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		graph[x].pb(i);

	}
	vi vis(n + 1, 0);
	vi subord(n + 1, 0);
	dfs(1, vis, graph, subord);
	for (i = 1; i <= n; i++)
		cout << subord[i] - 1 << " ";



}
int32_t main()
{


	io();
	light;

	vi check = {2, 3, 5};

	int tc = 1;
	int tt = 1;
	//cin >> tc;

	while (tc--) {

		solve();

	}
}



