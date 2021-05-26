/*
heap.h
Graph class declaration
Jacobo Soffer
A01028653
*/
#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include "util/ip.h"
#include "util/heap.h"

class Graph {
private:
    int numNodes;
    int numEdges;
    // Stores the nodes in the graph
    std::vector<Ip> nodes;
    // Stores the relationships within the
    // nodes
    std::vector<Ip>* data;
    // Parses a line and returns
    // the IP addresses
    void split(std::string line, std::vector<Ip>& res);
    // Parses a line containing numbers
    void split(std::string line, std::vector<int>& res);
public:
    // Default constructor
    // loadGraphList must be called before
    // using the object
    Graph();
    // Filename constructor
    // Takes the filename containing the graph
    // as the first argument.
    Graph(std::string);
    // Input stream constructor
    // Takes cin as the first argument for use with stdin redirection.
    Graph(std::istream&);
    // Loads the graph as an adj.list
    void loadGraphList(std::istream& input);
    // Returns a string containing the graph elements
    std::string print();
    // Loads graph nodes to a heap
    void loadToHeap(Heap<Ip>&);
};

#endif