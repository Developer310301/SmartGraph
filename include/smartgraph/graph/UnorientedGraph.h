#include "smartgraph/graph/Graph.hpp"

namespace smartgraph::graph{
    
    using namespace smartgraph::interface;

    template<typename V, typename E>
    class UnorientedGraph : public Graph<V,E>{

        public:
            /**
             * @brief Returns the number of incoming vertexes to vertex ``v``.
             * 
             * @param v Vertex which getting the incoming vertexes.
             * @return unsigned long Number of incoming vertexes.
             */
            unsigned long inDegree(V v) override;

            /**
             * @brief Returns an array of incoming Edges to vertex ``v``.
             * 
             * @param v Vertex which getting the incoming edges.
             * @return std::vector<EdgePointer> Array of incoming edges.
             */
            std::vector<const Edge<E>*> incomingEdges(V v) override;

            /**
             * @brief Insert a new @see Edge that will contains an object ``y`` between the vertexes ``u`` and ``v`` and it will return a reference to the new edge.
             * 
             * @param u Starting vertex.
             * @param y Ending vertex.
             * @param x Content of the new edge.
             * @return int returns 1 if correctly inserted, 0 otherwise
             */
            int insertEdge(V u, V y, E x) override;

            /**
             * @brief Remove the vertex from the graph and all the incident edges from him
             * 
             * @param v Vertex to remove
             * @return int returns 1 if correctly removed, 0 if the vertex doesn't exist in the graph, -1 for others error
             */
            int removeVertex(V v) override;

            /**
             * @brief Remove the edge from the graph
             * 
             * @param e Edge to remove
             * @return int returns 1 if correctly removed, 0 if the edge doesn't exist in the graph, -1 for others error
             */
            int removeEdge(E e) override;

    };

}