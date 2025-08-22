#include "power_of_troy.h"

namespace troy {
    void give_new_artifact(human& h, std::string artifact_name){
        h.possession = std::make_unique<artifact>(artifact_name);
    }

    void exchange_artifacts(std::unique_ptr<troy::artifact>& p1_artifact,std::unique_ptr<troy::artifact>& p2_artifact){
        std::swap(p1_artifact, p2_artifact);
    }

    void manifest_power(human& h, std::string pow){
        h.own_power = std::make_shared<power>(pow);
    }

    void use_power(human& caster, human& target){
        target.influenced_by = caster.own_power;
    }

    int power_intensity(human& h){
        if(!h.own_power) return 0;
        return h.own_power.use_count();
    }
} 
