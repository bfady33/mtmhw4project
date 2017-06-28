//
// Created by Fady on 6/27/2017.
//

#include "ScaryRoom.h"
#include "Exceptions.h"

mtm::escaperoom::ScaryRoom::ScaryRoom(char* name, const int& escapeTime, const int& level, const int& maxParticipants,
                                      const int& ageLimit,const int& numOfScaryEnigmas) :
        EscapeRoomWrapper::EscapeRoomWrapper(name , escapeTime , level ,maxParticipants) ,minAge(ageLimit) ,
        numOfScaryEnigmas(numOfScaryEnigmas){

}

void mtm::escaperoom::ScaryRoom::setNewAgeLimit(const int& limit){
    if(limit < 0)
        throw mtm::escaperoom::ScaryRoomIllegalAgeLimit();
    this->minAge = limit;
}

void mtm::escaperoom::ScaryRoom::incNumberOfScaryEnigmas(){
    this->numOfScaryEnigmas++;
}

int mtm::escaperoom::ScaryRoom::getAgeLimit(){
    return this->minAge;
}

void mtm::escaperoom::ScaryRoom::print(std::ostream &output) {
    output << "Scary Room: " << roomGetName(room) << "(" << roomGetMaxTime(room) << "/" << getLevel(room) << "/" <<
           roomGetMaxParticipants(room) << ")";
}

