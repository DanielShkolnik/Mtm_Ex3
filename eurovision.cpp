
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

MainControl& MainControl::operator+=(Vote& vote){
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
//*************************Participant**************************************

Participant::Participant(string stateName, string songName, string singerName, int songLength):
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
