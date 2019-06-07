#ifndef EUROVISION_H_
#define EUROVISION_H_

#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::cout;
using std::ostream;

// it's allowed to define here any using statements, according to needs.
// do NOT define here : using namespace std;

//---------------------------------------------------

enum VoterType { All, Regular, Judge };
enum Phase { Registration, Contest, Voting };

//---------------------------------------------------

class Participant
{
// relevant private members can be defined here, if necessary.
private :
    const string stateName;
    string songName;
    string singerName;
    int songLength;
    bool registered;

// need to define here possibly c'tr and d'tr and ONLY methods that
// are mentioned and demonstrated in the test example that has been published.
// NO OTHER METHODS SHOULD APPEAR HERE.
// NO friend is allowed here.
public :
    explicit Participant(string stateName, string songName="", string singerName="", int songLength=0);
    Participant(const Participant& participant) = delete;
    Participant& operator=(const Participant& par) = delete;
    void update(string songName, int songLength, string singerName);
    string state() const;
    string song() const;
    int timeLength() const;
    string singer() const;
    bool isRegistered() const;
    void updateRegistered(bool setRegistration);
    ~Participant();
};
ostream& operator<<(ostream& os, const Participant& participant);

//---------------------------------------------------

class Voter
{
// relevant private members can be defined here, if necessary.
private :
    string originState;
    VoterType typeOfVoter;
    int numOfVotes;

// need to define here possibly c'tr and d'tr and ONLY methods that
// are mentioned and demonstrated in the test example that has been published.
// NO OTHER METHODS SHOULD APPEAR HERE.
// NO friend is allowed here.
public :
    Voter(string originState, VoterType voterType=Regular); // implement numOfVotes=0
    string state() const;
    VoterType voterType() const;
    int timesOfVotes() const;
    Voter& operator++();
    ~Voter();
};
ostream& operator<<(ostream& os, const Voter& voter);

// -----------------------------------------------------------

struct Vote
{
// ALL is public here.
// need to define ONLY data members and c'tr and d'tr.
// NO NEED to define anything else.
    Voter voter;
    string* selectedStates;
    Vote(Voter voter, string state1, string state2="", string state3="", string state4="", string state5="",
         string state6="", string state7="", string state8="", string state9="", string state10="");
    ~Vote();
};

// -----------------------------------------------------------

class ParticipantScore{
private:
    const Participant* participant;
    int regularVotes;
    int judgeVotes;

public:
    ParticipantScore();
    void setParticipant(const Participant* participant);
    void addRegularVote();
    void addJudgeVote(int place);
    void resetVotes();
    const Participant* getParticipant();
    ~ParticipantScore();
};

// -----------------------------------------------------------

class MainControl
{
// relevant private members can be defined here, if necessary.
private :
    Phase phase;
    ParticipantScore* participantScores;
    int maxSongLength;
    int maxParticipants;
    int maxRegularTimesToVote;
    bool isStateExist(string stateName);
    int getFirstEmptyIndex();
    int getParticipantIndexByStateName(string stateName) const ;
// need to define here possibly c'tr and d'tr and ONLY methods that
// are mentioned and demonstrated in the test example that has been published.
// NO OTHER METHODS SHOULD APPEAR HERE.
// Also it's allowed here to define friend.
public :
    explicit MainControl(int maxSongLength=180, int maxParticipants=26, int maxRegularTimesToVote=5);
    MainControl& operator+=(const Participant& participant);
    MainControl& operator+=(Vote& vote);
    void setPhase(Phase phase);
    MainControl& operator-=(const Participant& participant);
    bool legalParticipant(const Participant& participant) const ;
    bool participate(string stateName) const ;
    ~MainControl();
};
ostream& operator<<(ostream& os, const MainControl& mainControl);

// -----------------------------------------------------------

#endif
