//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include "UniversalDependencyTreeBankWord.h"

#include <utility>

UniversalDependencyTreeBankWord::UniversalDependencyTreeBankWord(int id, string name, string lemma, UniversalDependencyPosType upos,
                                                                 string xpos,
                                                                 UniversalDependencyTreeBankFeatures* features,
                                                                 UniversalDependencyRelation* relation, string deps,
                                                                 string misc) : Word(std::move(name)){
    this->id = id;
    this->lemma = std::move(lemma);
    this->upos = upos;
    this->xpos = std::move(xpos);
    this->features = features;
    this->deps = std::move(deps);
    this->relation = relation;
    this->misc = std::move(misc);
}

int UniversalDependencyTreeBankWord::getId() {
    return id;
}

string UniversalDependencyTreeBankWord::getLemma() {
    return lemma;
}

UniversalDependencyPosType UniversalDependencyTreeBankWord::getUpos() {
    return upos;
}

string UniversalDependencyTreeBankWord::getXpos() {
    return xpos;
}

UniversalDependencyTreeBankFeatures* UniversalDependencyTreeBankWord::getFeatures() {
    return features;
}

string UniversalDependencyTreeBankWord::getFeatureValue(string featureName) {
    return features->getFeatureValue(featureName);
}

UniversalDependencyRelation* UniversalDependencyTreeBankWord::getRelation() {
    return relation;
}

string UniversalDependencyTreeBankWord::getDeps() {
    return deps;
}

string UniversalDependencyTreeBankWord::getMisc() {
    return misc;
}

string UniversalDependencyTreeBankWord::to_string() {
    return ::to_string(id) + "\t" + name + "\t" + lemma + "\t" + UniversalDependencyRelation::to_string(upos) + "\t" +
           xpos + "\t" + features->to_string() + "\t" + ::to_string(relation->to()) + "\t" +
           relation->to_string() + "\t" + deps + "\t" + misc;
}

UniversalDependencyTreeBankWord::~UniversalDependencyTreeBankWord() {
    delete features;
    delete relation;
}
