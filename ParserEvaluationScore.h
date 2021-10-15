//
// Created by Olcay Taner YILDIZ on 15.10.2021.
//

#ifndef DEPENDENCYPARSER_PARSEREVALUATIONSCORE_H
#define DEPENDENCYPARSER_PARSEREVALUATIONSCORE_H


class ParserEvaluationScore {
private:
    double LAS = 0.0;
    double UAS = 0.0;
    double LS = 0.0;
    int wordCount = 0;
public:
    ParserEvaluationScore();
    ParserEvaluationScore(double LAS, double UAS, double LS, int wordCount);
    double getLAS();
    double getUAS();
    double getLS();
    int getWordCount();
    void add(ParserEvaluationScore parserEvaluationScore);
};


#endif //DEPENDENCYPARSER_PARSEREVALUATIONSCORE_H
