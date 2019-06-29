//
// Created by pda on 24.05.19.
//

#ifndef RPN_ABSTRACTOPERATION_H
#define RPN_ABSTRACTOPERATION_H

#include <vector>;

class AbstractOperation {
protected:
    char symbol;
    int priority;
public:
    AbstractOperation(char, int);

    char get_symbol();

    int get_priority();

    virtual float culculate(float, float) = 0;

};


#endif //RPN_ABSTRACTOPERATION_H
