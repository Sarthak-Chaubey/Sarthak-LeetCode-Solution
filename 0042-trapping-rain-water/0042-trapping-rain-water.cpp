class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;
        int area = 0;
        while(left < right) {
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);
            if(maxLeft < maxRight) {
                area += (maxLeft - height[left]);
                left++;
            } else {
                area += (maxRight - height[right]);
                right--;
            }
        }
        return area;
    }
};