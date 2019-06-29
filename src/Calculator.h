//
// Created by pda on 24.05.19.
//

#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include <iostream>

#include "CollectionOperations.h"
#include "BuildReversePolishNotation.h"
#include "stack"


class ResultCulc {
private:
    float *val;
    bool error;
public:
    void set_value(float data);

    void set_error(bool err);

    float get_val();

    bool get_err();

    friend std::ostream &operator<<(std::ostream &out, const ResultCulc *obj);
};

class Calculator {
private:
    CollectionOperations collectionOperations;

public:
    int set_operations(CollectionOperations);

    ResultCulc *culculate(DtoRpn *rpn);//reverse polish notation
};


#endif //RPN_CALCULATOR_H
