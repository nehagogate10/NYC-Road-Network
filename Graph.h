#pragma once
#include <map>
#include <vector>
#include <string>


class Node {
    public:
        Node(long id, double y, double x, int osmid, std::string highway, int ref)
        : id_(id), y_(y), x_(x), osmid_(osmid), highway_(highway), ref_(ref) {};
        Node(long id, double x, double y) : id_(id), y_(y), x_(x) {};
        Node() {};

        long id_; //nothing
        double y_; //d3
        double x_; //d4
        int osmid_; //d5
        std::string highway_; //d6
        int ref_; //d7

    private:
};

class Edge {
    public:
        Node* from_;
        Node* to_;
        long from_id_, to_id_;

        Edge(){};

        Edge(std::string name, double length, int osmid, std::string highway, std::string oneway, 
        int key, int lanes, std::string maxspeed, std::string geometry, std::string ref, std::string bridge, 
        std::string tunnel, std::string width, std::string access, std::string service)
        : name_(name), length_(length), osmid_(osmid), highway_(highway), oneway_(oneway), key_(key), lanes_(lanes), maxspeed_(maxspeed), 
        geometry_(geometry), ref_(ref), bridge_(bridge), tunnel_(tunnel), width_(width), access_(access), service_(service) {};

        Edge(long from_id, long to_id, std::string name, double length)
        : from_id_(from_id), to_id_(to_id), name_(name), length_(length) {};
        std::string name_; //d8
        double length_; //d9
        int osmid_; //d10
        std::string highway_; //d11
        std::string oneway_; //d12
        int key_; //d13
        int lanes_; //d14
        std::string maxspeed_; //d15
        std::string geometry_; //d16
        std::string ref_; //d17
        std::string bridge_; //d18 yes format
        std::string tunnel_; //d19 yes format
        std::string width_; //d20
        std::string access_; //d21 yes format
        std::string service_; //d22
    private:
};

class Graph {
    public:
        std::map<long, Node> vertices_;
        std::vector<Edge> edges_;

        Graph(){};

        Graph(std::map<std::string, std::string> crs, std::string name, std::map<int, int> streets_per_node)
        : crs_(crs), name_(name), streets_per_node_(streets_per_node) {};
    private:
        std::map<std::string, std::string> crs_;
        std::string name_;
        std::map<int, int> streets_per_node_;
};

