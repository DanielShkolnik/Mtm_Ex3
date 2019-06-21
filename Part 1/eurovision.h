#ifndef EUROVISION_H_
#define EUROVISION_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    explicit Participant(const string& stateName, const string& songName="",int songLength=0,
            const string& singerName="");
    Participant(const Participant& participant) = delete;
    Participant& operator=(const Participant& par) = delete;
    void update(const string& songName, int songLength, const string& singerName);
    string state() const;
    string song() const;
    int timeLength() const;
    string singer() const;
    bool isRegistered() const;
    void updateRegistered(bool setRegistration);
    ~Participant()= default;
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
    explicit Voter(const string& originState, VoterType voterType=Regular); // implement numOfVotes=0
    string state() const;
    VoterType voterType() const;
    int timesOfVotes() const;
    Voter& operator++();
    ~Voter()= default;
};
ostream& operator<<(ostream& os, const Voter& voter);

// -----------------------------------------------------------

struct Vote
{
// ALL is public here.
// need to define ONLY data members and c'tr and d'tr.
// NO NEED to define anything else.
    Voter& voter;
    string* selectedStates;
    Vote(Voter& voter, const string& state1, const string& state2="", const string& state3="", const string& state4="",
         const string& state5="", const string& state6="", const string& state7="", const string& state8="",
         const string& state9="", const string& state10="");
    Vote(const Vote&) = default;
    ~Vote();
};

// -----------------------------------------------------------

class ParticipantScore{
private:
    Participant* participant;
    int regularVotes;
    int judgeVotes;

public:
    ParticipantScore();
    ParticipantScore(const ParticipantScore&) = default;
    ParticipantScore& operator=(const ParticipantScore&) = default;
    void setParticipant(Participant* participant);
    void addRegularVote();
    void addJudgeVote(int place);
    void resetVotes();
    Participant* getParticipant();
    ~ParticipantScore()= default;
    friend ostream& operator<<(ostream& os, const ParticipantScore& participantScore);
    int getRegularVote();
    int getJudgeVote();
};
ostream& operator<<(ostream& os, const ParticipantScore& participantScore);
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
    bool isStateExist(const string& stateName);
    int getFirstEmptyIndex();
    int getParticipantIndexByStateName(string stateName) const;
    void sortParticipantsByStateNames();
    void swapParticipantsByIndex(int participant1,int participant2);
    int getParticipantIndex(const Participant& participant);
    bool predicateByJudge(const ParticipantScore& participantScore1, const ParticipantScore& participantScore2);
    bool predicateByRegular(const ParticipantScore& participantScore1, const ParticipantScore& participantScore2);
    bool predicateByAll(const ParticipantScore& participantScore1, const ParticipantScore& participantScore2);
// need to define here possibly c'tr and d'tr and ONLY methods that
// are mentioned and demonstrated in the test example that has been published.
// NO OTHER METHODS SHOULD APPEAR HERE.
// Also it's allowed here to define friend.
public :
    explicit MainControl(int maxSongLength=180, int maxParticipants=26, int maxRegularTimesToVote=5);
    MainControl& operator+=(Participant& participant);
    MainControl& operator+=(Vote vote);
    void setPhase(Phase phase);
    MainControl& operator-=(const Participant& participant);
    bool legalParticipant(const Participant& participant) const ;
    bool participate(const string& stateName) const ;
    ~MainControl();
    friend ostream& operator<<(ostream& os, MainControl& mainControl);
    class Iterator{
    public:
        Iterator();
        explicit Iterator(ParticipantScore* participantScore);
        Iterator(const Iterator&) = default;
        ~Iterator() = default;
        Iterator& operator=(const Iterator& iterator) = default;
        Iterator& operator++();
        Iterator&operator--() = delete;
        friend bool operator<(const MainControl::Iterator& iterator1, const MainControl::Iterator& iterator2);
        Participant& operator*();
        friend bool operator==(const MainControl::Iterator& iterator1, const MainControl::Iterator& iterator2);
    private:
        ParticipantScore* participantScore;
    };
    Iterator begin();
    Iterator end();
    string operator()(int i, VoterType voterType);
};
bool operator<(const MainControl::Iterator& iterator1, const MainControl::Iterator& iterator2);
bool operator==(const MainControl::Iterator& iterator1, const MainControl::Iterator& iterator2);
ostream& operator<<(ostream& os, const MainControl& mainControl);

// -----------------------------------------------------------

#endif
