//#include "smartgraph/graph/UnorientedGraph.h"

namespace smartgraph::graph{

    template<typename V, typename E>
    unsigned long UnorientedGraph<V,E>::numVertices(){
        return this->_vertexes.size();
    }

    template<typename V, typename E>
    std::vector<std::shared_ptr<const Vertex<V>>> UnorientedGraph<V,E>::vertices(){

        std::vector<std::shared_ptr<const Vertex<V>>> verts{};

        for(auto& it : this->_vertexes){
            verts.emplace_back(std::shared_ptr<const Vertex<V>>(&(it)));
        }

        return verts;

    }

    template<typename V, typename E>
    unsigned long UnorientedGraph<V,E>::numEdges(){
        return this->_edges.size();
    }

    template<typename V, typename E>
    std::vector<std::shared_ptr<const Edge<E>>> UnorientedGraph<V,E>::edges(){
        std::vector<std::shared_ptr<const Edge<E>>> edgs{};

        for(auto& it : this->_edges){
            edgs.emplace_back(std::shared_ptr<const Edge<E>>(&it));
        }

        return edgs;
    }

    template<typename V, typename E>
    std::shared_ptr<const Edge<E>> UnorientedGraph<V,E>::getEdge(std::shared_ptr<const Vertex<V>> u, std::shared_ptr<const Vertex<V>> v){
        return this->_adjacencyMap[u][v];
    }

    template<typename V, typename E>
    std::vector<std::shared_ptr<const Vertex<V>>> UnorientedGraph<V,E>::endVertices(std::shared_ptr<const Edge<E>> e){
        std::vector<std::shared_ptr<const Vertex<V>>> verts{};

        for(auto& it : this->_adjacencyMap){
            for(auto& it1 : it.second){
                if(it1.second == e){
                    verts.emplace_back(it.first);
                    verts.emplace_back(it1.first);
                }
            }
        }

        return verts;
    }

    template<typename V, typename E>
    std::shared_ptr<const Vertex<V>> UnorientedGraph<V,E>::opposite(std::shared_ptr<const Vertex<V>> v, std::shared_ptr<const Edge<E>> e){
        for(auto& it : this->_adjacencyMap[v]){
            if(it.second == e){
                return it.first;
            }
        }
        return std::shared_ptr<const Vertex<V>>(nullptr);
    }

    template<typename V, typename E>
    unsigned long UnorientedGraph<V,E>::outDegree(std::shared_ptr<const Vertex<V>> v){
        return this->_adjacencyMap[v].size();
    }

    template<typename V, typename E>
    unsigned long UnorientedGraph<V,E>::inDegree(std::shared_ptr<const Vertex<V>> v){
        return this->outDegree(v);
    }

    template<typename V, typename E>
    std::vector<std::shared_ptr<const Edge<E>>> UnorientedGraph<V,E>::outgoingEdges(std::shared_ptr<const Vertex<V>> v){

        std::vector<std::shared_ptr<const Edge<E>>> edgs{};

        for(auto& it : this->_adjacencyMap[v]){
            edgs.emplace_back(it.second);
        }

        return edgs;
    }

    template<typename V, typename E>
    std::vector<std::shared_ptr<const Edge<E>>> UnorientedGraph<V,E>::incomingEdges(std::shared_ptr<const Vertex<V>> v){
        return this->outgoingEdges(v);
    }

    template<typename V, typename E>
    std::shared_ptr<const Vertex<V>> UnorientedGraph<V,E>::insertVertex(V x){
        Vertex<V> v;
        v.setElement(x);
        auto it = (this->_vertexes.insert(v).first);        
        this->_adjacencyMap[std::shared_ptr<const Vertex<V>>(&*(it))] = {};

        return std::shared_ptr<const Vertex<V>>(&*(it));
    }

    template<typename V, typename E>
    std::shared_ptr<const Edge<E>> UnorientedGraph<V,E>::insertEdge(std::shared_ptr<const Vertex<V>> u, std::shared_ptr<const Vertex<V>> y, E x){
        Edge<E> e;
        e.setElement(x);
        auto it = this->_edges.insert(e).first;
        this->_adjacencyMap[u][y] = std::shared_ptr<const Edge<E>>(&*(it));
        return std::shared_ptr<const Edge<E>>(&*(it));
    }
}