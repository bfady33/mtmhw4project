//
// Created by Or on 23/06/17.
//

#include "Enigma.h"

mtm::escaperoom::Enigma::Enigma(const std::string &name, const Difficulty &difficulty, const int &numOfElements) :
    name(name), difficulty(difficulty), num_of_elements(numOfElements){
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

Difficulty mtm::escaperoom::Enigma::getDifficulty() const {
    return difficulty;
}

string mtm::escaperoom::Enigma::getName() const {
    return name;
}

friend std::ostream& mtm::escaperoom::operator<<(std::ostream& output, const Enigma& enigma) {
    return output << enigma.name << " (" << enigma.difficulty << ") " << enigma.num_of_elements;
}