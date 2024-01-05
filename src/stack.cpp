#include "stack.h"

template <typename T> void stack::Stack<T>::push(const T &value) {
  auto temporary = std::unique_ptr<Node<T>>(value);
  temporary->next = std::move(top);
  top = std::move(temporary);
}

template <typename T> std::optional<T> stack::Stack<T>::peek() const {
  if (top == nullptr) {
    return std::nullopt;
  }

  return top->data;
}

template <typename T> std::optional<T> stack::Stack<T>::pop() {
  if (top == nullptr) {
    return std::nullopt;
  }

  std::unique_ptr<Node<T>> temporary = std::move(top);
  top = std::move(temporary->next);
}
