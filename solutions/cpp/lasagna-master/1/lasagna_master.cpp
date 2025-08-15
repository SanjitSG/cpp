#include "lasagna_master.h"

namespace lasagna_master {

int preparationTime(const std::vector<std::string>& layers, int avgTime) {
    return layers.size() * avgTime;
}

amount quantities(const std::vector<std::string>& list) {
    amount obj{0, 0.0};
    for (const std::string& s : list) {
        if (s == "noodles") {
            obj.noodles += 50;
        }
        if (s == "sauce") {
            obj.sauce += 0.2;
        }
    }
    return obj;
}

void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendList) {
    if (!friendList.empty()) {
        myList.back() = friendList.back();
    }
}

vector<double> scaleRecipe(const vector<double>& amounts, int num_portions) {
    vector<double> scaled_recipe;
    
    double amount_per_portion = static_cast<double>(num_portions) / 2.0;
    for (double amount : amounts) {
        scaled_recipe.push_back(amount * amount_per_portion);
    }
    return scaled_recipe;
}
 
void addSecretIngredient(std::vector<std::string>& myList, const std::string& secret) {
    myList.back() = secret;
}

}  // namespace lasagna_master