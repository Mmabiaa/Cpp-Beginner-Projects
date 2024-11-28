#include <iostream>
#include <map>
#include <string>
#include <iomanip>  // For setting precision in percentage output

using namespace std;

// Function to store quiz questions and answers and return quiz and score
void Quiz_Question(int& score, map<string, pair<string, string>>& quiz) {
    score = 0;

    // Initializing quiz questions and answers
    quiz["questions 1"] = make_pair("What is the capital of France?: ", "Paris");
    quiz["questions 2"] = make_pair("What is the capital of Germany?: ", "Berlin");
    quiz["questions 3"] = make_pair("What is the capital of Canada?: ", "Toronto");
    quiz["questions 4"] = make_pair("What is the capital of Italy?: ", "Rome");
    quiz["questions 5"] = make_pair("What is the capital of Spain?: ", "Madrid");
    quiz["questions 6"] = make_pair("What is the capital of Portugal?: ", "Lisbon");
    quiz["questions 7"] = make_pair("What is the capital of Switzerland?: ", "Bern");
    quiz["questions 8"] = make_pair("What is the capital of Netherlands?: ", "Amsterdam");
    quiz["questions 9"] = make_pair("What is the capital of Austria?: ", "Vienna");
    quiz["questions 10"] = make_pair("What is the capital of Russia?: ", "Moscow");
}


string capitalize_first_letter(string str) {
    if (!str.empty()) {
        str[0] = toupper(str[0]);  // Convert the first letter to uppercase
        for (size_t i = 1; i < str.length(); ++i) {
            str[i] = tolower(str[i]);  // Convert the rest of the string to lowercase
        }
    }
    return str;
}
// Function to display quiz and results
void display_Quiz(map<string, pair<string, string>>& quiz, int& score) {
    string user_answer;
    for (const auto& entry : quiz) {
        // Display the question
        cout << entry.second.first;

        // Get the user's answer
        cout << "Your answer: ";
        cin >> user_answer;

        // Capitalize the first letter of the user's answer
        user_answer = capitalize_first_letter(user_answer);

        // Check the answer and display the result
        if (user_answer == entry.second.second) {
            cout << "Correct!" << endl;
            score++;
            cout << "Your Score = " << score << "" << endl;
        } else {
            cout << "Wrong!" << endl;
            cout << "Correct Answer = " << entry.second.second << endl;
            cout << "Your Score = " << score << "" << endl;
        }
        cout << endl;
    }

    // Display final score and percentage
    cout << "\nTotal = " << score << " / 10" << endl;
    double percentage = (static_cast<double>(score) / 10) * 100;
    cout << "Percentage = " << fixed << setprecision(2) << percentage << "%" << endl;
    cout << "\nThanks for participating..." << endl;
}

int main() {
    int score;
    map<string, pair<string, string>> quiz;
    cout<<"---Welcome to the City Quiz---"<<endl;
    cout<< "-------------------------------- \n";

    // Get quiz questions and answers
    Quiz_Question(score, quiz);

    // Display the quiz and results
    display_Quiz(quiz, score);

    return 0;
}
