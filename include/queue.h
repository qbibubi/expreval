#pragma once

#include <memory>
#include <optional>

namespace queue {

template <typename T> class Queue {
public:
  Queue() : m_front(nullptr), m_back(nullptr) {}
  ~Queue() = default;

  std::optional<T> front() const;
  std::optional<T> back() const;
  bool empty() const;
  void push(const T &value);
  void pop();
  int size() const;

private:
  struct Node {
    Node(const T &value) : data(value), next(nullptr) {}
    T data;
    std::unique_ptr<Node> next;
  };

  std::unique_ptr<T> m_front;
  T *m_back;
};

}; // namespace queue
