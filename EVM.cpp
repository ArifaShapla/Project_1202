#include <iostream>
#include <cstdlib>

using namespace std;

struct Candidate
{
    string name;
    int votes;
    Candidate* next;
};

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

};

int main()
{
    CandidateList candidateList;
    candidateList.addCandidate("Candidate 1");
    candidateList.addCandidate("Candidate 2");
    candidateList.addCandidate("Candidate 3");

    int choice;
    do
    {
        // Display menu
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
            break;
        }
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
