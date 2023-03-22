//
// Created by barro on 2023-02-15.
//
#include <iostream>
#include "Stack.h"


Stack::Stack() = default;

//push coordinates to stack
void Stack::push(Coordinate coordinate) {
    auto node = new Node();
    node->m_data = std::move(coordinate);
    node->m_next = m_first;
    m_first = node;

}

//delete the first node off of the stack
void Stack::pop() {
    auto node = m_first;

    m_first = m_first ? m_first->m_next : nullptr;
    delete node;
}

//Show the coordinates in the first node of the stack
Coordinate Stack::peek() {
    return m_first ? m_first->m_data : Coordinate({0, 1});
}

//overloaded output operator to print contents of the stack
std::ostream &operator<<(std::ostream &output, Stack &stack) {
    auto node = stack.m_first;
    while (node != nullptr) {
        std::cout << "x-position: " << node->m_data.m_x_pos << ". ";
        std::cout << "y-position: " << node->m_data.m_y_pos << "." << std::endl;
        node = node->m_next;
    }
    return output;
}