#include<bits/stdc++.h>

using namespace std;

void calculate(vector<int> arr, int K, int i)
{
    map<int, int> temp;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(temp.find(arr[i+1]-arr[i]) != temp.end() )
        temp[arr[i+1]-arr[i]] = 1;
        else
        {
            /* code */
            temp[arr[i+1]-arr[i]] += 1;
        }
        
    }
    int count  = 0;
    while(count < K)
    {
        int hehe = temp.rbegin()->first;
        if(hehe == 1)
        {
            cout<<"Case #"<<i<<": "<<1<<endl;
            return;
        }
        int val = hehe/2;
        int val2 = hehe-val;
        if(temp[hehe] == 1)
        temp.erase(hehe);
        else 
        temp[hehe]--;
        temp[val] += 1;
        temp[val2] += 1;
        count++;
    }
    cout<<"Case #"<<i<<": "<<temp.rbegin()->first<<endl;
}


int main()
{
    int T;
    vector<vector<int>> ret;
    vector<int> vec;
    // cout<<"Enter the no. of test cases: "<<endl;
    cin>>T;
    cout<<endl;
    cout<<endl;
    for(int i=1;i<=T;i++)
    {
        vector<int> arr;
        int N, K;
        cin>>N;
        cin>>K;
        vec.push_back(K);
        for(int j=0;j<N;j++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
        }
        ret.push_back(arr);
    }
    for(int i=0;i<ret.size();i++)
    {
        calculate(ret[i], vec[i], i+1);
    }
}