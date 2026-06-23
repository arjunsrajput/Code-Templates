#include<bits/stdc++.h>
using namespace std;
vector<int> NextGreaterElement(vector<int> & arr){
    int n=arr.size();
    stack<int>stk;
    vector<int>nge(n,-1);
    for(int i=n-1; i>=0; i--){
        while(!stk.empty() && stk.top()<=arr[i]) stk.pop();
        nge[i]=stk.empty()?-1:stk.top();
        stk.push(arr[i]);
    }
    return nge;
}
vector<int> PreviousGreaterElement(vector<int> & arr){
    int n=arr.size();
    stack<int>stk;
    vector<int>pge(n,-1);
    for(int i=0; i<n; i++){
        while(!stk.empty() && stk.top()<=arr[i]) stk.pop();
        pge[i]=stk.empty()?-1:stk.top();
        stk.push(arr[i]);
    }
    return pge;
}
int main(){
    vector<int>arr={1,2,63,2,7,77,5,3,25,6,2};
    vector<int>nge=NextGreaterElement(arr);
    for(auto it : nge){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int>pge=PreviousGreaterElement(arr);
    for(auto it : pge){
        cout<<it<<" ";
    }
    return 0;
}