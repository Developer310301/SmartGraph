#ifndef SMARTGRAPH_VERTEX_H
#define SMARTGRAPH_VERTEX_H

#include <functional>

namespace smartgraph::interface{

    /**
     * @brief Class that represents a vertex of a graph.
     * 
     * @tparam T the type of the content of the created vertex.
     */
    template<typename T>
    class Vertex{
        
        private:
            T _element; //Content of a vertex.

        public:
            Vertex() = delete;
            /**
             * @brief Constructor of a vertex.
             * 
             * @param element content of the vertex
             */
            Vertex(T element) : _element(element){};

            /**
             * @brief Get the Element object
             * 
             * @return T* pointer of type ``T`` to the content of the vertex
             */
            T* getElement() { return &this->_element; };

            bool operator==(const Vertex<T>& other) const{
                return this->_element==other._element;
            }
    };

}

namespace std{

    template<typename T>
    struct hash<smartgraph::interface::Vertex<T>>{
        size_t operator()(const smartgraph::interface::Vertex<T>& obj) const {
            // Hash the data inside the MyClass instance
            return std::hash<T>()(*obj.getElement());
        }
    };
    
}

#endif