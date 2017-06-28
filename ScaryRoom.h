//
// Created by Fady on 6/27/2017.
//

#ifndef HW4PROJECT_SCARYROOM_H
#define HW4PROJECT_SCARYROOM_H


#include "EscapeRoomWrapper.h"
namespace mtm {
    namespace escaperoom {

        class ScaryRoom : public EscapeRoomWrapper {
        private:
            int minAge;
            int numOfScaryEnigmas;

        protected:
            virtual void print(std::ostream& output);

        public:
            ScaryRoom(char *name, const int &escapeTime, const int &level, const int &maxParticipants,
                      const int &ageLimit, const int &numOfScaryEnigmas);

            //set the agelimit to limit
            void setNewAgeLimit(const int& limit);

            //icreases the number of scapry Enigmas in Room
            void incNumberOfScaryEnigmas();

            //returns the age limit of room
            int getAgeLimit();

        };
    }
}
#endif //HW4PROJECT_SCARYROOM_H
