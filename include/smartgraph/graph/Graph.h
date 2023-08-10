#include <string>
#include <sstream>

#include "smartgraph/interface/IGraph.h"

namespace smartgraph::graph{

    using namespace smartgraph::interface;

    template<typename V, typename E>
    class Graph : public IGraph<V, E>{

        public:

            Graph() : IGraph<V,E>(){}

            /**
             * @brief Get the number of vertex in the graph.
             * 
             * @return unsigned long Number of vertex.
             */
            unsigned long numVertices() override;
            
            /**
             * @brief Get a vector of vertex in the graph.
             * 
             * @return std::vector<Vertex<T>> vector of vertex.
             */
            std::vector<Vertex<V>> vertices() override;

            /**
             * @brief Get the number of edges in the graph.
             * 
             * @return unsigned long number of edges.
             */
            unsigned long numEdges() override;

            /**
             * @brief Get a vector of edges in the graph.
             * 
             * @return std::vector<Edge<E>> vector of edges.
             */
            std::vector<Edge<E>> edges() override;

            /**
             * @brief Get the Edge reference object between the edges ``u`` and ``v``.
             * 
             * @param u starting vertex.
             * @param v ending vertex.
             * @return Edge if found.
             */
            const Edge<E>* getEdge(V u, V v) override;

            /**
             * @brief Get the two vertices of the specified edge.
             * 
             * @param e Edge used to get the two vertexes.
             * @return std::vector<VertexPointer> Array containing the references to the two vertexes of the given Edge.
             */
            std::vector<const Vertex<V>*> endVertices(E e) override;

            /**
             * @brief Get neighbors verteces of the specified vertex
             * 
             * @param v starting vertex
             * @return std::vector<VertexPointer> Array containing the references to the neighboring verteces
             */
            std::vector<const Vertex<V>*> getNeightbors(V v);

            /**
             * @brief Get the terminal vertex of ``e`` different from ``v``.
             * 
             * @param v Starting vertex.
             * @param e Edge where to look for.
             * @return VertexPointer The opposite vertex of ``v``, ``nullptr`` if ``e`` isn't incident with ``v``.
             */
            const Vertex<V>* opposite(V v, E e) override;

            /**
             * @brief Returns the number of outgoing vertexes from vertex ``v``.
             * 
             * @param v Vertex which getting the outgoing vertexes.
             * @return unsigned long Number of outgoing vertexes.
             */
            unsigned long outDegree(V v) override;

            /**
             * @brief Returns the number of incoming vertexes to vertex ``v``.
             * 
             * @param v Vertex which getting the incoming vertexes.
             * @return unsigned long Number of incoming vertexes.
             */
            virtual unsigned long inDegree(V v) override;

            /**
             * @brief Returns an array of incoming Edges from vertex ``v``.
             * 
             * @param v Vertex which getting the incoming edges.
             * @return std::vector<EdgePointer> Array of incoming edges.
             */
            std::vector<const Edge<E>*> outgoingEdges(V v) override;

            /**
             * @brief Returns an array of incoming Edges to vertex ``v``.
             * 
             * @param v Vertex which getting the incoming edges.
             * @return std::vector<EdgePointer> Array of incoming edges.
             */
            virtual std::vector<const Edge<E>*> incomingEdges(V v) override;

            /**
             * @brief Insert a new @see Vertex that will contains an object ``x`` and then it will return a reference to the new vertex.
             * 
             * @param x Content of a new vertex.
             * @return int returns 1 if correctly inserted, 0 otherwise
             */
            int insertVertex(V x) override;

            /**
             * @brief Insert a new @see Edge that will contains an object ``y`` between the vertexes ``u`` and ``v`` and it will return a reference to the new edge.
             * 
             * @param u Starting vertex.
             * @param y Ending vertex.
             * @param x Content of the new edge.
             * @return int returns 1 if correctly inserted, 0 otherwise
             */
            virtual int insertEdge(V u, V y, E x) override;

            /**
             * @brief Remove the vertex from the graph and all the incident edges from him
             * 
             * @param v Vertex to remove
             * @return int returns 1 if correctly removed, 0 if the vertex doesn't exist in the graph, -1 for others error
             */
            virtual int removeVertex(V v) override;

            /**
             * @brief Remove the edge from the graph
             * 
             * @param e Edge to remove
             * @return int returns 1 if correctly removed, 0 if the edge doesn't exist in the graph, -1 for others error
             */
            virtual int removeEdge(E e) override;

            /**
             * @brief Methot that determine if a vertex exists in the graph
             * 
             * @param v Vertex to find
             * @return int return 1 if the vertex exists, 0 otherwise
             */
            int vertexExists(V v) override;

            /**
             * @brief Method that determine if an edge exists in the graph
             * 
             * @param e Edge to find
             * @return int return 1 if the edge exists, 0 otherwise
             */
            int edgeExists(E e) override;

            /**
             * @brief Method that print out the graph structure
             * 
             * @return std::string 
             */
            std::string toString();



    };

}