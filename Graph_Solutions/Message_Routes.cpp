
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
void solve() {

	int n, m;
	cin >> n >> m;

	vi graph[n + 1];

	int i;
	for (i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	vi dis(n + 1, -1);

	queue<int>q;
	q.push(1);
	vi parent(n + 1);
	dis[1] = 0;


	parent[1] = -1;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		if (node == n)
		{
			break;
		}
		for (auto &it : graph[node])
		{
			if (dis[it] == -1)
			{
				dis[it] = dis[node] + 1;
				q.push(it);
				parent[it] = node;
			}
		}
	}
	if (dis[n] == -1)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
	int node = n;
	vi res;
	while (1)
	{
		if (node == -1)
			break;

		//cout << node << ' ';
		res.insert(res.begin(), node);
		node = parent[node];
	}
	cout << res.size() << endl;
	for (auto &it : res)
	{
		cout << it << " ";
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






