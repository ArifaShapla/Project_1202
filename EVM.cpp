#include <iostream>
#include <cstdlib>

using namespace std;

struct Voter
{
    int NIDnumber;
    int vote;
    Voter* next;
};
int votes[3] = {0};
int spoiltVotes = 0;

Voter* createVoter(int NIDnumber, int vote)
{
    Voter* newVoter = new Voter;
    newVoter->NIDnumber = NIDnumber;
    newVoter->vote = vote;
    newVoter->next = nullptr;
    return newVoter;
}

class CandidateList
{
private:
    Candidate* head;

public:
    CandidateList() : head(nullptr) {}

    void addCandidate(string name)
    {
        Candidate* newCandidate = new Candidate;
        newCandidate->name = name;
        newCandidate->votes = 0;
        newCandidate->next = head;
        head = newCandidate;
    }
    void displayCandidates()
    {
        Candidate* current = head;
        cout << "Candidates:\n";
        while (current != nullptr)
        {
            cout << current->name << "\n";
            current = current->next;
        }
        cout << endl;
    }

    void vote(string candidateName)
    {
        Candidate* current = head;
        while (current != nullptr)
        {
            if (current->name == candidateName)
            {
                current->votes++;
                cout << "Vote for " << candidateName << " recorded.\n";
                return;
            }
            current = current->next;
        }
        cout << "Candidate not found.\n";
    }
    void displayResults()
    {
        Candidate* current = head;
        cout << "Election Results:\n";
        while (current != nullptr)
        {
            cout << current->name << ": " << current->votes << " votes\n";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
        string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "Admin" && userPassword == "Shakib75")
        {
            cout << "Welcome Admin!\n";
            break;
        }

        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }

    cout << "Thank you for logging in.\n";
    CandidateList candidateList;
    candidateList.addCandidate("TIGER");
    candidateList.addCandidate("LION");
    candidateList.addCandidate("BLACK CAT");

    int choice;
    do
    {

        cout << "1. Display Candidates\n";
        cout << "2. Vote\n";
        cout << "3. Display Results\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            candidateList.displayCandidates();
            break;

        case 2:
        {
            string candidateName;
            cout << "Enter the name of the candidate you want to vote for: ";
            cin.ignore();
            getline(cin, candidateName);
            candidateList.vote(candidateName);
            break;
        }
        case 3:
            candidateList.displayResults();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    while (choice != 4);

    return 0;
}
