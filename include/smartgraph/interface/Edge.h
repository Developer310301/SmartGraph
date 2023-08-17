#ifndef SMARTGRAPH_EDGE_H
#define SMARTGRAPH_EDGE_H

#include <functional>
#include <ostream>

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
            Edge(){};

            void setElement(T& element) { this->_element=element; }        

            /**
             * @brief Get the Element object
             * 
             * @return T* pointer of type ``T`` to the content of the edge
             */
            const T* getElement() const { return &(this->_element); };

            bool operator==(const Edge<T>& other) const{
                return this->_element==other._element;
            }

            bool operator!=(const Edge<T>& other) const{
                return this->_element!=other._element;
            }

            bool operator<(const Edge<T>& other) const{
                return this->_element<other._element;
            }

            bool operator>(const Edge<T>& other) const{
                return this->_element>other._element;
            }
    };

    template<typename E>
    std::ostream& operator<<(std::ostream& os, const Edge<E>& obj){
        os << *(obj.getElement());
        return os;
    }


} // namespace smartgraph::interface

namespace std{

    template<typename T>
    struct hash<smartgraph::interface::Edge<T>>{
        size_t operator()(const smartgraph::interface::Edge<T>& obj) const {
            // Hash the data inside the MyClass instance
            return std::hash<T>()(*(obj.getElement()));
        }
    };
    
}


#endif