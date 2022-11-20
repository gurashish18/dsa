#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int j = 0;
    while (j < t)
    {
        int n;
        cin >> n;
        priority_queue<int> q;
        vector<int> v;
        vector<int> ans2;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            q.push(x);
            v.push_back(x);
        }
        vector<int> v2 = v;
        if (v.size() == 2)
        {
            cout << "Case #" << j + 1 << ": " << min(v[0], v[1]) << " " << -1 << endl;
        }
        else
        {
            sort(v.begin(), v.end());

            for (int i = 0; i < v.size(); i++)
            {
                int s = 0;
                int e = v.size() - 1;
                int mid = s - (e - s) / 2;
                int ans = -1;
                int target = 2 * v[i];

                while (s <= e)
                {
                    if (v[mid] <= target)
                    {
                        ans = min(v[mid], ans);
                        // ans = v[mid];
                        // cout << ans;
                        s = mid + 1;
                    }
                    else
                    {
                        e = mid - 1;
                    }
                    mid = s - (e - s) / 2;
                }
                ans2.push_back(ans);
            }
        }
        cout << "Case #" << j + 1 << ": ";
        for (int i = 0; i < ans2.size(); i++)
        {
            cout << ans2[i] << " ";
        }
        cout << endl;
        j++;
    }
}