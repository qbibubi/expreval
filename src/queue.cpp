#include "queue.h"

template <typename T> bool queue::Queue<T>::empty() const {
  return this->m_front == nullptr;
}

template <typename T> int queue::Queue<T>::size() const {
  //
}

template <typename T> void queue::Queue<T>::push(const T &value) {
  auto new_node = std::make_unique<Node>(value);
  if (!this->empty()) {
    this->m_back->next = std::move(new_node);

  } else {
    this->m_front = this->m_back = new_node.get();
    this->m_back = this->m_back->next.get();
  }
}

template <typename T> std::optional<T> queue::Queue<T>::front() const {}
template <typename T> std::optional<T> queue::Queue<T>::back() const {}
