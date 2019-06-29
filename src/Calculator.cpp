//
// Created by pda on 24.05.19.
//

#include "Calculator.h"

ResultCulc *Calculator::culculate(DtoRpn *rpn) {

    ResultCulc *resultCulc = new ResultCulc;

    if (rpn == nullptr) {
        resultCulc->set_error(true);
        return resultCulc;
    }


    stack<float> numbers;
    int i = 0;

    while (i < rpn->get_size()) {
        if (rpn->get_node(i).state == true) {
            float num;
            bcopy(rpn->get_node(i).val, &num, 4);
            numbers.push(num);
            i++;
        } else if (rpn->get_node(i).state == false) {
            float f1;
            float f2;
            f1 = numbers.top();
            numbers.pop();

            if (numbers.empty()) {
                resultCulc->set_error(true);
                return resultCulc;
            }

            f2 = numbers.top();
            numbers.pop();
            char sym;
            bcopy(rpn->get_node(i).sign, &sym, 1);
            if (f1 == 0 && sym == '/') {
                resultCulc->set_error(true);
                return resultCulc;
            }
            numbers.push(collectionOperations.get_operation(sym)->culculate(f2, f1));
            i++;
        }
    }
    if (numbers.empty()) {
        resultCulc->set_error(true);
        return resultCulc;
    } else {
        resultCulc->set_error(false);
        resultCulc->set_value(numbers.top());
    }

    return resultCulc;
}

int Calculator::set_operations(CollectionOperations collection) {
    if (collection.is_empty())
        return 1;
    collectionOperations = collection;
}

void ResultCulc::set_error(bool err) {
    this->error = err;
}

void ResultCulc::set_value(float data) {
    this->val = new float;
    bcopy(&data, this->val, 4);
}

bool ResultCulc::get_err() {
    return this->error;
}

float ResultCulc::get_val() {
    return *val;
}

std::ostream &operator<<(std::ostream &out, const ResultCulc *obj) {
    if (obj->error == true) { return out; }
    out << *obj->val;
    return out;
}