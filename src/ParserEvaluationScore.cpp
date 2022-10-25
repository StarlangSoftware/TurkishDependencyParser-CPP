//
// Created by Olcay Taner YILDIZ on 15.10.2021.
//

#include "ParserEvaluationScore.h"

ParserEvaluationScore::ParserEvaluationScore() = default;

ParserEvaluationScore::ParserEvaluationScore(double LAS, double UAS, double LS, int wordCount) {
    this->LAS = LAS;
    this->UAS = UAS;
    this->LS = LS;
    this->wordCount = wordCount;
}

double ParserEvaluationScore::getLAS() const{
    return LAS;
}

double ParserEvaluationScore::getUAS() const{
    return UAS;
}

double ParserEvaluationScore::getLS() const{
    return LS;
}

int ParserEvaluationScore::getWordCount() const{
    return wordCount;
}

void ParserEvaluationScore::add(const ParserEvaluationScore& parserEvaluationScore) {
    LAS = (LAS * wordCount + parserEvaluationScore.LAS * parserEvaluationScore.wordCount) / (wordCount + parserEvaluationScore.wordCount);
    UAS = (UAS * wordCount + parserEvaluationScore.UAS * parserEvaluationScore.wordCount) / (wordCount + parserEvaluationScore.wordCount);
    LS = (LS * wordCount + parserEvaluationScore.LS * parserEvaluationScore.wordCount) / (wordCount + parserEvaluationScore.wordCount);
    wordCount += parserEvaluationScore.wordCount;
}
