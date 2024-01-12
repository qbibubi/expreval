#pragma once

#include <memory>
#include <optional>

namespace stack {

template <typename T> class Stack {
public:
  Stack() : top(nullptr) {}
  ~Stack() = default;

  void push(const T &value);
  bool empty() const;
  std::size_t size() const;
  std::optional<T> peek() const;
  std::optional<T> pop();

private:
  struct Node {
    Node(const T &data) : data(data), next(nullptr) {}
    std::unique_ptr<Node> next;
    T data;
  };

  Node *top;
};

}; // namespace stack
