#include "stack.h"

template <typename T> void stack::Stack<T>::push(const T &value) {
  auto temporary = std::unique_ptr<Node>(value);
  temporary->next = std::move(top);
  top = std::move(temporary);
}

template <typename T> bool stack::Stack<T>::empty() const {
  return top == nullptr;
}

template <typename T> std::size_t stack::Stack<T>::size() const {
  std::size_t stack_size = 0;
  Node *temporary_node = top;

  while (temporary_node) {
    ++stack_size;
    temporary_node = temporary_node->next;
  }

  return stack_size;
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

  std::unique_ptr<Node> temporary = std::move(top);
  top = std::move(temporary->next);
}
