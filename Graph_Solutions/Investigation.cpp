
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
vector<pii>graph[(int)1e5 + 4];
void solve()
{
	int n, m;
	cin >> n >> m;
	int i;

	for (i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].pb({b, c});
	}
	int inf = 1e18;
	vi dis(n + 1, inf);
	dis[1] = 0;
	vi route(n + 1);
	vi min_f(n + 1);
	vi max_f(n + 1);
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	route[1] = 1;
	pq.push({0, 1});
	while (!pq.empty())
	{
		pii p = pq.top();
		pq.pop();
		int node = p.ss;
		int distance = p.ff;
		if (distance > dis[node]) {

			//cout << node << " " << distance << " " << dis[node] << endl;
			continue;
		}
		for (auto &it : graph[node])
		{
			int nextNode = it.ff;
			int nextDis = it.ss;
			//if (dis[nextNode] < dis[node] + nextDis)continue;
			if (dis[nextNode] == dis[node] + nextDis)
			{
				route[nextNode] = (route[nextNode] + route[node]) % M;

				min_f[nextNode] = min(min_f[nextNode], min_f[node] + 1);
				max_f[nextNode] = max(max_f[node] + 1, max_f[nextNode]);
			}
			else if (dis[nextNode] > dis[node] + nextDis)
			{

				dis[nextNode] = dis[node] + nextDis;
				pq.push({dis[nextNode], nextNode});
				route[nextNode] = route[node];
				min_f[nextNode] = min_f[node] + 1;
				max_f[nextNode] = max_f[node] + 1;
			}
		}
	}

	cout << dis[n] << " " << route[n] << " " << min_f[n] << " " << max_f[n] << endl;
}

int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();



}





