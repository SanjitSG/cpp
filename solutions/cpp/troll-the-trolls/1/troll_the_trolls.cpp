namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};
// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action{
    read,
    write,
    remove
};
    
// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster, AccountStatus viewer){

    switch (poster){
        case AccountStatus::troll:
            return viewer == AccountStatus::troll;
        case AccountStatus::guest:
        case AccountStatus::user:
        case AccountStatus::mod:
            return true;
        default: 
            return false;
    }
}

    
// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action a, AccountStatus entity){
    switch (a){
        case Action::read:
            return true;
        case Action::write:
            return entity != AccountStatus::guest;
        case Action::remove:
            return entity == AccountStatus::mod;
        default:
            return false;
    }
        
}
// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus p1, AccountStatus p2){
    // guest - mod -> fasle
    // mod - guest -> false
    // 
    // troll - troll -> true
    // user:user - user:mod - mod:user -> true 
    //false otherwise
    switch(p1){
        case AccountStatus::user:
            return p2 == AccountStatus::user || p2 == AccountStatus::mod;
        case AccountStatus::mod:
            return p2 == AccountStatus::mod || p2 == AccountStatus::user;
        case AccountStatus::troll:
            return p2 == AccountStatus::troll;
        default:
            return false;
    }
} 
// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus p1, AccountStatus p2){
    // AccountStatus AccountStatus -> Boolean
    // produce true if first accountStatus has *slightly* higher priority
    // priority list: mod - user - guest - trolls
    // mod - mod - false
    // mod - !mod -> true
    // user - !mod -> true
    // guest - !mod and !user - true
    // false otherwise
    switch(p1){
        case AccountStatus::mod:
            return p2 != AccountStatus::mod;
        case AccountStatus::user:
            return p2 != AccountStatus::mod && p2 != AccountStatus::user;
        case AccountStatus::guest:
            return p2 == AccountStatus::troll;
        default:
            return false;
    }
}
}  // namespace hellmath