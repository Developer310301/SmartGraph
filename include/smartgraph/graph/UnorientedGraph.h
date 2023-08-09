#ifndef SMARTGRAPH_UNORIENTED_GRAPH_H
#define SMARTGRAPH_UNORIENTED_GRAPH_H

#include "smartgraph/interface/IGraph.h"

namespace smartgraph::graph{
    
    using namespace smartgraph::interface;

    template<typename V, typename E>
    class UnorientedGraph : IGraph<V,E>{

    };

}

#include "smartgraph/graph/UnorientedGraph.hpp"

#endif