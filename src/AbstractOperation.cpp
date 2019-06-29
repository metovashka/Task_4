//
// Created by pda on 24.05.19.
//

#include "AbstractOperation.h"

AbstractOperation::AbstractOperation(char symb, int pri) {
    symbol = symb;
    priority = pri;
}

int AbstractOperation::get_priority() {
    return priority;
}

char AbstractOperation::get_symbol() {
    return symbol;
}

