class Solution 
{
public:
    void calculate(int n,vector<bool>&vis,int i,int & count)
    {
        if (i>n)
        {
            count++;
            return;
        }
        for (int j=1;j<=n;j++)
        {
            if (!vis[j]&&(i%j==0||j%i==0))
            {
            vis[j]=true;
            calculate(n,vis,i+1,count);
            vis[j]=false;
            }
        }
    }
    int countArrangement(int n) 
    {
        int count=0;
        vector<bool>vis(n+1,false);
        calculate(n,vis,1,count);
        return count;
    }
};