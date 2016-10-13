#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> 
#include <set>
#include <utility>
#include <algorithm> 
#include <iterator>

using namespace std;


typedef int vertex_t;
typedef double weight_t;

const weight_t max_weight = numeric_limits<double>::infinity();

struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
        : target(arg_target), weight(arg_weight) { }
};

typedef vector<vector<neighbor> > adjacency_list_t;

// Computing the shortest pathway

void DijkstraComputePaths(vertex_t source,
                     const adjacency_list_t &adjacency_list,
                     vector<weight_t> &min_distance,
                     vector<vertex_t> &previous){
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    set<pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(make_pair(min_distance[source], source));

    while (!vertex_queue.empty())
    {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());

        // Visit each edge exiting u
        const vector<neighbor> &neighbors = adjacency_list[u];
        for (vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
            neighbor_iter != neighbors.end();
            neighbor_iter++)
        {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
            if (distance_through_u < min_distance[v]) {
                vertex_queue.erase(make_pair(min_distance[v], v));

                min_distance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.insert(make_pair(min_distance[v], v));

            }
        }
    } // while
}

int main(){
	
	return 0;
}
