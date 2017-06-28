//
// Created by Fady on 6/28/2017.
//


#include "KidsRoom.h"
#include "Exceptions.h"

mtm::escaperoom::KidsRoom::KidsRoom(char* name, const int& escapeTime, const int& level, const int& maxParticipants,
                                    const int& ageLimit) :
        EscapeRoomWrapper::EscapeRoomWrapper(name , escapeTime , level ,maxParticipants) ,maxAge(ageLimit) {

}

void mtm::escaperoom::KidsRoom::print(std::ostream &output) {
    output << "Kids Room: " << roomGetName(room) << "(" << roomGetMaxTime(room) << "/" << getLevel(room) << "/" <<
           roomGetMaxParticipants(room) << "/"<< maxAge <<")";
}

void mtm::escaperoom::KidsRoom::setNewAgeLimit(const int& limit){
    if(limit < 0)
        throw mtm::escaperoom::KidsRoomIllegalAgeLimit();
    maxAge = limit;
}

int mtm::escaperoom::KidsRoom::getAgeLimit(){
    return this->maxAge;
}


