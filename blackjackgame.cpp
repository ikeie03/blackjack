#include <vector>
#include <random>
#include <iostream>
#include "blackjackgame.h"

std::vector<std::vector<char>> BlackjackGame::hard_array = {
    {'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'},
    {'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'},
    {'Z', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'H', 'H', 'H'},
    {'Z', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'},
    {'Z', 'H', 'H', 'H', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
    {'Z', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
    {'Z', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
    {'Z', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
    {'Z', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'}
};

std::vector<std::vector<char>> BlackjackGame::soft_array = {
    {'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'},
    {'Z', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'D', 'D', 'D', 'D', 'S', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'S', 'E', 'E', 'E', 'S', 'S', 'H', 'H', 'H', 'H'},
    {'Z', 'S', 'S', 'S', 'S', 'S', 'E', 'S', 'S', 'S', 'S', 'S'},
    {'Z', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
    {'Z', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'}
};

std::vector<std::vector<char>> BlackjackGame::split_array = {
    {'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'},
    {'Z', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'Z', 'H', 'H', 'P', 'P', 'P', 'P', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'P', 'P', 'P', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'H', 'H', 'H'},
    {'Z', 'H', 'P', 'P', 'P', 'P', 'H', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'H', 'P', 'P', 'P', 'P', 'P', 'H', 'H', 'H', 'H', 'H'},
    {'Z', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'Z', 'S', 'P', 'P', 'P', 'P', 'S', 'P', 'P', 'S', 'S', 'S'},
    {'Z', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
    {'Z', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}
};

BlackjackGame::BlackjackGame(
    int num_decks, std::vector<double> values, double betting_unit, double bankroll
    ) : num_decks(num_decks), values(values), betting_unit(betting_unit), bankroll(bankroll) {

    std::vector<int> deck = {
        1,1,1,1,
        2,2,2,2,
        3,3,3,3,
        4,4,4,4,
        5,5,5,5,
        6,6,6,6,
        7,7,7,7,
        8,8,8,8,
        9,9,9,9,
        10,10,10,10,
        10,10,10,10,
        10,10,10,10,
        10,10,10,10
    };
    for (int i = 0; i < num_decks; i++) {
        shoe.insert(shoe.end(), deck.begin(), deck.end());
    }

    // shuffle the deck
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(shoe.begin(), shoe.end(), g);

    // cut the deck
    std::uniform_int_distribution<int> dist(40, 50);
    cut_cards = dist(g);
}

bool BlackjackGame::surrender(int dealer, std::vector<int>& player_hand) {
    int player_sum = 0;
    for (int i = 0; i < int(player_hand.size()); i++) {
        if (player_hand[i] == 1) {
            return false;
        } else {
            player_sum += player_hand[i];
        }
    }
    // surrender only on 15 vs 10 or 16 vs 9,10,A
    if (player_sum == 15 && dealer == 10) {
        return true;
    }
    if (player_sum == 16) {
        if (dealer == 9 || dealer == 10 || dealer == 1) {
            return true;
        }
    }
    return false;
}

bool BlackjackGame::split_pairs(int dealer, std::vector<int>& player_hand) {
    if (player_hand.size() != 2 || player_hand[0] != player_hand[1]) {
        // making sure its a pair
        return false;
    } else if (split_array[player_hand[0]][dealer] == 'P'){
        // if the strategy chart says split
        return true;
    } else {
        return false;
    }
}

int BlackjackGame::hardTotal(std::vector<int>& player_hand) {
    int hard_total = 0;
    for (size_t i = 0; i < player_hand.size(); i++) {
        if (player_hand[i] == 1) {
            hard_total += 1;
        } else {
            int card = player_hand[i];
            hard_total += card;
        }
    }
    return hard_total;
}

int BlackjackGame::softTotal(std::vector<int>& player_hand) {
    int soft_total = 0;
    for (size_t i = 0; i < player_hand.size(); i++) {
        if (player_hand[i] == 1) {
            soft_total += 11;
        } else {
            int card = player_hand[i];
            soft_total += card;
        }
    }
    return soft_total;
}

bool BlackjackGame::double_down(int dealer, std::vector<int>& player_hand) {
    int soft_total = softTotal(player_hand);
    int hard_total = hardTotal(player_hand);

    if (soft_total == hard_total && hard_total <= 21) {
        // use the hard total array
        return (hard_array[hard_total][dealer] == 'D' || hard_array[hard_total][dealer] == 'E');
    } else if (soft_total <= 21) {
        // use the soft total array
        int total_without_aces = soft_total - 11;
        return (soft_array[total_without_aces][dealer] == 'D' || soft_array[total_without_aces][dealer] == 'E');
    } else {
        // bust: stand
        return false;
    }
}

bool BlackjackGame::hit(int dealer, std::vector<int>& player_hand) {
    int soft_total = softTotal(player_hand);
    int hard_total = hardTotal(player_hand);

    // bust
    if (hard_total > 21) {
        return false;
    }

    if (soft_total == hard_total || soft_total > 21) {
        // use hard total array if there are no aces or the soft_total is bust
        return (hard_array[hard_total][dealer] == 'H' || hard_array[hard_total][dealer] == 'D');
    } else {
        // use soft total array
        int total_without_aces = soft_total - 11;
        return (soft_array[total_without_aces][dealer] == 'D' || soft_array[total_without_aces][dealer] == 'H');
    }
}

double BlackjackGame::trueCount() {
    int total_cards = num_decks * 52;
    int cards_remaining = total_cards - curr_card_idx;
    double decks_remaining = cards_remaining / 52.0;
    double true_count = count / decks_remaining;
    return true_count;
}

void BlackjackGame::play_hand() {
    // dealer shows one card
    int dealer_card = deal_card();

    // bet size based on the count
    double bet_size = betting_unit * bankroll;
    if (this->trueCount() > 1.0) {
        bet_size *= this->trueCount();
    }
    // std::cout << "COUNT " << this->trueCount() << " BET " << bet_size << std::endl;

    // player gets two cards
    std::vector<int> player_hand;
    player_hand.push_back(deal_card());
    player_hand.push_back(deal_card());

    helper_hand(dealer_card, player_hand, bet_size, false);
}

void BlackjackGame::helper_hand(int dealer, std::vector<int> player_hand, double bet, bool post_split) {
    double curr_bankroll = bankroll;
    // decide whether to surrender (not allowed after split)
    // if (!post_split && surrender(dealer, player_hand)) {
    //     bankroll -= (bet / 2);
    //     // std::cout << "SURRENDER " << "dealer " << dealer << "hand " << player_hand[0] << " " << player_hand[1] << std::endl;
    //     return;
    // }
    // many casinos don't allow surrenders and it's rarely optimal anyway, so might remove this

    // decide whether to split (not allowed after split)
    if (!post_split && split_pairs(dealer, player_hand)) {
        // std::cout << "SPLIT " << "dealer " << dealer << "hand " << player_hand[0] << " " << player_hand[1] << std::endl;
        std::vector<int> new_hand1 = {player_hand[0], deal_card()};
        std::vector<int> new_hand2 = {player_hand[1], deal_card()};
        helper_hand(dealer, new_hand1, bet, true);
        helper_hand(dealer, new_hand2, bet, true);
        return;
    }

    // decide whether to double down (not allowed after split)
    if (!post_split && double_down(dealer, player_hand)) {
        // std::cout << "DOUBLE DOWN " << "dealer " << dealer << "hand " << player_hand[0] << " " << player_hand[1] << std::endl;
        bet *= 2;
    }

    // hit until stand
    while (hit(dealer, player_hand)) {
        // std::cout << "HIT " << "dealer " << dealer << " hand ";
        // for (int card : player_hand) {
        //     std::cout << card << " ";
        // }
        // std::cout << std::endl;
        player_hand.push_back(deal_card());
    }
    // std::cout << "STAND " << "dealer " << dealer << " hand ";
    // for (int card : player_hand) {
    //     std::cout << card << " ";
    // }
    // std::cout << std::endl;

    // dealer reveals cards
    int hole_card = deal_card();
    std::vector<int> dealer_hand = {dealer, hole_card};
    int dealer_hard_total = hardTotal(dealer_hand);
    int dealer_soft_total = softTotal(dealer_hand);
    int dealer_total = (dealer_soft_total > 21) ? dealer_hard_total : dealer_soft_total;
    while (dealer_total < 17) {
        dealer_hand.push_back(deal_card());
        dealer_hard_total = hardTotal(dealer_hand);
        dealer_soft_total = softTotal(dealer_hand);
        dealer_total = (dealer_soft_total > 21) ? dealer_hard_total : dealer_soft_total;
    }


    // determine outcome
    int soft_total = softTotal(player_hand);
    int hard_total = hardTotal(player_hand);
    int hand_total = (soft_total > 21) ? hard_total : soft_total;

    if (hand_total > 21) {
        // bust, lose
        bankroll -= bet;
    } else if (dealer_total > 21 || hand_total > dealer_total) {
        // player wins
        if ((player_hand.size() == 2) && (hand_total == 21) && (dealer_total != 21 || dealer_hand.size() != 2)) {
            // blackjack
            bankroll += (1.5 * bet);
        } else {
            bankroll += bet;
        }
    } else if (dealer_total > hand_total) {
        // dealer wins
        bankroll -= bet;
    } else {
        // draw, no change
    }

    // std::cout << "player ";
    // for (int i = 0; i < player_hand.size(); i++) {
    //     std::cout << player_hand[i] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "dealer ";
    // for (int i = 0; i < dealer_hand.size(); i++) {
    //     std::cout << dealer_hand[i] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "result: " << bankroll - curr_bankroll << std::endl;

}

int BlackjackGame::deal_card() {
    int card = shoe[curr_card_idx];
    curr_card_idx++;
    if (curr_card_idx >= (int(shoe.size()) - cut_cards)) {
        can_continue = false;
    }

    // update the count
    count += values[card];

    return card;
}














/*
void BlackjackGame::helper_hand(int dealer, std::vector<std::vector<int>>& player_hands, std::vector<double>& bets) {
    // for each hand, decide whether to surrender
    std::vector<int> idxs_to_remove;
    for (int i = 0; i < int(player_hands.size()); i++) {
        std::vector<int> hand = player_hands[i];
        if (surrender(dealer, hand)) {
            double bet = bets[i];
            bankroll -= (bet / 2.0);
            idxs_to_remove.push_back(i);
        }
    }
    // remove the surrendered hands
    for (int i = int(idxs_to_remove - 1); i > -1; i--) {
        int index = idxs_to_remove[i];
        player_hands.erase(player_hands.begin() + index);
        bets.erase(bets.begin() + index);
        // indicate a hand was played
        hands_count++;
    }

    // see whether to split each hand or not
    std::vector<std::vector<int>> hands_to_add;
    for (int i = 0; i < int(player_hands.size()); i++) {
        std::vector<int>& hand = player_hands[i];
        double bet = bets[i];
        if (split_pairs(dealer, hand)) {
            // mark this hand for removal and add two more 
            player_hands.erase(player_hands.begin() + i);
            bets.erase(bets.begin() + i);
            // new hands
            std::vector<int> first_hand = {hand[0], deal_card()};
            std::vector<int> second_hand = {hand[1], deal_card()};
            player_hands.push_back(first_hand);
            bets.push_back(bet);
            player_hands.push_back(second_hand);
            bets.push_back(bet);
            // recur (in case we need to split or surrender again)
            helper_hand(dealer, player_hands, bets);
            return;
        }
    }

    // decide whether to double down
    for (int i = 0; i < int(player_hands.size()); i++) {
        std::vector<int> hand = player_hands[i];
        if (double_down(dealer, hand)) {
            bets[i] *= 2;
        }
    }

    // now the only thing to do is hit until all decks stand
    for (int i = 0; i < int(player_hands.size()); i++) {
        std::vector<int>& hand = player_hands[i];
        while (hit(dealer, hand)) {
            int new_card = deal_card();
            hand.push_back(new_card);
        }
    }


    // reveal dealer card
    int hole_card = deal_card();
    int dealer_total = hole_card + dealer;
    while (dealer_total < 17) {
        dealer_total += deal_card();
    }

    // determine the outcome of all our hands
    // add the winnings from each hand
    // subtract the amount bet on each hand
    // modify the bankroll

    for (size_t i = 0; i < player_hands.size(); i++) {
        std::vector<int>& hand = player_hands[i];
        int soft_total = softTotal(hand);
        int hard_total = hardTotal(hand);
        int hand_total = (soft_total > 21) ? hard_total : soft_total;

        if (hand_total > 21) {
            if (dealer_total < 21) {
                // player busts, loses
                bankroll -= bets[i];
            }
            // otherwise both bust (no change)
        } else if (dealer_total > 21 || hand_total > dealer_total) {
            // player wins
            bankroll += bets[i];
        } else if (hand_total < dealer_total) {
            // dealer wins
            bankroll -= bets[i];
        }
        // otherwise tie (no change)
        
        hands_count++;
    }
}
*/