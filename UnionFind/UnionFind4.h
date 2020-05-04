//
// Created by 赵子葳 on 5/1/20.
//

#ifndef UNIONFIND_UNIONFIND4_H
#define UNIONFIND_UNIONFIND4_H
#include <cassert>
namespace UF4 {
    class UnionFind {
    private:
        int *parent;
        int count;
        int* rank;

    public:
        UnionFind(int n) {
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }
        int find(int p){
            assert( p >= 0 && p < count);
//            while(p != parent[p]) {
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//            return p;
            if (p != parent[p]){
                parent[p] = find(parent[p]);
            }
            return parent[p];
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int proot = find(p);
            int qroot = find(q);

            if(proot == qroot)
                return;

            if (rank[proot] < rank[qroot]){
                parent[proot] = qroot;
            }
            else if(rank[proot] > rank[qroot]){
                parent[qroot] = proot;
            }
            else{
                parent[proot] = qroot;
                rank[qroot] += 1;
            }


        }
    };
}
#endif //UNIONFIND_UNIONFIND4_H
