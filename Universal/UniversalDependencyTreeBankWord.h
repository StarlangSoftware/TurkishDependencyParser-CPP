//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKWORD_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKWORD_H


#include <Word.h>
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
    UniversalDependencyTreeBankWord(int id, string name, string lemma, UniversalDependencyPosType upos, string xpos,
                                    UniversalDependencyTreeBankFeatures* features,
                                    UniversalDependencyRelation* relation, string deps, string misc);
    int getId();
    string getLemma();
    UniversalDependencyPosType getUpos();
    string getXpos();
    UniversalDependencyTreeBankFeatures* getFeatures();
    string getFeatureValue(string featureName);
    UniversalDependencyRelation* getRelation();
    string getDeps();
    string getMisc();
    string to_string();
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKWORD_H
