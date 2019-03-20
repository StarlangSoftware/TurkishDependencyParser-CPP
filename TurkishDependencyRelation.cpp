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

TurkishDependencyType TurkishDependencyRelation::getDependencyTag(string tag) {
    for (int j = 0; j < 23; j++) {
        if (tag == TurkishDependencyRelation::turkishDependencyTypes[j]) {
            return TurkishDependencyRelation::turkishDependencyTags[j];
        }
    }
}

TurkishDependencyRelation::TurkishDependencyRelation(int toWord, int toIG, string dependencyType) : DependencyRelation(toWord){
    this->toIG = toIG;
    this->turkishDependencyType = getDependencyTag(move(dependencyType));
}

int TurkishDependencyRelation::getToIG(){
    return toIG;
}

TurkishDependencyType TurkishDependencyRelation::getTurkishDependencyType(){
    return turkishDependencyType;
}

string TurkishDependencyRelation::to_string() {
    return TurkishDependencyRelation::turkishDependencyTypes[static_cast<int>(turkishDependencyType)];
}
