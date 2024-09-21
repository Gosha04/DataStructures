#ifndef NQUEUE_H
#define NQUEUE_H

template <typename T>
class NQueue
{
private:
    int m_count;   // Current number of elements in the queue
    int m_front;   // Index of the front of the queue
    int m_back;    // Index of the back of the queue
    int m_max;     // Max size of the array
    T* m_arr;      // Pointer to the array for storing queue elements

public:
    NQueue();           // Default constructor
    NQueue(int size);   // Constructor with initial size
    ~NQueue();          // Destructor
    void add(T value); // Enqueue (add element to the back)
    T remove();            // Dequeue (remove element from the front)
    T peek();           // Peek at the front element without removing
    bool isEmpty();     // Check if the queue is empty
    bool isFull();      // Check if the queue is full
    int size();         // Get the current number of elements in the queue
};

// Default constructor
template <typename T>
NQueue<T>::NQueue() { 
    m_count = 0;
    m_max = 0;
    m_front = 0;
    m_back = -1;
    m_arr = nullptr;
}

// Constructor with initial size
template <typename T>
NQueue<T>::NQueue(int size) { 
    m_count = 0;
    m_max = size;
    m_front = 0;
    m_back = -1;
    m_arr = new T[m_max]; // Allocate memory for the array
}

// Destructor
template <typename T>
NQueue<T>::~NQueue() { 
    if (m_arr != nullptr) {
        delete[] m_arr;  // Clean up dynamically allocated memory
    }
}

// Enqueue (add element to the back of the queue)
template <typename T>
void NQueue<T>::add(T value) {
    if (isFull()) {
        // If full, expand the capacity of the queue by 2x
        int new_max = m_max == 0 ? 1 : m_max * 2;
        T* temp = new T[new_max];
        
        // Copy existing elements to new array (circular)
        for (int i = 0; i < m_count; ++i) {
            temp[i] = m_arr[(m_front + i) % m_max];
        }

        delete[] m_arr;
        m_arr = temp;
        m_front = 0;
        m_back = m_count - 1;
        m_max = new_max;
    }

    // Update m_back and wrap around if necessary
    m_back = (m_back + 1) % m_max;
    m_arr[m_back] = value;
    ++m_count;
}

// Dequeue (remove element from the front of the queue)
template <typename T>
T NQueue<T>::remove() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    T value = m_arr[m_front];
    m_front = (m_front + 1) % m_max; // Move front forward and wrap if necessary
    --m_count;
    return value;
}

// Peek at the front element without removing it
template <typename T>
T NQueue<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return m_arr[m_front];
}

// Return the current number of elements in the queue
template <typename T>
int NQueue<T>::size() { 
    return m_count;
}

// Check if the queue is empty
template <typename T>
bool NQueue<T>::isEmpty() { 
    return m_count == 0;
}

// Check if the queue is full
template <typename T>
bool NQueue<T>::isFull() { 
    return m_count == m_max;
}

#endif
