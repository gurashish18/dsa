#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> nums, int target, int original)
{
    int l=0, h=nums.size()-1;
    int ans=-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;

        if(nums[mid]<=(2*original))
        {
            if(nums[mid]!=original)
                ans=nums[mid];
            l=mid+1;
        }
        else
            h=mid-1;
    }
    return ans;
}


vector<int> solve()
{
    int n;
    cin>>n;

    vector<int> ratings(n);
    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        cin>>ratings[i];
    }

    vector<int> nums=ratings;
    sort(nums.begin(), nums.end());

    for(int i=0;i<n;i++)
    {
        int val=bs(nums, ratings[i]*2, ratings[i]);
        ans.push_back(val);
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;


    for(int i=0;i<t;i++)
    {
        vector<int> ans;
        ans = solve();
        cout<<"Case #"<<i+1<<": ";
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}