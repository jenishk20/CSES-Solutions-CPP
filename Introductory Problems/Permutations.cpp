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

#define inf 1e9
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

bool check(unsigned int x)
{
	return !(x & (x - 1));
}
int lcm(int a, int b)
{
	return (a * b) / __gcd(a, b);
}
void solve()
{


	int n;
	cin >> n;

	int i;
	if (n == 1)
	{
		cout << "1";
		return;
	}
	if (n == 2 || n == 3)
	{
		cout << "NO SOLUTION";
		return;
	}
	for (i = 2; i <= n; i += 2)
	{
		cout << i << " ";
	}
	for (i = 1; i <= n; i += 2)
		cout << i << " ";





}




int32_t main()
{
	//c_p_c();
	FIO;

	//w(t)
	solve();

}