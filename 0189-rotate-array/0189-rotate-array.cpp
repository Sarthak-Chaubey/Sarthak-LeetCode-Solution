class Solution {
public:
    void rev(vector<int>& nums,int left, int right){
        while(left<right)
        {
            swap(nums[left],nums[right]);
                left++;
                right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k = k%n;
        rev(nums,0,n-1);
        rev(nums,0,k-1);
        rev(nums,k,n-1);
    }
};