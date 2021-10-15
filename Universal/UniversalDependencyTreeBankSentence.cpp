//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include <Word.h>
#include "UniversalDependencyTreeBankSentence.h"
#include "UniversalDependencyTreeBankWord.h"

UniversalDependencyTreeBankSentence::UniversalDependencyTreeBankSentence() : Sentence(){

}

void UniversalDependencyTreeBankSentence::addComment(string comment) {
    comments.emplace_back(comment);
}

string UniversalDependencyTreeBankSentence::to_string() {
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
UniversalDependencyTreeBankSentence::compareParses(UniversalDependencyTreeBankSentence *sentence) {
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
