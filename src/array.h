#ifndef ARRAY_H
#define ARRAY_H

#include <string.h>

template <class T>
class Array {
public:
    void append(T elem) {
        int dstIndex = m_length;
        if (m_length + 1 > m_allocatedLength) {
            int newLength = m_allocatedLength + 1;
            T* newValues = new T[newLength];
            if (m_length > 0) {
                memcpy(newValues, m_values, sizeof(T) * m_length);
                delete [] m_values;
            }
            m_allocatedLength = newLength;
            m_values = newValues;
        }
        m_values[dstIndex] = elem;
        m_length++;
    }

    void removeAt(int i) {
        if (i + 1 > m_length)
            return;

        for (int iItem = i; iItem + 1 < m_length; iItem++) {
            memcpy(&m_values[iItem], &m_values[iItem + 1], sizeof(T));
        }
        m_length--;
    }

    int indexOf(T elem) {
        for (int i = 0; i < m_length; i++) {
            if (m_values[i] == elem)
                return i;
        }
        return -1;
    }

    int length() const {
        return m_length;
    }

    T at(int i) {
        return m_values[i];
    }

    ~Array() {
        if (m_values)
            delete [] m_values;
    }

private:
    T* m_values = nullptr;
    int m_length = 0;
    int m_allocatedLength = 0;
};

#endif // ARRAY_H
