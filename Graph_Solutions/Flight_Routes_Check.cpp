
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

const int N = 2e5 + 10;
vi graph[N];
vi transpose[N];
stack<int>se;
void dfs(int node, vi &vis, vi graph[])
{
	vis[node] = 1;

	for (auto &it : graph[node])
	{
		if (!vis[it])
		{
			dfs(it, vis, graph);
		}

	}
	se.push(node);
}


void solve()
{
	int n, m;
	cin >> n >> m;
	int i, j;
	vi vis(n + 1, 0);

	for (i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].pb(v);
		transpose[v].pb(u);
	}

	dfs(1, vis, graph);
	for (i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			cout << "NO\n";
			cout << 1 << " " << i << endl;
			return;
		}
	}
	fill(vis.begin(), vis.end(), 0);
	dfs(1, vis, transpose);
	for (i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			cout << "NO\n";
			cout << i << " " << 1 << endl;
			return;
		}
	}
	cout << "YES\n";
}


int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();



}






