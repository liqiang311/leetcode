class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        res.resize(2);
        int n = nums.size();
        int *sign = new int[n];
        memset(sign,0,sizeof(int)*n);
        for (int i=0; i<n; i++)
        {
            sign[nums[i]-1] ++;
            if (sign[nums[i]-1]==2) res[0]=nums[i];
        }
        for (int i=0; i<n; i++)
        {
            if (sign[i] == 0){ res[1] = i+1; delete sign; return res;}
        }
        delete sign;
        return res;
    }
};