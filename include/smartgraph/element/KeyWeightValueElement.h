#ifndef SMARTGRAPH_KEYWEIGHTVALUEELEMENT_H
#define SMARTGRAPH_KEYWEIGHTVALUEELEMENT_H

#include <functional>
#include <ostream>

#include "smartgraph/element/KeyValueElement.h"

namespace smartgraph::element{

    template<typename K, typename W, typename V>
    class KeyWeightValueElement : public KeyValueElement<K,V>{

        private:
            W _weight;

        public:
            KeyWeightValueElement() : KeyValueElement<K,V>(){};
            KeyWeightValueElement(K key, W weight, V value) : KeyValueElement<K,V>(key, value), _weight(weight){};

            void setWeight(const W w) { this->_weight = w; }

            W getWeight() const { return this->_weight; }
    };

    template<typename K, typename W, typename V>
    std::ostream& operator<<(std::ostream& os, const KeyWeightValueElement<K,W,V>& obj){
        os << "(" << obj.getKey() << " : "<< obj.getWeight() <<", "<< obj.getValue() << ")";
        return os;
    }
}

namespace std{

   template<typename K, typename W, typename V>
    struct hash<smartgraph::element::KeyWeightValueElement<K,W,V>>{
        size_t operator()(const smartgraph::element::KeyWeightValueElement<K,W,V>& obj) const {
            return std::hash<K>()(obj.getKey());
        }
    };
    
}

#endif