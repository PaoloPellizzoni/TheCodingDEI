#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MAXN 2001
#define MAXW 2001

using namespace std;

int n, S;
vector<vector<int>> a, w;
vector<int> ans;
int bestFirst;
int memo[MAXN][MAXW];

int solve(int id, int rem){
	if(id == n) return 0;
	if(memo[id][rem] >= 0) return memo[id][rem];
	
	int maxv = 0;
	for(int i=0; i<a[id].size(); i++){
		int maxp = min(rem, w[id][i]);
		int tmp = a[id][i]*maxp + solve(id+1, rem - maxp);
		if(tmp > maxv){
			maxv = tmp;
			if(id == 0)
				bestFirst = a[0][i];
		}
	}
	
	return memo[id][rem] = maxv;
}


int main(){
	cin >> S >> n;
	n++;
	a = vector<vector<int>>(n);
	w = vector<vector<int>>(n);
	for(int i=0; i<n; i++){
		int k;
		cin >> k;
		a[i] = vector<int>(k);
		w[i] = vector<int>(k);
		for(int j=0; j<k; j++){
			cin >> a[i][j]; // price
		}
		for(int j=0; j<k; j++){
			cin >> w[i][j]; // peopl
		}
		
	}
	
	memset(memo, -1, sizeof(memo));
	
	cout << solve(0, S) << endl;
	cout << bestFirst << endl;
	
}
