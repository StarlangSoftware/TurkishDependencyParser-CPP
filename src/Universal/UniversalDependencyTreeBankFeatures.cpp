//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include <vector>
#include <iostream>
#include "Dictionary/Word.h"
#include "UniversalDependencyTreeBankFeatures.h"
#include "UniversalDependencyRelation.h"

const string UniversalDependencyTreeBankFeatures::universalFeatureTypes[24] =
        {"PronType", "NumType", "Poss", "Reflex", "Foreign",
         "Abbr", "Typo", "Gender", "Animacy", "NounClass",
         "Number", "Case", "Definite", "Degree", "VerbForm",
         "Mood", "Tense", "Aspect", "Voice", "Evident",
         "Polarity", "Person", "Polite", "Clusivity"};

const vector<string> UniversalDependencyTreeBankFeatures::universalFeatureValues[24] = {
        {"Art",    "Dem",    "Emp",    "Exc",    "Ind",    "Int",    "Neg",    "Prs",    "Rcp",    "Rel",     "Tot"},
        {"Card",   "Dist",   "Frac",   "Mult",   "Ord",    "Range",  "Sets"},
        {"Yes"},
        {"Yes"},
        {"Yes"},

        {"Yes"},
        {"Yes"},
        {"Com",    "Fem",    "Masc",   "Neut"},
        {"Anim",   "Hum",    "Inan",   "Nhum"},
        {"Bantu1", "Bantu2", "Bantu3", "Bantu4", "Bantu5", "Bantu6", "Bantu7", "Bantu8", "Bantu9", "Bantu10", "Bantu11", "Bantu12", "Bantu13", "Bantu14", "Bantu15", "Bantu16", "Bantu17", "Bantu18", "Bantu19", "Bantu20", "Bantu21", "Bantu22", "Bantu23", "Wol1", "Wol2", "Wol3", "Wol4", "Wol5", "Wol6", "Wol7", "Wol8", "Wol9", "Wol10", "Wol11", "Wol12"},

        {"Coll",   "Count",  "Dual",   "Grpa",   "Grpl",   "Inv",    "Pauc",   "Plur",   "Ptan",   "Sing",    "Tri"},
        {"Abs",    "Acc",    "Erg",    "Nom",    "Abe",    "Ben",    "Cau",    "Cmp",    "Cns",    "Com",     "Dat",     "Dis",     "Equ",     "Gen",     "Ins",     "Par",     "Tem",     "Tra",     "Voc",     "Abl",     "Add",     "Ade",     "All",     "Del",  "Ela",  "Ess",  "Ill",  "Ine",  "Lat",  "Loc",  "Per",  "Sbe",  "Sbl",   "Spl",   "Sub", "Sup", "Ter"},
        {"Com",    "Cons",   "Def",    "Ind",    "Spec"},
        {"Abs",    "Aug",    "Cmp",    "Dim",    "Equ",    "Pos",    "Sup"},
        {"Conv",   "Fin",    "Gdv",    "Ger",    "Inf",    "Part",   "Sup",    "Vnoun"},

        {"Adm",    "Cnd",    "Des",    "Imp",    "Ind",    "Int",    "Irr",    "Jus",    "Nec",    "Opt",     "Pot",     "Prp",     "Qot",     "Sub"},
        {"Fut",    "Imp",    "Past",   "Pqp",    "Pres"},
        {"Hab",    "Imp",    "Iter",   "Perf",   "Prog",   "Prosp"},
        {"Act",    "Antip",  "Bfoc",   "Cau",    "Dir",    "Inv",    "Lfoc",   "Mid",    "Pass",   "Rcp"},
        {"Fh",     "Nfh"},

        {"Neg",    "Pos"},
        {"0",      "1",      "2",      "3",      "4"},
        {"Elev",   "Form",   "Humb",   "Infm"},
        {"Ex",     "In"}
};

const vector<string> UniversalDependencyTreeBankFeatures::turkishFeatureValues[24] = {
        {"Art",  "Dem",  "Ind",  "Int",   "Neg",    "Prs",        "Rcp",     "Rel",        "Tot"},
        {"Card", "Dist", "Ord"},
        {},
        {"Yes"},
        {},

        {"Yes"},
        {},
        {},
        {},
        {},

        {"Plur", "Sing"},
        {"Acc",  "Nom",  "Dat",  "Equ",   "Gen",    "Ins",        "Abl",     "Loc"},
        {"Def",  "Ind"},
        {"Cmp",  "Sup"},
        {"Conv", "Fin",  "Part", "Vnoun"},

        {"Cnd",  "Des",  "Gen",  "Imp",   "Ind",    "Nec",        "Opt",     "Pot",        "DesPot", "CndPot",   "CndGen",  "CndGenPot", "GenPot", "PotPot", "GenNecPot", "GenNec", "NecPot", "GenPotPot", "ImpPot"},
        {"Fut",  "Past", "Pqp",  "Pres",  "Aor"},
        {"Imp",  "Perf", "Prog", "Prosp", "Hab",    "Rapid"},
        {"Cau",  "Pass", "Rcp",  "Rfl",   "CauCau", "CauCauPass", "CauPass", "CauPassRcp", "CauRcp", "PassPass", "PassRfl", "PassRcp"},
        {"Fh",   "Nfh"},

        {"Neg",  "Pos"},
        {"1",    "2",    "3"},
        {},
        {}
};

const vector<string> UniversalDependencyTreeBankFeatures::englishFeatureValues[24] = {
        {"Art",  "Dem",  "Emp",  "Ind", "Int", "Neg", "Prs", "Rcp", "Rel", "Tot"},
        {"Card", "Frac", "Mult", "Ord"},
        {"Yes"},
        {},
        {},

        {},
        {},
        {"Fem",  "Masc", "Neut"},
        {},
        {},

        {"Plur", "Sing"},
        {"Acc",  "Nom",  "Gen"},
        {"Def",  "Ind"},
        {"Cmp",  "Pos",  "Sup"},
        {"Fin",  "Ger",  "Inf",  "Part"},

        {"Imp",  "Ind",  "Sub"},
        {"Past", "Pres"},
        {},
        {"Pass"},
        {},

        {},
        {"1",    "2",    "3"},
        {},
        {}
};

UniversalDependencyTreeBankFeatures::UniversalDependencyTreeBankFeatures(const string &language,
                                                                         const string &features) {
    if (features != "_") {
        vector<string> list = Word::split(features, "|");
        for (const string &feature: list) {
            if (feature.find_first_of('=') != -1) {
                string featureName = feature.substr(0, feature.find_first_of('=') - 1);
                string featureValue = feature.substr(feature.find_first_of('=') + 1);
                if (featureValueIndex(language, featureName, featureValue) != -1) {
                    featureList.emplace(featureName, featureValue);
                } else {
                    cout << "Fature does not contain = ->" << featureName << " or the value " << featureValue <<  " is wrong" << endl;
                }
            } else {
                cout << "Fature does not contain = ->" << features;
            }
        }
    }
}

string UniversalDependencyTreeBankFeatures::getFeatureValue(const string &feature) const {
    return featureList.at(feature);
}

string UniversalDependencyTreeBankFeatures::to_string() const {
    if (featureList.empty()) {
        return "_";
    }
    string result;
    for (auto &feature: featureList) {
        if (result.empty()) {
            result = feature.first + "=" + feature.second;
        } else {
            result += "|" + feature.first + "=" + feature.second;
        }
    }
    return result;
}

bool UniversalDependencyTreeBankFeatures::featureExists(const string &feature) const {
    return featureList.contains(feature);
}

int UniversalDependencyTreeBankFeatures::featureIndex(const string& featureName) {
    string tmpName;
    if (featureName.find('[') != string::npos){
        tmpName = featureName.substr(0, featureName.find('['));
    }
    for (int i = 0; i < 24; i++){
        if (universalFeatureTypes[i] == tmpName){
            return i;
        }
    }
    return -1;
}

int UniversalDependencyTreeBankFeatures::dependencyIndex(const string &universalDependency) {
    int index = 0;
    for (const auto& dependency : UniversalDependencyRelation::universalDependencyTypes){
        if (dependency == universalDependency){
            return index;
        }
        index++;
    }
    return -1;
}

int UniversalDependencyTreeBankFeatures::numberOfValues(const string& language, const string& featureName) {
    int index = featureIndex(featureName);
    if (index != -1) {
        if (language == "en") {
            return englishFeatureValues[index].size();
        } else {
            if (language == "tr"){
                return turkishFeatureValues[index].size();
            }
        }
    }
    return -1;
}

int UniversalDependencyTreeBankFeatures::featureValueIndex(const string &language, const string &featureName,
                                                           const string &featureValue) {
    vector<string> *searchArray;
    int index = featureIndex(featureName);
    if (index != -1) {
        if (language == "en") {
            searchArray = const_cast<vector<std::string> *>(englishFeatureValues);
        } else {
            if (language == "tr") {
                searchArray = const_cast<vector<std::string> *>(turkishFeatureValues);
            } else {
                searchArray = const_cast<vector<std::string> *>(universalFeatureValues);
            }
        }
        int featureValueIndex = -1;
        for (int i = 0; i < searchArray[index].size(); i++){
            if (searchArray[index][i] == featureValue){
                featureValueIndex = i;
            }
        }
        return featureValueIndex;
    }
    return -1;
}
