#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
SEGMENT TREE (Range Sum Query + Point Update)

Operations:
1. Build        -> O(n)
2. Range Query  -> O(log n)
3. Point Update -> O(log n)

Tree Representation (0-based indexing)

Parent      = i
Left Child  = 2*i + 1
Right Child = 2*i + 2
===========================================================
*/

//----------------------------------------------------------
// Build Segment Tree
//
// i -> current node index in segment tree
// l -> left boundary of current segment
// r -> right boundary of current segment
//----------------------------------------------------------
void buildSegmentTree(int i, int l, int r,
                      vector<int> &segmentTree,
                      vector<int> &arr)
{
    // Leaf node
    if (l == r)
    {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;

    // Build left subtree
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);

    // Build right subtree
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);

    // Merge children's answer
    segmentTree[i] =
        segmentTree[2 * i + 1] +
        segmentTree[2 * i + 2];
}

//----------------------------------------------------------
// Range Sum Query
//
// Query Range  : [start, end]
// Current Node : [l, r]
//
// Three Cases:
//
// 1. No Overlap
//      return 0
//
// 2. Complete Overlap
//      return current node value
//
// 3. Partial Overlap
//      recurse on both children
//----------------------------------------------------------
int query(int start, int end,
          int i,
          int l,
          int r,
          vector<int> &segmentTree)
{
    // -------------------------
    // Case 1 : No Overlap
    // -------------------------
    //
    // Query :     [5------8]
    //
    // Current:
    // [0---3]
    //
    if (r < start || l > end)
        return 0;

    // -------------------------
    // Case 2 : Complete Overlap
    // -------------------------
    //
    // Query :
    // [2-------------8]
    //
    // Current :
    //      [3-----5]
    //
    if (start <= l && r <= end)
        return segmentTree[i];

    // -------------------------
    // Case 3 : Partial Overlap
    // -------------------------
    int mid = l + (r - l) / 2;

    int leftSum =
        query(start, end,
              2 * i + 1,
              l, mid,
              segmentTree);

    int rightSum =
        query(start, end,
              2 * i + 2,
              mid + 1, r,
              segmentTree);

    return leftSum + rightSum;
}

//----------------------------------------------------------
// Point Update
//
// Update arr[idx] = val
//
// Only nodes containing idx are updated.
//
// Example:
//
//               [0,7]
//              /
//          [0,3]
//             \
//            [2,3]
//             /
//          [3,3]
//
// After updating leaf,
// update all its ancestors.
//----------------------------------------------------------
void update(int idx,
            int val,
            int i,
            int l,
            int r,
            vector<int> &segmentTree)
{
    // Reached target element
    if (l == r)
    {
        segmentTree[i] = val;
        return;
    }

    int mid = l + (r - l) / 2;

    // Decide whether idx lies in left or right half
    if (idx <= mid)
        update(idx, val,
               2 * i + 1,
               l, mid,
               segmentTree);
    else
        update(idx, val,
               2 * i + 2,
               mid + 1, r,
               segmentTree);

    // Recompute current node after child update
    segmentTree[i] =
        segmentTree[2 * i + 1] +
        segmentTree[2 * i + 2];
}

//----------------------------------------------------------
// Utility Function
//----------------------------------------------------------
void printArray(vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    int n = arr.size();

    // Allocate Segment Tree
    // 4*n is sufficient for recursive implementation
    vector<int> segmentTree(4 * n);

    //----------------------------
    // BUILD
    //----------------------------
    buildSegmentTree(0, 0, n - 1,
                     segmentTree,
                     arr);

    cout << "Original Array\n";
    printArray(arr);

    cout << "\n";

    //--------------------------------------------------
    // QUERIES
    //--------------------------------------------------

    cout << "========== RANGE SUM QUERIES ==========\n";

    cout << "Sum [0,9] = "
         << query(0,9,0,0,n-1,segmentTree)
         << "\n";

    cout << "Sum [0,4] = "
         << query(0,4,0,0,n-1,segmentTree)
         << "\n";

    cout << "Sum [2,4] = "
         << query(2,4,0,0,n-1,segmentTree)
         << "\n";

    cout << "Sum [3,7] = "
         << query(3,7,0,0,n-1,segmentTree)
         << "\n";

    cout << "Sum [5,9] = "
         << query(5,9,0,0,n-1,segmentTree)
         << "\n";

    cout << "\n";

    //--------------------------------------------------
    // UPDATE 1
    //--------------------------------------------------

    cout << "========== UPDATE ==========\n";

    cout << "Updating index 3 to 100\n";

    arr[3] = 100;

    update(3,100,0,0,n-1,segmentTree);

    printArray(arr);

    cout << "\n";

    cout << "Sum [2,4] = "
         << query(2,4,0,0,n-1,segmentTree)
         << "\n";

    cout << "Sum [0,9] = "
         << query(0,9,0,0,n-1,segmentTree)
         << "\n";

    cout << "\n";

    //--------------------------------------------------
    // UPDATE 2
    //--------------------------------------------------

    cout << "Updating index 0 to 50\n";

    arr[0] = 50;

    update(0,50,0,0,n-1,segmentTree);

    printArray(arr);

    cout << "Sum [0,2] = "
         << query(0,2,0,0,n-1,segmentTree)
         << "\n\n";

    //--------------------------------------------------
    // UPDATE 3
    //--------------------------------------------------

    cout << "Updating index 9 to 20\n";

    arr[9] = 20;

    update(9,20,0,0,n-1,segmentTree);

    printArray(arr);

    cout << "Sum [7,9] = "
         << query(7,9,0,0,n-1,segmentTree)
         << "\n";

    cout << "Sum [0,9] = "
         << query(0,9,0,0,n-1,segmentTree)
         << "\n";

    return 0;
}