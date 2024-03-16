

#ifndef DATASTRUCTURESCPP_DARRAY_H
#define DATASTRUCTURESCPP_DARRAY_H

#include <cstdlib>
#include <utility>

namespace wstd {
    template<typename DArray>
    class DArrayIterator {

    public:
        using ValueType = typename DArray::ValueType;
        using PointerType = ValueType*;
        using ReferenceType = ValueType&;

    private:
        PointerType pData;

    public:
        explicit DArrayIterator(PointerType ptr) : pData(ptr) {};


        DArrayIterator& operator ++ () {
            pData++;
            return *this;
        };

        DArrayIterator operator ++ (int) {
            DArrayIterator iterator = *this;
            ++(*this);
            return iterator;
        }

        DArrayIterator& operator -- () {
            pData--;
            return *this;
        };

        DArrayIterator operator -- (int) {
            DArrayIterator iterator = *this;
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

        bool operator == (const DArrayIterator& other) const {
            return pData == other.pData;
        }

        bool operator != (const DArrayIterator& other) const {
            return pData != other.pData;
        }
    };

    template<typename T>
    class DArray {
    private:
        T* data;
        size_t length;
        size_t capacity;

    public:
        using ValueType = T;
        using Iterator = DArrayIterator<DArray<T>>;

        explicit DArray(size_t _capacity) {
            capacity = _capacity;
            data = new T[capacity];
            length = 0;
        }

        ~DArray() {
            delete data;
        }

        void push_back(T newData) {
            if (length == capacity) {
                resize(sizeof(T) * (capacity * 2));
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

            delete[] data;

            data = newData;
            capacity = newCapacity;
        }

        void emplace_back(T data);

        T pop_back() {
            if (length > 0)
                length--;
            return data[length];
        }

        void insert();

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

#endif //DATASTRUCTURESCPP_DARRAY_H
