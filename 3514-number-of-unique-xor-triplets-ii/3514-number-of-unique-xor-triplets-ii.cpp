class Solution {
public:
    int n;
    bool store[2048];
    int ans;
    bool vis[1505][4][2048];

    void solve(int idx, int cnt, int xr, vector<int>& nums) {
        if (cnt == 3) {
            if (!store[xr]) {
                store[xr] = true;
                ans++;
            }
            return;
        }

        if (idx >= n) return;

        if (vis[idx][cnt][xr]) return;
        vis[idx][cnt][xr] = true;

        solve(idx, cnt + 1, xr ^ nums[idx], nums);
        solve(idx + 1, cnt, xr, nums);
    }
    int uniqueXorTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        n = nums.size();
        ans = 0;

        memset(store, false, sizeof(store));
        memset(vis, false, sizeof(vis));

        solve(0, 0, 0, nums);

        return ans;
    }
};