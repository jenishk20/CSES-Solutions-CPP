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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
bool cmp(pii p1, pii p2)
{
	if (p1.ss > p2.ss)
		return true;

	else
		return false;
}
void solve()
{
	int n;
	cin >> n;

	map<int, bool> ma;

	int i;
	for (i = 0; i < n; i++)
	{
		int x, y;

		cin >> x >> y;
		ma[x] = 1;
		ma[y] = 0;
	}
	int c = 1;

	int ans = 0;
	int maxi = 0;
	for (auto &it : ma)
	{
		if (it.ss)
		{
			ans++;
			maxi = max(maxi, ans);

		}
		else
		{
			ans--;
		}

	}
	cout << maxi << endl;


}




int32_t main()
{

	//c_p_c();

	FIO;
	//w(t)
	solve();


}