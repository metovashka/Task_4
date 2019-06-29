//
// Created by pda on 25.05.19.
//

#include "CollectionOperations.h"


float Plus::culculate(float a, float b) {
    return a+b;
}

float Minus::culculate(float a, float b) {
    return a-b;
}

float Multi::culculate(float a, float b) {
    return a*b;
}

float Div::culculate(float a, float b) {
    return a/b;
}

int CollectionOperations::add() {

    Collection.push_back(new Plus('+', 2));
    Collection.push_back(new Minus('-', 2));
    Collection.push_back(new Multi('*', 3));
    Collection.push_back(new Div ('/', 3));
}

int CollectionOperations::del() {
    if (Collection.empty()) return -1;
    Collection.pop_back();
}

AbstractOperation *CollectionOperations::get_operation(char sign) {
    if (Collection.empty()) return nullptr;
    for (int i = 0; i < Collection.size(); i++) {
        if (Collection.at(i)->get_symbol() == sign) {
            return Collection.at(i);
        }
    }
    return nullptr;
}

int CollectionOperations::get_size() {
    return Collection.size();
}

bool CollectionOperations::have_symbol(char sym) {
    bool flag = false;
    int len = Collection.size();

    for (int i = 0; i < len; i++) {

        AbstractOperation *buf = Collection.at(i);

        char now_sym = buf->get_symbol();
        if (sym == now_sym) {
            flag = true;
            i = len;
        }
    }
    return flag;

}

bool CollectionOperations::is_empty() {
    return Collection.empty();
}