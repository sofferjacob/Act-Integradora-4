/*
ip.cpp
IP class methods definition
Jacobo Soffer | A01028653
Modified: 10/05/21
*/
#include <stdexcept>
#include <cmath>
#include <iostream>
#include "ip.h"

Ip::Ip() : address(""), weight(0), mode(HeapNode) {}

Ip::Ip(std::string ip, int index, bool hasPort) : weight(0), mode(GraphNode) {
    setAddress(ip, hasPort);
}

std::string Ip::getAddress() {
    return address;
}

void Ip::setAddress(std::string ip, bool hasPort) {
    if (hasPort) {
        address = ip.substr(0, ip.find(":"));
    }
    else {
        address = ip;
    }
    int strPos = address.find(".");
    int lastPos = 0;
    while (strPos != std::string::npos) {
        octets.push_back(stoi(address.substr(lastPos, strPos - lastPos)));
        lastPos = strPos + 1;
        strPos = address.find(".", lastPos);
    }
    try {
        octets.push_back(stoi(address.substr(lastPos, address.length() - (lastPos))));
    }
    catch (...) {
        std::cout << "here it is" << std::endl;
        std::cout << "ip: " << ip << std::endl;
        std::cout << "address: " << address << std::endl;
        std::cout << "last pos: " << lastPos << std::endl;
        std::cout << "to: " << (address.length() - lastPos) << std::endl;
        //throw "fuck it";
    }
    if (octets.size() != 4) {
        throw std::invalid_argument("Invalid IP address");
    }
    weight = (pow(octets[0], 4) + pow(octets[1], 3) + pow(octets[2], 2) + octets[3]);
}

std::vector<int> Ip::getOctets() {
    return octets;
}

int Ip::getAdj() {
    return adj;
}

void Ip::setAdj(int n) {
    adj = n;
}

Ip Ip::setMode(IpMode m) {
    mode = m;
    return *this;
}

bool Ip::operator >(const Ip& other) {
    if (mode == HeapNode) return adj > other.adj;
    return weight > other.weight;
}

bool Ip::operator >=(const Ip& other) {
    if (mode == HeapNode) return adj >= other.adj;
    return weight >= other.weight;
}

bool Ip::operator <(const Ip& other) {
    if (mode == HeapNode) return adj < other.adj;
    return weight < other.weight;
}

bool Ip::operator <=(const Ip& other) {
    if (mode == HeapNode) return adj <= other.adj;
    return weight <= other.weight;
}

bool Ip::operator ==(const Ip& other) {
    if (mode == HeapNode) return adj == other.adj;
    return weight == other.weight;
}

bool Ip::operator !=(const Ip& other) {
    if (mode == HeapNode) return adj != other.adj;
    return weight != other.weight;
}