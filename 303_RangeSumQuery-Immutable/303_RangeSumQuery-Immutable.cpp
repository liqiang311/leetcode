class NumArray {
public:
    vector<int> arr;
    vector<int> sum;
    
    NumArray(vector<int> nums) {
        arr.resize(nums.size());
        for (int i=0; i<arr.size(); i++)
            arr[i] = nums[i];
        sum.resize(arr.size());
        if (arr.size()) sum[0] = arr[0];
        for (int i=1; i<arr.size(); i++)
        {
            sum[i] = sum[i-1] + arr[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j] - sum[i] + arr[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */