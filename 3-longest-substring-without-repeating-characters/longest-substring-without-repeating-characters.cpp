class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.size();
        if (n==0)
        return 0;
        int ans=1,left=0;
        unordered_map<char,int>mpp;
        for (int i=0;i<n;i++)
        {
            char ch=s[i];
            if (mpp.find(ch)!=mpp.end())
            left=max(left,mpp[ch]+1);
            mpp[ch]=i;
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};