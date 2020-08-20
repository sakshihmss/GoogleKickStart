#include<bits/stdc++.h>

using namespace std;

void calculate(vector<int> arr, int n, int B, int i)
{
    sort(arr.begin(), arr.end());
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > B)
        {
            break;
        }
        else
        {
            B = B - arr[i];
            count++;
        }
    }
    cout<<"Case #"<<i<<": "<<count<<endl;
}

int main()
{
    int T;
    vector<vector<int>> ret;
    vector<int> vec;
    // cout<<"Enter the no. of test cases: "<<endl;
    cin>>T;
    cout<<endl;
    for(int i=1;i<=T;i++)
    {
        vector<int> arr;
        int N, B;
        cin>>N;
        cin>>B;
        cout<<endl;
        vec.push_back(B);
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
        calculate(ret[i], ret[i].size(), vec[i], i+1);
    }
}