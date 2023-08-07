#ifndef SMARTGRAPH_UNORIENTED_GRAPH_H
#define SMARTGRAPH_UNORIENTED_GRAPH_H

#include "smartgraph/interface/IGraph.h"

namespace smartgraph::graph{
    
    using namespace smartgraph::interface;

    template<typename V, typename E>
    class UnorientedGraph : IGraph<V,E>{
        using VertexPointer = std::shared_ptr<const Vertex<V>>;
        using EdgePointer = std::shared_ptr<const Edge<E>>;
        public:
            
            unsigned long numVertices() override;
            std::vector<VertexPointer> vertices() override;
            unsigned long numEdges() override;
            std::vector<std::shared_ptr<const Edge<E>>> edges() override;
            EdgePointer getEdge(VertexPointer u, VertexPointer v) override;
            std::vector<VertexPointer> endVertices(EdgePointer e) override;
            VertexPointer opposite(VertexPointer v, EdgePointer e) override;
            unsigned long outDegree(VertexPointer v) override;
            unsigned long inDegree(VertexPointer v) override;
            std::vector<EdgePointer> outgoingEdges(VertexPointer v) override;
            std::vector<EdgePointer> incomingEdges(VertexPointer v) override;
            VertexPointer insertVertex(V x) override;
            EdgePointer insertEdge(VertexPointer u, VertexPointer y, E x) override;

    };

}

#include "smartgraph/graph/UnorientedGraph.hpp"

#endif