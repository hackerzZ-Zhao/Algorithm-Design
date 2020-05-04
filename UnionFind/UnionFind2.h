//
// Created by 赵子葳 on 5/1/20.
//

#ifndef UNIONFIND_UNIONFIND2_H
#define UNIONFIND_UNIONFIND2_H
#include <cassert>
namespace UF2 {
    class UnionFind {
    private:
        int *parent;
        int count;

    public:
        UnionFind(int n) {
            parent = new int[count];
            this->count = count;
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        ~UnionFind() {
            delete[] parent;
        }
        int find(int p){
            assert( p >= 0 && p < count);
            while(p != parent[p])
                p = parent[p];
            return p;
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int proot = find(p);
            int qroot = find(q);

            if(proot == qroot)
                return;

            parent[proot] = qroot;

        }
    };
}

#endif //UNIONFIND_UNIONFIND2_H
