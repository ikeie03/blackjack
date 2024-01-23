#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include "blackjackgame.cpp"

double std_dev = -1;

extern "C" {

    double calculate_standard_deviation(std::vector<double>& outcomes, double mean, double bankroll) {
        double variance = 0;
        for (int i = 0; i < outcomes.size(); i++) {
            // difference between gain and average gain
            double difference = ((outcomes[i]-bankroll) - (mean-bankroll));
            variance += (difference * difference);
        }

        variance = variance / 100000.0;
        double standard_deviation = std::sqrt(variance);
        return standard_deviation;
    }

    // double std_dev = -1;
    double simulateBlackJack(int num_decks, double betting_unit, double bankroll,
                             double a_value, double _2_value, double _3_value,
                             double _4_value, double _5_value, double _6_value, double _7_value,
                             double _8_value, double _9_value, double _10_value) {
        std::vector<double> values = {0.0, a_value, _2_value, _3_value, _4_value,
                                      _5_value, _6_value, _7_value, _8_value, _9_value,
                                      _10_value, a_value};
        
        double average_bankroll = 0.0;
        for (int i = 0; i < values.size(); i++) {
            std::cout << values[i] << " ";
        }
        std::cout << std::endl;

        std::vector<double> outcomes(100000, 0.0);
        for (int i = 0; i < 100000; i++) {
            if (i % 10000 == 0) {
                std::cout << "all gud" << std::endl;
            }

            BlackjackGame simulated_shoe(num_decks, values, betting_unit, bankroll);
            while (simulated_shoe.can_continue) {
                simulated_shoe.play_hand();
            }
            outcomes[i] = simulated_shoe.bankroll;
            average_bankroll += simulated_shoe.bankroll;
            // std::cout << outcomes[i] << std::endl;
        }
        std::cout << std::endl;
        average_bankroll /= 100000;


        // calculate the standard deviation
        std_dev = calculate_standard_deviation(outcomes, average_bankroll, bankroll);

        // return the gain/loss
        return average_bankroll - bankroll;
    }

    double get_std_dev() {
        return std_dev;
    }
}

// g++ -std=c++11 -shared -fPIC -o monte_carlo.dylib monte_carlo.cpp

