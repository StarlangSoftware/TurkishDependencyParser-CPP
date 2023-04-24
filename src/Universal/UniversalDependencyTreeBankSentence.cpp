//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include "Dictionary/Word.h"
#include <iostream>
#include <regex>
#include "UniversalDependencyTreeBankSentence.h"
#include "UniversalDependencyTreeBankWord.h"

UniversalDependencyTreeBankSentence::UniversalDependencyTreeBankSentence() : Sentence(){

}

UniversalDependencyTreeBankSentence::UniversalDependencyTreeBankSentence(const string& language, const string& sentence) : Sentence(){
    UniversalDependencyRelation* relation;
    vector<string> lines = Word::split(sentence, "\n");
    for (const string& line : lines){
        if (line.empty()){
            continue;
        }
        if (Word::startsWith(line, "#")){
            addComment(Word::trim(line));
        } else {
            vector<string> items = Word::split(line, "\t");
            if (items.size() != 10){
                cout << "Line does not contain 10 items ->" << line;
            } else {
                string id = items[0];
                if (regex_match(id, regex("\\d+"))){
                    string surfaceForm = items[1];
                    string lemma = items[2];
                    UniversalDependencyPosType upos = UniversalDependencyRelation::getDependencyPosType(items[3]);
                    string xpos = items[4];
                    auto* features = new UniversalDependencyTreeBankFeatures(language, items[5]);
                    if (items[6] != "_"){
                        int to = stoi(items[6]);
                        string dependencyType = items[7];
                        std::transform(dependencyType.begin(), dependencyType.end(), dependencyType.begin(), ::toupper);
                        relation = new UniversalDependencyRelation(to, dependencyType);
                    } else {
                        relation = nullptr;
                    }
                    string deps = items[8];
                    string misc = items[9];
                    auto* word = new UniversalDependencyTreeBankWord(stoi(id), surfaceForm,
                                                                     lemma, upos, xpos, features, relation, deps, misc);
                    addWord(word);
                }
            }
        }
    }
}

void UniversalDependencyTreeBankSentence::addComment(const string& comment) {
    comments.emplace_back(comment);
}

string UniversalDependencyTreeBankSentence::to_string() const{
    string result;
    for (const string& comment : comments){
        result += comment + "\n";
    }
    for (Word* w : this->words){
        auto* word = (UniversalDependencyTreeBankWord*) w;
        result += word->to_string() + "\n";
    }
    return result;
}

ParserEvaluationScore
UniversalDependencyTreeBankSentence::compareParses(UniversalDependencyTreeBankSentence *sentence) const{
    ParserEvaluationScore score = ParserEvaluationScore();
    for (int i = 0; i < words.size(); i++){
        UniversalDependencyRelation* relation1 = ((UniversalDependencyTreeBankWord*) words.at(i))->getRelation();
        UniversalDependencyRelation* relation2 = ((UniversalDependencyTreeBankWord*) sentence->getWord(i))->getRelation();
        if (relation1 != nullptr && relation2 != nullptr){
            score.add(relation1->compareRelations(relation2));
        }
    }
    return score;
}
