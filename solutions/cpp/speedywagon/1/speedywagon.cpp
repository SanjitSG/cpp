#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(pillar_men_sensor* ptr) {
    if (ptr == nullptr) {
        return false;
    }
    return true;
}

 //activity_counter
int activity_counter(pillar_men_sensor* sensors, int capacity) {
    int total_activity = 0; 
    for (int i = 0; i < capacity; ++i) {
        total_activity += (sensors + i)->activity;
    }

    return total_activity;
}

bool alarm_control(pillar_men_sensor* ptr){
    if(ptr != nullptr){
        if(ptr->activity > 0){
            return true;
        }
    }
    return false;
};

// pass address of sensor data array
bool uv_alarm(pillar_men_sensor* ptr){
    if(ptr != nullptr){
        if(uv_light_heuristic(&ptr->data) > ptr->activity){
            // passing address of data array &ptr
            return true;
        }   
    }
    return false;
}
// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
