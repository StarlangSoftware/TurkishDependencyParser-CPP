//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include <fstream>
#include <iostream>
#include "UniversalDependencyTreeBankCorpus.h"
#include "UniversalDependencyRelation.h"
#include "UniversalDependencyTreeBankSentence.h"

using namespace std;

UniversalDependencyTreeBankCorpus::UniversalDependencyTreeBankCorpus(const string& fileName) {
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    this->language = fileName.substr(0, fileName.find('_'));
    this->fileName = fileName;
    string line;
    string sentence;
    while (inputStream.good()){
        getline(inputStream, line);
        if (line.empty()){
            auto* treeBankSentence = new UniversalDependencyTreeBankSentence(language, sentence);
            if (treeBankSentence->wordCount() > 0){
                addSentence(treeBankSentence);
            }
            sentence = "";
        } else {
            sentence += line + "\n";
        }
    }
}

ParserEvaluationScore UniversalDependencyTreeBankCorpus::compareParses(const UniversalDependencyTreeBankCorpus& corpus) {
    ParserEvaluationScore score = ParserEvaluationScore();
    for (int i = 0; i < sentences.size(); i++){
        score.add(((UniversalDependencyTreeBankSentence*) sentences.at(i))->compareParses((UniversalDependencyTreeBankSentence*) corpus.getSentence(i)));
    }
    return score;
}

UniversalDependencyTreeBankCorpus::UniversalDependencyTreeBankCorpus() {

}
