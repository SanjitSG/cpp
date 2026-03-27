#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
// vector -> vector
// produce a vector of elements which are scores round down to integer

// vector is a dynamic array - i have to traverse each element and convert it into int
// it is a map function - but for now i will use for loop
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> int_scores;
   
    for(int i = 0; i<student_scores.size(); i++){
        int_scores.emplace_back(static_cast<int>(student_scores.at(i)));
    }
    return int_scores;
}


int count_failed_students(std::vector<int> student_scores) {
    int students_failing{0};
    
    for(int score : student_scores){
        if(score <= 40) ++students_failing;
    }
    return students_failing;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int interval = static_cast<int> ((highest_score - 40 )/4);
   
    std::array<int, 4> threshold;
    
    threshold[0] = 41;
   for(int i=1; i<4; i++){
       threshold[i] = threshold[i-1] + interval;
   }
    return threshold;
}

std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {

    std::vector<std::string> student_ranks;
    for(int i=0; i<student_scores.size(); i++){
        std::string make_student = std::to_string(i+1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]);
        student_ranks.emplace_back(make_student);
    }
    return student_ranks;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {

    for(int i=0; i<student_scores.size(); ++i){
        if(student_scores[i] == 100) return student_names[i];
    }
    return "";
}
