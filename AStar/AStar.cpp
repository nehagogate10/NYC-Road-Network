#include "AStar.h"
#include <map>
#include <iostream>
#include <math.h>
#include <algorithm>

AStar::AStar(Graph & graph) {
    g = graph;
}

std::vector<Edge> AStar::findConnectingEdges(long currentNodeId) {
    std::vector<Edge> edges = g.edges_;
    std::vector<Edge> results;

    //traverse edges and find incident edges
    for (size_t i = 0; i < edges.size(); i++) {
        if (edges[i].from_id_ == currentNodeId || edges[i].to_id_ == currentNodeId) {
            results.push_back(edges[i]);
        }
    }
    return results;
}


//refactored mp mazes code
std::vector<int> AStar::findBestPath(Node & start, Node & end) {
    int startingId = start.id_;
    int endingId = end.id_;

    //used in mp mazes-- key is id of node
    std::map<long, double> distance;
    std::map<long, int> previous;
    std::vector<long> notvisited;
    int currentId = 0;

    //go through the vertices and initialize the values
    for(auto it = g.vertices_.begin(); it != g.vertices_.end(); it++) {
        long id = it->first;

        notvisited.push_back(id);
        distance[id] = (id == startingId) ? 0 : INT_MAX;
        previous[id] = (id == startingId) ? startingId : -1;
    }

    while (!notvisited.empty()) {
        //find the minimum distance + mid
        int minIDIndex = currentId;
        double minDist = INT_MAX;

        for (size_t i = 0; i < notvisited.size(); i++) {
            int currentDistance = distance[notvisited[i]];

            if (currentDistance < minDist) {
                minDist = currentDistance;
                minIDIndex = i;
                currentId = notvisited[i];
            }
        }

        notvisited.erase(notvisited.begin() + minIDIndex);

        if (currentId == endingId) {
            break;
        } else {
            std::vector<Edge> neighbors = findConnectingEdges(currentId);
            for (size_t i = 0; i < neighbors.size(); i++) {
                double newDist = distance[currentId] + neighbors[i].length_;
                long nextNodeId = 0;

                //check whether the next node is the source or destination of the edge
                if (neighbors[i].from_id_ == currentId) {
                    nextNodeId = neighbors[i].to_id_;
                } else {
                    nextNodeId = neighbors[i].from_id_;
                }

                if (newDist + FindDistance(currentId, endingId) < distance[nextNodeId] + FindDistance(nextNodeId, endingId)) {
                    previous[nextNodeId] = currentId;
                    distance[nextNodeId] = newDist;
                }
            }
        }
    }

    //store the path and reverse it
    std::vector<int> path;
    while (currentId != startingId) {
        path.push_back(currentId);
        currentId = previous[currentId];
    }
    path.push_back(startingId);
    std::reverse(path.begin(), path.end());

    return path;
}


//heuristic function
double AStar::FindDistance(long currentId, long destinationId) {
    Node currentNode = g.vertices_[currentId];
    Node destinationNode = g.vertices_[destinationId];

    double distance = pow(currentNode.x_ - destinationNode.x_, 2);
    distance += pow(currentNode.y_ - destinationNode.y_, 2);

    distance = pow(distance, 0.5);

    return distance;
}