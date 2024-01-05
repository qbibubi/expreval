#pragma once

#include <memory>
#include <optional>

namespace stack {
template <typename T> class Node {
public:
  Node(const T &data) : data(data), next(nullptr) {}
  std::unique_ptr<Node<T>> next;
  T data;
};

template <typename T> class Stack {
public:
  Stack() : top(nullptr) {}
  ~Stack() = default;

  void push(const T &value);
  std::optional<T> peek() const;
  std::optional<T> pop();

private:
  std::unique_ptr<Node<T>> top;
};
}; // namespace stack
