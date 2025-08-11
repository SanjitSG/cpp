namespace targets {
class Alien {
    public:
    int x_coordinate;
    int y_coordinate;
    //constructor
    Alien (int x, int y) : x_coordinate(x), y_coordinate(y){};

    int get_health() const { return health; }
    
    bool hit(){
        if(health > 0){
            --health;
            return true;
        }
        return false;
    }
    
    bool is_alive() const { return health != 0; }

    bool teleport(int x_new, int y_new){
        x_coordinate = x_new;
        y_coordinate = y_new;
        return true;
    }
    bool collision_detection(const Alien &obj) const{
        return x_coordinate == obj.x_coordinate && y_coordinate == obj.y_coordinate;
    }
    private:
    int health{3};
};
}  // namespace targets