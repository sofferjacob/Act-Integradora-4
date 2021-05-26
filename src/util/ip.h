/*
ip.h
Stores an IP address
and enables comparisons.
Jacobo Soffer | A01028653
Modified: 10/05/21
*/
#ifndef _IP_H
#define _IP_H

#include <string>
#include <vector>

enum  IpMode { GraphNode, HeapNode };

class Ip {
public:
    // Default constructor.
    // setAddress() must be
    // called before using 
    // object.
    Ip();
    // Takes an IPv4 address with port
    // as an argument. Fully initializes
    // the object.
    Ip(std::string, int, bool wPort = true);
    bool operator >(const Ip&);
    bool operator >=(const Ip&);
    bool operator <(const Ip&);
    bool operator <=(const Ip&);
    bool operator ==(const Ip&);
    bool operator !=(const Ip&);
    // Returns the stored IP address
    // as a string
    std::string getAddress();
    // Sets the IP address.
    // Takes an IPv4 address with port
    // as an argument
    void setAddress(std::string, bool wPort = true);
    // Returns a vector containing
    // every segment of the IP address
    // as an integer
    std::vector<int> getOctets();
    void setAdj(int);
    int getAdj();
    Ip setMode(IpMode mode);
private:
    // Weighted IP address value.
    // Used for comparisons
    double weight;
    std::vector<int> octets;
    std::string address;
    int adj;
    IpMode mode;
};

#endif