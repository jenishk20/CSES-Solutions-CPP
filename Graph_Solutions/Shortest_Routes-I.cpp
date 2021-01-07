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


#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define REP(i,n) for(i=0;i<n;i++)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int M = 1e9 + 7;
long long mod(long long x) {
	return ((x % M + M) % M);
}
long long add(long long a, long long b) {
	return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b) {
	return mod(mod(a) * mod(b));
}
bool f(int x, int y)
{
	return x > y;
}

const int N = 1e5 + 5;
const int inf = 1e15;
vector<pii>graph[N];
vi dis(N + 1, inf), vis(N + 1, 0);
int n, m;
void solve()
{


	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		graph[a].pb({b, w});
		//graph[b].pb({a, w});
	}

	priority_queue<pii, vector<pii>, greater<pii>>pq;

	dis[1] = 0;
	//vis[1] = 1;
	pq.push({0, 1});
	while (!pq.empty())
	{
		pii curr = pq.top();
		pq.pop();


		int node = curr.ss;
		int dist = curr.ff;
		if (vis[node])
			continue;

		vis[node] = 1;
		for (pii p : graph[node])
		{

			if (!vis[p.ff]) {

				if (dis[p.ff] > dist + p.ss)
				{
					dis[p.ff] = dist + p.ss;

					pq.push({dis[p.ff], p.ff});
				}
			}
		}
	}


	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
}




int32_t main()
{
	//c_p_c();
	FIO;
	solve();

}