class Solution {
public:
    void beautiful (int i,int n,int &count,vector<bool>&vis)
    {
        if (i>n)
        {
            count+=1;
            return;
        }
        for (int j=1;j<=n;j++)
        {
            if (!vis[j]&&(i%j==0||j%i==0))
            {
                vis[j]=true;
                beautiful(i+1,n,count,vis);
                vis[j]=false;
            }
        }
    }

    int countArrangement(int n) 
    {
        int count=0;
        vector<bool>vis(n+1,false);
        beautiful(1,n,count,vis);
        return count;
    }
};