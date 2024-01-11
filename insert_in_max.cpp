#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        int cut_idx = v.size() - 1;
        while (cut_idx != 0)
        {
            int prents_idx = (cut_idx - 1) / 2;
            if (v[prents_idx] < v[cut_idx])
            {
                swap(v[prents_idx], v[cut_idx]);
            }
            else
                break;
            cut_idx = prents_idx;
        }
    }
    for(int val:v){

        cout<< val<<" ";

    }

    return 0;
}
