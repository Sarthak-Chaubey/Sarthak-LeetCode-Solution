class Solution {

void subsetSum(int idx, int sum, int size, vector<vector<int>> &arr, vector<int> &nums){
    if(idx < 0) {
        arr[size].push_back(sum); // pushing the elements in array
        return ;
    }

    subsetSum(idx - 1, sum + nums[idx], size + 1, arr, nums); // take
    subsetSum(idx - 1, sum, size, arr, nums); // notTake
}

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);

        int N = n/2;
        vector<int> left, right;
        for(int i = 0; i < N; i++){
            left.push_back(nums[i]); // creating a left array which consist elements from index i = 0 to i = n/2 - 1.
            right.push_back(nums[i + N]); // creating a right array which consist element from index i = n/2 to i = n - 1.
        }

        vector<vector<int>> left_sum(N+1), right_sum(N+1); // creating a two vector left_sum and right_sum for all possible subset sum.

        subsetSum(N-1, 0, 0, left_sum, left); // finiding all subset sum for leftPart
        subsetSum(N-1, 0, 0, right_sum, right); // finding all subset sum for rightPart


        for(int i = 0; i < N; i++){
            sort(right_sum[i].begin(), right_sum[i].end()); // sorting all possible size subsetSum for the rightPart
        }
        
        int res = abs(right_sum[N][0] - left_sum[N][0]); // It means you have all elements from left and right then what will be the absoulte difference 

        for(int subsetSize = 1; subsetSize < N; subsetSize++){ // iterating from subsetSize 1 means all subset possible of size 1 to N for the leftPart.

            for(auto &a: left_sum[subsetSize]){
                int target = sum/2 - a; // target to search in the rightPart

                int rightIdx = N - subsetSize; // subsetSize of the rightPart

                auto &v = right_sum[rightIdx]; // all sub possbile of rightIdx size.

                auto itr = lower_bound(v.begin(), v.end(), target); // target itr 

                if(itr != v.end()){
                    int leftSum = a + *itr; // now total sum of the leftPart
                    int rightSum = sum - leftSum; // now according to the leftPart the rightSum
                    res = min(res, abs(rightSum - leftSum)); // absoulte difference between them.
                }
            }
        }
    
        return res;

    }
};