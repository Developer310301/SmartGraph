#ifndef SMARTGRAPH_EDGE_H
#define SMARTGRAPH_EDGE_H

namespace smartgraph::interface{
    
    /**
     * @brief Class that represents an edge of a graph.
     * 
     * @tparam T the type of the content of the created edge.
     */
    template<typename T>
    class Edge{
        
        private:
            T _element; //Content of an edge.

        public:
            Edge() = delete;
            /**
             * @brief Constructor of an edge.
             * 
             * @param element content of the edge
             */
            Edge(T element) : _element(element){};

            /**
             * @brief Get the Element object
             * 
             * @return T* pointer of type ``T`` to the content of the edge
             */
            T* getElement() { return &this->_element; };
    };

} // namespace smartgraph::interface


#endif