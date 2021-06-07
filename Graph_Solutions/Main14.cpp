
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
bool comp(pii a, pii b)
{

	return  a.ss < b.ss;
}
vi  graph[(int)1e5 + 2];

void solve()
{

	int n, m;
	cin >> n >> m;

	vi indegree(n + 1, 0);
	int i;
	for (i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		indegree[v]++;

	}
	queue<int>q;
	for (i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) {
			q.push(i);

		}
	}
	vi ans;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		ans.pb(node);
		for (auto &it : graph[node])
		{
			indegree[it]--;
			if (indegree[it] == 0)
			{
				q.push(it);
			}
		}
	}

	if (ans.size() != n)
	{
		cout << "IMPOSSIBLE";
		return;
	}
	for (auto &it : ans)
		cout << it << " ";

	cout << endl;

}


int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();



}






