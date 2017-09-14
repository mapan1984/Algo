## 表示

* 邻接链表
* 邻接矩阵

## 搜索

### 广度优先搜索(Breadth-First-Search)

输入图G = (V, E)是以邻接链表所表示的，对任意结点u，u.color存放u的颜色(WRITE代表未发现的结点，BLACK代表已搜索的结点，GRAY代表已发现但未搜索的结点)，u.π存放u的前驱节点，u.d记录广度优先搜索算法所计算出的从源结点s到结点u之间的距离。

```
bfs(G, s)
    for each vertex u ∈ G.V - {s}
        u.color = WRITE
        u.d = ∞
        u.π = NIL
    s.color = GRAY
    s.d = 0
    s.π = NIL
    Q = Ø  // Q是先进先出的队列
    enqueue(Q, s)
    while Q ≠ Ø
        u = dequeue(Q)
        for each v ∈ G.Adj[u]
            if v.color == WRITE
                v.color = GRAY
                v.d = u.d + 1
                v.π = u
                enqueue(Q, v)
        u.color = BLACK
```

T(n) = O(V + E)

### 深度优先搜索(Depth-First-Search)

```
global time

dfs(G)
    for each vertex u ∈ G.V
        u.color = WRITE
        u.π = NIL
    time = 0
    for each vertex u ∈ G.V
        if u.color == WRITE
            dfs_visit(G, u)

dfs_visit(G, u)
    time = time + 1  // white vertex u has just been discoverd
    u.d = time
    u.color = GRAY
    for each v ∈ G.Adj[u]  // explore edge (u, v)
        if v.color == WRITE
            v.π = u
            dfs_visit(G, v)
    u.color = BLACK
    time = time + 1
    u.f = time
```

## 拓扑排序

拓扑排序次序恰好与深度搜索结点的完成时间相反，对一个有向无环图进行拓扑排序：

```
topological_sort(G)
    call dfs(G) to compute finishing times v.f for each vertex v
    as each vertex is finished, insert it onto the front of a linked list
    return the linked list of vertices
```
