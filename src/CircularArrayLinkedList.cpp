#include "CircularArrayLinkedList.h"

using namespace std;

CircularArrayLinkedList::CircularArrayLinkedList() {
    this->head = nullptr;
}

void CircularArrayLinkedList::insert(TemporaryEmployee *data) {
    if(head == nullptr) {
        head = new Node();
        head->data = data;
        head->next = 0;
        list[0] = head;
    }
    else {
        current = head;
        // LAST ELEMENT'S NEXT VALUE ALWAYS EQUALS TO HEAD'S INDEX
        while(list[current->next] != head) {
            current = list[current->next];
        }
        Node* node = new Node();
        node->data = data;
        node->next = current->next;
        int index = getAvailable();
        current->next = index;
        list[index] = node;
    }
}


void CircularArrayLinkedList::remove(int employeeNum) {
    if(head->data->getEmployeeNumber() == employeeNum) {
        while(list[current->next] != head) {
            current = list[current->next];
        }
        list[current->next] = nullptr;
        current->next = head->next;
        delete head;
        head = list[current->next];
        return;
    }
    Node* prev = nullptr;
    current = head;
    while(current->data->getEmployeeNumber() != employeeNum){
        prev = current;
        current = list[current->next];
    }
    list[prev->next] = nullptr;
    prev->next = current->next;
    delete current;
}

int CircularArrayLinkedList::getAvailable() {
    for(int index = 0; index < MAX_SIZE; index++) {
        if(list[index] == nullptr) {
            return index;
        }
    }
    return -1;
}

bool CircularArrayLinkedList::contains(int employeeNumber) {
    Node* i;
    if (head == nullptr)
        return false;
    for (i = head; list[i->next] != head; i = list[i->next]) {
        if (i->data->getEmployeeNumber() == employeeNumber) {
            return true;
        }
    }
    if (i->data->getEmployeeNumber() == employeeNumber)
        return true;
    return false;
}

TemporaryEmployee *CircularArrayLinkedList::find(int employeeNumber) {
    Node* i;
    for (i = head; list[i->next] != head; i = list[i->next]) {
        if (i->data->getEmployeeNumber() == employeeNumber) {
            return i->data;
        }
    }
    if (i->data->getEmployeeNumber() == employeeNumber) {
        return i->data;
    }
}

void CircularArrayLinkedList::createVector(vector<Employee *> *employee) {
    Node* i;
    if (head == nullptr)
        return;
    for (i = head; list[i->next] != head; i = list[i->next]) {
            employee->push_back(i->data);
    }
    employee->push_back(i->data);
}

