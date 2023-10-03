//
// Created by Olcay Taner Yıldız on 2019-03-16.
//

#include "TurkishDependencyTreeBankCorpus.h"
#include "XmlDocument.h"
#include "TurkishDependencyTreeBankSentence.h"

/**
 * Constructor to create an empty copy of this corpus.
 * @return An empty copy of this corpus.
 */
TurkishDependencyTreeBankCorpus TurkishDependencyTreeBankCorpus::emptyCopy() const{
    return TurkishDependencyTreeBankCorpus();
}

/**
 * Another constructor for TurkishDependencyTreeBankCorpus. The method gets the corpus as an xml file, and
 * reads sentences one by one. For each sentence, the function constructs a TurkishDependencyTreeBankSentence.
 * @param fileName Input file name to read the TurkishDependencyTreeBankCorpus.
 */
TurkishDependencyTreeBankCorpus::TurkishDependencyTreeBankCorpus(const string& fileName) : Corpus() {
    XmlDocument doc = XmlDocument(fileName);
    TurkishDependencyTreeBankSentence* sentence;
    doc.parse();
    XmlElement* rootNode = doc.getFirstChild();
    XmlElement* sentenceNode = rootNode->getFirstChild();
    while (sentenceNode != nullptr){
        sentence = new TurkishDependencyTreeBankSentence(sentenceNode);
        addSentence(sentence);
        sentenceNode = sentenceNode->getNextSibling();
    }
}
