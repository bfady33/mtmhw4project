//
// Created by Fady on 6/22/2017.
//
#include "EscapeRoomWrapper.h"
#include "Exceptions.h"

#define DEFAULT_TIME 60
#define DEFAULT_PARTICIPANTS 6

//the functions of EscapeRoomWrapper

mtm::escaperoom::EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& escapeTime, const int& level,
                                                      const int& maxParticipants){
    room = escapeRoomCreate(name , escapeTime, maxParticipants , level);
    if(room == NULL){
        EscapeRoomMemoryProblemException exc;
        throw exc;
    }
}

mtm::escaperoom::EscapeRoomWrapper::EscapeRoomWrapper(char *name, const int &level){
    room = escapeRoomCreate(name ,DEFAULT_TIME , DEFAULT_PARTICIPANTS , level);
    if(room == NULL){
        EscapeRoomMemoryProblemException exc;
        throw exc;
    }
}

mtm::escaperoom::EscapeRoomWrapper::EscapeRoomWrapper(const EscapeRoomWrapper &room) {
    this->room = escapeRoomCopy(room.room);
    if(this->room == NULL){
        EscapeRoomMemoryProblemException exc;
        throw exc;
    }
}

mtm::escaperoom::EscapeRoomWrapper::~EscapeRoomWrapper() {
    escapeRoomDestroy(this->room);
}

int mtm::escaperoom::EscapeRoomWrapper::getMaxParticipants() const {
    return roomGetMaxParticipants(this->room);
}

int mtm::escaperoom::EscapeRoomWrapper::level() const {
    return getLevel(this->room);
}

int mtm::escaperoom::EscapeRoomWrapper::getMaxTime() const {
    return roomGetMaxTime(this->room);
}

std::string mtm::escaperoom::EscapeRoomWrapper::getName() const {
    return roomGetName(this->room);
}

double mtm::escaperoom::EscapeRoomWrapper::getRate() const {
    return roomGetRate(this->room);
}

void mtm::escaperoom::EscapeRoomWrapper::rate(const int& newRate) const{
    updateRate(this->room , newRate);
}

bool mtm::escaperoom::EscapeRoomWrapper::operator==(const EscapeRoomWrapper &room) const {
    return areEqualRooms(room.room , this->room);
}

mtm::escaperoom::EscapeRoomWrapper& mtm::escaperoom::EscapeRoomWrapper::operator=(const EscapeRoomWrapper& room){
    if(&room == this){
        return *this;
    }
    escapeRoomDestroy(this->room);
    this->room = escapeRoomCopy(room.room);
    if(this->room == NULL){
        EscapeRoomMemoryProblemException exc;
        throw exc;
    }
    return *this;
}

bool mtm::escaperoom::EscapeRoomWrapper::operator!=(const EscapeRoomWrapper &room) const {
    return !areEqualRooms(room.room , this->room);
}

bool mtm::escaperoom::EscapeRoomWrapper::operator<(const EscapeRoomWrapper &room) const {
    return isBiggerRoom(room.room , this->room);
}

bool mtm::escaperoom::EscapeRoomWrapper::operator>(const EscapeRoomWrapper &room) const {
    return isBiggerRoom(this->room, room.room);
}

void mtm::escaperoom::EscapeRoomWrapper::addEnigma(const Enigma& enigma){
    this->enigmas.insert(this->enigmas.end() , enigma);
}

void mtm::escaperoom::EscapeRoomWrapper::removeEnigma(const Enigma& enigma){
    if(this->enigmas.size() == 0){
        EscapeRoomNoEnigmasException exc;
        throw exc;
    }

    for(int i = 0 ; i < this->enigmas.size() ; i++){
        if(this->enigmas[i] == enigma){
            this->enigmas.erase(this->enigmas.begin() + i);
            return;
        }
    }
    EscapeRoomEnigmaNotFoundException exc;
    throw exc;
}

mtm::escaperoom::Enigma mtm::escaperoom::EscapeRoomWrapper::getHardestEnigma(){
    if(this->enigmas.size() == 0){
        EscapeRoomNoEnigmasException exc;
        throw exc;
    }
    Enigma mostDiffE = this->enigmas[0];
    mtm::escaperoom::Difficulty currMaxDiff = mtm::escaperoom::EASY_ENIGMA;
    for(int i = 0 ; i < this->enigmas.size() ; i++){
        if(this->enigmas[i].getDifficulty() > currMaxDiff)
            mostDiffE = this->enigmas[i];
    }

    return mostDiffE;
}

std::vector<mtm::escaperoom::Enigma>& mtm::escaperoom::EscapeRoomWrapper::getAllEnigmas(){
    return  this->enigmas;
}

namespace mtm {
    namespace escaperoom{
    std::ostream &operator<<(std::ostream &output, const mtm::escaperoom::EscapeRoomWrapper &room) {
        print(output);
        return output;
    }
}
}

void mtm::escaperoom::EscapeRoomWrapper::print(std::ostream &output) {
    output << roomGetName(room) << "(" << roomGetMaxTime(room) << "/" << getLevel(room) << "/" <<
    roomGetMaxParticipants(room) << ")";
}