#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        list<int>myList;
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            myList.push_back(val);
        }
        myList.sort();
        myList.unique();
        for(int value:myList){
            cout<<value<<" ";
        }
        cout<<endl;

    }
    return 0;
}

