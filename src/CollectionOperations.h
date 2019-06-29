//
// Created by pda on 25.05.19.
//

#ifndef RPN_COLLECTIONOPERATIONS_H
#define RPN_COLLECTIONOPERATIONS_H

#include <vector>
#include "AbstractOperation.h"

class Plus : public AbstractOperation {
public:
    Plus(char s, int a) : AbstractOperation(s, a) {
    };

    float culculate(float, float) override;
};

class Minus : public AbstractOperation {
public:
    Minus(char s, int a) : AbstractOperation(s, a) {
    };

    float culculate(float, float) override;
};

class Multi : public AbstractOperation {
public:
    Multi(char s, int a) : AbstractOperation(s, a) {
    };

    float culculate(float, float) override;
};

class Div : public AbstractOperation {
public:
    Div(char s, int a) : AbstractOperation(s,a) {
    };
     float culculate(float, float) override;
};

class CollectionOperations {
private:
    std::vector<AbstractOperation *> Collection;

public:
    int add();

    bool is_empty();

    int del();

    int get_size();

    AbstractOperation *get_operation(char);

    bool have_symbol(char);

};


#endif //RPN_COLLECTIONOPERATIONS_H
