
#include "eurovision.h"

const int MAX_JUDGE_VOTES=10;
const int FULL=-1;
const int NOT_IN_ARRAY=-1;

//*************************MAIN CONTROL**************************************

MainControl::MainControl(int maxSongLength, int maxParticipants, int maxRegularTimesToVote):
                        phase(Registration),participantScores(new ParticipantScore[maxParticipants]){
    this->maxSongLength=maxSongLength;
    this->maxParticipants=maxParticipants;
    this->maxRegularTimesToVote=maxRegularTimesToVote;
}
MainControl& MainControl::operator+=(Participant& participant){
    if(!(this->legalParticipant(participant)) || this->phase != Registration){
        return *this;
    }
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
    if(this->phase!=Voting || !(this->isStateExist(vote.voter.state()))){
        return *this;
    }
    if(vote.voter.voterType()==Regular && vote.voter.timesOfVotes() < this->maxRegularTimesToVote){
        if(vote.selectedStates[0]==vote.voter.state()){
            return *this;
        }
        int index = this->getParticipantIndexByStateName(vote.selectedStates[0]);
        if(index >= 0) {
            this->participantScores[index].addRegularVote();
            ++(vote.voter);
        }
    }
    if(vote.voter.voterType()==Judge && vote.voter.timesOfVotes() < 1 ){
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

void MainControl::setPhase(Phase phase){
    if((this->phase==Registration && phase==Contest) ||
        (this->phase==Contest && phase==Voting)){
        this->phase = phase;
    }

}

int MainControl::getParticipantIndex(const Participant& participant){
    for (int i=0; i<this->maxParticipants; i++) {
        if (this->participantScores[i].getParticipant() == &participant) {
            return i;
        }
    }
    return NOT_IN_ARRAY;
}


MainControl& MainControl::operator-=(const Participant& participant){
    if(this->phase != Registration){
        return *this;
    }
    int index = this->getParticipantIndex(participant);
    if(index >= 0){
        this->participantScores[index].setParticipant(nullptr);
        this->participantScores[index].resetVotes();
    }
    this->sortParticipantsByStateNames();
    return *this;
}

MainControl::~MainControl(){
    delete[] this->participantScores;
}

bool MainControl::isStateExist(const string& stateName){
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
        if(this->participantScores[i].getParticipant()!= nullptr && this->participantScores[i].getParticipant()->state()==stateName){
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
bool MainControl::participate(const string& stateName) const{
    return (this->getParticipantIndexByStateName(stateName)>=0);
}

void MainControl::sortParticipantsByStateNames(){
    for(int i=0; i<this->maxParticipants; i++) {
        int maxIndex = i;
        int j;
        for(j=i+1; j< this->maxParticipants;j++){
            if(this->participantScores[j].getParticipant() == nullptr){
                continue;
            }
            if(this->participantScores[maxIndex].getParticipant() == nullptr ||
                this->participantScores[maxIndex].getParticipant()->state() > this->participantScores[j].getParticipant()->state()) {
                maxIndex = j;
            }
        }
        if(this->participantScores[maxIndex].getParticipant() == nullptr) return;
        this->swapParticipantsByIndex(i,maxIndex);
    }
}
void MainControl::swapParticipantsByIndex(int participantScore1,int participantScore2){
    ParticipantScore temp = this->participantScores[participantScore1];
    this->participantScores[participantScore1] = this->participantScores[participantScore2];
    this->participantScores[participantScore2] = temp;
}

ostream& operator<<(ostream& os, MainControl& mainControl){
    os << "{" << endl;
    if(mainControl.phase==Contest){
        os << "Contest"<< endl;
    }
    mainControl.sortParticipantsByStateNames();
    if (mainControl.phase==Registration){
        os << "Registration" << endl;
        for(int i=0; i<mainControl.maxParticipants; i++){
            if(mainControl.participantScores[i].getParticipant() == nullptr){
                break;
            }
            os << *(mainControl.participantScores[i].getParticipant()) << endl;
        }
    }
    else if(mainControl.phase==Voting){
        os << "Voting" << endl;
        for(int i=0; i<mainControl.maxParticipants; i++){
            if(mainControl.participantScores[i].getParticipant() == nullptr){
                break;
            }
            //os << mainControl.participantScores[i] << endl;
            os << mainControl.participantScores[i].getParticipant()->state() << " : Regular(" << mainControl.participantScores[i].getRegularVote()
            << ") Judge(" << mainControl.participantScores[i].getJudgeVote() << ")" << endl;
        }
    }
    os << "}" << endl;

    return os;
}
MainControl::Iterator MainControl::begin(){
    return MainControl::Iterator(this->participantScores);
}

MainControl::Iterator MainControl::end(){
    return MainControl::Iterator(&this->participantScores[this->getFirstEmptyIndex()]);
}
//***********************************Predicate******************************************************

MainControl::predicate::predicate(VoterType voterType):voterType(voterType){}
bool MainControl::predicate::operator()(const ParticipantScore& participantScore1, const ParticipantScore& participantScore2){
    if(this->voterType==Regular){
        return this->predicateByRegular(participantScore1,participantScore2);
    }
    if(this->voterType==Judge){
        return this->predicateByJudge(participantScore1,participantScore2);
    }
    return this->predicateByAll(participantScore1,participantScore2);
}

bool MainControl::predicate::predicateByJudge(const ParticipantScore& participantScore1, const ParticipantScore& participantScore2){
    if (participantScore1.getJudgeVote()==participantScore2.getJudgeVote()){
        return participantScore1.getParticipant()->state()>participantScore2.getParticipant()->state();
    }
    return participantScore1.getJudgeVote()>participantScore2.getJudgeVote();
}

bool MainControl::predicate::predicateByRegular(const ParticipantScore& participantScore1, const ParticipantScore& participantScore2){
    if (participantScore1.getRegularVote()==participantScore2.getRegularVote()){
        return participantScore1.getParticipant()->state()>participantScore2.getParticipant()->state();
    }
    return participantScore1.getRegularVote()>participantScore2.getRegularVote();
}
bool MainControl::predicate::predicateByAll(const ParticipantScore& participantScore1, const ParticipantScore& participantScore2){
    int participantScore1All=participantScore1.getJudgeVote()+participantScore1.getRegularVote();
    int participantScore2All=participantScore2.getJudgeVote()+participantScore2.getRegularVote();
    if (participantScore1All==participantScore2All){
        return participantScore1.getParticipant()->state()>participantScore2.getParticipant()->state();
    }
    return participantScore1All>participantScore2All;
}

string  MainControl::operator()(int i, VoterType voterType){
    MainControl::Iterator iterator;
    if(voterType==Regular){
        MainControl::predicate predicate1(Regular);
        iterator = get(this->begin(),this->end(),predicate1,i);
    }
    if(voterType==Judge){
        MainControl::predicate predicate2(Judge);
        iterator = get(this->begin(),this->end(),predicate2,i);
    }
    if(voterType==All){
        MainControl::predicate predicate3(All);
        iterator = get(this->begin(),this->end(),predicate3,i);
    }
    if(iterator==this->end()) return "";
    return (*iterator).getParticipant()->state();
}


//************************ Iterator *****************************************
MainControl::Iterator::Iterator(ParticipantScore* participantScore): participantScorePtr(participantScore){}
MainControl::Iterator::Iterator():participantScorePtr(nullptr){}

MainControl::Iterator&  MainControl::Iterator::operator++(){
    this->participantScorePtr++;
    return *this;
}
bool operator<(const MainControl::Iterator& iterator1, const MainControl::Iterator& iterator2){
    return iterator1.participantScorePtr < iterator2.participantScorePtr;
}

ParticipantScore& MainControl::Iterator::operator*(){
    return *(participantScorePtr);
}

bool operator==(const MainControl::Iterator& iterator1, const MainControl::Iterator& iterator2){
    return iterator1.participantScorePtr == iterator2.participantScorePtr;
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

void Participant::update(const string& songName, int songLength, const string& singerName){
    if (!this->registered){
        if(songName!="") this->songName=songName;
        if(songLength != 0) this->songLength=songLength;
        if(singerName!="") this->singerName=singerName;
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
                << '/' << participant.singer() << ']';
}


//*************************Voter**************************************

Voter::Voter(const string& originState, VoterType voterType){
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
    os << '<' << voter.state() << '/';
    if(voter.voterType()==Regular){
        os << "Regular"  << '>';
    }
    else{
        os << "Judge"  << '>';
    }
    return os;
}

//*************************Vote**************************************

Vote::Vote(Voter& voter, const string& state1, const string& state2, const string& state3, const string& state4,
        const string& state5, const string& state6, const string& state7, const string& state8, const string& state9,
           const string& state10):
        voter(voter),selectedStates(new string[MAX_JUDGE_VOTES]) {
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

void ParticipantScore::setParticipant(Participant* participant){
    if(participant == nullptr){
        //remove participant
        this->participant->updateRegistered(false);
    }
    else{
        //add participant
        participant->updateRegistered(true);
    }
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

Participant* ParticipantScore::getParticipant() const{
    return this->participant;
}

ostream& operator<<(ostream& os, const ParticipantScore& participantScore){
    //return os << participantScore.participant->state() << " : Regular(" << participantScore.regularVotes << ") Judge("
    //<< participantScore.judgeVotes << ")";
    return  os << *participantScore.getParticipant();
}

int ParticipantScore::getRegularVote() const{
    return this->regularVotes;
}

int ParticipantScore::getJudgeVote() const{
    return this->judgeVotes;
}

//*************************Get_Function******************************************************



