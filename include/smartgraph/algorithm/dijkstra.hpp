#ifndef SMARTGRAPH_DIJKSTRA_H
#define SMARTGRAPH_DIJKSTRA_H

#include "smartgraph/algorithm/dijkstra.h"

namespace smartgraph::algorithm{

    template<typename X, typename Y>
    struct inverseComparator{
        constexpr bool operator()(std::pair<X, Y> const& a, std::pair<X, Y> const& b)  const noexcept{
            return a.second > b.second;
        }
    };

    template<typename V, typename K, typename W, typename E>
    std::map<V, W> dijkstra(Graph<V, KeyWeightValueElement<K,W,E>>& graph, const V v_start){

        std::map<V, W> d;
        std::map<V, W> cloud;

        std::priority_queue<std::pair<V,W>, std::vector<std::pair<V,W>>,inverseComparator<V,W>> pq;
        std::priority_queue<std::pair<V,W>, std::vector<std::pair<V,W>>,inverseComparator<V,W>> pq_cp;

        for(auto& v : graph.vertices()){
            if(v.getElement() == v_start){
                pq.push({v_start, 0});
                d[v_start]=0;
            }else{
                pq.push({v.getElement(), std::numeric_limits<W>::max()});
                d[v.getElement()] = std::numeric_limits<W>::max();
            }
        }

        while(pq.size()!=0){
            std::pair<V,W> u = pq.top();
            pq.pop();
            cloud[u.first] = u.second;
            for(auto ed : graph.outgoingEdges(u.first)){
                V v = graph.opposite(u.first, ed->getElement())->getElement();
                
                if(!cloud.count(v)){
                    W current_weight = ed->getElement().getWeight();
                    if(d[u.first]+current_weight < d[v]){
                        d[v] = d[u.first]+current_weight;
                        pq_cp = pq;
                        /*for(auto& it : pq){
                            if(it.first == v){
                                it.second = d[v];
                                break;
                            }
                        }*/
                    }    
                }
            }
        }

        return cloud;   
    }
}

#endif