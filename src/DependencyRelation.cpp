//
// Created by olcay on 14.03.2019.
//

#include "DependencyRelation.h"

/**
 * Constructor for a DependencyRelation. Takes toWord as a parameter and sets the corresponding attribute.
 * @param toWord Index of the word in the sentence that dependency relation is related
 */
DependencyRelation::DependencyRelation(int toWord) {
    this->toWord = toWord;
}

/**
 * Accessor for toWord attribute
 * @return toWord attribute value
 */
int DependencyRelation::to() const{
    return toWord;
}
