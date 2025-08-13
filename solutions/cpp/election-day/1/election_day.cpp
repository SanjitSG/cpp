#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};


int vote_count(ElectionResult& candidate){
     return candidate.votes;
}

void increment_vote_count(ElectionResult& candidate, int vote){
    candidate.votes += vote;
}

ElectionResult& determine_result(std::vector<ElectionResult>& candidates){
    int winner_index = 0;
   
    for(int i = 1; i<candidates.size(); i++){
        if(candidates[i].votes > candidates[winner_index].votes){
            winner_index = i;
            }
        }
      ElectionResult& winner = candidates[winner_index];
    winner.name = "President " + winner.name;
    return winner;
 }


}  // namespace election