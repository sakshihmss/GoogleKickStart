#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int N;
        cin>>N;
        vector<string> temp;
        for(int j=0;j<=N;j++)
        {
            string s;
            getline(cin, s);
            temp.push_back(s);
        }
        int max = 0;
        string ans = "";
        for(int j=0;j<temp.size();j++)
        {
            unordered_map<char, int> m;
            string st = temp[j];
            int count = 0;
            for(int k=0;k<st.length();k++)
            {
                if(st[k] != ' '){
                    if(m.find(st[k]) == m.end())
                    {
                        m[st[k]] = 1;
                        count++;
                    }
                }
            }
            if(count > max)
            {
                max = count;
                ans = st;
            }
            else if(count == max)
            {
                if(st < ans)
                {
                    ans = st;
                }
            }
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}