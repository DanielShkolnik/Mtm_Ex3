//
// Created by Yossi Levi on 08/06/2019.
//

#include <iostream>
#include <string.h>
using std::string;
#include "../eurovision.h"

using std::cout;
using std::endl;



void TEST5(){
    freopen ("../tests/test5myresult.txt","w",stdout);
    MainControl eurovision;
    Participant p1("turkey","song_turkey",161,"singer_turkey");
    cout<<p1<<endl;
    Participant p2("slovakia","song_slovakia",168,"singer_slovakia");
    cout<<p2<<endl;
    Participant p3("georgia","song_georgia",119,"singer_georgia");
    cout<<p3<<endl;
    Participant p4("belgium","song_belgium",177,"singer_belgium");
    cout<<p4<<endl;
    Participant p5("switzerland","song_switzerland",106,"singer_switzerland");
    cout<<p5<<endl;
    Participant p6("ukraine","song_ukraine",146,"singer_ukraine");
    cout<<p6<<endl;
    Participant p7("ukraine","song_ukraine",159,"singer_ukraine");
    cout<<p7<<endl;
    Participant p8("hungary","song_hungary",141,"singer_hungary");
    cout<<p8<<endl;
    Participant p9("kazakhastan","song_kazakhastan",121,"singer_kazakhastan");
    cout<<p9<<endl;
    Participant p10("estonia","song_estonia",207,"singer_estonia");
    cout<<p10<<endl;
    Participant p11("cyrpus","song_cyrpus",127,"singer_cyrpus");
    cout<<p11<<endl;
    Participant p12("greece","song_greece",111,"singer_greece");
    cout<<p12<<endl;
    Participant p13("kazakhastan","song_kazakhastan",125,"singer_kazakhastan");
    cout<<p13<<endl;
    Participant p14("norway","song_norway",125,"singer_norway");
    cout<<p14<<endl;
    Participant p15("armenia","song_armenia",118,"singer_armenia");
    cout<<p15<<endl;
    Participant p16("turkey","song_turkey",159,"singer_turkey");
    cout<<p16<<endl;
    Participant p17("andora","song_andora",112,"singer_andora");
    cout<<p17<<endl;
    Participant p18("ukraine","song_ukraine",218,"singer_ukraine");
    cout<<p18<<endl;
    Participant p19("greece","song_greece",119,"singer_greece");
    cout<<p19<<endl;
    Participant p20("russia","song_russia",147,"singer_russia");
    cout<<p20<<endl;
    Participant p21("bosnia","song_bosnia",105,"singer_bosnia");
    cout<<p21<<endl;
    Participant p22("hungary","song_hungary",146,"singer_hungary");
    cout<<p22<<endl;
    Participant p23("belarus","song_belarus",123,"singer_belarus");
    cout<<p23<<endl;
    Participant p24("germany","song_germany",219,"singer_germany");
    cout<<p24<<endl;
    Participant p25("netherlands","song_netherlands",230,"singer_netherlands");
    cout<<p25<<endl;
    Participant p26("croatia","song_croatia",156,"singer_croatia");
    cout<<p26<<endl;
    Participant p27("belarus","song_belarus",166,"singer_belarus");
    cout<<p27<<endl;
    Participant p28("sweden","song_sweden",126,"singer_sweden");
    cout<<p28<<endl;
    Participant p29("cyrpus","song_cyrpus",218,"singer_cyrpus");
    cout<<p29<<endl;
    Participant p30("armenia","song_armenia",113,"singer_armenia");
    cout<<p30<<endl;
    Participant p31("armenia","song_armenia",184,"singer_armenia");
    cout<<p31<<endl;
    Participant p32("slovakia","song_slovakia",167,"singer_slovakia");
    cout<<p32<<endl;
    Participant p33("serbia","song_serbia",161,"singer_serbia");
    cout<<p33<<endl;
    Participant p34("armenia","song_armenia",138,"singer_armenia");
    cout<<p34<<endl;
    Participant p35("luxembourg","song_luxembourg",179,"singer_luxembourg");
    cout<<p35<<endl;
    Participant p36("bosnia","song_bosnia",158,"singer_bosnia");
    cout<<p36<<endl;
    p11.update("new_song",0,"");
    p26.update("new_song",0,"");
    p31.update("new_song",0,"");
    p13.update("new_song",0,"");
    p28.update("new_song",0,"newsinger");
    p8.update("new_song",0,"newsinger");
    p4.update("new_song",0,"newsinger");
    p28.update("new_song",0,"newsinger");
    p5.update("new_song",159,"newsinger");
    p28.update("new_song",129,"newsinger");
    p25.update("new_song",132,"newsinger");
    p5.update("new_song",186,"newsinger");
    cout<<eurovision<<endl;
    eurovision+=p35;
    eurovision+=p9;
    eurovision+=p18;
    eurovision+=p35;
    eurovision+=p28;
    eurovision+=p15;
    eurovision+=p9;
    eurovision+=p36;
    eurovision+=p26;
    eurovision+=p21;
    eurovision+=p4;
    eurovision+=p34;
    eurovision+=p29;
    eurovision+=p33;
    cout<<eurovision<<endl;
    eurovision-=p29;
    eurovision+=p33;
    eurovision-=p5;
    eurovision+=p17;
    eurovision-=p7;
    eurovision+=p12;
    eurovision+=p2;
    eurovision+=p10;
    eurovision-=p9;
    eurovision+=p8;
    eurovision-=p5;
    eurovision-=p34;
    eurovision+=p21;
    eurovision-=p11;
    eurovision+=p34;
    eurovision+=p13;
    eurovision+=p33;
    eurovision+=p32;
    eurovision-=p29;
    eurovision-=p2;
    eurovision+=p11;
    eurovision+=p31;
    eurovision+=p1;
    eurovision-=p32;
    cout<<eurovision<<endl;
    (((((((((((((eurovision+=p35)-=p27)-=p12)+=p29)-=p24)+=p21)-=p20)-=p30)
    +=p27)-=p20)+=p6)+=p21)+=p34)+=p9;
    eurovision.setPhase(Contest);
    eurovision.setPhase(Voting);
    std::cout<<eurovision.participate("israel")<<std::endl;
    std::cout<<eurovision.participate("hungary")<<std::endl;
    std::cout<<eurovision.participate("italy")<<std::endl;
    std::cout<<eurovision.participate("ireland")<<std::endl;
    std::cout<<eurovision.participate("austria")<<std::endl;
    std::cout<<eurovision.participate("uk")<<std::endl;
    std::cout<<eurovision.participate("georgia")<<std::endl;
    std::cout<<eurovision.participate("netherlands")<<std::endl;
    std::cout<<eurovision.participate("netherlands")<<std::endl;
    std::cout<<eurovision.participate("greece")<<std::endl;
    std::cout<<eurovision.participate("ukraine")<<std::endl;
    std::cout<<eurovision.participate("norway")<<std::endl;
    std::cout<<eurovision.participate("netherlands")<<std::endl;
    std::cout<<eurovision.participate("spain")<<std::endl;
    p22.update("",120,"");
    cout<<p22<<endl;
    p2.update("",120,"");
    cout<<p2<<endl;
    p21.update("",120,"");
    cout<<p21<<endl;
    p29.update("",120,"");
    cout<<p29<<endl;
    p25.update("",120,"");
    cout<<p25<<endl;
    p19.update("",120,"");
    cout<<p19<<endl;
    p35.update("",120,"");
    cout<<p35<<endl;
    p7.update("",120,"");
    cout<<p7<<endl;
    p3.update("",120,"");
    cout<<p3<<endl;
    p8.update("",120,"");
    cout<<p8<<endl;
    p10.update("",120,"");
    cout<<p10<<endl;
    p20.update("",120,"");
    cout<<p20<<endl;
    p35.update("",120,"");
    cout<<p35<<endl;
    p17.update("",120,"");
    cout<<p17<<endl;
    Voter v1("greece",Regular);
    Voter v2("armenia",Regular);
    Voter v3("lithiania");
    Voter v4("spain",Judge);
    Voter v5("belarus",Regular);
    Voter v6("hungary",Regular);
    Voter v7("andora",Judge);
    Voter v8("france",Judge);
    Voter v9("norway",Judge);
    Voter v10("austria",Judge);
    Voter v11("spain");
    Voter v12("slovenia");
    Voter v13("germany",Judge);
    Voter v14("bosnia",Judge);
    Voter v15("belgium",Judge);
    Voter v16("france",Regular);
    Voter v17("ireland");
    Voter v18("serbia",Judge);
    Voter v19("moldova");
    Voter v20("croatia");
    Voter v21("serbia",Judge);
    Voter v22("italy");
    Voter v23("kazakhastan",Regular);
    Voter v24("latvia",Judge);
    Voter v25("russia");
    Voter v26("bulgaria",Judge);
    Voter v27("lithiania");
    Voter v28("andora",Judge);
    Voter v29("switzerland",Judge);
    Voter v30("ukraine",Judge);
    Voter v31("ukraine");
    Voter v32("latvia",Regular);
    Voter v33("moldova",Judge);
    Voter v34("hungary",Judge);
    Voter v35("slovenia");
    Voter v36("cyrpus");
    Voter v37("germany");
    Voter v38("russia",Judge);
    Voter v39("latvia",Judge);
    Voter v40("uk",Judge);
    Voter v41("netherlands",Judge);
    Voter v42("france",Regular);
    Voter v43("norway",Regular);
    Voter v44("russia");
    Voter v45("sweden",Regular);
    Voter v46("belgium");
    Voter v47("hungary",Judge);
    Voter v48("israel",Regular);
    Voter v49("slovenia");
    Voter v50("belarus",Regular);
    Voter v51("cyrpus",Regular);
    Voter v52("latvia");
    Voter v53("netherlands",Judge);
    Voter v54("netherlands",Judge);
    Voter v55("russia");
    Voter v56("kazakhastan",Judge);
    Voter v57("switzerland");
    Voter v58("moldova");
    Voter v59("andora",Regular);
    Voter v60("malta");
    Voter v61("ukraine",Judge);
    Voter v62("sweden",Judge);
    Voter v63("slovenia");
    Voter v64("germany",Judge);
    Voter v65("hungary");
    Voter v66("andora",Regular);
    Voter v67("italy",Judge);
    Voter v68("bosnia");
    Voter v69("netherlands",Regular);
    Voter v70("malta",Regular);
    Voter v71("hungary",Regular);
    Voter v72("switzerland",Regular);
    Voter v73("norway",Judge);
    Voter v74("andora",Judge);
    Voter v75("uk",Regular);
    Voter v76("croatia");
    Voter v77("estonia",Regular);
    Voter v78("spain",Judge);
    Voter v79("croatia");
    Voter v80("israel",Regular);
    Voter v81("greece",Judge);
    Voter v82("austria");
    Voter v83("italy",Regular);
    Voter v84("kazakhastan",Regular);
    Voter v85("andora");
    Voter v86("ireland",Regular);
    Voter v87("hungary");
    Voter v88("cyrpus",Regular);
    Voter v89("luxembourg",Judge);
    Voter v90("france");
    Voter v91("armenia",Judge);
    Voter v92("ukraine");
    Voter v93("spain");
    Voter v94("armenia",Judge);
    Voter v95("austria",Regular);
    Voter v96("cyrpus");
    Voter v97("croatia",Regular);
    Voter v98("netherlands",Regular);
    Voter v99("turkey");
    cout<<eurovision<<endl;
    eurovision+=Vote(v35,"latvia");
    eurovision+=Vote(v54,"malta","moldova","estonia","luxembourg","lithiania","germany","ireland","andora");
    eurovision+=Vote(v55,"cyrpus");
    eurovision+=Vote(v83,"austria");
    eurovision+=Vote(v5,"greece");
    eurovision+=Vote(v65,"france");
    eurovision+=Vote(v58,"netherlands");
    eurovision+=Vote(v43,"hungary");
    eurovision+=Vote(v99,"kazakhastan");
    eurovision+=Vote(v89,"ukraine","netherlands","lithiania","switzerland","bosnia","moldova");
    eurovision+=Vote(v25,"georgia");
    eurovision+=Vote(v48,"france");
    eurovision+=Vote(v1,"ireland");
    eurovision+=Vote(v32,"israel");
    eurovision+=Vote(v67,"switzerland","ireland","kazakhastan");
    eurovision+=Vote(v33,"croatia","turkey","austria","greece","andora","france");
    eurovision+=Vote(v33,"bulgaria","hungary","bulgaria","georgia");
    eurovision+=Vote(v54,"lithiania","norway","lithiania","armenia","slovenia","hungary","cyrpus");
    eurovision+=Vote(v95,"spain");
    eurovision+=Vote(v82,"bulgaria");
    eurovision+=Vote(v13,"ukraine","latvia","lithiania","norway","turkey");
    eurovision+=Vote(v60,"turkey");
    eurovision+=Vote(v45,"georgia");
    eurovision+=Vote(v22,"belarus");
    eurovision+=Vote(v38,"sweden","ireland","netherlands","serbia");
    eurovision+=Vote(v45,"austria");
    eurovision+=Vote(v60,"belarus");
    eurovision+=Vote(v20,"slovakia");
    eurovision+=Vote(v39,"andora","hungary","georgia","ukraine","latvia","israel");
    eurovision+=Vote(v10,"hungary","cyrpus","moldova","greece","latvia","kazakhastan","ukraine");
    eurovision+=Vote(v79,"sweden");
    eurovision+=Vote(v72,"israel");
    eurovision+=Vote(v91,"belgium","netherlands","ireland","sweden","hungary","armenia","andora","slovakia");
    eurovision+=Vote(v3,"estonia");
    eurovision+=Vote(v7,"serbia","norway");
    eurovision+=Vote(v25,"belarus");
    eurovision+=Vote(v68,"latvia");
    eurovision+=Vote(v38,"armenia","ukraine","georgia","slovakia","slovenia","norway");
    eurovision+=Vote(v79,"malta");
    eurovision+=Vote(v13,"italy","lithiania","hungary","slovenia","belarus","greece","georgia","slovakia");
    eurovision+=Vote(v55,"austria");
    eurovision+=Vote(v58,"hungary");
    eurovision+=Vote(v5,"moldova");
    eurovision+=Vote(v4,"belarus","france","sweden","spain","serbia","moldova","kazakhastan","lithiania");
    eurovision+=Vote(v11,"belarus");
    eurovision+=Vote(v19,"slovenia");
    eurovision+=Vote(v76,"slovenia");
    eurovision+=Vote(v91,"latvia","slovenia");
    eurovision+=Vote(v38,"armenia","turkey","bosnia","armenia","moldova","croatia","germany");
    eurovision+=Vote(v87,"luxembourg");
    eurovision+=Vote(v33,"luxembourg","croatia");
    eurovision+=Vote(v90,"slovenia");
    eurovision+=Vote(v95,"sweden");
    eurovision+=Vote(v31,"latvia");
    eurovision+=Vote(v53,"slovakia","hungary","france","bulgaria","belarus","norway","ireland");
    eurovision+=Vote(v53,"austria","moldova","lithiania","croatia","greece","andora","norway","belarus");
    eurovision+=Vote(v87,"switzerland");
    eurovision+=Vote(v5,"ukraine");
    eurovision+=Vote(v28,"hungary","belarus","russia","sweden","norway","bulgaria","ireland");
    eurovision+=Vote(v17,"ireland");
    eurovision+=Vote(v29,"croatia","hungary");
    eurovision+=Vote(v47,"italy","sweden","croatia","israel","italy","georgia","norway","slovenia","switzerland");
    eurovision+=Vote(v85,"netherlands");
    eurovision+=Vote(v50,"slovenia");
    eurovision+=Vote(v69,"spain");
    eurovision+=Vote(v3,"croatia");
    eurovision+=Vote(v52,"croatia");
    eurovision+=Vote(v53,"austria","serbia","france","lithiania","austria","norway","slovakia","bulgaria","italy");
    eurovision+=Vote(v16,"norway");
    eurovision+=Vote(v3,"bosnia");
    eurovision+=Vote(v26,"cyrpus","serbia","austria","ukraine","germany","georgia","slovakia","andora","switzerland","netherlands");
    eurovision+=Vote(v10,"andora","greece","ireland","hungary","malta","moldova");
    eurovision+=Vote(v44,"slovenia");
    eurovision+=Vote(v65,"georgia");
    eurovision+=Vote(v37,"hungary");
    eurovision+=Vote(v85,"france");
    eurovision+=Vote(v32,"armenia");
    eurovision+=Vote(v5,"ukraine");
    eurovision+=Vote(v31,"croatia");
    eurovision+=Vote(v38,"slovakia","norway");
    eurovision+=Vote(v36,"greece");
    eurovision+=Vote(v40,"bosnia","france","austria","hungary");
    eurovision+=Vote(v78,"moldova","luxembourg","croatia","belarus","latvia","israel");
    eurovision+=Vote(v18,"israel","lithiania","ukraine","bulgaria","spain");
    eurovision+=Vote(v89,"russia","spain","italy","slovenia","turkey","latvia","bosnia");
    eurovision+=Vote(v41,"serbia","bulgaria","latvia");
    eurovision+=Vote(v99,"russia");
    eurovision+=Vote(v35,"croatia");
    eurovision+=Vote(v22,"armenia");
    eurovision+=Vote(v35,"ukraine");
    eurovision+=Vote(v28,"france","andora","russia","serbia","kazakhastan","switzerland","cyrpus","hungary","slovakia","sweden");
    eurovision+=Vote(v8,"france","switzerland","luxembourg");
    eurovision+=Vote(v75,"russia");
    eurovision+=Vote(v84,"slovakia");
    eurovision+=Vote(v28,"ukraine","hungary");
    eurovision+=Vote(v30,"russia","cyrpus","belarus","sweden");
    eurovision+=Vote(v48,"slovakia");
    eurovision+=Vote(v62,"belgium","germany","moldova","greece","turkey","kazakhastan");
    eurovision+=Vote(v39,"russia","slovenia","norway");
    eurovision+=Vote(v58,"estonia");
    eurovision+=Vote(v67,"belarus","bulgaria","greece","malta","netherlands","spain");
    eurovision+=Vote(v81,"italy","slovakia","france","kazakhastan");
    eurovision+=Vote(v81,"hungary","latvia","bulgaria","slovenia","moldova","lithiania");
    eurovision+=Vote(v54,"sweden","israel","luxembourg","turkey","kazakhastan","germany");
    eurovision+=Vote(v57,"bosnia");
    eurovision+=Vote(v76,"norway");
    eurovision+=Vote(v66,"serbia");
    eurovision+=Vote(v79,"russia");
    eurovision+=Vote(v83,"hungary");
    eurovision+=Vote(v31,"slovakia");
    eurovision+=Vote(v75,"germany");
    eurovision+=Vote(v58,"bosnia");
    eurovision+=Vote(v11,"estonia");
    eurovision+=Vote(v23,"estonia");
    eurovision+=Vote(v72,"france");
    eurovision+=Vote(v33,"austria","estonia","germany","croatia","cyrpus");
    eurovision+=Vote(v72,"estonia");
    eurovision+=Vote(v70,"germany");
    eurovision+=Vote(v25,"serbia");
    eurovision+=Vote(v72,"ukraine");
    eurovision+=Vote(v64,"austria","france","estonia","kazakhastan");
    eurovision+=Vote(v25,"ireland");
    eurovision+=Vote(v93,"israel");
    eurovision+=Vote(v56,"hungary","malta","cyrpus");
    eurovision+=Vote(v24,"serbia","moldova","lithiania","croatia","estonia","armenia");
    eurovision+=Vote(v11,"serbia");
    eurovision+=Vote(v74,"serbia","ireland","bulgaria","belgium");
    eurovision+=Vote(v65,"georgia");
    eurovision+=Vote(v8,"greece","andora","switzerland","cyrpus","belarus","belgium","estonia");
    eurovision+=Vote(v8,"sweden","hungary","georgia","netherlands","estonia");
    eurovision+=Vote(v56,"moldova","spain","switzerland","ireland","estonia","ukraine","latvia");
    eurovision+=Vote(v91,"slovenia","spain","bosnia","belgium","cyrpus","italy");
    eurovision+=Vote(v87,"slovenia");
    eurovision+=Vote(v24,"netherlands","belarus","spain","ireland","austria","netherlands","luxembourg","estonia");
    eurovision+=Vote(v83,"netherlands");
    eurovision+=Vote(v20,"spain");
    eurovision+=Vote(v49,"norway");
    eurovision+=Vote(v51,"norway");
    eurovision+=Vote(v23,"netherlands");
    eurovision+=Vote(v10,"bulgaria","germany");
    eurovision+=Vote(v61,"hungary","moldova","bulgaria","switzerland");
    eurovision+=Vote(v31,"netherlands");
    eurovision+=Vote(v34,"belarus","serbia","austria","belgium","greece","ukraine");
    eurovision+=Vote(v47,"georgia","ireland","ukraine","moldova","bulgaria","norway","cyrpus","spain","russia");
    eurovision+=Vote(v3,"netherlands");
    eurovision+=Vote(v70,"latvia");
    eurovision+=Vote(v73,"russia","georgia","belarus","sweden","kazakhastan","bulgaria","serbia","slovakia");
    eurovision+=Vote(v73,"bosnia","serbia","ukraine","norway","bulgaria","slovakia","moldova","croatia","estonia");
    eurovision+=Vote(v6,"switzerland");
    eurovision+=Vote(v59,"austria");
    eurovision+=Vote(v31,"spain");
    eurovision+=Vote(v45,"kazakhastan");
    eurovision+=Vote(v44,"cyrpus");
    eurovision+=Vote(v43,"italy");
    eurovision+=Vote(v25,"malta");
    eurovision+=Vote(v19,"luxembourg");
    eurovision+=Vote(v16,"italy");
    eurovision+=Vote(v65,"latvia");
    eurovision+=Vote(v30,"slovenia","slovakia","cyrpus","croatia");
    eurovision+=Vote(v52,"sweden");
    eurovision+=Vote(v72,"italy");
    eurovision+=Vote(v74,"spain","luxembourg","ireland","greece","france","kazakhastan","israel","georgia");
    eurovision+=Vote(v33,"greece","ukraine","andora","ireland","belarus","armenia");
    eurovision+=Vote(v98,"lithiania");
    eurovision+=Vote(v22,"serbia");
    eurovision+=Vote(v27,"austria");
    eurovision+=Vote(v97,"austria");
    eurovision+=Vote(v26,"austria","slovenia","italy","armenia","france");
    eurovision+=Vote(v78,"switzerland","georgia","lithiania");
    eurovision+=Vote(v29,"serbia","georgia","bulgaria","slovakia","croatia");
    eurovision+=Vote(v21,"france","moldova","netherlands","spain","slovakia","kazakhastan");
    eurovision+=Vote(v85,"belarus");
    eurovision+=Vote(v45,"italy");
    eurovision+=Vote(v74,"switzerland","israel","russia","austria","moldova","germany");
    eurovision+=Vote(v96,"kazakhastan");
    eurovision+=Vote(v35,"andora");
    eurovision+=Vote(v54,"germany","armenia","russia");
    eurovision+=Vote(v37,"luxembourg");
    eurovision+=Vote(v71,"serbia");
    eurovision+=Vote(v72,"estonia");
    eurovision+=Vote(v82,"italy");
    eurovision+=Vote(v20,"switzerland");
    eurovision+=Vote(v63,"belgium");
    eurovision+=Vote(v34,"estonia","italy","malta","hungary","sweden","croatia","lithiania");
    eurovision+=Vote(v17,"ukraine");
    eurovision+=Vote(v1,"italy");
    eurovision+=Vote(v46,"croatia");
    eurovision+=Vote(v84,"andora");
    eurovision+=Vote(v62,"armenia","serbia","slovakia","estonia","france","spain","norway","germany");
    eurovision+=Vote(v75,"slovakia");
    eurovision+=Vote(v46,"georgia");
    eurovision+=Vote(v94,"georgia","luxembourg","andora","spain");
    eurovision+=Vote(v6,"belgium");
    eurovision+=Vote(v43,"austria");
    eurovision+=Vote(v58,"moldova");
    eurovision+=Vote(v73,"belarus","russia","bosnia","norway","belgium","serbia","switzerland");
    eurovision+=Vote(v83,"belgium");
    eurovision+=Vote(v80,"georgia");
    eurovision+=Vote(v98,"sweden");
    cout<<eurovision<<endl;

}
