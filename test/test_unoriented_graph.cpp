#include <iostream>
#include <string>

#include "smartgraph/graph/UnorientedGraph.h"

using namespace smartgraph::graph;

int main(){

    UnorientedGraph<std::string,int> graph;

    std::cout << "Number of vertexes: "<<graph.numVertices()<<std::endl;

    return 0;
}