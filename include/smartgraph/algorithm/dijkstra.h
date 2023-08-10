#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <limits>


#include "smartgraph/graph/Graph.hpp"
#include "smartgraph/interface/Vertex.h"
#include "smartgraph/interface/Edge.h"
#include "smartgraph/element/KeyWeightValueElement.h"

namespace smartgraph::algorithm{

    using namespace smartgraph::graph;
    using namespace smartgraph::element;
    using namespace smartgraph::interface;

    /**
     * @brief Method that claculate the shortest path between two verteces with the Dijkstra algorithm
     * 
     * @tparam V Type of Vertex
     * @tparam K Type of edge Key
     * @tparam W Type of edge Weight
     * @tparam E Type of edge value
     * @param graph Graph containing veteces and edges
     * @param v_start Start vertex
     * @return std::pair<int,std::vector<Vertex<V>>> pair containing the total weight as first and a vector of verteces that represents the path calculated
     */
    template<typename V, typename K, typename W=unsigned long, typename E>
    std::map<V, W> dijkstra(Graph<V, KeyWeightValueElement<K,W,E>>& graph, const V v_start);

}