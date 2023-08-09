#ifndef SMARTGRAPH_VERTEX_H
#define SMARTGRAPH_VERTEX_H

#include <functional>
#include <ostream>

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
            Vertex(){};
            /**
             * @brief Set content of a vertex.
             * 
             * @param element content of the vertex
             */
            void setElement(T element) {this->_element = element;};

            /**
             * @brief Get the Element object
             * 
             * @return T* pointer of type ``T`` to the content of the vertex
             */
            T getElement() const { return this->_element; };

            bool operator==(const Vertex<T>& other) const{
                return this->_element==other._element;
            }

            bool operator!=(const Vertex<T>& other) const{
                return this->_element!=other._element;
            }
    };

    template<typename V>
    std::ostream& operator<<(std::ostream& os, const Vertex<V>& obj){
        os << obj.getElement();
        return os;
    }

}

namespace std{

    template<typename T>
    struct hash<smartgraph::interface::Vertex<T>>{
        size_t operator()(const smartgraph::interface::Vertex<T>& obj) const {
            // Hash the data inside the MyClass instance
            return std::hash<T>()(obj.getElement());
        }
    };
    
}

#endif