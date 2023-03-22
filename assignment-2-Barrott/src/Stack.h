#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H

#include <string>

struct Coordinate {
    int m_x_pos;
    int m_y_pos;

};

struct Node {
    Coordinate m_data{};
    Node *m_next{nullptr};
};

class Stack {
public:
    Stack();

    void push(Coordinate coordinate);

    void pop();

    Coordinate peek();

    Node *m_first{nullptr};

    friend std::ostream &operator<<(std::ostream &output, Stack &stack);
};


#endif //ASSIGNMENT_2_STACK_H
