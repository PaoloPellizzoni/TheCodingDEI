class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, cur = 0;
        int i=0,j=0,n=s.size();
        while(j < n){
            cur += abs(s[j]-t[j]);
            j++;
            while(cur > maxCost){
                cur -= abs(s[i]-t[i]);
                i++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};

