#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int N, K;
        cin>>N;
        cin>>K;
        int prev;
        cin>>prev;
        cout<<prev<<endl;
        priority_queue<int> pq;
        for(int j=1;j<N;i++)
        {
            int val;
            cin>>val;
            pq.push(val-prev);
            prev = val;
        }
        cout<<pq.top()<<endl;
        for(int j=1;j<=K;j++)
        {
            int val = pq.top();
            pq.pop();
            if(val%2 == 0)
            {
                pq.push(val/2);
                pq.push(val/2);
            }
            else
            {
                pq.push(val/2);
                pq.push((val/2)+1);
            }
        }
        cout<<"Case #"<<i<<": "<<1<<endl;
    }
    return 0;
}