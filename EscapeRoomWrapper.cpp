//
// Created by Fady on 6/22/2017.
//
#include "EscapeRoomWrapper.h"
#include "Exceptions.h"

#define DEFAULT_TIME 60
#define DEFAULT_PARTICIPANTS 6

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

bool mtm::escaperoom::EscapeRoomWrapper::operator==(const EscapeRoomWrapper &room) const {
    return areEqualRooms(room.room , this->room);
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

std::ostream& operator<<(std::ostream &output, const mtm::escaperoom::EscapeRoomWrapper &room) {
    return output<<""<<"";
}