class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int>s(nums.begin(),nums.end());
        for(auto &it:s){
            if(s.find(it-1)==s.end()){
                int x = it;
                int cnt = 1;
                while(s.find(x+1)!=s.end()){
                    x++;
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};