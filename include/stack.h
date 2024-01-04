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

  void push(const T &value) {
    auto temporary = std::unique_ptr<Node<T>>(value);
    temporary->next = std::move(top);
    top = std::move(temporary);
  }

  std::optional<T> peek() const {
    if (top == nullptr) {
      return std::nullopt;
    }

    return top->data;
  }

  std::optional<T> pop() {
    if (top == nullptr) {
      return std::nullopt;
    }

    std::unique_ptr<Node<T>> temporary = std::move(top);
    top = std::move(temporary->next);
  }

private:
  std::unique_ptr<Node<T>> top;
};
}; // namespace stack
