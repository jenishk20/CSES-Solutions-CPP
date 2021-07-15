#include<bits/stdc++.h>

using namespace std;


#define ff              first
#define ss              second
#define int 			long long
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
#define mt               make_tuple
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define REP(i,n) for(i=0;i<n;i++)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll 				long long
const long long   M = 1e9 + 7;

void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
}

bool ok(vi temp)
{
	int n = temp.size();
	if (n <= 2)
		return 1;
	if (n >= 5)
		return 0;

	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				if (temp[i] >= temp[j] && temp[j] >= temp[k] ||
				        temp[i] <= temp[j] && temp[j] <= temp[k])
					return false;
			}
		}
	}
	return true;
}
void solve()
{
	int n, x;
	cin >> n >> x;

	int a[n];
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	//cout << a[0] << endl;
	i = 0;
	int j = 0;
	int sum = 0;
	int c = 0;
	while (i < n)
	{
		sum += a[i];

		while (sum >= x)
		{
			if (sum == x)
				c++;
			sum -= a[j];
			j++;
		}
		i++;
	}
	cout << c << endl;

}

int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();

	return 0;



}





