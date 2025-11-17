#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Question {
    string question;
    string opt1, opt2, opt3, opt4;
    char correctAns;
};

int askQuestion(const Question &q) {
    char ans;
    cout << "\n" << q.question << endl;
    cout << "A. " << q.opt1 << endl;
    cout << "B. " << q.opt2 << endl;
    cout << "C. " << q.opt3 << endl;
    cout << "D. " << q.opt4 << endl;
    cout << "Enter your answer (A/B/C/D): ";
    cin >> ans;

    while (!(ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D' ||
             ans == 'a' || ans == 'b' || ans == 'c' || ans == 'd')) {
        cout << "Invalid input. Please enter A, B, C, or D: ";
        cin >> ans;
    }

    if (ans == q.correctAns || ans == q.correctAns + 32) {
        cout << "Correct!\n";
        return 1;
    } else {
        cout << "Wrong! Correct answer: " << q.correctAns << "\n";
        return 0;
    }
}

void showResult(const string &name, int score, int total) {
    cout << "\n--- Test Completed ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Your total score: " << score << "/" << total << endl;

    if (score == total)
        cout << "Excellent! Perfect score!\n";
    else if (score >= total * 0.7)
        cout << "Very Good!\n";
    else if (score >= total * 0.5)
        cout << "Good! Keep practicing.\n";
    else
        cout << "Try again, you'll improve!\n";
}

int main() {
    string name;
    int roll, choice, score = 0;

    cout << "==============================\n";
    cout << "         QUIZ APPLICATION      \n";
    cout << "==============================\n";

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your roll number: ";
    cin >> roll;

    cout << "\nSelect Quiz Category:\n";
    cout << "1. Math Quiz\n";
    cout << "2. General Knowledge Quiz\n";
    cout << "Enter choice (1/2): ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Question mathQuiz[10] = {
        {"What is 5 + 3?", "6", "7", "8", "9", 'C'},
        {"What is 12 / 4?", "3", "4", "5", "6", 'A'},
        {"What is 9 * 2?", "16", "17", "18", "19", 'C'},
        {"What is the square of 6?", "36", "30", "25", "49", 'A'},
        {"What is 15 - 7?", "6", "7", "8", "9", 'C'},
        {"What is cube of 3?", "6", "9", "27", "81", 'C'},
        {"Addition of 20 + 50?", "5", "70", "15", "20", 'B'},
        {"Which is a prime number?", "4", "6", "9", "11", 'D'},
        {"Square of 5?", "15", "25", "45", "30", 'B'},
        {"Subtraction of 70 - 30?", "50", "30", "40", "10", 'C'}
    };

    Question gkQuiz[10] = {
        {"Which planet is known as the Red Planet?", "Earth", "Mars", "Venus", "Jupiter", 'B'},
        {"Who wrote the National Anthem of India?", "Rabindranath Tagore", "Mahatma Gandhi", "Bankim Chandra", "Sarojini Naidu", 'A'},
        {"What is the capital of Japan?", "Beijing", "Tokyo", "Seoul", "Bangkok", 'B'},
        {"Who is known as the Father of Computers?", "Charles Babbage", "Alan Turing", "Newton", "Einstein", 'A'},
        {"Which is the largest ocean?", "Indian", "Atlantic", "Pacific", "Arctic", 'C'},
        {"What is the national animal of India?", "Elephant", "Lion", "Tiger", "Peacock", 'C'},
        {"Who was the first President of India?", "Rajendra Prasad", "Nehru", "Gandhi", "Ambedkar", 'A'},
        {"Which country gifted the Statue of Liberty to the USA?", "England", "France", "Italy", "Germany", 'B'},
        {"Which festival is known as the festival of lights?", "Holi", "Eid", "Diwali", "Christmas", 'C'},
        {"What is the smallest planet in our solar system?", "Mercury", "Mars", "Venus", "Pluto", 'A'}
    };

    int totalQuestions = 10;

    cout << "\n--- Starting Quiz ---\n";

    if (choice == 1) {
        for (int i = 0; i < totalQuestions; i++)
            score += askQuestion(mathQuiz[i]);
    } else if (choice == 2) {
        for (int i = 0; i < totalQuestions; i++)
            score += askQuestion(gkQuiz[i]);
    } else {
        cout << "Invalid choice! Exiting program.\n";
        return 0;
    }

    showResult(name, score, totalQuestions);

    cout << "\nThank you for participating, " << name << "!\n";

    return 0;
}
