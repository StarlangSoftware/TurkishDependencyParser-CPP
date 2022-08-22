//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include <vector>
#include <iostream>
#include "Dictionary/Word.h"
#include "UniversalDependencyTreeBankFeatures.h"

UniversalDependencyTreeBankFeatures::UniversalDependencyTreeBankFeatures(string features) {
    if (features != "_"){
        vector<string> list = Word::split(features, "|");
        for (const string& feature : list){
            if (feature.find_first_of('=') != -1){
                string featureName = feature.substr(0, feature.find_first_of('=') - 1);
                string featureValue = feature.substr(feature.find_first_of('=') + 1);
                featureList.emplace(featureName, featureValue);
            } else {
                cout << "Fature does not contain = ->" << features;
            }
        }
    }
}

string UniversalDependencyTreeBankFeatures::getFeatureValue(const string& feature) {
    return featureList.at(feature);
}

string UniversalDependencyTreeBankFeatures::to_string() {
    if (featureList.empty()){
        return "_";
    }
    string result;
    for (auto& feature: featureList){
        if (result.empty()){
            result = feature.first + "=" + feature.second;
        } else {
            result += "|" + feature.first + "=" + feature.second;
        }
    }
    return result;
}

bool UniversalDependencyTreeBankFeatures::featureExists(const string& feature) {
    return featureList.contains(feature);
}
