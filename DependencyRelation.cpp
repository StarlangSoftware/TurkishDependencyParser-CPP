//
// Created by olcay on 14.03.2019.
//

#include "DependencyRelation.h"

DependencyRelation::DependencyRelation(int toWord) {
    this->toWord = toWord;
}

int DependencyRelation::to() {
    return toWord;
}
