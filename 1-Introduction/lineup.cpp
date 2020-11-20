#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
	cin >> n;
	vector<string> v;
	vector<string> incr;
	vector<string> decr;
	for(int i=0; i<n; i++){
		string s; 
		cin >> s;
		v.push_back(s);
		incr.push_back(s);
		decr.push_back(s);
	}
	sort(incr.begin(), incr.end());
	sort(decr.begin(), decr.end(), greater<string>() );
	
	bool flg = true;
	for(int i=0; i<n; i++){
		if(v[i] != incr[i]){
			flg = false;
			break;
		}
	}
	if(flg){
		cout << "INCREASING\n";
		return 0;
	}
	flg = true;
	for(int i=0; i<n; i++){
		if(v[i] != decr[i]){
			flg = false;
			break;
		}
	}
	if(flg){
		cout << "DECREASING\n";
		return 0;
	}
	cout << "NEITHER";
}
    