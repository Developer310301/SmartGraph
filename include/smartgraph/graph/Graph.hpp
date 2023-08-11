#ifndef SMARTGRAPH_GRAPH_H
#define SMARTGRAPH_GRAPH_H

#include "smartgraph/graph/Graph.h"

namespace smartgraph::graph{

    template<typename V, typename E>
    unsigned long Graph<V,E>::numVertices(){
        return this->_adjacencyMap.size();
    }

    template<typename V, typename E>
    std::vector<Vertex<V>> Graph<V,E>::vertices(){
        std::vector<Vertex<V>> verts;

        for(auto& it : this->_adjacencyMap){
            verts.push_back(it.first);
        }

        return verts;
    }

    template<typename V, typename E>
    unsigned long Graph<V,E>::numEdges(){
        return this->_edges.size();
    }

    template<typename V, typename E>
    std::vector<Edge<E>> Graph<V,E>::edges(){
        std::vector<Edge<E>> verts;

        for(auto& it : this->_edges){
            verts.push_back(it);
        }

        return verts;
    }

    template<typename V, typename E>
    const Edge<E>* Graph<V,E>::getEdge(V u, V v){
        Vertex<V> v1, v2;
        v1.setElement(u); v2.setElement(v);
        auto it_v1 = this->_adjacencyMap.find(v1);
        auto it_v2 = this->_adjacencyMap.find(v2);
        if(it_v1 != this->_adjacencyMap.end() && it_v2 != this->_adjacencyMap.end())
            return (this->_adjacencyMap[v1][&(it_v2->first)]);
        else
            return nullptr;
    }

    template<typename V, typename E>
    std::vector<const Vertex<V>*> Graph<V,E>::endVertices(E e){
        Edge<E> edge; edge.setElement(e);
        std::vector<const Vertex<V>*> verts;
        auto edge_it = this->_edges.find(edge);
        if(edge_it == this->_edges.end()){
            return verts;
        }
            
        for(auto& it : this->_adjacencyMap){

            for(auto& it1: it.second){
                if(it1.second == &*edge_it){
                    verts.push_back(&(it.first));
                    verts.push_back(it1.first);
                    return verts;
                }
            }

        }


        return verts;
    }

    template<typename V, typename E>
    std::vector<const Vertex<V>*> Graph<V,E>::getNeightbors(V v){
        Vertex<V> v1; v1.setElement(v);
        std::vector<const Vertex<V>*> verts;

        if(!this->_adjacencyMap.count(v1)){
            return verts;
        }

        for(auto& it : this->_adjacencyMap[v1]){
            verts.emplace_back((it.first));
        }
        return verts;
    }

    template<typename V, typename E>
    const Vertex<V>* Graph<V,E>::opposite(V v, E e){
        Vertex<V> v1; v1.setElement(v);
        Edge<E> edge; edge.setElement(e);
        auto edge_it = this->_edges.find(edge);
        if(edge_it == this->_edges.end()){
            return nullptr;
        }
        if(this->_adjacencyMap.count(v1)){
            for(auto& it : this->_adjacencyMap[v1]){
                if(it.second == &*edge_it){
                    return (it.first);
                }
            }
        }

        return nullptr;
    }

    template<typename V, typename E>
    unsigned long Graph<V,E>::outDegree(V v){
        Vertex<V> v1; v1.setElement(v);
        return this->_adjacencyMap[v1].size();
    }

    template<typename V, typename E>
    unsigned long Graph<V,E>::inDegree(V v){
        Vertex<V> v1; v1.setElement(v);
        unsigned long counter = 0;
        auto it_v = this->_adjacencyMap.find(v1);
        if(it_v != this->_adjacencyMap.end())
            for(auto& it :this->_adjacencyMap){
                if(it.first.getElement() != v && it.second.count(&(it_v->first))){
                    counter++;
                }
            }

        return counter;
    }

    template<typename V, typename E>
    std::vector<const Edge<E>*> Graph<V,E>::outgoingEdges(V v){
        Vertex<V> v1; v1.setElement(v);
        std::vector<const Edge<E>*> edges;

        for(auto it : this->_adjacencyMap[v1]){
            edges.push_back((it.second));
        }

        return edges;
    }

    template<typename V, typename E>
    std::vector<const Edge<E>*> Graph<V,E>::incomingEdges(V v){
        Vertex<V> v1; v1.setElement(v);
        std::vector<const Edge<E>*> edges;
        auto it_v = this->_adjacencyMap.find(v1);
        if(it_v != this->_adjacencyMap.end())
            for(auto& it :this->_adjacencyMap){
                if(it.first.getElement() != v && it.second.count(&(it_v->first))){
                    edges.push_back((it.second[&(it_v->first)]));
                }
            }

        return edges;
    }

    template<typename V, typename E>
    int Graph<V,E>::insertVertex(V x){
        Vertex<V> v1; v1.setElement(x);
        auto it_v1 = this->_adjacencyMap.find(v1);
        if(it_v1 != this->_adjacencyMap.end())
            return 0;
        this->_adjacencyMap[v1];
        return 1;
    }

    template<typename V, typename E>
    int Graph<V,E>::insertEdge(V u, V y, E x){
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
        
        return 1;
    }

    template<typename V, typename E>
    int Graph<V,E>::removeVertex(V v){
        Vertex<V> v1; v1.setElement(v);
        std::unordered_set<const Edge<E>*> edge_to_remove;
        auto it_v1 = this->_adjacencyMap.find(v1);
        if(it_v1 == this->_adjacencyMap.end()){
            return 0;
        }

        for(auto& it : this->_adjacencyMap[v1]){
            edge_to_remove.insert((it.second));
            it.second=nullptr;
        }

        for(auto& it: this->_adjacencyMap){
            if(it.second.count(&(it_v1->first))){
                edge_to_remove.insert((it.second[&(it_v1->first)]));
                it.second[&(it_v1->first)] = nullptr;
                it.second.erase(&(it_v1->first));
            }
        }

        for(auto& it : edge_to_remove){
            this->_edges.erase(*it);
        }

        this->_adjacencyMap.erase(v1);

        return 1;
    }

    template<typename V, typename E>
    int Graph<V,E>::removeEdge(E e){
        Edge<E> ed; ed.setElement(e);
        auto it = this->_edges.find(ed);
        if(it==this->_edges.end()){
            return 0;
        }

        for(auto& it_v : this->_adjacencyMap){
            for(auto& it_v1 : it_v.second){
                if(it_v1.second == &*it){
                    it_v1.second = nullptr;
                    this->_adjacencyMap[it_v.first].erase(it_v1.first);
                    this->_edges.erase(ed);
                    return 1;
                }
            }
        }

        return 0;
    }

    template<typename V, typename E>
    int Graph<V,E>::vertexExists(V v){
        Vertex<V> v1; v1.setElement(v);
        return this->_adjacencyMap.count(v1);
    }

    template<typename V, typename E>
    int Graph<V,E>::edgeExists(E e){
        Edge<E> ed; ed.setElement(e);
        return this->_edges.count(ed);
    }

    template<typename V, typename E>
    std::string Graph<V,E>::toString(){

        std::ostringstream ss;

        for(auto& it : this->_adjacencyMap){
            ss << "[vertex: "<< &(it.first) <<"] " << it.first << ":\n";
            for(auto& it1 : it.second){
                ss << "\t[edge: " << it1.second << "] " << *(it1.second);
                ss << "\t--->\t";
                ss << "[vertex: "<< it1.first <<"] " << *(it1.first) << std::endl;
            }
        }

        return ss.str();

    }
}

#endif