#include <iostream>
#include <string>

#include "smartgraph/algorithm/dijkstra.hpp"
#include "smartgraph/graph/UnorientedGraph.hpp"
#include "smartgraph/element/KeyWeightValueElement.h"

using namespace smartgraph;

int main(int argc, char* argv[]){

    using Vertex = std::string;
    using Edge = element::KeyWeightValueElement<std::string, int, std::string>;
    using DGraph = graph::UnorientedGraph<Vertex, Edge>;

    if(argc!=3) return -1;

    std::string startpoint(argv[1]);
    std::string endpoint(argv[2]);

    DGraph d_graph;

    d_graph.insertVertex("JFK");
    d_graph.insertVertex("ORD");
    d_graph.insertVertex("BOS");
    d_graph.insertVertex("MIA");
    d_graph.insertVertex("SFO");
    d_graph.insertVertex("LAX");
    d_graph.insertVertex("DFW");

    d_graph.insertEdge("BOS","JFK",Edge("BOS-JFK",187,""));
    d_graph.insertEdge("BOS","ORD",Edge("BOS-ORD",867,""));
    d_graph.insertEdge("BOS","SFO",Edge("BOS-SFO",2704,""));
    d_graph.insertEdge("BOS","MIA",Edge("BOS-MIA",1258,""));
    d_graph.insertEdge("JFK","ORD",Edge("JFK-ORD",740,""));
    d_graph.insertEdge("JFK","MIA",Edge("JFK-MIA",1090,""));
    d_graph.insertEdge("MIA","DFW",Edge("MIA-DFW",1121,""));
    d_graph.insertEdge("MIA","LAX",Edge("MIA-LAX",2342,""));
    d_graph.insertEdge("ORD","DFW",Edge("ORD-DFW",802,""));
    d_graph.insertEdge("ORD","SFO",Edge("ORD-SFO",1846,""));
    d_graph.insertEdge("DFW","SFO",Edge("DFW-SFO",1464,""));
    d_graph.insertEdge("DFW","LAX",Edge("DFW-LAX",1235,""));
    d_graph.insertEdge("SFO","LAX",Edge("SFO-LAX",337,""));

    std::cout << d_graph.toString();

    auto cloud = algorithm::dijkstra<std::string, std::string, int, std::string>(d_graph,startpoint,endpoint);

    std::cout << std::endl << "Shortest paths calculated from "<< startpoint << " to "<< endpoint <<":" << std::endl;

    while(!cloud.empty()){
        auto elem = cloud.top();
        if(elem.second.getKey()!="")
            std::cout << "---[" << elem.second.getKey() << " : " << elem.second.getWeight() << "]---->";
        std::cout << elem.first << " ";
        cloud.pop();
    }
    std::cout<<std::endl;
    return 0;
}