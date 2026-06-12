# Disjoint Set Union (DSU) / Union Find

## What is DSU?

Disjoint Set Union (DSU), also known as Union Find, is a data structure used to efficiently maintain a collection of disjoint (non-overlapping) sets.

It supports two primary operations:

1. Find → Determine which set an element belongs to.
2. Union → Merge two sets into one.

---

## Applications

- Detecting cycles in an undirected graph
- Kruskal's Minimum Spanning Tree (MST)
- Finding connected components
- Dynamic connectivity problems
- Number of Provinces
- Number of Islands
- Accounts Merge
- Network connectivity problems

---

## Core Operations

### Find Parent

Returns the ultimate parent (representative) of a node.

```cpp
int findParent(int u) {
    if (u == parent[u]) return u;
    return parent[u] = findParent(parent[u]); // Path Compression
}
```

### Union

Merges two components if they belong to different sets.

---

## Path Compression

### Idea

While finding the ultimate parent, directly connect every visited node to the root.

Before:

1 <- 2 <- 3 <- 4

After findParent(4):

      1
    / | \
   2  3  4

### Benefit

- Flattens the tree
- Makes future find operations much faster
- Essential for achieving near O(1) complexity

---

## Union By Rank

### Idea

Attach the smaller-height tree under the larger-height tree.

### Implementation

```cpp
void unionByRank(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    if (pu == pv) return;

    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    }
    else if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    }
    else {
        parent[pv] = pu;
        rank[pu]++;
    }
}
```

### Rank Meaning

Rank approximates the height of the tree.

### Important Point

Rank increases only when both trees have the same rank.

---

## Union By Size

### Idea

Attach the smaller component under the larger component.

### Implementation

```cpp
void unionBySize(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    if (pu == pv) return;

    if (size[pu] < size[pv]) {
        parent[pu] = pv;
        size[pv] += size[pu];
    }
    else {
        parent[pv] = pu;
        size[pu] += size[pv];
    }
}
```

### Important Point

Size stores the number of nodes in a connected component.

---

## Union By Rank vs Union By Size

| Union By Rank | Union By Size |
|--------------|--------------|
| Uses tree height | Uses component size |
| Slightly harder to reason about | More intuitive |
| Common in theory | Common in CP |
| Same complexity | Same complexity |

Both are equally efficient.

---

## Time Complexity

Using:

- Path Compression
- Union By Rank OR Union By Size

| Operation | Complexity |
|------------|------------|
| Find | O(α(N)) |
| Union | O(α(N)) |

where α(N) is the Inverse Ackermann Function.

For all practical values of N:

α(N) ≤ 4 or 5

Hence DSU operations are considered almost O(1).

---

## Common Interview Questions

### Why do we need Path Compression?

It flattens the tree and speeds up future find operations.

### Why does Rank not always equal Height?

After path compression, the actual height changes but rank is not updated.

Therefore rank becomes an upper bound on height rather than the exact height.

### Can we use both Union By Rank and Union By Size together?

No.

Choose one:

- Path Compression + Union By Rank
- Path Compression + Union By Size

Mixing them makes rank/size information unreliable.

---

## Important Notes

- Every node starts as its own parent.
- Always find ultimate parents before performing union.
- If both nodes have the same ultimate parent, they already belong to the same component.
- Use path compression in every find operation.
- Prefer Union By Size in competitive programming due to its simplicity.
- DSU is one of the most important data structures for graph problems.

---

## Complexity Summary

Initialization : O(N)

Find           : O(α(N))

Union          : O(α(N))

Space          : O(N)

---

## One-Line Definition

DSU is a data structure that efficiently manages disjoint sets and supports merging sets and finding whether two elements belong to the same set.

## Must-Do DSU Problems

### Basic
- Number of Provinces (LC 547)
- Redundant Connection (LC 684)

### Intermediate
- Accounts Merge (LC 721)
- Most Stones Removed (LC 947)
- Number of Operations to Make Network Connected (LC 1319)

### Advanced
- Making A Large Island (LC 827)
- Number of Islands II
- Kruskal's Algorithm (MST)
- Swim in Rising Water (DSU Approach)