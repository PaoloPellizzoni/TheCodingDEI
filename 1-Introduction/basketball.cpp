#include <bits/stdc++.h>
using namespace std;

int n, p, m;
string s;
int main(){
	cin >> n >> p >> m;
	unordered_map<string, int> map;
	for(int i=0; i<n; i++){
		cin >> s;
		map[s] = 0;
	}
	bool flg = false;
	for(int i=0; i<m; i++){
		int tmp;
		cin >> s;
		cin >> tmp;
		map[s] += tmp;
		if(map[s] >= p){
			flg = true;
			cout << s << " wins!\n";
			map[s] = -100000000;
		}
		
	}
	if(!flg)
		cout << "No winner!\n";
}
    