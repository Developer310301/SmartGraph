#ifndef SMARTGRAPH_KEYVALUEELEMENT_H
#define SMARTGRAPH_KEYVALUEELEMENT_H

#include <functional>
#include <ostream>

namespace smartgraph::element{

    template<typename K, typename V>
    class KeyValueElement{

        protected:
            K _key;
            V _value;

        public:
            KeyValueElement(){};

            KeyValueElement(K k, V v) : _key(k), _value(v){}

            void setKey(const K k) { this->_key = k; }
            void setValue(const V v) { this->_value = v; }

            const K getKey() const { return this->_key; }
            V getValue() const { return this->_value; }

            bool operator==(const KeyValueElement<K,V>& other) const{
                return this->_key == other._key;
            }

            bool operator!=(const KeyValueElement<K,V>& other) const{
                return this->_key != other._key;
            }

    };

    template<typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const KeyValueElement<K,V>& obj){
        os << "(" << obj.getKey() << " : " << obj.getValue() << ")";
        return os;
    }
}

namespace std{

    template<typename K, typename V>
    struct hash<smartgraph::element::KeyValueElement<K,V>>{
        size_t operator()(const smartgraph::element::KeyValueElement<K,V>& obj) const {
            return std::hash<K>()(obj.getKey());
        }
    };
    
}

#endif