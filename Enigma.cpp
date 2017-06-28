//
// Created by Or on 23/06/17.
//

#include "Enigma.h"
#include "Exceptions.h"

//using std::string;

mtm::escaperoom::Enigma::Enigma(const std::string& name, const Difficulty& difficulty, const int& numOfElements ,
                                const set<string> &elements){
    if(elements.size() != numOfElements){
        EnigmaIllegalSizeParamException exc;
        throw exc;
    }
    this->name = name;
    this->difficulty = difficulty;
    this->num_of_elements = numOfElements;
    this->elements = elements;
}

mtm::escaperoom::Enigma::Enigma(const std::string& name, const Difficulty& difficulty){
    this->name = name;
    this->difficulty = difficulty;
    this->num_of_elements = 0;
}

bool mtm::escaperoom::Enigma::operator==(const Enigma &enigma) const {
    return (this->name.compare(enigma.name) == 0) && (this->difficulty == enigma.difficulty);
}

bool mtm::escaperoom::Enigma::operator!=(const Enigma &enigma) const {
    return !(*this == enigma);
}

bool mtm::escaperoom::Enigma::operator<(const Enigma &enigma) const {
    return (this->difficulty < enigma.difficulty);
}

bool mtm::escaperoom::Enigma::operator>(const Enigma &enigma) const {
    return (enigma < *this);
}

bool mtm::escaperoom::Enigma::areEqualyComplex(const Enigma& enigma) const {
    return (this->difficulty == enigma.difficulty) && (this->num_of_elements == enigma.num_of_elements);
}

mtm::escaperoom::Difficulty mtm::escaperoom::Enigma::getDifficulty() const {
    return difficulty;
}

void mtm::escaperoom::Enigma::addElement(const string& element){
    this->elements.insert(element);
}

void mtm::escaperoom::Enigma::removeElement(const string& element){
    if(this->elements.size() == 0){
        EnigmaNoElementsException exc;
        throw exc;
    }
    if(this->elements.find(element) == this->elements.end())
    {
        mtm::escaperoom::EnigmaElementNotFoundException exc;
        throw exc;
    }
    this->elements.erase(element);
}

string mtm::escaperoom::Enigma::getName() const {
    return name;
}

namespace mtm{
    namespace escaperoom {
        std::ostream &operator<<(std::ostream &output, const Enigma &enigma) {
            return output << enigma.name << " (" << enigma.difficulty << ") " << enigma.num_of_elements;
        }
    }
}