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

    Voter* head = nullptr;
    Voter* current = nullptr;

        for (int i = 1; i <= n; i++)
    {
        cout << "Enter your NIDnumber:" << endl;
        cin >> NIDnumber;

        if (NIDnumber <= 50)
        {
            cout << "You can vote..." << endl;
            cout << "List of political parties:" << endl;
            cout << "1.TIGER" << endl;
            cout << "2.LION" << endl;
            cout << "3.BLACK CAT" << endl;

            cout << "Select your political party:" << endl;

            cin >> vote;

            if (vote >= 1 && vote <= 3)
            {
                castVote(vote);

                if (head == nullptr)
                {
                    head = createVoter(NIDnumber, vote);
                    current = head;
                }
                else
                {
                    current->next = createVoter(NIDnumber, vote);
                    current = current->next;
                }
            }
            else
            {
                spoiltVotes++;
            }
        }
        else
        {
            cout << "You can not vote...." << endl;
        }
    }

    cout << "Number of votes for TIGER: " << votes[0] << endl;
    cout << "Number of votes for LION: " << votes[1] << endl;
    cout << "Number of votes for BLACK CAT: " << votes[2] << endl;

    cout << "Number of spoilt votes: " << spoiltVotes << endl;

    string Name;
    string Password;
    int login = 0;

    while (login < 5)
    {
        cout << "Admin user name: ";
        cin >>Name;
        cout << "Please enter your user password: ";
        cin >> Password;

        if (Name == "Shapla" && Password == "Shakib75")
        {
            cout << "Welcome Admin!\n";
            break;
        }

        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            login++;
        }
    }
    if (login == 5)
    {
        cout << "Too many login attempts! The program will now terminate.";
        return 0;
    }

    cout << "******\n";

     announceWinner();

     current = head;
    while (current != nullptr)
    {
        Voter* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;

}
