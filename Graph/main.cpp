#include <iostream>
#include "ReadGraph.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
using namespace std;

int main() {
    string filename = "/Users/zhaoziwei/CLionProjects/Graph/testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout<<endl;

    Path<SparseGraph> dfs(g, 0);
    cout<<"DFS : ";
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g, 0);
    cout<<"BFS : ";
    bfs.showPath(6);

    return 0;
}
