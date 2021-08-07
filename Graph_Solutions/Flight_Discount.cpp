#include<bits/stdc++.h>

using namespace std;


#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(a)      (a).begin(),(a).end()
#define inf 1e17
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define REP(i,n) for(i=0;i<n;i++)
#define FIO             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define N 100005
const long long   M = 1e9 + 7;

void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
}

int mod(int x) {
	return (x % M + M) % M;
}
bool f(int x, int y)
{
	return x > y;
}
int  add(int a, int b)
{
	return mod(mod(a) + mod(b));
}

int dis1[N], dis2[N];
int vis[N];
void dijks(int src, int dis[], vector<pii>graph[])
{
	//cout << src << endl;
	priority_queue<pii, vector<pii>, greater<pii>>q;

	memset(vis, 0, sizeof vis);
	for (int i = 0; i <= 100005; i++)
		dis[i + 1] = inf;
	q.push({0, src});
	dis[src] = 0;

	while (!q.empty())
	{
		int distance = q.top().ff;
		int node = q.top().ss;

		//cout << distance << " " << node << endl;
		q.pop();
		if (vis[node])
			continue;
		vis[node] = 1;
		for (auto &it : graph[node])
		{
			pii p = it;

			if (dis[p.ff] > dis[node] + p.ss)
			{
				dis[p.ff] = dis[node] + p.ss;
				q.push({dis[p.ff], p.ff});
			}

		}
	}


}
void solve() {

	int n, m;
	cin >> n >> m;


	vector<pii>graph[n + 1];
	vector<pii>transpose[n + 1];
	vector<tuple<int, int, int>>edges;
	int i, j;
	for (i = 0; i < m; i++)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({u, v, wt});
		graph[u].pb({v, wt});
		transpose[v].pb({u, wt});
	}

	dijks(1, dis1, graph);
	dijks(n, dis2, transpose);


	int ans = inf;
	for (auto [x, y, z] : edges) {
		ans = min(ans, dis1[x] + dis2[y] + z / 2);
	}

	cout << ans;


}


int32_t main()
{

	c_p_c();



	int tt = 1;
	//w(t)
	solve();



}
