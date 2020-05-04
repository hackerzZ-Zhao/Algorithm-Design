//
// Created by 赵子葳 on 5/1/20.
//

#ifndef UNIONFIND_UNIONFIND1_H
#define UNIONFIND_UNIONFIND1_H
#include <iostream>
#include <cassert>
using namespace std;

class UnionFind{
private:
    int* id;
    int count;

public:
    UnionFind(int n){
        count = n;
        id = new int[n];
        for(int i = 0; i < n; i++)
            id[i] = i;
    }
    ~UnionFind(){
        delete [] id;
    }
    int find(int p){
        assert( p >= 0 && p < count);
        return id[p];
    }

    bool isConnected(int p, int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){
        int pid = find(p);
        int qid = find(q);

        if(pid == qid)
            return;
        for(int i = 0; i < count; i++)
            if(id[i] == pid)
                id[i] = qid;
    }
};

#endif //UNIONFIND_UNIONFIND1_H
