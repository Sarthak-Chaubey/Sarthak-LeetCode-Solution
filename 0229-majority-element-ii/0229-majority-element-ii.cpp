

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        int count1 = 0, count2 = 0;
        int num1 = INT_MIN, num2 = INT_MIN;

        vector<int> ans;

        // 🔍 Find two potential candidates
        for (int num : nums) {

            if (count1 == 0 && num2 != num) {
                num1 = num;
                count1++;
            }
            else if (count2 == 0 && num1 != num) {
                num2 = num;
                count2++;
            }
            else if (num == num1) {
                count1++;
            }
            else if (num == num2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == num1) count1++;
            else if (num == num2) count2++;
        }

        if (count1 > n / 3)
            ans.push_back(num1);

        if (count2 > n / 3)
            ans.push_back(num2);

        return ans;
    }
};