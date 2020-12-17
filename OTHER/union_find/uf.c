#include <stdio.h>
#include <stdlib.h>

typedef struct UF{
    int* id;  // access to component id (site indexed)
    size_t count;  // number of components
    size_t length;
}UF;


void init(UF uf, size_t n) {
    uf.count = n;
    uf.length = n;
    uf.id = (int *)malloc(n*sizeof(int));
    for (size_t i = 0; i < n; i++) {
        uf.id[i] = i;
    }
}

int count(UF uf) {
    return uf.count;
}


///////////////////////////数组表示////////////////////////////////////////////
int find_1(UF uf, int p) {
    return uf.id[p];
}

void merge_1(UF uf, int p, int q) {
    // 获得p和q的组号
    int p_id = find_1(uf, p);
    int q_id = find_1(uf, q);
    // 如果组号相等，则直接返回
    if (p_id == q_id) {
        return;
    }
    // 遍历一次，改变组号使他们属于一个组
    for (size_t i = 0; i < uf.length; i++) {
        if (uf.id[i] == p_id) {
            uf.id[i] = q_id;
        }
    }
    uf.count--;
}
///////////////////////////////////////////////////////////////////////////////

////////////////////////////////树表示/////////////////////////////////////////
int find_2(UF uf, int p) {
    // 寻找p节点所在组的根节点，根节点具有性质id[root] == root
    while (p != uf.id[p]) {
        p = uf.id[p];
    }
    return p;
}

void merge_2(UF uf, int p, int q) {
    // Give p and q the same root.
    int p_root = find_2(uf, p);
    int q_root = find_2(uf, q);
    if (p_root == q_root) {
        return;
    }
    // 将一颗树（及一个组）变成另一颗书（即一个组）的子树
    uf.id[p_root] = q_root;
    uf.count--;
}
///////////////////////////////////////////////////////////////////////////////

int connected(UF uf, int p, int q) {
    return find_1(uf, p) == find_2(uf, q);
}

