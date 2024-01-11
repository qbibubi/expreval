#include "queue.h"

template <typename T> std::optional<T> queue::Queue<T>::front() const {
  //
}

template <typename T> std::optional<T> queue::Queue<T>::back() const {
  //
}

template <typename T> bool queue::Queue<T>::empty() const {
  return this->m_front == nullptr;
}

template <typename T> void queue::Queue<T>::push(const T &value) {
  auto new_node = std::make_unique<Node>(value);
  if (empty()) {
    m_front = std::move(new_node);
    m_back = m_front->get();
  }
  m_back->next = std::move(new_node);
  m_back = m_back->next.get();
}

template <typename T> void queue::Queue<T>::pop() {
  if (this->empty()) {
    return;
  }

  auto temporary_node = std::move(m_front);
  m_front = std::move(temporary_node->next);
}

template <typename T> int queue::Queue<T>::size() const {
  //
}
