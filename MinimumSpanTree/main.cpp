#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include <iomanip>
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"
using namespace std;

int main() {
    string filename = "/Users/zhaoziwei/CLionProjects/MinimumSpanTree/testG1.txt";
    int V = 8;

    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

    LazyPrimMST<SparseGraph<double>, double> lazyPrimMst(g);
    vector<Edge<double>> mst = lazyPrimMst.mstEdges();
    for (int i = 0; i < mst.size(); ++i) {
        cout<<mst[i]<<endl;
    }
    cout<<"The MST weight is: "<<lazyPrimMst.result()<<endl;
    cout<<endl;

    PrimMST<SparseGraph<double>, double> primMst(g);
    mst = primMst.mstEdges();
    for (int i = 0; i < mst.size(); ++i) {
        cout<<mst[i]<<endl;
    }
    cout<<"The MST weight is: "<<primMst.result()<<endl;

    KruskalMST<SparseGraph<double>, double> kruskalMST(g);
    mst = kruskalMST.mstEdges();
    for (int i = 0; i < mst.size(); ++i) {
        cout<<mst[i]<<endl;
    }
    cout<<"The MST weight is: "<<kruskalMST.result()<<endl;
    return 0;
}
