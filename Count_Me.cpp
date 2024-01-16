#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin >>t;
    getchar();
    while (t--)
    {
    string sentence; 
    getline(cin, sentence);
    string word;
    stringstream ss(sentence);
    map<string, int> mp;
    int count = 0;
    string val;

    while (ss >> word)
    {
        mp[word]++;
        if (mp[word] > count)
        {
            count = mp[word];
            val = word;
        }
    }
        cout << val << " " << count << endl;

    }
    return 0;
}
