//
// Created by Olcay Taner YILDIZ on 15.10.2021.
//

#include "ParserEvaluationScore.h"

/**
 * Empty constructor of the parser evaluation score object.
 */
ParserEvaluationScore::ParserEvaluationScore() = default;

/**
 * Another constructor of the parser evaluation score object.
 * @param LAS Label attachment score
 * @param UAS Unlabelled attachment score
 * @param LS Label score
 * @param wordCount Number of words evaluated
 */
ParserEvaluationScore::ParserEvaluationScore(double LAS, double UAS, double LS, int wordCount) {
    this->LAS = LAS;
    this->UAS = UAS;
    this->LS = LS;
    this->wordCount = wordCount;
}

/**
 * Accessor for the LAS field
 * @return Label attachment score
 */
double ParserEvaluationScore::getLAS() const{
    return LAS;
}

/**
 * Accessor for the UAS field
 * @return Unlabel attachment score
 */
double ParserEvaluationScore::getUAS() const{
    return UAS;
}

/**
 * Accessor for the LS field
 * @return Label score
 */
double ParserEvaluationScore::getLS() const{
    return LS;
}

/**
 * Accessor for the word count field
 * @return Number of words evaluated
 */
int ParserEvaluationScore::getWordCount() const{
    return wordCount;
}

/**
 * Adds a parser evaluation score to the current evaluation score.
 * @param parserEvaluationScore Parser evaluation score to be added.
 */
void ParserEvaluationScore::add(const ParserEvaluationScore& parserEvaluationScore) {
    LAS = (LAS * wordCount + parserEvaluationScore.LAS * parserEvaluationScore.wordCount) / (wordCount + parserEvaluationScore.wordCount);
    UAS = (UAS * wordCount + parserEvaluationScore.UAS * parserEvaluationScore.wordCount) / (wordCount + parserEvaluationScore.wordCount);
    LS = (LS * wordCount + parserEvaluationScore.LS * parserEvaluationScore.wordCount) / (wordCount + parserEvaluationScore.wordCount);
    wordCount += parserEvaluationScore.wordCount;
}
