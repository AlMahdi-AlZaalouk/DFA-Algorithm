#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Al Mahdi Abdullah Al Zaalouk
// Language for even numbers by binary numbers {'0', '1'}

using namespace std;
class DFA {
private:

    enum State {
        q0, q1
    };

    // Alphabet
    vector<char> L = {'0', '1'};

    State transitionFunction(State currentState, char symbol) {
        switch (currentState) {
            case q0:
                return (symbol == '0') ? q1 : q0;
            case q1:
                return (symbol == '0') ? q1 : q0;
            default:
                return q0;
        }
    }

    State startState = q0;

    vector<State> finalState = {q1};

    bool isFinalState(State state) {
        for (auto acceptingState : finalState) {
            if (state == acceptingState) {
                return true;
            }
        }
        return false;
    }

public:

    bool isAccepted(const string& inputString) {
        State currentState = startState;
        for (char symbol : inputString) {
            if (find(L.begin(), L.end(), symbol) == L.end()) {
                cout << "Invalid symbol encountered." << endl;
                return false;
            }
            currentState = transitionFunction(currentState, symbol);
        }

        return isFinalState(currentState);
    }
};

int main() {
    DFA dfa;
    string inputString;

    cout << "Enter the string to test: ";
    cin >> inputString;

    if (dfa.isAccepted(inputString)) {
        cout << "The string is accepted by the DFA." << endl;
    } else {
        cout << "The string is rejected by the DFA." << endl;
    }

    return 0;
}
