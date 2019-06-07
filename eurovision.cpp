
#include "eurovision.h"

//*************************MAIN CONTROL**************************************
#define MAX_JUDGE_VOTES 10

MainControl::MainControl(int maxSongLength, int maxParticipants,
                        int maxRegularTimesToVote): phase(Registration),
                        participantScores(new ParticipantScore[maxParticipants]){
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




