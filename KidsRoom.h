//
// Created by Fady on 6/28/2017.
//

#ifndef HW4PROJECT_KIDSROOM_H
#define HW4PROJECT_KIDSROOM_H


#include "EscapeRoomWrapper.h"

namespace mtm {
    namespace escaperoom {

        class KidsRoom : public EscapeRoomWrapper {
        private:
            int maxAge;

        protected:
            virtual void print(std::ostream& output);
        public:
            KidsRoom(char* name, const int& escapeTime, const int& level, const int& maxParticipants,
                     const int& ageLimit);

            void setNewAgeLimit(const int& limit);

            int getAgeLimit();
        };
    }
}


#endif //HW4PROJECT_KIDSROOM_H
