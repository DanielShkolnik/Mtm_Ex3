#include <iostream>

#include "eurovision.h"

using std::cout;
using std::endl;

#define TEST(num)  cout << endl << "TEST" << " " << (num) << endl;


int main()
{
    MainControl eurovision(180,5);
    Participant p1("Israel","Song_Israel",175,"Singer_Israel");
    Participant p2("UK","Song_UK",170,"Singer_UK");
    Participant p3("France","Song_France",150,"Singer_France");
    Participant p4("Australia","Song_Australia",180,"Singer_Australia");
    Participant p5("Cyprus","Song_Cyprus",172,"Singer_Cyprus");
    Participant p6("Cyprus","Song_Cyprus_copy",170,"Singer_Cyprus_copy");
    Participant p7("Cyprus2","Song_Cyprus2",172,"Singer_Cyprus2");
    Participant p8("Cyprus3","Song_Cyprus3",172,"Singer_Cyprus3");
    Participant p9("Cyprus4","Song_Cyprus4",172,"Singer_Cyprus4");
    Participant p10("Cyprus5","Song_Cyprus5",172,"Singer_Cyprus5");

    (((((((eurovision += p1) += p2) += p3) += p4) += p5) += p6) += p7) += p8;

    cout << eurovision << endl;

    ((eurovision -= p4) += p6) += p7;
    cout << eurovision << endl;

    (((((((eurovision -= p1) -= p2) -= p3) -= p4) -= p5) -= p6) -= p7);
    cout << eurovision << endl;

    ((((((eurovision += p5)+= p6)+= p7)+= p8)+= p9)+= p10);
    cout << eurovision << endl;

    Voter vr2("Israel");
    Voter vr3("UK");
    Voter vr4("France");
    Voter vr5("Australia");

    eurovision += Vote(vr2,"Cyprus"); //need to check.
    eurovision.setPhase(Voting);
    cout << eurovision << endl;
    eurovision.setPhase(Contest);
    eurovision += Vote(vr2,"Cyprus");
    cout << eurovision << endl;
    eurovision.setPhase(Voting);
    cout << "VOTING PHASE"<< endl;
    cout << eurovision << endl;
    eurovision.setPhase(Registration);
    cout << eurovision << endl;

    eurovision -= p5;
    cout << eurovision << endl;
    cout << p5.isRegistered() << endl;


    Voter vr6("Cyprus", Regular);
    Voter vj2("Israel",Judge);
    Voter vj3("UK",Judge);
    Voter vj4("France",Judge);
    Voter vj5("Australia",Judge);
    Voter vj6("Cyprus",Judge);

    eurovision += Vote(vr2,"UK","France"); //need to check.
    cout << "Voter4 times of vote: "<<vr4.timesOfVotes() << endl;
    eurovision += Vote(vr4,"ASDASD");
    cout << "Voter4 times of vote: "<<vr4.timesOfVotes() << endl;
    eurovision += Vote(vj4,"asdasd","asdasd","Cyprus","Cyprus2");
    eurovision += Vote(vj4,"Cyprus","Cyprus2","France");
    eurovision += Vote(vj4,"Cyprus");
    eurovision -= p5;
    cout << eurovision << endl;
}

