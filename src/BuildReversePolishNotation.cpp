//
// Created by pda on 24.05.19.
//

#include "BuildReversePolishNotation.h"


int DtoRpn::add_node(node object) {
    chain_nodes.push_back(object);
}

node DtoRpn::get_node(int k) {
    return chain_nodes.at(k);
}

int DtoRpn::get_size() {
    return chain_nodes.size();
}

bool BuildReversePolishNotation::set_operations(CollectionOperations &collection) {
    collectionOperations = collection;
}

int get_top_stack_priority(stack<char> op_stack, CollectionOperations collectionOperations);

DtoRpn *BuildReversePolishNotation::get_rpn(string input) {
    int len = input.length();
    char *str = new char[len + 1];

    strcpy(str, &input[0]);
    str[len] = '\0';

    stack<char> op_stack;

    DtoRpn *result = new DtoRpn;

    node buf_node;
    int i = 0;
    float val;
    while (i < len) {
        string str_token = "";
        while (collectionOperations.have_symbol(str[i]) == false &&
               (str[i] != '(' && str[i] != ')' && str[i] != '\0')) {
            str_token = str_token + str[i];
            i++;
        }
        if (str_token != "") {
            val = stof(str_token);
            buf_node.state = true;
            buf_node.val = new float;
            bcopy(&val, buf_node.val, 4);
            result->add_node(buf_node);
        } else {

            if (collectionOperations.have_symbol(str[i])) {
                AbstractOperation *buf_operation = collectionOperations.get_operation(str[i]);
                if (op_stack.empty()) {
                    op_stack.push(str[i]);
                    i++;
                } else {
                    int top_priority = get_top_stack_priority(op_stack, collectionOperations);

                    if (top_priority < buf_operation->get_priority()) {
                        op_stack.push(str[i]);
                        i++;
                    } else {

                        while (top_priority >= buf_operation->get_priority() && !op_stack.empty()) {
                            buf_node.state = false;
                            buf_node.sign = new char;
                            bcopy(&op_stack.top(), buf_node.sign, 1);
                            result->add_node(buf_node);
                            op_stack.pop();

                            top_priority = get_top_stack_priority(op_stack, collectionOperations);
                        }
                    }
                }
            } else if (str[i] == '(') {
                op_stack.push(str[i]);
                i++;
            } else if (str[i] == ')') {
                while (op_stack.top() != '(' && op_stack.empty() == false) {
                    buf_node.state = false;
                    buf_node.sign = new char;
                    bcopy(&op_stack.top(), buf_node.sign, 1);
                    result->add_node(buf_node);
                    op_stack.pop();
                }
                op_stack.pop();
                i++;
            }


        }


    }

    while (!op_stack.empty()) {
        buf_node.state = false;
        buf_node.sign = new char;
        bcopy(&op_stack.top(), buf_node.sign, 1);
        result->add_node(buf_node);
        op_stack.pop();
    }

    return result;
}

int get_top_stack_priority(stack<char> op_stack, CollectionOperations collectionOperations) {
    int top_priority = 0;
    if (op_stack.empty()) { return top_priority; }
    if (op_stack.top() == '(') { top_priority = 1; }
    else {
        AbstractOperation *top_op = collectionOperations.get_operation(op_stack.top());

        top_priority = top_op->get_priority();
    }
}