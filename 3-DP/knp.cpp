#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MAXN 2001
#define MAXW 2001

using namespace std;

int n, S;
vector<int> a, w;
vector<int> ans;
int memo[MAXN][MAXW];
int pred[MAXN][MAXW];
int solve(int id, int rem){
	if(id == n) return 0;
	if(memo[id][rem] >= 0) return memo[id][rem];
	
	int take = -1;
	if(rem >= w[id])
		take = solve(id+1, rem - w[id]) + a[id];
	int notake = solve(id+1, rem);
	if(take > notake){
		memo[id][rem] = take;
		pred[id][rem] = 1;
	}
	else{
		memo[id][rem] = notake;
		pred[id][rem] = 0;
	}
	return memo[id][rem];
}

void printAns(int id, int rem){
	if(id==n) return;
	if(pred[id][rem]){
		ans.push_back(id);
		printAns(id+1, rem - w[id]);
	}
	else printAns(id+1, rem);
}


int main(){
	while(cin >> S){
		cin >> n;
		a = vector<int>(n);
		w = vector<int>(n);
		for(int i=0; i<n; i++)
			cin >> a[i] >> w[i];
		
		memset(memo, -1, sizeof(memo));
		memset(pred, 0, sizeof(pred));
		ans = vector<int>(0);
		
		solve(0, S);
		printAns(0, S);
		cout << ans.size() << endl;
		for(int ii : ans) cout << ii << " ";
		cout << endl;
	}
	
}
