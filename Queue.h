
#ifndef DATASTRUCTURESCPP_QUEUE_H
#define DATASTRUCTURESCPP_QUEUE_H

#include <cstdlib>
#include <utility>

namespace wstd {

    template<typename Queue>
    class QueueIterator {

    public:
        using ValueType = typename Queue::ValueType;
        using PointerType = ValueType*;
        using ReferenceType = ValueType&;

    private:
        PointerType pData;

    public:
        explicit QueueIterator(PointerType ptr) : pData(ptr) {};


        QueueIterator& operator ++ () {
            pData++;
            return *this;
        };

        QueueIterator operator ++ (int) {
            QueueIterator iterator = *this;
            ++(*this);
            return iterator;
        }

        QueueIterator& operator -- () {
            pData--;
            return *this;
        };

        QueueIterator operator -- (int) {
            QueueIterator iterator = *this;
            --(*this);
            return iterator;
        }

        ReferenceType operator [] (int index) {
            return *(pData[index]);
        }

        PointerType operator -> () {
            return pData;
        }

        ReferenceType operator*() {
            return *pData;
        }

        bool operator == (const QueueIterator& other) const {
            return pData == other.pData;
        }

        bool operator != (const QueueIterator& other) const {
            return pData != other.pData;
        }
    };

    template<typename T>
    class Queue {
    private:
        T* data;
        size_t length;
        size_t capacity;

    public:
        using ValueType = T;
        using Iterator = QueueIterator<Queue<T>>;

        explicit Queue(size_t _capacity) {
            capacity = _capacity;
            data = new T[capacity];
            length = 0;
        }

        ~Queue() {
            delete data;
        }

        void enqueue(T newData) {
            if (length == capacity) {
                resize(capacity + sizeof(T));
            }
            data[length] = newData;
            length++;
        }

        void resize(size_t newCapacity) {
            T* newData = (T*)::operator new(newCapacity * sizeof(T));
            if (newCapacity < length)
                length = newCapacity;

            for (size_t i = 0; i < length; i++)
                newData[i] = std::move(data[i]);

            for (size_t i = 0; i < length; i++)
                data[i].~T();

            ::operator delete(data, capacity * sizeof(T));

            data = newData;
            capacity = newCapacity;
        }

        T dequeue() {
            T dequeued = data[0];
            for (int i = 0; i < length; i++) {
                data[i] = data[i + 1];
            }
            return dequeued;
        }

        Iterator begin() {
            return Iterator(data);
        }

        Iterator end() {
            return Iterator(data + length);
        }

        T operator [] (size_t index) {
            return data[index];
        }

        [[nodiscard]] size_t getLength() const {
            return length;
        }

        [[nodiscard]] size_t getCapacity() const {
            return capacity;
        }
    };
}

#endif //DATASTRUCTURESCPP_QUEUE_H
