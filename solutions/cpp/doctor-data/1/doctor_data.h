#pragma once
#include<string>

namespace star_map{
    enum class System{
    BetaHydri,
    Sol,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani
    };
}

namespace heaven{
    class Vessel{
    public:   
       
    std::string vessel_name;
    int generation;
    star_map::System current_system;
    int busters;

    Vessel(std::string name, int gen, star_map::System sys = star_map::System::Sol);

    Vessel replicate(std::string);
    void make_buster();
    bool shoot_buster();
    
    
    };
    std::string get_older_bob(Vessel v1, Vessel v2);
    bool in_the_same_system(Vessel v1, Vessel v2);
}