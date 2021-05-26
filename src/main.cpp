#include <iostream>
#include "util/heap.h"
#include "graph.h"

using namespace std;

int main() {
    cout << "Act. Integradora 4" << endl;
    cout << "Cargando grafo..." << endl;
    Graph a("bitacoraGrafos.txt");
    cout << "Cargando nodos al heap..." << endl;
    Heap<Ip> heap;
    a.loadToHeap(heap);
    cout << "Resultados:" << endl;
    for (int i = 0; i < 5; i++) {
        Ip res = heap.poll();
        cout << (i + 1) << ": " << res.getAddress() << " con " << res.getAdj() << " nodos adyacentes." << endl;
    }
    return 0;
}