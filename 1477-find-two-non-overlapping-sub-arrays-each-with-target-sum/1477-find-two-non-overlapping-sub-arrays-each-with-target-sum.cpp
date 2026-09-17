class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size(),j=0,s=0,mn=INT_MAX,ans=INT_MAX;
        vector<int> a(n,INT_MAX);
        for(int i=0;i<n;i++){
            s+=arr[i];
            while(s>target) s-=arr[j++];
            if(s==target){
                int l=i-j+1;
                if(j>0&&a[j-1]!=INT_MAX) ans=min(ans,l+a[j-1]);
                mn=min(mn,l);
            }
            a[i]=mn;
        }
        return ans==INT_MAX?-1:ans;
    }
};