#include <bits/stdc++.h>
using namespace std;
class DSU
{
    vector<int> parent, rank,size;

public:
    DSU(int n)
        {
            parent.resize(n + 1, 0);
            rank.resize(n + 1, 0);
            size.resize(n + 1, 0);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
                size[i]=1;
            }
        }
    int findParent(int u)
        {
            if (u == parent[u]) return u;
            return parent[u] = findParent(parent[u]); // finding parent with path compression
        }

    void unionByRank(int u, int v)
        {
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if (ulp_u == ulp_v)
                return;
            if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
            else if (rank[ulp_u] > rank[ulp_v])  parent[ulp_v] = ulp_u;
            else
            {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v)
            {
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if (ulp_u == ulp_v)
                return;
            if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            }else{                // for equal size case we can attach to anyone so no need to write explicit else if
                parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
            }
           }
};

int main()
{
    DSU ds(7);
    //(1,2)(2,3)(4,5)(6,7)(5,6)
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // check if 3 or 7 belong to same component/group
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "Not same till now" << endl;
    }
    ds.unionByRank(3, 7);

    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "Not same till now" << endl;
    }
    return 0;
}