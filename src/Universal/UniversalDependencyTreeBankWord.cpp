//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include "UniversalDependencyTreeBankWord.h"

#include <utility>

UniversalDependencyTreeBankWord::UniversalDependencyTreeBankWord(int id, const string& name, const string& lemma, UniversalDependencyPosType upos,
                                                                 const string& xpos,
                                                                 UniversalDependencyTreeBankFeatures* features,
                                                                 UniversalDependencyRelation* relation, const string& deps,
                                                                 const string& misc) : Word(name){
    this->id = id;
    this->lemma = lemma;
    this->upos = upos;
    this->xpos = xpos;
    this->features = features;
    this->deps = deps;
    this->relation = relation;
    this->misc = misc;
}

int UniversalDependencyTreeBankWord::getId() const{
    return id;
}

string UniversalDependencyTreeBankWord::getLemma() const{
    return lemma;
}

UniversalDependencyPosType UniversalDependencyTreeBankWord::getUpos() const{
    return upos;
}

string UniversalDependencyTreeBankWord::getXpos() const{
    return xpos;
}

UniversalDependencyTreeBankFeatures* UniversalDependencyTreeBankWord::getFeatures() const{
    return features;
}

string UniversalDependencyTreeBankWord::getFeatureValue(const string& featureName) const{
    return features->getFeatureValue(featureName);
}

UniversalDependencyRelation* UniversalDependencyTreeBankWord::getRelation() const{
    return relation;
}

string UniversalDependencyTreeBankWord::getDeps() const{
    return deps;
}

string UniversalDependencyTreeBankWord::getMisc() const{
    return misc;
}

string UniversalDependencyTreeBankWord::to_string() const{
    return ::to_string(id) + "\t" + name + "\t" + lemma + "\t" + UniversalDependencyRelation::to_string(upos) + "\t" +
           xpos + "\t" + features->to_string() + "\t" + ::to_string(relation->to()) + "\t" +
           relation->to_string() + "\t" + deps + "\t" + misc;
}

UniversalDependencyTreeBankWord::~UniversalDependencyTreeBankWord() {
    delete features;
    delete relation;
}

bool UniversalDependencyTreeBankWord::featureExists(const string& featureName) const{
    return features->featureExists(featureName);
}
