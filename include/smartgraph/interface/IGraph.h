#ifndef SMARTGRAPH_IGRAPH_H
#define SMARTGRAPH_IGRAPH_H

#include "smartgraph/interface/Vertex.h"
#include "smartgraph/interface/Edge.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>

namespace smartgraph::interface{

    /**
     * @brief Interface that represents a generic Graph.
     * 
     * @tparam V Type of vertex content.
     * @tparam E Type of edge content.
     */
    template<typename V, typename E>
    class IGraph{
        using VertexPointer = std::shared_ptr<Vertex<V>>;
        using EdgePointer = std::shared_ptr<Edge<E>>;
        using AdjancencyMap = std::unordered_map<Vertex<V>,std::unordered_map<VertexPointer,EdgePointer>>;
        using EdgeList = std::unordered_set<Edge<E>>;

        private:
            AdjancencyMap _adjacencyMap{};  //Map of vetexes andacencies.
            EdgeList _edges{};                //List of edges.

        public:

            //IGraph() : _adjacencyMap(AdjancencyMap(10)), _edges(EdgeList(10)){}
            IGraph(){};

            /**
             * @brief Get the number of vertex in the graph.
             * 
             * @return unsigned long Number of vertex.
             */
            virtual unsigned long numVertices() = 0;
            
            /**
             * @brief Get a vector of vertex in the graph.
             * 
             * @return std::vector<Vertex<V>> vector of vertex.
             */
            virtual std::vector<VertexPointer> vertices() = 0;

            /**
             * @brief Get the number of edges in the graph.
             * 
             * @return unsigned long number of edges.
             */
            virtual unsigned long numEdges() = 0;

            /**
             * @brief Get a vector of edges in the graph.
             * 
             * @return std::vector<Edge<E>*> vector of edges.
             */
            virtual std::vector<EdgePointer> edges() = 0;

            /**
             * @brief Get the Edge reference object between the edges ``u`` and ``v``.
             * 
             * @param u starting vertex.
             * @param v ending vertex.
             * @return Edge<E>* reference to the edge.
             */
            virtual EdgePointer getEdge(VertexPointer u, VertexPointer v) = 0;

            /**
             * @brief Get the two vertices of the specified edge.
             * 
             * @param e Edge used to get the two vertexes.
             * @return std::vector<Vertex<V>*> Array containing the references to the two vertexes of the given Edge.
             */
            virtual std::vector<VertexPointer> endVertices(Edge<E>* e) = 0;

            /**
             * @brief Get the terminal vertex of ``e`` different from ``v``.
             * 
             * @param v Starting vertex.
             * @param e Edge where to look for.
             * @return Vertex<V>* The opposite vertex of ``v``, ``nullptr`` if ``e`` isn't incident with ``v``.
             */
            virtual VertexPointer opposite(VertexPointer v, EdgePointer e) = 0;

            /**
             * @brief Returns the number of outgoing vertexes from vertex ``v``.
             * 
             * @param v Vertex which getting the outgoing vertexes.
             * @return unsigned long Number of outgoing vertexes.
             */
            virtual unsigned long outDegree(VertexPointer v) = 0;

            /**
             * @brief Returns the number of incoming vertexes to vertex ``v``.
             * 
             * @param v Vertex which getting the incoming vertexes.
             * @return unsigned long Number of incoming vertexes.
             */
            virtual unsigned long inDegree(VertexPointer v) = 0;

            /**
             * @brief Returns an array of incoming Edges from vertex ``v``.
             * 
             * @param v Vertex which getting the incoming edges.
             * @return std::vector<Edge<E>*> Array of incoming edges.
             */
            virtual std::vector<EdgePointer> outgoingEdges(VertexPointer v) = 0;

            /**
             * @brief Returns an array of incoming Edges to vertex ``v``.
             * 
             * @param v Vertex which getting the incoming edges.
             * @return std::vector<Edge<E>*> Array of incoming edges.
             */
            virtual std::vector<EdgePointer> incomingEdges(VertexPointer v) = 0;

            /**
             * @brief Insert a new @see Vertex that will contains an object ``x`` and then it will return a reference to the new vertex.
             * 
             * @param x Content of a new vertex.
             * @return Vertex<V>* Reference to the created vertex.
             */
            virtual VertexPointer insertVertex(V x) = 0;

            /**
             * @brief Insert a new @see Edge that will contains an object ``y`` between the vertexes ``u`` and ``v`` and it will return a reference to the new edge.
             * 
             * @param u Reference to the starting vertex.
             * @param y Reference to the ending vertex.
             * @param x Content of the new edge.
             * @return Edge<E>* Reference to the new edge.
             */
            virtual EdgePointer insertEdge(VertexPointer u, VertexPointer y, E x) = 0;

            /**
             * @brief Remove the vertex from the graph and all the incident edges from him
             * 
             * @param v Vertex to remove
             * @return int returns 1 if correctly removed, 0 if the vertex doesn't exist in the graph, -1 for others error
             */
            virtual int removeVertex(VertexPointer v) = 0;

            /**
             * @brief Remove the edge from the graph
             * 
             * @param e Edge to remove
             * @return int returns 1 if correctly removed, 0 if the edge doesn't exist in the graph, -1 for others error
             */
            virtual int removeEdge(EdgePointer e) = 0;

    };

}

#endif