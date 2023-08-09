#include <iostream>
#include <string>

#include "smartgraph/graph/Graph.hpp"

using namespace smartgraph::graph;

int main(){

    Graph<std::string, int>* graph = new Graph<std::string, int>();

    graph->insertVertex("BOS");
    graph->insertVertex("JFK");
    graph->insertVertex("MIA");
    graph->insertEdge("BOS","JKF",2000);

    std::cout << "Number of vertices: " << graph->numVertices() << std::endl;
    std::cout << "Vertices:" << std::endl;
    for(auto it : graph->vertices()){
        std::cout << "\t" << it << std::endl;
    }

    std::cout << "Number of edges: " << graph->numEdges() << std::endl;
    std::cout << "Edges:" << std::endl;
    for(auto it : graph->edges()){
        std::cout << "\t" << it << std::endl;
    }

    
    std::cout << "Graph Layout:\n" << graph->toString();


    delete graph;

    return 0;
}