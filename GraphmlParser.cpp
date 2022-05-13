#include "GraphmlParser.h"

void GraphmlParser::parseFile(std::string & file, Graph & graph) {
    Edge edge;
    Node node;
    bool edge_tag = false;
    bool node_tag = false;

    std::string line;
    std::ifstream in(file);
    while(getline(in,line)) {
        std::string temp; //removing whitespaces
        for (size_t i = 0; i < line.length(); i++) {
            if ((line[i] == ' ' || line[i] == '\t') && temp.size() == 0) {
                continue;
            } else {
                temp += line[i];
            }
        }

        //Checking if new node beginning 
        if (temp.rfind("<node", 0) == 0) {
            node = Node();

            if (temp.find("id") != std::string::npos) {
                size_t start_pos = temp.find("\"") + 1;
                size_t size = temp.find("\">") - start_pos;
                node.id_ = std::stol(temp.substr(start_pos, size));

                node_tag = true;
            }
        }

        //Get node properties
        if(node_tag) {
            //Getting y
            if (temp.find("d3") != std::string::npos) {
                size_t start_pos = temp.find(">") + 1;
                size_t size = temp.find("</data>") - start_pos;
                node.y_ = std::stod(temp.substr(start_pos, size));
            }

            //Getting x
            if (temp.find("d4") != std::string::npos) {
                size_t start_pos = temp.find(">") + 1;
                size_t size = temp.find("</data>") - start_pos;
                node.x_ = std::stod(temp.substr(start_pos, size));
            }
        }

        //Finished constructing node
        if (temp.rfind("</node", 0) == 0) {
            if(node_tag) {
                graph.vertices_[node.id_] = node;
            }

            node_tag = false;
        }

        //Checking if new edge beginning 
        if (temp.rfind("<edge", 0) == 0) {
            edge = Edge();

            if (temp.find("source") != std::string::npos && temp.find("target") != std::string::npos) {
                size_t start_pos = temp.find("\"") + 1;
                size_t size = temp.find(" target>") - start_pos;
                edge.from_id_ = std::stol(temp.substr(start_pos, size));

                start_pos = temp.find("t=\"") + 3;
                size = temp.find("\">") - start_pos;
                edge.to_id_ = std::stol(temp.substr(start_pos, size));

                edge_tag = true;
            }
        }

        //Get edge properties
        if(edge_tag) {
            //Getting name
            if (temp.find("d8") != std::string::npos) {
                size_t start_pos = temp.find(">") + 1;
                size_t size = temp.find("</data>") - start_pos;
                edge.name_ = temp.substr(start_pos, size);
            }

            //Getting length
            if (temp.find("d9") != std::string::npos) {
                size_t start_pos = temp.find(">") + 1;
                size_t size = temp.find("</data>") - start_pos;
                edge.length_ = std::stod(temp.substr(start_pos, size));
            }
        }

        //Finished constructing edge
        if (temp.rfind("</edge", 0) == 0) {
            if(edge_tag) {
                graph.edges_.push_back(edge);
            }
            edge_tag = false;
        }
    }
}