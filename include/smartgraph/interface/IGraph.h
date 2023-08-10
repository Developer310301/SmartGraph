#ifndef SMARTGRAPH_IGRAPH_H
#define SMARTGRAPH_IGRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>

#include "smartgraph/interface/Vertex.h"
#include "smartgraph/interface/Edge.h"

namespace smartgraph::interface{

    /**
     * @brief Interface that represents a generic Graph.
     * 
     * @tparam V Type of vertex content.
     * @tparam E Type of edge content.
     */
    template<typename V, typename E>
    class IGraph{
        using VertexPointer = const Vertex<V>*;
        using EdgePointer = const Edge<E>*;
        using AdjancencyMap = std::unordered_map<Vertex<V>,std::unordered_map<VertexPointer,EdgePointer>>;
        using VertexList = std::unordered_set<Vertex<V>>;
        using EdgeList = std::unordered_set<Edge<E>>;

        protected:
            AdjancencyMap _adjacencyMap{};  //Map of vetexes andacencies.
            EdgeList _edges{};              //List of edges.

        public:

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
             * @return std::vector<Vertex<T>> vector of vertex.
             */
            virtual std::vector<Vertex<V>> vertices() = 0;

            /**
             * @brief Get the number of edges in the graph.
             * 
             * @return unsigned long number of edges.
             */
            virtual unsigned long numEdges() = 0;

            /**
             * @brief Get a vector of edges in the graph.
             * 
             * @return std::vector<Edge<E>> vector of edges.
             */
            virtual std::vector<Edge<E>> edges() = 0;

            /**
             * @brief Get the Edge reference object between the edges ``u`` and ``v``.
             * 
             * @param u starting vertex.
             * @param v ending vertex.
             * @return Edge if found.
             */
            virtual const Edge<E>* getEdge(V u, V v) = 0;

            /**
             * @brief Get the two vertices of the specified edge.
             * 
             * @param e Edge used to get the two vertexes.
             * @return std::vector<Vertex<V>> Array containing the references to the two vertexes of the given Edge.
             */
            virtual std::vector<const Vertex<V>*> endVertices(E e) = 0;

            /**
             * @brief Get the terminal vertex of ``e`` different from ``v``.
             * 
             * @param v Starting vertex.
             * @param e Edge where to look for.
             * @return VertexPointer The opposite vertex of ``v``, ``nullptr`` if ``e`` isn't incident with ``v``.
             */
            virtual const Vertex<V>* opposite(V v, E e) = 0;

            /**
             * @brief Returns the number of outgoing vertexes from vertex ``v``.
             * 
             * @param v Vertex which getting the outgoing vertexes.
             * @return unsigned long Number of outgoing vertexes.
             */
            virtual unsigned long outDegree(V v) = 0;

            /**
             * @brief Returns the number of incoming vertexes to vertex ``v``.
             * 
             * @param v Vertex which getting the incoming vertexes.
             * @return unsigned long Number of incoming vertexes.
             */
            virtual unsigned long inDegree(V v) = 0;

            /**
             * @brief Returns an array of incoming Edges from vertex ``v``.
             * 
             * @param v Vertex which getting the incoming edges.
             * @return std::vector<EdgePointer> Array of incoming edges.
             */
            virtual std::vector<const Edge<E>*> outgoingEdges(V v) = 0;

            /**
             * @brief Returns an array of incoming Edges to vertex ``v``.
             * 
             * @param v Vertex which getting the incoming edges.
             * @return std::vector<EdgePointer> Array of incoming edges.
             */
            virtual std::vector<const Edge<E>*> incomingEdges(V v) = 0;

            /**
             * @brief Insert a new @see Vertex that will contains an object ``x`` and then it will return a reference to the new vertex.
             * 
             * @param x Content of a new vertex.
             * @return int returns 1 if correctly inserted, 0 otherwise
             */
            virtual int insertVertex(V x) = 0;

            /**
             * @brief Insert a new @see Edge that will contains an object ``y`` between the vertexes ``u`` and ``v`` and it will return a reference to the new edge.
             * 
             * @param u Starting vertex.
             * @param y Ending vertex.
             * @param x Content of the new edge.
             * @return int returns 1 if correctly inserted, 0 otherwise
             */
            virtual int insertEdge(V u, V y, E x) = 0;

            /**
             * @brief Remove the vertex from the graph and all the incident edges from him
             * 
             * @param v Vertex to remove
             * @return int returns 1 if correctly removed, 0 if the vertex doesn't exist in the graph, -1 for others error
             */
            virtual int removeVertex(V v) = 0;

            /**
             * @brief Remove the edge from the graph
             * 
             * @param e Edge to remove
             * @return int returns 1 if correctly removed, 0 if the edge doesn't exist in the graph, -1 for others error
             */
            virtual int removeEdge(E e) = 0;

            ~IGraph() { 
                for(auto& it : this->_adjacencyMap){
                    for(auto& it1 : it.second){
                        it1.second = nullptr;
                    }
                    this->_adjacencyMap[it.first].clear();
                }
                this->_adjacencyMap.clear();
                this->_edges.clear();

            }
    };

}

#endif