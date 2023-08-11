#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <limits>

#include "smartgraph/misc/updateable_priority_queue.h"
#include "smartgraph/graph/Graph.hpp"
#include "smartgraph/interface/Vertex.h"
#include "smartgraph/interface/Edge.h"
#include "smartgraph/element/KeyWeightValueElement.h"

namespace smartgraph::algorithm{

    using namespace smartgraph::graph;
    using namespace smartgraph::element;
    using namespace smartgraph::interface;
    using namespace smartgraph::misc;

    /**
     * @brief Method that calculate the shortest path between a given vertex and all other verteces of the graph with the Dijkstra algorithm
     * 
     * @tparam V Type of Vertex
     * @tparam K Type of edge Key
     * @tparam W Type of edge Weight
     * @tparam E Type of edge value
     * @param graph Graph containing veteces and edges
     * @param v_start Start vertex
     * @return std::map<V, W> map containing all reachable verteces and their shortest distance from the start vertex 
     */
    template<typename V, typename K, typename W=unsigned long, typename E>
    std::map<V, W> dijkstra(Graph<V, KeyWeightValueElement<K,W,E>>& graph, const V v_start);

    /**
     * @brief Method that compute the shortest path between a start vertex and a end vertex
     * 
     * @tparam V Type of Vertex
     * @tparam K Type of edge Key
     * @tparam W Type of edge Weight
     * @tparam E Type of edge value
     * @param graph Graph containing veteces and edges
     * @param v_start Start vertex
     * @param v_end End vertex
     * @return std::stack<std::pair<V, KeyWeightValueElement<K,W,E>>> stack containing the shortest path from v_start to v_end
     */
    template<typename V, typename K, typename W, typename E>
    std::stack<std::pair<V, KeyWeightValueElement<K,W,E>>> dijkstra(Graph<V, KeyWeightValueElement<K,W,E>>& graph, const V v_start, const V v_end);

}