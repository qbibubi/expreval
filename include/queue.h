#pragma once

#include <memory>
#include <optional>

namespace queue {

template <typename T> class Queue {
public:
  Queue() {}
  ~Queue() = default;

  std::optional<T> front() const;
  std::optional<T> back() const;
  bool empty() const;
  int size() const;
  void push(const T &value);
  void pop();

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
