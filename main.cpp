#include <iostream>
#include <string.h>

#include "src/BuildReversePolishNotation.h"
#include "src/Calculator.h"
#include "src/CollectionOperations.h"

using namespace std;

int main() {
    string input = "(3+4)/3*(7-2)";

    CollectionOperations collectionOperations;
    BuildReversePolishNotation PolishNotation;
    Calculator calculator;

    collectionOperations.add();
    PolishNotation.set_operations(collectionOperations);
    calculator.set_operations(collectionOperations);

    cout << calculator.culculate(PolishNotation.get_rpn(input));

    return 0;
}