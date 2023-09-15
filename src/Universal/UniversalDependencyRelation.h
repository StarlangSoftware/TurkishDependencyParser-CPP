//
// Created by olcay on 14.03.2019.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYRELATION_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYRELATION_H


#include <string>
#include "../DependencyRelation.h"
#include "../ParserEvaluationScore.h"
#include "UniversalDependencyType.h"
#include "UniversalDependencyPosType.h"

using namespace std;

class UniversalDependencyRelation : public DependencyRelation {
private:
    UniversalDependencyType universalDependencyType;
public:
    static const string universalDependencyTypes[62];
    static const UniversalDependencyType universalDependencyTags[62];
    static const string universalDependencyPosTypes[17];
    static const UniversalDependencyPosType universalDependencyPosTags[17];
    explicit UniversalDependencyRelation(int toWord);
    static UniversalDependencyType getDependencyTag(const string& tag);
    static UniversalDependencyPosType getDependencyPosType(const string& tag);
    UniversalDependencyRelation();
    UniversalDependencyRelation(UniversalDependencyRelation& copy);
    UniversalDependencyRelation(int toWord, const string& dependencyType);
    ParserEvaluationScore compareRelations(UniversalDependencyRelation* relation) const;
    string to_string() const;
    static string to_string(UniversalDependencyPosType posType);
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYRELATION_H
