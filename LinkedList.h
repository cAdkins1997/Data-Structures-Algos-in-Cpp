
#ifndef DATASTRUCTURESCPP_LINKEDLIST_H
#define DATASTRUCTURESCPP_LINKEDLIST_H

#include <cstdlib>
#include <cassert>
#include <iostream>

namespace wstd {
    template<typename T>
    struct Node {
        T data;
        Node* next;
        Node* previous;
    };

    template<typename T>
    class LinkedList {
    private:
        Node<T>* head;
        Node<T>* end;
        size_t length;

        Node<T>* nodeAt(const size_t index) {
            size_t midpoint = length / 2;
            if (index == 0)
                return head;
            else if ((index < midpoint && head->next != nullptr) || index == midpoint) {
                Node<T> *currentNode = head->next;
                size_t j = 0;
                while (currentNode->next != nullptr && j != index) {
                    currentNode = currentNode->next;
                    j++;
                }
                return currentNode;
            } else if (index > midpoint && end->previous != nullptr) {
                Node<T> *currentNode = end;
                size_t j = length - 1;
                while (currentNode->previous != nullptr && j != index) {
                    currentNode = currentNode->previous;
                    j--;
                }
                return currentNode;
            }
        }

    public:

        LinkedList() {
            head = new Node<T>;
            head->next = nullptr;
            head->previous = end;
            end = new Node<T>;
            length = 0;
        }

        void append(const T& newData) {
            auto* newNode = new Node<T>{newData, nullptr, nullptr};
            if (head->next == nullptr) {
                head->next = newNode;
                head->previous = end;
                newNode->next = head;
                newNode->previous = head;
                end = newNode;
            }
            else {
                end->next = newNode;
                newNode->previous = end;
                newNode->next = head;
                end = newNode;
            }
            length++;
        }

        void insert(const T& newData, const size_t location) {
            auto* newNode = new Node<T>{newData, nullptr, nullptr};
            Node<T>* previousNode = nodeAt(location);
            if (previousNode->next != nullptr) {
                Node<T>* nextNode = previousNode->next;
                nextNode->previous = newNode;
                newNode->next = nextNode;
            }
            previousNode->next = newNode;
            length++;
        }

        void replaceAt(const T& newData, const size_t location) {
            auto* newNode = new Node<T>{newData, nullptr, nullptr};
            Node<T>* nodeToReplace = nodeAt(location);
            nodeToReplace->data = newData;
        }

        void remove(size_t index) {
            Node<T>* selectedNode = nodeAt(index);
            Node<T>* nextNode = selectedNode->next;
            Node<T>* previousNode = selectedNode->previous;
            nextNode->previous = previousNode;
            previousNode->next = nextNode;
            delete selectedNode;
        }

        T operator [] (const size_t index) const {
            size_t midpoint = length / 2;
            if (index == 0)
                return head->data;
            else if ((index < midpoint && head->next != nullptr) || index == midpoint) {
                Node<T>* currentNode = head->next;
                size_t j = 0;
                while (currentNode->next != nullptr && j != index) {
                    currentNode = currentNode->next;
                    j++;
                }
                return currentNode->data;
            }
            else if (index > midpoint && end->previous != nullptr) {
                Node<T>* currentNode = end;
                size_t j = length - 1;
                while (currentNode->previous != nullptr && j != index) {
                    currentNode = currentNode->previous;
                    j--;
                }
                return currentNode->data;
            }
        }

        [[nodiscard]] Node<T> getHead() const {
            return head;
        }

        [[nodiscard]] Node<T> getEnd() const {
            return end;
        };

        [[nodiscard]] size_t getSize() const {
            return length;
        }
    };
}


#endif //DATASTRUCTURESCPP_LINKEDLIST_H
