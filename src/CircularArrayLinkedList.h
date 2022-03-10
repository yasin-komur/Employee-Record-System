#ifndef ASSIGNMENT2SCRATCH_CIRCULARARRAYLINKEDLIST_H
#define ASSIGNMENT2SCRATCH_CIRCULARARRAYLINKEDLIST_H
#define MAX_SIZE 20
#include "TemporaryEmployee.h"
#include <vector>
#include "Employee.h"

using namespace std;
class Node {
public:
    TemporaryEmployee* data;
    int next;
};

class CircularArrayLinkedList {
    Node* list[20] = {NULL};
    Node* head = nullptr;
    Node* current = nullptr;
    int getAvailable();
public:
    CircularArrayLinkedList();
    void insert(TemporaryEmployee* data);
    void remove(int employeeNum);
    bool contains(int employeeNumber);
    TemporaryEmployee* find(int  number);
    void createVector(vector<Employee *> *Employee);
};

#endif //ASSIGNMENT2SCRATCH_CIRCULARARRAYLINKEDLIST_H