//
// Created by Olcay Taner Yıldız on 2019-03-16.
//

#include "TurkishDependencyTreeBankWord.h"

TurkishDependencyTreeBankWord::TurkishDependencyTreeBankWord(XmlElement* wordNode) {
    string IG, relationName, dependencyType;
    int i, index, toWord = 0, toIG = 0;
    if (wordNode->hasAttributes()){
        name = wordNode->getPcData();
        if (!wordNode->getAttributeValue("IG").empty()){
            IG = wordNode->getAttributeValue("IG");
            parse = MorphologicalParse(splitIntoInflectionalGroups(IG));
        }
        if (!wordNode->getAttributeValue("REL").empty()){
            relationName = wordNode->getAttributeValue("REL");
            if (relationName != "[,( )]"){
                vector<string> relationParts = Word::split(relationName, ",[]()");
                index = 0;
                for (int i = 0; i < relationParts.size(); i++){
                    if (!relationParts.at(i).empty()){
                        index++;
                        switch (index){
                            case 1:
                                toWord = stoi(relationParts[i]);
                                break;
                            case 2:
                                toIG = stoi(relationParts[i]);
                                break;
                            case 3:
                                dependencyType = relationParts[i];
                                relation = TurkishDependencyRelation(toWord - 1, toIG - 1, dependencyType);
                                break;
                        }
                    }
                }
            }
        }
        for (i = 1; i <= 9; i++){
            if (!wordNode->getAttributeValue("ORG_IG" + std::to_string(i)).empty()){
                IG = wordNode->getAttributeValue("ORG_IG" + std::to_string(i));
                if (i == 1){
                    originalParses.emplace_back(MorphologicalParse(splitIntoInflectionalGroups(IG)));
                }
            }
        }
    }
}

vector<string> TurkishDependencyTreeBankWord::splitIntoInflectionalGroups(string IG) {
    vector<string> inflectionalGroups;
    IG = Word::replaceAll(IG, "(+Punc", "@");
    IG = Word::replaceAll(IG, ")+Punc", "$");
    vector<string> iGs = Word::split(IG, "[()]");
    for (int i = 0; i < iGs.size(); i++){
        string IGI = iGs[i];
        IGI = Word::replaceAll(IGI, "@", "(+Punc");
        IGI = Word::replaceAll(IGI, "$", ")+Punc");
        if (!IGI.empty()){
            inflectionalGroups.emplace_back(IGI);
        }
    }
    return inflectionalGroups;
}

MorphologicalParse TurkishDependencyTreeBankWord::getParse() {
    return parse;
}

MorphologicalParse TurkishDependencyTreeBankWord::getOriginalParse(int index) {
    return originalParses.at(index);
}

int TurkishDependencyTreeBankWord::size() {
    return originalParses.size();
}

TurkishDependencyRelation TurkishDependencyTreeBankWord::getRelation() {
    return relation;
}
