#pragma once
#include<string>
#include<vector>
using namespace std;

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

    int preparationTime(const std::vector<std::string>& layers, int avgTime = 2);
amount quantities(const std::vector<std::string>& list);
void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendList);
vector<double> scaleRecipe(const vector<double>& amounts, int num_portion); 
void addSecretIngredient(std::vector<std::string>& myList, const std::string& secretIngredient);

}  // namespace lasagna_master
