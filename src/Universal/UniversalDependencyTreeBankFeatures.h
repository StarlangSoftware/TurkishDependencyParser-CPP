//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H


#include <unordered_map>
#include <string>

using namespace std;

class UniversalDependencyTreeBankFeatures {
private:
    unordered_map<string, string> featureList;
public:
    explicit UniversalDependencyTreeBankFeatures(const string& features);
    string getFeatureValue(const string& feature) const;
    bool featureExists(const string& feature) const;
    string to_string() const;
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H
