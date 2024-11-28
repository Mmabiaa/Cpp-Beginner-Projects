#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>

using namespace std;

// Function to create dice faces
map<int, string> create_dice() {
    map<int, string> dice_faces;
    dice_faces[1] = R"(
+-------+
|   1   |
|   ●   |
|       |
+-------+
)";
    dice_faces[2] = R"(
+-------+
| ●     |
|   2   |
|     ● |
+-------+
)";
    dice_faces[3] = R"(
+-------+
| ●  3  |
|   ●   |
|     ● |
+-------+
)";
    dice_faces[4] = R"(
+-------+
| ●   ● |
|   4   |
| ●   ● |
+-------+
)";
    dice_faces[5] = R"(
+-------+
| ● 5 ● |
|   ●   |
| ●   ● |
+-------+
)";
    dice_faces[6] = R"(
+-------+
| ●   ● |
| ● 6 ● |
| ●   ● |
+-------+
)";
    return dice_faces;
}

// Function to get valid number of players
int get_number_of_players() {
    int players;
    while (true) {
        cout << "Enter the number of players (2-4): ";
        cin >> players;
        if (players >= 2 && players <= 4) {
            break;
        } else {
            cout << "Please enter a valid number of players (2-4)." << endl;
        }
    }
    return players;
}

// Function to handle a player's dice roll
int roll_dice(map<int, string>& dice_faces) {
    int roll_value = rand() % 6 + 1;  // Roll the dice (1-6)
    cout << "You rolled: " << roll_value << endl;
    cout << dice_faces[roll_value] << endl;  // Display the dice face
    return roll_value;
}

// Function to update player's score after rolling the dice
void update_score(int roll_value, vector<int>& player_scores, int current_player) {
    player_scores[current_player] += roll_value;  // Add roll to the player's total score
    cout << "Player " << current_player + 1 << "'s current score: " << player_scores[current_player] << endl;
}

// Function to check if a player has won the game
bool check_winner(vector<int>& player_scores, int max_score) {
    for (int i = 0; i < player_scores.size(); i++) {
        if (player_scores[i] >= max_score) {
            cout << "\nPlayer " << i + 1 << " wins with " << player_scores[i] << " points!" << endl;
            return true;  // Return true if there's a winner
        }
    }
    return false;  // Return false if no one has won yet
}

// Function to handle the player's turn
bool player_turn(int current_player, vector<int>& player_scores, map<int, string>& dice_faces, int max_score) {
    string roll_option;
    cout << "Player " << current_player + 1 << ", would you like to roll (y/n): ";
    cin >> roll_option;
    if (roll_option == "n") {
        cout << "Player " << current_player + 1 << " has chosen to skip their turn." << endl;
    } else if (roll_option == "y") {
        int total_roll = 0;
        int roll_value = roll_dice(dice_faces);  // Roll the dice and get the roll value
        total_roll += roll_value;

        // Check if player rolled a 6 and allow a bonus roll
        while (roll_value == 6) {
            cout << "Bonus Roll! You rolled a 6, roll again!" << endl;
            roll_value = roll_dice(dice_faces);  // Bonus roll
            total_roll += roll_value;
        }

        update_score(total_roll, player_scores, current_player);  // Update the score based on the total rolls

        if (check_winner(player_scores, max_score)) {  // Check if the player has won
            return true;  // If someone won, end the game
        }
    } else {
        cout << "Invalid input. Please enter 'y' to roll or 'n' to skip the turn." << endl;
    }
    return false;  // Continue game if no one has won
}

// Function to display current scores of all players
void display_scores(const vector<int>& player_scores) {
    cout << "\nCurrent scores:" << endl;
    for (int i = 0; i < player_scores.size(); i++) {
        cout << "Player " << i + 1 << ": " << player_scores[i] << " points" << endl;
    }
}

// Main game loop
void roll() {
    int max_score = 20;  // Set the maximum score to 20
    int players = get_number_of_players();  // Get the number of players
    vector<int> player_scores(players, 0);  // Initialize a list to store each player's score
    map<int, string> dice_faces = create_dice();  // Create dice faces

    // Game loop
    while (true) {
        for (int current_player = 0; current_player < players; current_player++) {
            cout << "\nPlayer " << current_player + 1 << "'s turn" << endl;

            if (player_turn(current_player, player_scores, dice_faces, max_score)) {  // Check if someone won
                return;  // End the game if there's a winner
            }

            display_scores(player_scores);  // Display updated scores after each turn
        }
    }
}

// Start the game
int main() {
    srand(time(0));  // Seed the random number generator
    roll();
    cout << "Game Over!😁👌" << endl;
    return 0;
}
