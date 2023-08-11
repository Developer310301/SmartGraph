#ifndef SMARTGRAPH_UNORIENTED_GRAPH_H
#define SMARTGRAPH_UNORIENTED_GRAPH_H

#include "smartgraph/graph/UnorientedGraph.h"

namespace smartgraph::graph{
    template<typename V, typename E>
    unsigned long UnorientedGraph<V,E>::inDegree(V v){
        return this->outDegree(v);
    }

    template<typename V, typename E>
    std::vector<const Edge<E>*> UnorientedGraph<V,E>::incomingEdges(V v){
        return this->outgoingEdges(v);
    }

    template<typename V, typename E>
    int UnorientedGraph<V,E>::insertEdge(V u, V y, E x){
        Vertex<V> v1; v1.setElement(u);
        Vertex<V> v2; v2.setElement(y);
        Edge<E> ed; ed.setElement(x);

        auto it_ed = this->_edges.find(ed);
        if(it_ed != this->_edges.end()) return 0;

        auto it_v1 = this->_adjacencyMap.find(v1);
        auto it_v2 = this->_adjacencyMap.find(v2);
        if(it_v1 == this->_adjacencyMap.end() || it_v2 == this->_adjacencyMap.end()) return 0;

        auto ed_ptr = this->_edges.insert(ed);

        this->_adjacencyMap[v1][&(it_v2->first)] = &*(ed_ptr.first);
        this->_adjacencyMap[v2][&(it_v1->first)] = &*(ed_ptr.first);
        
        return 1;
    }

    template<typename V, typename E>
    int UnorientedGraph<V,E>::removeVertex(V v){
        Vertex<V> v1; v1.setElement(v);

        auto it_v1 = this->_adjacencyMap.find(v1);

        if(it_v1 == this->_adjacencyMap.end()) return 0;

        for(auto& it : this->_adjacencyMap[v1]){
            auto ed_ptr = this->_adjacencyMap[*(it.first)][&(it_v1->first)];
            this->_edges.erase(*ed_ptr);
            this->_adjacencyMap[*(it.first)].erase(&(it_v1->first));
        }

        this->_adjacencyMap.erase(v1);

        return 1;
    }

    template<typename V, typename E>
    int UnorientedGraph<V,E>::removeEdge(E e){
        Edge<E> ed; ed.setElement(e);
        auto it = this->_edges.find(ed);
        if(it==this->_edges.end()){
            return 0;
        }

        for(auto& it_v : this->_adjacencyMap){
            for(auto& it_v1 : it_v.second){
                if(it_v1.second == &*it){
                    this->_adjacencyMap[*(it_v1.first)][&(it_v.first)] = nullptr;
                    this->_adjacencyMap[*(it_v1.first)].erase(&(it_v.first));
                    it_v1.second = nullptr;
                    this->_adjacencyMap[it_v.first].erase(it_v1.first);
                    this->_edges.erase(ed);
                    return 1;
                }
            }
        }

        return 0;
    }
}

#endif