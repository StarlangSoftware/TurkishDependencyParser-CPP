//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include "UniversalDependencyTreeBankWord.h"

/**
 * Constructor of the universal dependency word. Sets the attributes.
 * @param id Id of the word
 * @param name Name of the word
 * @param lemma Lemma of the word
 * @param upos Universal part of speech tag.
 * @param xpos Extra part of speech tag
 * @param features Feature list of the word
 * @param relation Universal dependency relation of the word
 * @param deps External dependencies for the word
 * @param misc Miscellaneous information for the word.
 */
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

/**
 * Accessor for the id attribute.
 * @return Id attribute
 */
int UniversalDependencyTreeBankWord::getId() const{
    return id;
}

/**
 * Accessor for the lemma attribute
 * @return Lemma attribute
 */
string UniversalDependencyTreeBankWord::getLemma() const{
    return lemma;
}

/**
 * Accessor for the upos attribute
 * @return Upos attribute
 */
UniversalDependencyPosType UniversalDependencyTreeBankWord::getUpos() const{
    return upos;
}

/**
 * Accessor for the xpos attribute
 * @return Xpos attribute
 */
string UniversalDependencyTreeBankWord::getXpos() const{
    return xpos;
}

/**
 * Accessor for the features attribute
 * @return Features attribute
 */
UniversalDependencyTreeBankFeatures* UniversalDependencyTreeBankWord::getFeatures() const{
    return features;
}

/**
 * Gets the value of a given feature.
 * @param featureName Name of the feature
 * @return Value of the feature
 */
string UniversalDependencyTreeBankWord::getFeatureValue(const string& featureName) const{
    return features->getFeatureValue(featureName);
}

/**
 * Accessor for the relation attribute.
 * @return Relation attribute
 */
UniversalDependencyRelation* UniversalDependencyTreeBankWord::getRelation() const{
    return relation;
}

/**
 * Accessor for the deps attribute
 * @return Xpos attribute
 */
string UniversalDependencyTreeBankWord::getDeps() const{
    return deps;
}

/**
 * Accessor for the misc attribute
 * @return Xpos attribute
 */
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

/**
 * Checks if the given feature exists.
 * @param featureName Name of the feature
 * @return True if the given feature exists, false otherwise.
 */
bool UniversalDependencyTreeBankWord::featureExists(const string& featureName) const{
    return features->featureExists(featureName);
}

UniversalDependencyTreeBankWord::UniversalDependencyTreeBankWord() : Word("root"){
    this->id = 0;
    this->lemma = "";
    this->upos = UniversalDependencyPosType::X;
    this->xpos = "";
    this->features = nullptr;
    this->deps = "";
    this->misc = "";
    this->relation = new UniversalDependencyRelation(-1, "DEP");
}

/**
 * Mutator for the relation attribute
 * @param relation New relation attribute
 */
void UniversalDependencyTreeBankWord::setRelation(UniversalDependencyRelation* _relation) {
    this->relation = _relation;
}

UniversalDependencyTreeBankWord::UniversalDependencyTreeBankWord(UniversalDependencyTreeBankWord &copy)  : Word(copy.name) {
    this->id = copy.id;
    this->lemma = copy.lemma;
    this->upos = copy.upos;
    this->xpos = copy.xpos;
    this->features = new UniversalDependencyTreeBankFeatures(*copy.features);
    this->deps = copy.deps;
    this->relation = new UniversalDependencyRelation(*copy.relation);
    this->misc = copy.misc;
}
