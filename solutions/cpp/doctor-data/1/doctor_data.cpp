#include "doctor_data.h"

namespace heaven{

        Vessel::Vessel(std::string name = "Bob", int gen = 1, star_map::System sys):vessel_name(name), generation(gen), current_system(sys){};
    
        Vessel Vessel::replicate(std::string name){
            return Vessel(name, generation + 1, current_system);
        }

        void Vessel::make_buster() {
            busters++;
        }
    
        bool Vessel::shoot_buster(){
            if(busters != 0){
                --busters;
                return true;
            }
            return false;
        }

    std::string get_older_bob(Vessel v1, Vessel v2){
        if(v1.generation < v2.generation){
            return v1.vessel_name;
        }
        return v2.vessel_name;
    }
    
    bool in_the_same_system(Vessel v1, Vessel v2){
        return v1.current_system == v2.current_system;
    }
}