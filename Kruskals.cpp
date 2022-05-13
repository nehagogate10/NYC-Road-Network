#include "Kruskals.h"

Kruskals::Kruskals(Graph & graph) {
    graph_ = graph;

    sortEdges();
    ds_ = DisjointSets();
    ds_.makeDisjointSet(graph);
}


void Kruskals::sortEdges() {
    std::sort(graph_.edges_.begin(),graph_.edges_.end(),
    [] (const Edge& lhs, const Edge& rhs)
    {
        return lhs.length_ < rhs.length_;
    });
}


void DisjointSets::makeDisjointSet(Graph & graph) {
    for (auto it = graph.vertices_.begin(); it != graph.vertices_.end(); ++it) {
        // for (int y=0;y<graph.edges_.size();y++) {
        //     if (graph.edges_[y].to_id_ == it->first) {
        //         //insert the node that it came from into the disjointset map
        //         disjoint_map.insert ( std::pair<long,long>(it->first, graph.edges_[y].from_id_) );
        //     } else if (graph.edges_[y].from_id_ == it->first) {
        //         //insert the node that it came from into the disjointset map
        //         disjoint_map.insert ( std::pair<long,long>(it->first, graph.edges_[y].from_id_) );
        //     } else {
        //         //insert the size of the group the node is part of
        //         disjoint_map.insert ( std::pair<long,long>(it->first, ) );
        //     }
        // }

        disjoint_map[it->first] = -1;
    }
}

std::vector<Edge> Kruskals::traverse_kruskal() {
    std::vector<Edge> trav;
    for(size_t i = 0; i < graph_.edges_.size(); i++) {
        if(ds_.find(graph_.edges_[i].to_id_) != ds_.find(graph_.edges_[i].from_id_)) {
            trav.push_back(graph_.edges_[i]);
            ds_.setunion(graph_.edges_[i].to_id_, graph_.edges_[i].from_id_);
        }
    }

    return trav;
}

long DisjointSets::find(long elem) {
    if (elem >= (long)disjoint_map.size()) {
        return -1;
    }
    if (disjoint_map[elem] < 0) {
        return elem;
    } else {
        disjoint_map[elem] = find(disjoint_map[elem]);
        return disjoint_map[elem];
    }
}

void DisjointSets::setunion(long a, long b) {
    if (find(a) == find(b)) {
        //roots are already the same
        return;
    }

    long larger = (disjoint_map[find(a)] > disjoint_map[find(b)]) ? find(a) : find(b); 
    long smaller = (disjoint_map[find(a)] > disjoint_map[find(b)]) ? find(b) : find(a); 

    disjoint_map[smaller] += disjoint_map[larger];
    disjoint_map[larger] = smaller;
}


long DisjointSets::size(long elem) {
    return (-1 * disjoint_map[find(elem)]);
}




