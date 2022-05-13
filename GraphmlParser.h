#pragma once
#include <map>
#include <string>
#include <utility>
#include <iostream>
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>

class GraphmlParser {
    public: 
    void parseFile(std::string & file, Graph & graph);
    private:
};