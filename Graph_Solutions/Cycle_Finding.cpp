
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
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

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
int  add(int a, int b)
{
	return mod(mod(a) + mod(b));
}
bool f(int x, int y)
{
	return x > y;
}
int powmod(int a, int b)
{
	int res = 1;
	a = a % M;
	while (b)
	{
		if (b % 2 == 0)
		{
			b /= 2;
			a = (a * a) % M;
		}
		else
		{
			b = b - 1;
			res = (res * a) % M;
		}
	}
	return res;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<vi>graph;
	int i;
	for (i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vi temp;
		temp.pb(u);
		temp.pb(v);
		temp.pb(w);
		graph.pb(temp);
	}
	vi dist(n + 1);
	dist[1] = 0;
	vi par(n + 1, -1);

	int st = -1;
	for (i = 0; i < n; i++)
	{
		st = -1;
		for (int j = 0; j < m; j++)
		{
			int u = graph[j][0];
			int v = graph[j][1];
			int wt = graph[j][2];

			if (dist[v] > dist[u] + wt)
			{
				dist[v] = dist[u] + wt;
				par[v] = u;
				st = v;

			}

		}
	}

	if (st != -1) {
		cout << "YES\n";

		for (i = 1; i <= n; i++)
		{
			st = par[st];

		}

		vi cycle;
		for (int v = st;; v = par[v])
		{
			cycle.pb(v);

			if (v == st && cycle.size() > 1)
			{
				break;
			}
		}
		reverse(cycle.begin(), cycle.end());
		for (auto &it : cycle)
			cout << it << " ";

	}
	else
	{
		cout << "NO";
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





