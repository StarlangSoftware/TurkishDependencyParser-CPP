//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKWORD_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKWORD_H


#include "Dictionary/Word.h"
#include "UniversalDependencyPosType.h"
#include "UniversalDependencyTreeBankFeatures.h"
#include "UniversalDependencyRelation.h"

class UniversalDependencyTreeBankWord : public Word {
private:
    int id;
    string lemma;
    UniversalDependencyPosType upos;
    string xpos;
    UniversalDependencyTreeBankFeatures* features = nullptr;
    UniversalDependencyRelation* relation = nullptr;
    string deps;
    string misc;
public:
    ~UniversalDependencyTreeBankWord();
    UniversalDependencyTreeBankWord(int id, const string& name, const string& lemma, UniversalDependencyPosType upos, const string& xpos,
                                    UniversalDependencyTreeBankFeatures* features,
                                    UniversalDependencyRelation* relation, const string& deps, const string& misc);
    int getId() const;
    string getLemma() const;
    UniversalDependencyPosType getUpos() const;
    string getXpos() const;
    UniversalDependencyTreeBankFeatures* getFeatures() const;
    string getFeatureValue(const string& featureName) const;
    bool featureExists(const string& featureName) const;
    UniversalDependencyRelation* getRelation() const;
    string getDeps() const;
    string getMisc() const;
    string to_string() const;
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKWORD_H
