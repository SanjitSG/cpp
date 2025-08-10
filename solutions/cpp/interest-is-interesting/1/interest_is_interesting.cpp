double interest_rate(double balance) {
    if(balance < 0) return 3.213;
    if(balance < 1000) return 0.5;
    if(balance < 5000) return 1.621;
    return 2.475;
}

double yearly_interest(double balance) {
    return balance * interest_rate(balance)/100;
}

double annual_balance_update(double balance) {
    return balance + yearly_interest(balance);
}

int years_until_desired_balance(double balance, double target_balance) {
    double current_balance = balance; // temp variable so that i dont mutate the original balance object.
    int years{0};
    while (current_balance < target_balance){ // 1000 < 1032 | 1016 < 1032 | 1032 < 1032-> false
        current_balance = annual_balance_update(current_balance); // new balance: 1016 | 1032
        ++years; // 1 | 2
    }
    return years; // return 2
}