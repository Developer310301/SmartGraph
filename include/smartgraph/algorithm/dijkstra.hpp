#ifndef SMARTGRAPH_DIJKSTRA_H
#define SMARTGRAPH_DIJKSTRA_H

#include "smartgraph/algorithm/dijkstra.h"

namespace smartgraph::algorithm{

    template<typename V, typename K, typename W, typename E>
    std::map<V, W> dijkstra(Graph<V, KeyWeightValueElement<K,W,E>>& graph, const V v_start){

        std::map<V, W> d;
        std::map<V, W> cloud;

        UpdateablePriorityPairQueue<V, W, inverseComparator<V, W>> pq;

        for(auto& v : graph.vertices()){
            if(*(v->getElement()) == v_start){
                pq.push({v_start, 0});
                d[v_start]=0;
            }else{
                pq.push({*(v->getElement()), std::numeric_limits<W>::max()});
                d[*(v->getElement())] = std::numeric_limits<W>::max();
            }
        }

        while(pq.size()!=0){
            std::pair<V,W> u = pq.top();
            pq.pop();
            if(u.second != std::numeric_limits<W>::max());
                cloud[u.first] = u.second;
            for(auto ed : graph.outgoingEdges(u.first)){
                V v = *(graph.opposite(u.first, *(ed->getElement()))->getElement());
                
                if(!cloud.count(v)){
                    W current_weight = ed->getElement()->getWeight();
                    if(d[u.first]+current_weight < d[v]){
                        d[v] = d[u.first]+current_weight;
                        pq.updateValue(v, d[v]);
                    }    
                }
            }
        }

        return cloud;
    }

    template<typename V, typename K, typename W, typename E>
    std::stack<std::pair<V, KeyWeightValueElement<K,W,E>>> dijkstra(Graph<V, KeyWeightValueElement<K,W,E>>& graph, const V v_start, const V v_end){
        std::map<V, W> reach_cloud = dijkstra(graph, v_start);
        std::stack<std::pair<V, KeyWeightValueElement<K,W,E>>> path;
        

        if(reach_cloud.size()==0 || !reach_cloud.count(v_end)) return path;

        V current_node = v_end;

        while(current_node!=v_start){
            

            for(auto& it : graph.incomingEdges(current_node)){
                V opposite_vertex = *(graph.opposite(current_node, *(it->getElement()))->getElement());
                if(reach_cloud[opposite_vertex] + it->getElement()->getWeight() == reach_cloud[current_node]){
                    path.push(std::pair<V, KeyWeightValueElement<K,W,E>>(current_node,*(it->getElement())));
                    current_node = opposite_vertex;
                    break;
                }
            }

        }

        path.push(std::pair<V, KeyWeightValueElement<K,W,E>>(v_start,KeyWeightValueElement<K,W,E>()));

        return path;
    }
}

#endif