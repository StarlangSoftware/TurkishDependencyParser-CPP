//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include <fstream>
#include <iostream>
#include "UniversalDependencyTreeBankCorpus.h"
#include "UniversalDependencyRelation.h"
#include "UniversalDependencyTreeBankSentence.h"

using namespace std;

/**
 * Constructs a universal dependency corpus from an input file. Reads the sentences one by one and constructs a
 * universal dependency sentence from each line read.
 * @param fileName Input file name.
 */
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

/**
 * Compares the corpus with the given corpus and returns a parser evaluation score for this comparison. The result
 * is calculated by summing up the parser evaluation scores of sentence by sentence comparisons.
 * @param corpus Universal dependency corpus to be compared.
 * @return A parser evaluation score object.
 */
ParserEvaluationScore UniversalDependencyTreeBankCorpus::compareParses(const UniversalDependencyTreeBankCorpus& corpus) {
    ParserEvaluationScore score = ParserEvaluationScore();
    for (int i = 0; i < sentences.size(); i++){
        score.add(((UniversalDependencyTreeBankSentence*) sentences.at(i))->compareParses((UniversalDependencyTreeBankSentence*) corpus.getSentence(i)));
    }
    return score;
}

UniversalDependencyTreeBankCorpus::UniversalDependencyTreeBankCorpus() {

}
