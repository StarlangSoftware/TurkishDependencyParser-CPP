//
// Created by Olcay Taner YILDIZ on 8.01.2021.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <CounterHashMap.h>
#include "catch.hpp"
#include "../src/Turkish/TurkishDependencyType.h"
#include "../src/Turkish/TurkishDependencyTreeBankCorpus.h"
#include "../src/Turkish/TurkishDependencyTreeBankSentence.h"
#include "../src/Turkish/TurkishDependencyTreeBankWord.h"

TEST_CASE("TurkishDependencyTreeBankCorpusTest-testDependencyCorpus") {
    CounterHashMap<TurkishDependencyType> relationCounts = CounterHashMap<TurkishDependencyType>();
    TurkishDependencyTreeBankCorpus corpus = TurkishDependencyTreeBankCorpus("metu-treebank.xml");
    REQUIRE(5635 == corpus.sentenceCount());
    int wordCount = 0;
    for (int i = 0; i < corpus.sentenceCount(); i++){
        auto* sentence = (TurkishDependencyTreeBankSentence*) corpus.getSentence(i);
        wordCount += sentence->wordCount();
        for (int j = 0; j < sentence->wordCount(); j++){
            auto* word = (TurkishDependencyTreeBankWord*) sentence->getWord(j);
            relationCounts.put(word->getRelation().getTurkishDependencyType());
        }
    }
    REQUIRE(53993 == wordCount);
    REQUIRE(10 == relationCounts[TurkishDependencyType::ETOL]);
    REQUIRE(16 == relationCounts[TurkishDependencyType::EQU_ADJUNCT]);
    REQUIRE(1142 == relationCounts[TurkishDependencyType::LOCATIVE_ADJUNCT]);
    REQUIRE(523 == relationCounts[TurkishDependencyType::ABLATIVE_ADJUNCT]);
    REQUIRE(1361 == relationCounts[TurkishDependencyType::DATIVE_ADJUNCT]);
    REQUIRE(23 == relationCounts[TurkishDependencyType::FOCUS_PARTICLE]);
    REQUIRE(73 == relationCounts[TurkishDependencyType::COLLOCATION]);
    REQUIRE(85 == relationCounts[TurkishDependencyType::RELATIVIZER]);
    REQUIRE(11692 == relationCounts[TurkishDependencyType::MODIFIER]);
    REQUIRE(903 == relationCounts[TurkishDependencyType::INTENSIFIER]);
    REQUIRE(240 == relationCounts[TurkishDependencyType::VOCATIVE]);
    REQUIRE(7261 == relationCounts[TurkishDependencyType::SENTENCE]);
    REQUIRE(159 == relationCounts[TurkishDependencyType::NEGATIVE_PARTICLE]);
    REQUIRE(4481 == relationCounts[TurkishDependencyType::SUBJECT]);
    REQUIRE(2476 == relationCounts[TurkishDependencyType::COORDINATION]);
    REQUIRE(2050 == relationCounts[TurkishDependencyType::CLASSIFIER]);
    REQUIRE(1516 == relationCounts[TurkishDependencyType::POSSESSOR]);
    REQUIRE(1952 == relationCounts[TurkishDependencyType::DETERMINER]);
    REQUIRE(202 == relationCounts[TurkishDependencyType::APPOSITION]);
    REQUIRE(289 == relationCounts[TurkishDependencyType::QUESTION_PARTICLE]);
    REQUIRE(597 == relationCounts[TurkishDependencyType::S_MODIFIER]);
    REQUIRE(8338 == relationCounts[TurkishDependencyType::OBJECT]);
    REQUIRE(271 == relationCounts[TurkishDependencyType::INSTRUMENTAL_ADJUNCT]);
}
