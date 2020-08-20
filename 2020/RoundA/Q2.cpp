#include<bits/stdc++.h>

using namespace std;

void calculate(vector<stack<int>> ret, int K, int i)
{
    int count = 0;
    int val = 0;
    while(count < K)
    {
        int check = 0;
        int max_val = 0;
        int index = 0;
        for(int i=0;i<ret.size();i++)
        {
            if(!ret[i].empty())
            {
                if(max_val < ret[i].top())
                {
                    max_val = ret[i].top();
                    index = i;
                }
                check += 1;
            }
        }
        ret[index].pop();
        val += max_val;
        count++;
        if(check == 0)
        break;
    }
    cout<<"Case #"<<i<<": "<<val<<endl;
}

int main()
{
    int T;
    vector<vector<stack<int>>> ret;
    vector<int> vec;
    // cout<<"Enter the no. of test cases: "<<endl;
    cin>>T;
    cout<<endl;
    for(int i=1;i<=T;i++)
    {
        vector<stack<int>> arr;
        int N, P, K;
        cin>>N;
        cin>>P;
        cin>>K;
        cout<<endl;
        vec.push_back(K);
        for(int j=0;j<N;j++)
        {
            vector<int> temp;
            for(int k=0;k<P;k++)
            {
                int val;
                cin>>val;
                temp.push_back(val);
            }
            stack<int> s;
            for(int k=temp.size()-1;k>=0;k--)
            s.push(temp[k]);
            arr.push_back(s);
        }
        ret.push_back(arr);
    }
    for(int i=0;i<ret.size();i++)
    {
        calculate(ret[i], vec[i], i+1);
    }
}

