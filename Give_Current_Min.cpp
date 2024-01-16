#include <bits/stdc++.h>
using namespace std;
void insert_heap(vector<int> &v, int x)
{
    v.push_back(x);
    int cur_idx = v.size() - 1;
    while (cur_idx != 0)
    {
        int parent_idx = (cur_idx - 1) / 2;
        if (v[parent_idx] > v[cur_idx])
            swap(v[parent_idx], v[cur_idx]);
        else
            break;
        cur_idx = parent_idx;
    }
}
void delete_heap(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int cur = 0;
    while (true)
    {
        int left_idx = cur * 2 + 1;
        int right_idx = cur * 2 + 2;
        int last_idx = v.size() - 1;
        if (left_idx <= last_idx && right_idx <= last_idx)
        {
            // duitai ache
            if (v[left_idx] <= v[right_idx] && v[left_idx] < v[cur])
            {
                swap(v[left_idx], v[cur]);
                cur = left_idx;
            }
            else if (v[right_idx] <= v[left_idx] && v[right_idx] < v[cur])
            {
                swap(v[right_idx], v[cur]);
                cur = right_idx;
            }
            else
            {
                break;
            }
        }
        else if (left_idx <= last_idx)
        {
            // left ase
            if (v[left_idx] < v[cur])
            {
                swap(v[left_idx], v[cur]);
                cur = left_idx;
            }
            else
            {
                break;
            }
        }
        else if (right_idx <= last_idx)
        {
            // right ase
            if (v[right_idx] < v[cur])
            {
                swap(v[right_idx], v[cur]);
                cur = right_idx;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}
void print_heap(vector<int> v)
{
    if (v.empty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << v.front() << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert_heap(v, x);
    }
    int q;
    cin >> q;
    while (q--)
    {

        int option;
        cin >> option;
        if (option == 0)
        {
            cin >> x;
            insert_heap(v, x);
            if(v.size()>0)
            print_heap(v);
            else
             cout<<"Empty";
        }
        else if (option == 1)
        {
            if(v.size()>0)
                print_heap(v);
            else
                cout<<"Empty";
        }
        else if (option == 2)
        {
            if(v.size()>0)
                delete_heap(v);
            if(v.size()>0)
                print_heap(v);
            else
            cout<<"Empty"<<endl;
        }
    }

    return 0;
}