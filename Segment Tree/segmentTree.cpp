#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int i,int l, int r, vector<int> &segmentTree,vector<int> &arr){

    if(l==r){
        segmentTree[i]=arr[l]; //since arr[l]==arr[r]
        return;
    }
    int mid=l+(r-l)/2;
    buildSegmentTree(2*i+1,l,mid,segmentTree,arr);
    buildSegmentTree(2*i+2,mid+1,r,segmentTree,arr);
    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
}
int query(int start,int end, int i,int l,int r,vector<int> &segmentTree){
    // Case 1 : No overlap
    if(r<start || l>end) {
        return 0; //Out of bound (left & right both side)
    }

    // Case 2 : Complete overlap
    if(l>=start && r<=end){
        return segmentTree[i]; // cur is part of range so it will contribute [l,r] subset of [start,end]
    }

    // Case 3 : Partial overlap
    int mid=l+(r-l)/2;
    return query(start,end,2*i+1,l,mid,segmentTree)+query(start,end,2*i+2,mid+1,r,segmentTree);

}
void update(int idx, int val, int i, int l, int r,
            vector<int>& seg) {
    if (l == r) {
        seg[i] = val;
        return;
    }

    int mid = l + (r - l) / 2;

    if (idx <= mid)
        update(idx, val, 2 * i + 1, l, mid, seg);
    else
        update(idx, val, 2 * i + 2, mid + 1, r, seg);

    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}
int main() {
    int n=10;
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    vector<int>segmentTree(4*n);
    buildSegmentTree(0,0,9,segmentTree,arr);
    cout<<query(2,4,0,0,9,segmentTree);

    return 0;
}