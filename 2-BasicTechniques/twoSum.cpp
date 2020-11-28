class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int i=0, j = a.size()-1;
        vector<int> ans;
        while(i<j){
            if(a[i]+a[j]==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(a[i]+a[j] < target) i++;
            else j--;
        }
        return ans;
    }
};