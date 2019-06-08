
#include "eurovision.h"

//*************************MAIN CONTROL**************************************
#define MAX_JUDGE_VOTES 10
#define FULL -1
#define NOT_IN_ARRAY -1
MainControl::MainControl(int maxSongLength, int maxParticipants, int maxRegularTimesToVote):
                        phase(Registration),participantScores(new ParticipantScore[maxParticipants]){
    this->maxSongLength=maxSongLength;
    this->maxParticipants=maxParticipants;
    this->maxRegularTimesToVote=maxRegularTimesToVote;
}
MainControl& MainControl::operator+=(const Participant& participant){
    if(this->isStateExist(participant.state())){
        return *this;
    }
    int index = this->getFirstEmptyIndex();
    if(index >= 0){
        this->participantScores[index].setParticipant(&participant);
    }
    return *this;
}

MainControl& MainControl::operator+=(Vote vote){
    if(vote.voter.voterType()==Regular && vote.voter.timesOfVotes() < this->maxRegularTimesToVote){
        if(vote.selectedStates[0]==vote.voter.state()){
            return *this;
        }
        int index = this->getParticipantIndexByStateName(vote.selectedStates[0]);
        if(index >= 0) {
            this->participantScores[index].addRegularVote();
        }
        ++(vote.voter);
    }
    if(vote.voter.timesOfVotes() < 1){
        for(int i=0;i<MAX_JUDGE_VOTES;i++){
            if(vote.selectedStates[i] != vote.voter.state()){
                int index = this->getParticipantIndexByStateName(vote.selectedStates[i]);
                if(index >= 0){
                    this->participantScores[index].addJudgeVote(i);
                }
            }
        }
        ++(vote.voter);
    }
    return *this;
}

void MainControl::setPhase(Phase phase){}

MainControl& MainControl::operator-=(const Participant& participant){
    int index = this->getParticipantIndexByStateName(participant.state());
    if(index >= 0){
        this->participantScores[index].setParticipant(nullptr);
        this->participantScores[index].resetVotes();
    }
    return *this;
}

MainControl::~MainControl(){
    delete[] this->participantScores;
}

bool MainControl::isStateExist(string stateName){
    return (this->getParticipantIndexByStateName(stateName) >= 0);
}
int MainControl::getFirstEmptyIndex(){
    for(int i=0;i<this->maxParticipants;i++){
        if(this->participantScores[i].getParticipant() == nullptr){
            return i;
        }
    }
    return FULL;
}

int MainControl::getParticipantIndexByStateName(string stateName) const {
    for(int i=0;i<this->maxParticipants;i++){
        if(this->participantScores[i].getParticipant()->state()==stateName){
            return i;
        }
    }
    return NOT_IN_ARRAY;
}

bool MainControl::legalParticipant(const Participant& participant) const{
    if(participant.state()=="" || participant.song()=="" || participant.timeLength() > this->maxSongLength){
        return false;
    }
    return true;
}
bool MainControl::participate(string stateName) const{
    return (this->getParticipantIndexByStateName(stateName)>=0);
}

void MainControl::sortParticipantsByStateNames(){
    for(int i=0; i<this->maxParticipants; i++) {
        for(int j=0; j<this->maxParticipants; j++){

        }
    }
}
void MainControl::swapParticipantsByIndex(int participantScore1,int participantScore2){
    ParticipantScore temp = this->participantScores[participantScore1];
    this->participantScores[participantScore1] = this->participantScores[participantScore2];
    this->participantScores[participantScore2] = temp;
}

ostream& operator<<(ostream& os, const MainControl& mainControl){

    if (mainControl.phase==Registration){
        os << Registration << endl;
    }

}

//*************************Participant**************************************

Participant::Participant(const string& stateName, const string& songName,int songLength,
                         const string& singerName):
                         stateName(stateName) {
    this->songName= songName;
    this->singerName=singerName;
    this->songLength=songLength;
    this->registered= false;
}

void Participant::update(string songName, int songLength, string singerName){
    if (!this->registered){
        this->songName=songName;
        this->songLength=songLength;
        this->singerName=singerName;
    }
}

string Participant::state() const{
    return this->stateName;
}

string Participant::song() const{
    return this->songName;
}

int Participant::timeLength() const{
    return this->songLength;
}

string Participant::singer() const{
    return this->singerName;
}

bool Participant::isRegistered() const {
    return this->registered;
}

void Participant::updateRegistered(bool setRegistration){
    this->registered=setRegistration;
}

ostream& operator<<(ostream& os, const Participant& participant){
    return os << '[' << participant.state() << '/' << participant.song() << '/' << participant.timeLength()
                << '/' << participant.singer() << '/' << ']';
}


//*************************Voter**************************************

Voter::Voter(string originState, VoterType voterType){
    this->originState=originState;
    this->typeOfVoter=voterType;
    this->numOfVotes=0;
}

string Voter::state() const {
    return this->originState;
}

VoterType Voter::voterType() const {
    return this->typeOfVoter;
}

int Voter::timesOfVotes() const{
    return this->numOfVotes;
}

Voter& Voter::operator++(){
    this->numOfVotes+=1;
    return *this;
}

ostream& operator<<(ostream& os, const Voter& voter){
    return os << '<' << voter.state() << '/' << voter.voterType()  << '>';
}

//*************************Vote**************************************

Vote::Vote(Voter voter, string state1, string state2, string state3, string state4, string state5,
        string state6, string state7, string state8, string state9, string state10):
        voter(voter.state(),voter.voterType()), selectedStates(new string[MAX_JUDGE_VOTES]) {
    this->selectedStates[0]=state1;
    this->selectedStates[1]=state2;
    this->selectedStates[2]=state3;
    this->selectedStates[3]=state4;
    this->selectedStates[4]=state5;
    this->selectedStates[5]=state6;
    this->selectedStates[6]=state7;
    this->selectedStates[7]=state8;
    this->selectedStates[8]=state9;
    this->selectedStates[9]=state10;
}

Vote::~Vote(){
    delete[] selectedStates;
}

//*************************ParticipantScore**************************************

ParticipantScore::ParticipantScore(){
    this->participant= nullptr;
    this->regularVotes=0;
    this->judgeVotes=0;
}

void ParticipantScore::setParticipant(const Participant* participant){
    this->participant=participant;
}

void ParticipantScore::addRegularVote(){
    this->regularVotes+=1;
}

void ParticipantScore::addJudgeVote(int place){
    if (place==0) {
        this->judgeVotes+=12;
    }
    else if (place==1) {
        this->judgeVotes+=10;
    }
    else {
        this->judgeVotes+=(10-place);
    }
}

void ParticipantScore::resetVotes(){
    this->regularVotes=0;
    this->judgeVotes=0;
}

const Participant* ParticipantScore::getParticipant(){
    return this->participant;
}

