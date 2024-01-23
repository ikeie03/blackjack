#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

class BlackjackGame {
    public:
    int num_decks;
    int curr_card_idx = 0;
    double count = 0.0;
    double betting_unit;
    double bankroll;
    int cut_cards;
    bool can_continue = true;
    std::vector<double> values;
    std::vector<int> shoe;

    BlackjackGame(
        int num_decks, std::vector<double> values, double betting_unit, double bankroll
    );


    static bool hit(int dealer, std::vector<int>& player_hand);
    static bool double_down(int dealer, std::vector<int>& player_hand);
    static bool surrender(int dealer, std::vector<int>& player_hand);
    static bool split_pairs(int dealer, std::vector<int>& player_hand);

    void helper_hand(int dealer, std::vector<int> player_hand, double bet, bool post_split);

    static int hardTotal(std::vector<int>& player_hand);
    static int softTotal(std::vector<int>& player_hand);

    int deal_card();
    void play_hand();

    double trueCount();

    static std::vector<std::vector<char>> hard_array;

    static std::vector<std::vector<char>> soft_array;

    static std::vector<std::vector<char>> split_array;

};

#endif