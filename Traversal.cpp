#include "Traversal.h"

std::vector<Node> Traversal::BFS(Graph g) {
    std::queue<Node> q;
    std::vector<Node> nodes;
    
    //Initialising map of visited nodes
    std::map<long, bool> visited_ids;
    for (std::map<long, Node>::iterator it = g.vertices_.begin(); it != g.vertices_.end(); ++it) {
        visited_ids[it->second.id_] = false;
    }

    Node currentNode = g.vertices_.begin()->second;
    visited_ids[currentNode.id_] = true;
    nodes.push_back(currentNode);

    q.push(currentNode);
    while (!q.empty()) {
        std::cout << "hi" << std::endl;
        Node toDelete = q.front();
        nodes.push_back(toDelete);
        std::vector<Edge> edges = findEdges(toDelete, g);
        q.pop();

        for (int i = 0; i < edges.size(); i++) {
            if (!visited_ids[edges[i].to_id_]) {
                std::cout << edges[i].to_id_ << std::endl;
                q.push(g.vertices_[edges[i].to_id_]);
                visited_ids[edges[i].to_id_] = true;
            }

            if (!visited_ids[edges[i].from_id_]) {
                std::cout << edges[i].from_id_ << std::endl;
                q.push(g.vertices_[edges[i].from_id_]);
                visited_ids[edges[i].from_id_] = true;
            }
        }
    }

    return nodes;
}

std::vector<Edge> Traversal::findEdges(Node & node, Graph & g, bool directed) {
    std::vector<Edge> edges;
    long id = node.id_;
    for (int i = 0; i < g.edges_.size(); i++) {
        if (g.edges_[i].from_id_== id || (!directed && g.edges_[i].to_id_ == id)) {
            edges.push_back(g.edges_[i]);
        }
    }
    return edges;
}


