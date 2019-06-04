#include "pony.hpp"

void ponyOnTheHeap() {
    Pony* heapPony = new Pony("HHEEEAAAPP");
    delete heapPony;
}

void ponyOnTheStack() {
    Pony stavkPony("STAAAAAYYYAACK");
}

int main(void) {
    ponyOnTheStack();
    ponyOnTheHeap();
}