//
// Created by olcay on 14.03.2019.
//

#include "TurkishDependencyRelation.h"

const string TurkishDependencyRelation::turkishDependencyTypes[23] = {"VOCATIVE", "SUBJECT", "DATIVE.ADJUNCT", "OBJECT", "POSSESSOR",
                                           "MODIFIER", "S.MODIFIER", "ABLATIVE.ADJUNCT", "DETERMINER", "SENTENCE",
                                           "CLASSIFIER", "LOCATIVE.ADJUNCT", "COORDINATION", "QUESTION.PARTICLE", "INTENSIFIER",
                                           "INSTRUMENTAL.ADJUNCT", "RELATIVIZER", "NEGATIVE.PARTICLE", "ETOL", "COLLOCATION",
                                           "FOCUS.PARTICLE", "EQU.ADJUNCT", "APPOSITION"};

const TurkishDependencyType TurkishDependencyRelation::turkishDependencyTags[23] = {TurkishDependencyType::VOCATIVE, TurkishDependencyType::SUBJECT, TurkishDependencyType::DATIVE_ADJUNCT, TurkishDependencyType::OBJECT, TurkishDependencyType::POSSESSOR,
                                                                                    TurkishDependencyType::MODIFIER, TurkishDependencyType::S_MODIFIER, TurkishDependencyType::ABLATIVE_ADJUNCT, TurkishDependencyType::DETERMINER, TurkishDependencyType::SENTENCE,
                                                                                    TurkishDependencyType::CLASSIFIER, TurkishDependencyType::LOCATIVE_ADJUNCT, TurkishDependencyType::COORDINATION, TurkishDependencyType::QUESTION_PARTICLE, TurkishDependencyType::INTENSIFIER,
                                                                                    TurkishDependencyType::INSTRUMENTAL_ADJUNCT, TurkishDependencyType::RELATIVIZER, TurkishDependencyType::NEGATIVE_PARTICLE, TurkishDependencyType::ETOL, TurkishDependencyType::COLLOCATION,
                                                                                    TurkishDependencyType::FOCUS_PARTICLE, TurkishDependencyType::EQU_ADJUNCT, TurkishDependencyType::APPOSITION};

/**
 * The getDependencyTag method takes an dependency tag as string and returns the {@link TurkishDependencyType}
 * form of it.
 *
 * @param tag  Type of the dependency tag in string form
 * @return Type of the dependency in {@link TurkishDependencyType} form
 */
TurkishDependencyType TurkishDependencyRelation::getDependencyTag(string tag) {
    transform(tag.begin(),
              tag.end(),
              tag.begin(),
              ::toupper);
    for (int j = 0; j < 23; j++) {
        if (tag == TurkishDependencyRelation::turkishDependencyTypes[j]) {
            return TurkishDependencyRelation::turkishDependencyTags[j];
        }
    }
}

/**
 * Another constructor for TurkishDependencyRelation. Gets input toWord, toIG, and dependencyType as arguments and
 * calls the super class's constructor and sets the IG and dependency type.
 * @param toWord Index of the word in the sentence that dependency relation is related
 * @param toIG Index of the inflectional group the dependency relation is related
 * @param dependencyType Type of the dependency relation in string form
 */
TurkishDependencyRelation::TurkishDependencyRelation(int toWord, int toIG, string dependencyType) : DependencyRelation(toWord){
    this->toIG = toIG;
    this->turkishDependencyType = getDependencyTag(move(dependencyType));
}

/**
 * Accessor for the toIG attribute
 * @return toIG attribute
 */
int TurkishDependencyRelation::getToIG(){
    return toIG;
}

/**
 * Accessor for the turkishDependencyType attribute
 * @return turkishDependencyType attribute
 */
TurkishDependencyType TurkishDependencyRelation::getTurkishDependencyType(){
    return turkishDependencyType;
}

string TurkishDependencyRelation::to_string() {
    return TurkishDependencyRelation::turkishDependencyTypes[static_cast<int>(turkishDependencyType)];
}
