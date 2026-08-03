class Solution {
public:
    int maxProfit(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        int bought_for=INT_MAX,sold_for=INT_MIN;
        for (int i=0;i<n;i++)
        {
            bool bought=false;
            if (nums[i]<bought_for)
            {
                bought_for=nums[i];
                bought=true;
                sold_for=INT_MIN;
            }
            if (!bought&& nums[i]>sold_for)
            {
                sold_for=nums[i];
            }
            if (sold_for!=INT_MIN&&bought_for!=INT_MAX)
            ans=max(ans,(sold_for-bought_for));
        }
        return ans;
    }
};