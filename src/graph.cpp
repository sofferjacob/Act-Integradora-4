#include <stdexcept>
#include <sstream>
#include <set>
#include <fstream>
#include "algo/binary_search.h"
#include "algo/quick_sort.h"
#include "graph.h"

using namespace std;

Graph::Graph() {}

Graph::Graph(std::istream& input) {
    loadGraphList(input);
}

Graph::Graph(std::string filename) {
    ifstream file(filename);
    if (!file.good()) {
        file.close();
        throw invalid_argument("File not found");
    }
    loadGraphList(file);
    file.close();
}

void Graph::loadGraphList(std::istream& input) {
    std::string line;
    getline(input, line);
    vector<int> meta;
    split(line, meta);
    numNodes = meta[0];
    numEdges = meta[1];
    data = new vector<Ip>[numNodes];
    for (int i = 0; i < numNodes; i++) {
        getline(input, line);
        nodes.push_back(Ip(line, i, false));
    }
    quickSort(nodes, 0, nodes.size() - 1);
    while (std::getline(input, line)) {
        vector<Ip> res;
        split(line, res);
        int index = binarySearch(nodes, res[0]);
        if (index == -1) {
            throw invalid_argument("Malformed file");
        }
        data[index].push_back(res[1]);
    }
}

void Graph::split(std::string line, std::vector<Ip>& res) {
    int strPos = line.find(" ");
    int lastPos = 0;
    vector<string> parts;
    while (strPos != std::string::npos) {
        parts.push_back(line.substr(lastPos, strPos - lastPos));
        lastPos = strPos + 1;
        strPos = line.find(" ", lastPos);
    }
    parts.push_back(line.substr(lastPos, line.size() - lastPos));
    res.push_back(Ip(parts[3], -1));
    res.push_back(Ip(parts[4], -1));
}

void Graph::split(std::string line, std::vector<int>& res) {
    int strPos = line.find(" ");
    int lastPos = 0;
    while (strPos != std::string::npos) {
        res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
        lastPos = strPos + 1;
        strPos = line.find(" ", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

string Graph::print() {
    stringstream aux;
    for (int i = 0; i < numNodes; i++) {
        aux << "vertex "
            << nodes[i].getAddress() << " :";
        for (int j = 0; j < data[i].size(); j++) {
            aux << " " << data[i][j].getAddress();
        }
        aux << " ";
    }
    return aux.str();

}

void Graph::loadToHeap(Heap<Ip>& heap) {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].setAdj(data[i].size());
        heap.push(nodes[i].setMode(HeapNode));
        if (i < 10) {
            cout << nodes[i].getAdj() << endl;
        }
    }
}