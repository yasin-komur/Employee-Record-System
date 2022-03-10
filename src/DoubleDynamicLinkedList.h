#ifndef ASSIGNMENT2SCRATCH_DOUBLEDYNAMICLINKEDLIST_H
#define ASSIGNMENT2SCRATCH_DOUBLEDYNAMICLINKEDLIST_H
#include "PermanentEmployee.h"
#include <vector>

class Node2 {
public:
    Node2* next;
    Node2* prev;
    PermanentEmployee* data;
    Node2() {
        this->next = nullptr;
        this->prev = nullptr;
        this->data = nullptr;
    }
};

class DoubleDynamicLinkedList {
private:
    Node2* head;
public:
    DoubleDynamicLinkedList();
    void insert(PermanentEmployee* data);
    void remove(int employeeNum);
    bool contains(int employeeNumber);
    PermanentEmployee* find(int  employeeNumber);
    void createVector(std::vector<Employee *> *Employee);

};

#endif //ASSIGNMENT2SCRATCH_DOUBLEDYNAMICLINKEDLIST_H