#include "queue.h"
#include <optional>

template <typename T> std::optional<T> queue::Queue<T>::front() const {
  if (empty()) {
    return std::nullopt;
  }

  return m_front->data;
}

template <typename T> std::optional<T> queue::Queue<T>::back() const {
  if (empty()) {
    return std::nullopt;
  }

  return m_back->data;
}

template <typename T> bool queue::Queue<T>::empty() const {
  return m_front == nullptr;
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
  if (empty()) {
    return;
  }

  auto temporary_node = std::move(m_front);
  m_front = std::move(temporary_node->next);
}

template <typename T> std::size_t queue::Queue<T>::size() const {
  std::size_t queue_size = 0;
  std::unique_ptr<Node> current_node = m_front.get();

  while (current_node) {
    ++queue_size;
    current_node = current_node->next.get();
  }

  return queue_size;
}
