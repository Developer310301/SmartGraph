#ifndef SMARTGRAPH_UPDATEABLE_PRIORITY_QUEUE_H
#define SMARTGRAPH_UPDATEABLE_PRIORITY_QUEUE_H

#include <queue>
#include <unordered_map>
#include <utility>

namespace smartgraph::misc{

    template<typename X, typename Y>
    struct comparator{
        constexpr bool operator()(std::pair<X, Y> const& a, std::pair<X, Y> const& b)  const noexcept{
            return a.second < b.second;
        }
    };

    template<typename X, typename Y>
    struct inverseComparator{
        constexpr bool operator()(std::pair<X, Y> const& a, std::pair<X, Y> const& b)  const noexcept{
            return a.second > b.second;
        }
    };

    template<typename X, typename Y, typename Z>
    class UpdateablePriorityPairQueue : public std::priority_queue<std::pair<X, Y>, std::vector<std::pair<X, Y>>, Z>{
        public:
            void updateValue(const X x, const Y y){
                for(auto& it : this->c){
                    if(it.first == x){
                        it.second = y;
                        std::make_heap(this->c.begin(), this->c.end(), this->comp);
                        break;
                    }
                }
            }
    };

}

#endif