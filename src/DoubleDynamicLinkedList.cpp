#include "DoubleDynamicLinkedList.h"
#include <vector>

using namespace std;

DoubleDynamicLinkedList::DoubleDynamicLinkedList() {
    this->head = nullptr;
}

void DoubleDynamicLinkedList::insert(PermanentEmployee *data) {
    if(head == nullptr) {
        head = new Node2();
        head->data = data;
    }
    else {
        Node2* current  = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        Node2* node = new Node2();
        node->data = data;
        node->prev = current;
        current->next = node;
    }
}

void DoubleDynamicLinkedList::remove(int employeeNum) {
    if(head->data->getEmployeeNumber() == employeeNum) {
        Node2* temp = head->next;
        delete head;
        head = temp;
        head->prev = nullptr;
        return;
    }
    Node2* current = head;
    while(current->next != nullptr) {
        if(current->data->getEmployeeNumber() == employeeNum) {
            current->next->prev = current->prev;
            current->prev->next = current->next;
            delete current;
            return;
        }
        current = current->next;
    }
    if (current->next == nullptr) {
        current->prev->next = nullptr;
        delete current;
    }
}


bool DoubleDynamicLinkedList::contains(int employeeNumber) {
    Node2* temp = head;
    while (temp != nullptr) {
        if (temp->data->getEmployeeNumber() == employeeNumber) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

PermanentEmployee *DoubleDynamicLinkedList::find(int employeeNumber) {
    Node2* i;
    if (this->contains(employeeNumber)) {
        for (i = head; i->next != nullptr; i = i->next) {
            if (i->data->getEmployeeNumber() == employeeNumber) {
                return i->data;
            }
        }
        if (i->data->getEmployeeNumber() == employeeNumber) {
            return i->data;
        }
    }
}

void DoubleDynamicLinkedList::createVector(vector<Employee *> *employee) {
    Node2* i;
    if (head == nullptr)
        return;
    for (i = head; i->next != nullptr; i = i->next) {
        employee->push_back(i->data);
    }
    employee->push_back(i->data);
}
