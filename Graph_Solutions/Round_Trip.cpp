
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

#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define REP(i,n) for(i=0;i<n;i++)
#define FIO             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

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
const int N = 1e5 + 10 ;
vector<vi>graph;
int sv, ev;
vi parent;
vi vis;
int n, m;
bool dfs(int u, int p)
{
	vis[u] = true;
	parent[u] = p;
	for (auto v : graph[u])
	{
		if (v == p) continue;
		if (vis[v])
		{
			sv = v;
			ev = u;
			return true;
		}
		if (!vis[v])
			if (dfs(v, u))
				return true;
	}
	return false;
}
bool visit_all()
{
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
			if (dfs(i, -1)) return true;
	}
	return false;
}

void solve() {


	cin >> n >> m;



	int i;
	graph.resize(n + 1);
	for (i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	vis.resize(n + 1);
	parent.resize(n + 1);

	if (!visit_all())
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	int tv = ev;
	vector<int> ans;
	ans.push_back(ev);
	while (tv != sv)
	{
		ans.push_back(parent[tv]);
		tv = parent[tv];
	}
	ans.push_back(ev);
	cout << ans.size() << endl;
	for (auto c : ans)
	{
		cout << c << " ";
	}

}


int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();



}






