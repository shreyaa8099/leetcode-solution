class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        stack<int>st;
        int s=logs.size();
        vector<int>ans(n,0);
        int last_time=0;
        for (int i=0;i<s;i++)
        {
            string str=logs[i];
            stringstream ss(str);
            string temp;
            getline(ss,temp,':');
            int id=stoi(temp);
            getline(ss,temp,':');
            string type=temp;
            getline(ss,temp,':');
            int time=stoi(temp);

            if (type=="start")
            {
                if (!st.empty())
                ans[st.top()]+=time-last_time;
                st.push(id);
                last_time=time;
            }
            else if (type=="end")
            {
                ans[st.top()]+=time-last_time+1;
                
                st.pop();
                last_time=time+1;
            }
           
        }
        return ans;
    }
};