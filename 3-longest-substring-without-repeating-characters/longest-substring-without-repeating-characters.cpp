class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.size();
        if (n==0)
        return 0;
        int i=1;
        int cnt=0;
        int ans=1;
        int left=0;
        unordered_map<char,int>mpp;
        mpp[s[0]]=0;
        while (i<n)
        {
            char ch=s[i];
            if (mpp.find(ch)!=mpp.end())
            left=max(left,mpp[ch]+1);
            mpp[ch]=i;
            cnt=i-left+1;
            ans=max(ans,cnt);
            i++;
        }
        return ans;
    }
};