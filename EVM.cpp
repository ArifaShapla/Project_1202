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

void castVote(int vote)
{
    if (vote >= 1 && vote <= 3)
    {
        votes[vote - 1]++;
    }
    else
    {
        spoiltVotes++;
    }
}

void announceWinner()
{
    int maxVotesIndex = 0;
    for (int i = 1; i < 3; i++)
    {
        if (votes[i] > votes[maxVotesIndex])
        {
            maxVotesIndex = i;
        }
    }

    cout << "The winner is: ";
    switch (maxVotesIndex)
    {
    case 0:
        cout << "TIGER";
        break;
    case 1:
        cout << "LION";
        break;
    case 2:
        cout << "BLACK CAT";
        break;
    default:
        cout << "No winner";
    }
    cout << " with " << votes[maxVotesIndex] << " votes." << endl;
}



int main()
{
        string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Admin user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "Shapla" && userPassword == "Shakib75")
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
    int n, NIDnumber, vote;
    cout << "Admin..plz..Enter the number of voters:" << endl;
    cin >> n;
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
