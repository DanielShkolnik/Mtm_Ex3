//
// Created by Yossi Levi on 08/06/2019.
//

#include <iostream>
#include <string.h>
using std::string;
#include "../eurovision.h"

using std::cout;
using std::endl;



void TEST6(){
    freopen ("./tests/test6myresult.txt","w",stdout);
    MainControl eurovision;
    Participant p1("norway","song_norway",156,"singer_norway");
    cout<<p1<<endl;
    Participant p2("norway","song_norway",102,"singer_norway");
    cout<<p2<<endl;
    Participant p3("slovakia","song_slovakia",116,"singer_slovakia");
    cout<<p3<<endl;
    Participant p4("austria","song_austria",138,"singer_austria");
    cout<<p4<<endl;
    Participant p5("latvia","song_latvia",111,"singer_latvia");
    cout<<p5<<endl;
    Participant p6("italy","song_italy",113,"singer_italy");
    cout<<p6<<endl;
    Participant p7("ireland","song_ireland",169,"singer_ireland");
    cout<<p7<<endl;
    Participant p8("switzerland","song_switzerland",222,"singer_switzerland");
    cout<<p8<<endl;
    Participant p9("norway","song_norway",117,"singer_norway");
    cout<<p9<<endl;
    Participant p10("turkey","song_turkey",186,"singer_turkey");
    cout<<p10<<endl;
    Participant p11("greece","song_greece",177,"singer_greece");
    cout<<p11<<endl;
    Participant p12("slovakia","song_slovakia",104,"singer_slovakia");
    cout<<p12<<endl;
    Participant p13("serbia","song_serbia",122,"singer_serbia");
    cout<<p13<<endl;
    Participant p14("bosnia","song_bosnia",102,"singer_bosnia");
    cout<<p14<<endl;
    Participant p15("turkey","song_turkey",133,"singer_turkey");
    cout<<p15<<endl;
    Participant p16("norway","song_norway",165,"singer_norway");
    cout<<p16<<endl;
    Participant p17("netherlands","song_netherlands",176,"singer_netherlands");
    cout<<p17<<endl;
    Participant p18("uk","song_uk",144,"singer_uk");
    cout<<p18<<endl;
    Participant p19("belarus","song_belarus",138,"singer_belarus");
    cout<<p19<<endl;
    Participant p20("belarus","song_belarus",138,"singer_belarus");
    cout<<p20<<endl;
    Participant p21("germany","song_germany",109,"singer_germany");
    cout<<p21<<endl;
    Participant p22("ireland","song_ireland",195,"singer_ireland");
    cout<<p22<<endl;
    Participant p23("latvia","song_latvia",186,"singer_latvia");
    cout<<p23<<endl;
    Participant p24("georgia","song_georgia",212,"singer_georgia");
    cout<<p24<<endl;
    Participant p25("malta","song_malta",145,"singer_malta");
    cout<<p25<<endl;
    Participant p26("kazakhastan","song_kazakhastan",196,"singer_kazakhastan");
    cout<<p26<<endl;
    Participant p27("georgia","song_georgia",126,"singer_georgia");
    cout<<p27<<endl;
    Participant p28("georgia","song_georgia",181,"singer_georgia");
    cout<<p28<<endl;
    Participant p29("luxembourg","song_luxembourg",188,"singer_luxembourg");
    cout<<p29<<endl;
    Participant p30("russia","song_russia",108,"singer_russia");
    cout<<p30<<endl;
    Participant p31("armenia","song_armenia",172,"singer_armenia");
    cout<<p31<<endl;
    Participant p32("luxembourg","song_luxembourg",121,"singer_luxembourg");
    cout<<p32<<endl;
    Participant p33("kazakhastan","song_kazakhastan",201,"singer_kazakhastan");
    cout<<p33<<endl;
    Participant p34("switzerland","song_switzerland",177,"singer_switzerland");
    cout<<p34<<endl;
    Participant p35("belgium","song_belgium",136,"singer_belgium");
    cout<<p35<<endl;
    Participant p36("france","song_france",225,"singer_france");
    cout<<p36<<endl;
    p9.update("new_song",0,"");
    p32.update("new_song",0,"");
    p31.update("new_song",0,"");
    p21.update("new_song",0,"");
    p2.update("new_song",0,"newsinger");
    p22.update("new_song",0,"newsinger");
    p9.update("new_song",0,"newsinger");
    p1.update("new_song",0,"newsinger");
    p1.update("new_song",154,"newsinger");
    p35.update("new_song",162,"newsinger");
    p5.update("new_song",149,"newsinger");
    p15.update("new_song",121,"newsinger");
    cout<<eurovision<<endl;
    eurovision+=p9;
    eurovision+=p31;
    eurovision+=p22;
    eurovision+=p7;
    eurovision+=p25;
    eurovision+=p20;
    eurovision+=p6;
    eurovision+=p32;
    eurovision+=p16;
    eurovision+=p19;
    eurovision+=p34;
    eurovision+=p29;
    eurovision+=p12;
    eurovision+=p33;
    cout<<eurovision<<endl;
    eurovision+=p5;
    eurovision+=p17;
    eurovision-=p29;
    eurovision-=p4;
    eurovision-=p18;
    eurovision-=p18;
    eurovision-=p17;
    eurovision-=p24;
    eurovision+=p3;
    eurovision+=p5;
    eurovision+=p5;
    eurovision+=p25;
    eurovision-=p31;
    eurovision-=p11;
    eurovision+=p32;
    eurovision+=p36;
    eurovision-=p9;
    eurovision+=p4;
    eurovision+=p19;
    eurovision-=p7;
    eurovision+=p21;
    eurovision+=p24;
    eurovision+=p4;
    eurovision-=p16;
    cout<<eurovision<<endl;
    ((((eurovision+=p14)+=p22)+=p28)-=p33)+=p1;
    eurovision.setPhase(Contest);
    eurovision.setPhase(Voting);
    std::cout<<eurovision.participate("greece")<<std::endl;
    std::cout<<eurovision.participate("bosnia")<<std::endl;
    std::cout<<eurovision.participate("norway")<<std::endl;
    std::cout<<eurovision.participate("italy")<<std::endl;
    std::cout<<eurovision.participate("latvia")<<std::endl;
    std::cout<<eurovision.participate("ireland")<<std::endl;
    std::cout<<eurovision.participate("hungary")<<std::endl;
    std::cout<<eurovision.participate("belarus")<<std::endl;
    std::cout<<eurovision.participate("slovenia")<<std::endl;
    std::cout<<eurovision.participate("georgia")<<std::endl;
    std::cout<<eurovision.participate("georgia")<<std::endl;
    std::cout<<eurovision.participate("sweden")<<std::endl;
    std::cout<<eurovision.participate("switzerland")<<std::endl;
    std::cout<<eurovision.participate("slovakia")<<std::endl;
    p29.update("",120,"");
    cout<<p29<<endl;
    p11.update("",120,"");
    cout<<p11<<endl;
    p10.update("",120,"");
    cout<<p10<<endl;
    p30.update("",120,"");
    cout<<p30<<endl;
    p14.update("",120,"");
    cout<<p14<<endl;
    p17.update("",120,"");
    cout<<p17<<endl;
    p28.update("",120,"");
    cout<<p28<<endl;
    p16.update("",120,"");
    cout<<p16<<endl;
    p19.update("",120,"");
    cout<<p19<<endl;
    p10.update("",120,"");
    cout<<p10<<endl;
    p8.update("",120,"");
    cout<<p8<<endl;
    p29.update("",120,"");
    cout<<p29<<endl;
    p30.update("",120,"");
    cout<<p30<<endl;
    p16.update("",120,"");
    cout<<p16<<endl;
    Voter v1("belgium",Judge);
    Voter v2("slovenia",Judge);
    Voter v3("armenia",Regular);
    Voter v4("hungary",Judge);
    Voter v5("israel",Regular);
    Voter v6("belarus",Judge);
    Voter v7("georgia");
    Voter v8("uk",Regular);
    Voter v9("switzerland",Regular);
    Voter v10("italy",Regular);
    Voter v11("lithiania");
    Voter v12("hungary",Judge);
    Voter v13("malta",Judge);
    Voter v14("ireland",Judge);
    Voter v15("israel");
    Voter v16("bulgaria");
    Voter v17("slovenia");
    Voter v18("kazakhastan",Judge);
    Voter v19("georgia",Judge);
    Voter v20("uk",Judge);
    Voter v21("belgium",Regular);
    Voter v22("greece",Regular);
    Voter v23("luxembourg",Judge);
    Voter v24("slovenia");
    Voter v25("cyrpus",Judge);
    Voter v26("israel");
    Voter v27("ukraine",Judge);
    Voter v28("serbia",Regular);
    Voter v29("slovakia");
    Voter v30("italy",Regular);
    Voter v31("moldova",Judge);
    Voter v32("netherlands",Regular);
    Voter v33("bulgaria");
    Voter v34("andora",Regular);
    Voter v35("greece",Judge);
    Voter v36("andora",Regular);
    Voter v37("latvia",Judge);
    Voter v38("slovakia",Regular);
    Voter v39("latvia",Judge);
    Voter v40("israel");
    Voter v41("slovenia");
    Voter v42("bosnia");
    Voter v43("france",Judge);
    Voter v44("cyrpus",Judge);
    Voter v45("bulgaria",Regular);
    Voter v46("slovakia");
    Voter v47("lithiania",Regular);
    Voter v48("georgia",Judge);
    Voter v49("croatia");
    Voter v50("switzerland",Judge);
    Voter v51("moldova",Regular);
    Voter v52("georgia",Regular);
    Voter v53("russia");
    Voter v54("norway",Regular);
    Voter v55("bulgaria",Judge);
    Voter v56("luxembourg",Regular);
    Voter v57("uk",Judge);
    Voter v58("estonia",Judge);
    Voter v59("moldova",Regular);
    Voter v60("ireland",Regular);
    Voter v61("russia",Regular);
    Voter v62("spain");
    Voter v63("switzerland");
    Voter v64("russia");
    Voter v65("slovakia",Judge);
    Voter v66("bosnia",Regular);
    Voter v67("cyrpus");
    Voter v68("latvia",Judge);
    Voter v69("norway",Regular);
    Voter v70("switzerland",Judge);
    Voter v71("netherlands");
    Voter v72("italy",Regular);
    Voter v73("netherlands",Regular);
    Voter v74("turkey",Regular);
    Voter v75("greece");
    Voter v76("lithiania",Judge);
    Voter v77("uk",Judge);
    Voter v78("netherlands",Regular);
    Voter v79("bosnia");
    Voter v80("kazakhastan");
    Voter v81("lithiania",Regular);
    Voter v82("moldova");
    Voter v83("croatia");
    Voter v84("greece",Judge);
    Voter v85("turkey",Judge);
    Voter v86("croatia");
    Voter v87("andora",Regular);
    Voter v88("serbia",Judge);
    Voter v89("sweden",Regular);
    Voter v90("ireland",Regular);
    Voter v91("luxembourg",Judge);
    Voter v92("latvia",Judge);
    Voter v93("malta",Regular);
    Voter v94("lithiania",Regular);
    Voter v95("norway");
    Voter v96("hungary");
    Voter v97("greece",Judge);
    Voter v98("russia",Regular);
    Voter v99("estonia");
    cout<<eurovision<<endl;
    eurovision+=Vote(v46,"sweden");
    eurovision+=Vote(v94,"switzerland");
    eurovision+=Vote(v38,"cyrpus");
    eurovision+=Vote(v12,"turkey","belgium","lithiania","netherlands","slovenia","croatia","germany");
    eurovision+=Vote(v46,"latvia");
    eurovision+=Vote(v8,"serbia");
    eurovision+=Vote(v54,"latvia");
    eurovision+=Vote(v47,"malta");
    eurovision+=Vote(v4,"luxembourg","germany");
    eurovision+=Vote(v5,"georgia");
    eurovision+=Vote(v29,"malta");
    eurovision+=Vote(v59,"croatia");
    eurovision+=Vote(v65,"bosnia","germany","serbia","cyrpus");
    eurovision+=Vote(v76,"georgia","bosnia","greece","sweden","cyrpus","russia","switzerland");
    eurovision+=Vote(v1,"israel","malta","greece","israel","croatia","serbia","sweden","lithiania");
    eurovision+=Vote(v58,"netherlands","netherlands","ukraine","hungary","spain");
    eurovision+=Vote(v9,"croatia");
    eurovision+=Vote(v53,"georgia");
    eurovision+=Vote(v35,"ukraine","malta","serbia","hungary");
    eurovision+=Vote(v7,"netherlands");
    eurovision+=Vote(v73,"ireland");
    eurovision+=Vote(v96,"france");
    eurovision+=Vote(v49,"latvia");
    eurovision+=Vote(v83,"serbia");
    eurovision+=Vote(v7,"belgium");
    eurovision+=Vote(v44,"russia","andora","bulgaria","lithiania");
    eurovision+=Vote(v81,"kazakhastan");
    eurovision+=Vote(v67,"croatia");
    eurovision+=Vote(v71,"malta");
    eurovision+=Vote(v86,"norway");
    eurovision+=Vote(v71,"bosnia");
    eurovision+=Vote(v75,"turkey");
    eurovision+=Vote(v79,"switzerland");
    eurovision+=Vote(v52,"greece");
    eurovision+=Vote(v98,"serbia");
    eurovision+=Vote(v55,"andora","latvia","bosnia","belarus","georgia","andora");
    eurovision+=Vote(v16,"belgium");
    eurovision+=Vote(v43,"italy","bosnia","russia","italy","slovenia","georgia","switzerland","belgium");
    eurovision+=Vote(v39,"serbia","switzerland","croatia","slovakia","georgia","hungary","netherlands","malta","moldova","bulgaria");
    eurovision+=Vote(v35,"kazakhastan","norway","belarus","serbia","bulgaria","spain","netherlands","italy","france");
    eurovision+=Vote(v15,"sweden");
    eurovision+=Vote(v35,"latvia","turkey","sweden","germany");
    eurovision+=Vote(v89,"israel");
    eurovision+=Vote(v62,"switzerland");
    eurovision+=Vote(v64,"andora");
    eurovision+=Vote(v50,"turkey","bulgaria","bosnia");
    eurovision+=Vote(v24,"slovakia");
    eurovision+=Vote(v51,"russia");
    eurovision+=Vote(v68,"armenia","andora","ireland","luxembourg","norway","slovakia","france","belgium");
    eurovision+=Vote(v46,"belarus");
    eurovision+=Vote(v22,"slovakia");
    eurovision+=Vote(v65,"slovakia","turkey","serbia","slovakia","norway","ireland");
    eurovision+=Vote(v77,"russia","belarus","france","croatia","spain","ukraine","georgia");
    eurovision+=Vote(v15,"moldova");
    eurovision+=Vote(v94,"turkey");
    eurovision+=Vote(v31,"switzerland","cyrpus","moldova","france");
    eurovision+=Vote(v17,"switzerland");
    eurovision+=Vote(v87,"france");
    eurovision+=Vote(v82,"georgia");
    eurovision+=Vote(v66,"georgia");
    eurovision+=Vote(v18,"croatia","greece","israel","croatia","belarus","cyrpus","slovenia","armenia","malta");
    eurovision+=Vote(v92,"hungary","andora");
    eurovision+=Vote(v80,"lithiania");
    eurovision+=Vote(v93,"slovenia");
    eurovision+=Vote(v73,"france");
    eurovision+=Vote(v24,"belgium");
    eurovision+=Vote(v39,"spain","andora","serbia","greece","norway","austria");
    eurovision+=Vote(v63,"armenia");
    eurovision+=Vote(v93,"belgium");
    eurovision+=Vote(v37,"austria","switzerland","luxembourg","israel");
    eurovision+=Vote(v85,"belgium","norway","belgium","luxembourg","croatia","armenia");
    eurovision+=Vote(v36,"germany");
    eurovision+=Vote(v96,"france");
    eurovision+=Vote(v36,"belarus");
    eurovision+=Vote(v32,"russia");
    eurovision+=Vote(v90,"malta");
    eurovision+=Vote(v99,"austria");
    eurovision+=Vote(v6,"sweden","luxembourg","estonia");
    eurovision+=Vote(v12,"belgium","georgia","moldova","lithiania");
    eurovision+=Vote(v46,"ukraine");
    eurovision+=Vote(v14,"slovenia","israel","moldova","france","greece");
    eurovision+=Vote(v56,"luxembourg");
    eurovision+=Vote(v9,"bulgaria");
    eurovision+=Vote(v43,"bulgaria","malta","moldova","kazakhastan","sweden");
    eurovision+=Vote(v91,"belgium","belarus","austria","norway","turkey");
    eurovision+=Vote(v1,"sweden","france","ireland","norway");
    eurovision+=Vote(v11,"cyrpus");
    eurovision+=Vote(v34,"turkey");
    eurovision+=Vote(v67,"georgia");
    eurovision+=Vote(v88,"serbia","greece","slovenia");
    eurovision+=Vote(v77,"lithiania","kazakhastan","austria","belgium","germany");
    eurovision+=Vote(v99,"switzerland");
    eurovision+=Vote(v21,"malta");
    eurovision+=Vote(v75,"hungary");
    eurovision+=Vote(v13,"kazakhastan","norway","austria");
    eurovision+=Vote(v44,"latvia","ukraine","bulgaria","austria","hungary");
    eurovision+=Vote(v85,"luxembourg","malta","turkey");
    eurovision+=Vote(v63,"sweden");
    eurovision+=Vote(v87,"andora");
    eurovision+=Vote(v37,"spain","austria","malta","luxembourg","spain","ukraine","italy");
    eurovision+=Vote(v64,"slovakia");
    eurovision+=Vote(v43,"latvia","malta","norway","croatia","slovakia");
    eurovision+=Vote(v76,"germany","greece","ireland","netherlands","belarus","bulgaria","serbia","andora");
    eurovision+=Vote(v66,"andora");
    eurovision+=Vote(v43,"greece","estonia","spain","latvia","kazakhastan");
    eurovision+=Vote(v64,"russia");
    eurovision+=Vote(v46,"bosnia");
    eurovision+=Vote(v1,"georgia","switzerland","serbia","estonia");
    eurovision+=Vote(v67,"austria");
    eurovision+=Vote(v68,"russia","lithiania","italy");
    eurovision+=Vote(v18,"slovakia","russia");
    eurovision+=Vote(v47,"norway");
    eurovision+=Vote(v36,"latvia");
    eurovision+=Vote(v85,"moldova","belgium");
    eurovision+=Vote(v38,"malta");
    eurovision+=Vote(v88,"belarus","norway","ukraine","cyrpus","bosnia","russia","bulgaria","switzerland","lithiania");
    eurovision+=Vote(v17,"croatia");
    eurovision+=Vote(v76,"russia","luxembourg","belgium","belarus","france","russia","serbia");
    eurovision+=Vote(v96,"ireland");
    eurovision+=Vote(v52,"israel");
    eurovision+=Vote(v91,"malta","germany");
    eurovision+=Vote(v3,"lithiania");
    eurovision+=Vote(v46,"bulgaria");
    eurovision+=Vote(v59,"belgium");
    eurovision+=Vote(v28,"luxembourg");
    eurovision+=Vote(v73,"switzerland");
    eurovision+=Vote(v50,"estonia","spain","slovenia","luxembourg");
    eurovision+=Vote(v60,"israel");
    eurovision+=Vote(v83,"latvia");
    eurovision+=Vote(v67,"turkey");
    eurovision+=Vote(v89,"cyrpus");
    eurovision+=Vote(v22,"italy");
    eurovision+=Vote(v58,"slovenia","slovenia","serbia","georgia","malta","latvia","austria","lithiania");
    eurovision+=Vote(v96,"ukraine");
    eurovision+=Vote(v94,"slovakia");
    eurovision+=Vote(v41,"croatia");
    eurovision+=Vote(v1,"greece","netherlands","switzerland","ireland","luxembourg","croatia","greece");
    eurovision+=Vote(v41,"bosnia");
    eurovision+=Vote(v60,"germany");
    eurovision+=Vote(v16,"belgium");
    eurovision+=Vote(v52,"belgium");
    eurovision+=Vote(v6,"ireland","estonia","switzerland","italy","kazakhastan","lithiania","ireland");
    eurovision+=Vote(v22,"andora");
    eurovision+=Vote(v98,"bosnia");
    eurovision+=Vote(v5,"serbia");
    eurovision+=Vote(v87,"georgia");
    eurovision+=Vote(v13,"germany","sweden","cyrpus","serbia","slovenia");
    eurovision+=Vote(v96,"hungary");
    eurovision+=Vote(v11,"israel");
    eurovision+=Vote(v84,"sweden","netherlands","estonia","latvia","austria","andora","cyrpus","malta");
    eurovision+=Vote(v66,"greece");
    eurovision+=Vote(v55,"kazakhastan","slovenia","estonia");
    eurovision+=Vote(v77,"estonia","moldova","croatia","austria","ireland","spain");
    eurovision+=Vote(v85,"belarus","israel","belarus","austria","russia","spain","cyrpus","italy","kazakhastan");
    eurovision+=Vote(v24,"austria");
    eurovision+=Vote(v35,"russia","hungary","spain","ukraine","germany");
    eurovision+=Vote(v48,"spain","france","bulgaria","kazakhastan","andora","malta");
    eurovision+=Vote(v10,"bosnia");
    eurovision+=Vote(v84,"estonia","netherlands","france","ukraine","greece","luxembourg","slovakia","bulgaria","kazakhastan");
    eurovision+=Vote(v57,"netherlands","lithiania","ukraine","bosnia");
    eurovision+=Vote(v73,"austria");
    eurovision+=Vote(v19,"croatia","germany","slovakia","belarus","spain","belgium");
    eurovision+=Vote(v26,"belgium");
    eurovision+=Vote(v62,"israel");
    eurovision+=Vote(v33,"switzerland");
    eurovision+=Vote(v61,"kazakhastan");
    eurovision+=Vote(v27,"cyrpus","hungary");
    eurovision+=Vote(v59,"austria");
    eurovision+=Vote(v42,"slovakia");
    eurovision+=Vote(v45,"cyrpus");
    eurovision+=Vote(v37,"russia","switzerland");
    eurovision+=Vote(v17,"russia");
    eurovision+=Vote(v40,"spain");
    eurovision+=Vote(v85,"hungary","austria","georgia","netherlands","andora","switzerland");
    eurovision+=Vote(v19,"russia","slovakia","latvia","bulgaria","cyrpus");
    eurovision+=Vote(v37,"ireland","germany","turkey");
    eurovision+=Vote(v20,"croatia","belgium","slovakia","greece","russia","hungary","bosnia","switzerland");
    eurovision+=Vote(v6,"sweden","malta","ireland","latvia","estonia","belgium");
    eurovision+=Vote(v55,"sweden","luxembourg","france","austria","israel","andora","cyrpus");
    eurovision+=Vote(v1,"estonia","croatia","georgia","estonia","germany");
    eurovision+=Vote(v3,"georgia");
    eurovision+=Vote(v95,"georgia");
    eurovision+=Vote(v70,"cyrpus","kazakhastan","hungary","georgia","andora","malta","turkey","belgium","norway","moldova");
    eurovision+=Vote(v12,"armenia","slovenia","bosnia","netherlands","belarus","belgium","latvia","armenia");
    eurovision+=Vote(v40,"ukraine");
    eurovision+=Vote(v78,"norway");
    eurovision+=Vote(v48,"switzerland","hungary","netherlands","croatia","belgium","turkey","malta");
    eurovision+=Vote(v55,"bulgaria","slovakia","croatia","latvia","andora","lithiania","moldova","norway");
    eurovision+=Vote(v66,"malta");
    eurovision+=Vote(v69,"france");
    eurovision+=Vote(v8,"malta");
    eurovision+=Vote(v83,"lithiania");
    eurovision+=Vote(v84,"spain","turkey","bulgaria","georgia","lithiania","israel");
    eurovision+=Vote(v71,"latvia");
    eurovision+=Vote(v79,"serbia");
    eurovision+=Vote(v45,"ukraine");
    eurovision+=Vote(v27,"slovenia","hungary","ireland","serbia","luxembourg","turkey","kazakhastan","belarus");
    eurovision+=Vote(v36,"hungary");
    eurovision+=Vote(v14,"cyrpus","russia","luxembourg","turkey","netherlands","bosnia","greece");
    cout<<eurovision<<endl;

}
