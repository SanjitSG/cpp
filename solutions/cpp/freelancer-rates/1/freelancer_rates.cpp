#include<cmath>

double daily_rate(double hourly_rate) {
    return hourly_rate * 8.0;
}

double apply_discount(double before_discount, double discount) {
   
    return before_discount -  (before_discount * (discount/100));
}

int monthly_rate(double hourly_rate, double discount) {
    
    return ceil (apply_discount((22 * daily_rate(hourly_rate)),discount)) ;
}

int days_in_budget(int budget, double hourly_rate, double discount) {
    // TODO: Implement a function that takes a budget, an hourly rate, and a
    // discount, and calculates how many complete days of work that covers.
    // first get daily_rate(hourly_rate) 
    // - get discount on on it apply_discount(daily_rate(hourly_rate), discount) 
    // - divide discounted rate from total budget -> i will get number of days - i have to return floor 

    
    return floor (budget / apply_discount(daily_rate(hourly_rate), discount));
}