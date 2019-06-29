//
// Created by pda on 24.05.19.
//

#ifndef RPN_BUILDREVERSEPOLISHNOTATION_H
#define RPN_BUILDREVERSEPOLISHNOTATION_H

#include "CollectionOperations.h"
#include <string>
#include <stack>
#include "AbstractOperation.h"
#include <vector>
#include <string.h>

using namespace std;

struct node {
    float *val;
    char *sign;
    bool state; //1-val 0 -sign operation
};

class DtoRpn {
private:
    vector<node> chain_nodes;
public:
    int add_node(node);

    int get_size();

    node get_node(int);


};

using namespace std;

class BuildReversePolishNotation {
private:
    CollectionOperations collectionOperations;

public:

    bool set_operations(CollectionOperations &);

    DtoRpn *get_rpn(string);

};


#endif //RPN_BUILDREVERSEPOLISHNOTATION_H
