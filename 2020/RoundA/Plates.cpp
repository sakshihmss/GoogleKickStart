#include<bits/stdc++.h>
using namespace std;

// think in a way that we can pick 0 to p plates from every stack

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int N, K, P;
        cin>>N;
        cin>>K;
        cin>>P;
        int sum[N+1][K+1];
        memset(sum, 0, sizeof(sum));
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=K;k++)
            {
                int value;
                cin>>value;
                sum[j][k] = sum[j][k-1] + value;
            }
        }
        
        int dp[N+1][P+1];
        memset(dp, 0, sizeof(dp));
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=K;k++)
            {
                for(int p=k;p<=P;p++)
                {
                    dp[j][p] = max(dp[j][p], max(dp[j-1][p], dp[j-1][p-k] + sum[j][k]));
                }
            }
        }
        cout<<"Case #"<<i<<": "<<dp[N][P]<<endl;
    }
    return 0;
}

