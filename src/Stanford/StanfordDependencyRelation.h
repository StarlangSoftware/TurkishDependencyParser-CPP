//
// Created by olcay on 14.03.2019.
//

#ifndef DEPENDENCYPARSER_STANFORDDEPENDENCYRELATION_H
#define DEPENDENCYPARSER_STANFORDDEPENDENCYRELATION_H


#include <string>
#include "StanfordDependencyType.h"
#include "../DependencyRelation.h"

using namespace std;

class StanfordDependencyRelation : public DependencyRelation {
private:
    StanfordDependencyType stanfordDependencyType;
public:
    static const string stanfordDependencyTypes[49];
    static const StanfordDependencyType stanfordDependencyTags[49];
    static StanfordDependencyType getDependencyTag(const string& tag);
    StanfordDependencyRelation(int toWord, const string& dependencyType);
    string to_string() const;
};


#endif //DEPENDENCYPARSER_STANFORDDEPENDENCYRELATION_H
