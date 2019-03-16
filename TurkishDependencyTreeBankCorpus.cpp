//
// Created by Olcay Taner Yıldız on 2019-03-16.
//

#include "TurkishDependencyTreeBankCorpus.h"
#include "XmlDocument.h"
#include "TurkishDependencyTreeBankSentence.h"

TurkishDependencyTreeBankCorpus TurkishDependencyTreeBankCorpus::emptyCopy() {
    return TurkishDependencyTreeBankCorpus();
}

TurkishDependencyTreeBankCorpus::TurkishDependencyTreeBankCorpus(string fileName) : Corpus() {
    XmlDocument doc = XmlDocument(move(fileName));
    TurkishDependencyTreeBankSentence* sentence;
    doc.parse();
    XmlElement* rootNode = doc.getFirstChild();
    XmlElement* sentenceNode = rootNode->getFirstChild();
    while (sentenceNode != nullptr){
        sentence = new TurkishDependencyTreeBankSentence(sentenceNode);
        sentenceNode = sentenceNode->getNextSibling();
    }
}
