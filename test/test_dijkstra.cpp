#include <iostream>
#include <string>

#include "smartgraph/algorithm/dijkstra.hpp"
#include "smartgraph/graph/OrientedGraph.hpp"
#include "smartgraph/element/KeyWeightValueElement.h"

using namespace smartgraph;

int main(){

    using Vertex = std::string;
    using Edge = element::KeyWeightValueElement<std::string, int, std::string>;
    using DGraph = graph::OrientedGraph<Vertex, Edge>;

    DGraph d_graph;

    algorithm::dijkstra<std::string, std::string, int, std::string>(d_graph,"JFK");

    return 0;
}