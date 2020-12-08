#ifndef db_HMI_h
#define db_HMI_h

#include ".\udt_HMI.h"

//Vects length definition
const int l_HMI_LL= 5;
const int l_HMI_LB= 5;
const int l_HMI_LS= 5;
const int l_HMI_AS= 6;
const int l_HMI_AA= 6;
const int l_AlarmsL= 5;
const int l_AlarmsA= 5;


//Machine reactions definition
const byte REACT_NORMAL_STOP = 1;
const byte REACT_FAST_STOP = 2;
const byte REACT_WARNING = 3;
const byte REACT_SLOW_SPEED = 4;
const byte REACT_NOTIFICATION = 5;


//byte dei Flag
uint16_t byFlag;

//Logic Selection vars. lVecLL is the lenght of the Logic selection variables array.
udtLogicSelection VectLL[l_HMI_LL];

//Here you can give a name to the variable in the vect, for an easier use in the program. Only Logic selection type is allowed in this array.
struct db_HMI_LL {
	udtLogicSelection *Motor0 = &VectLL[0];
	udtLogicSelection *Motor1 = &VectLL[1];
	udtLogicSelection *Motor2 = &VectLL[2];
	udtLogicSelection *Motor3 = &VectLL[3];
	udtLogicSelection *Motor4 = &VectLL[4];  
};

db_HMI_LL _HMI_LL, *HMI_LL = &_HMI_LL;




//Logic Status vars. lVecLS is the lenght of the Logic status variables array.
udtLogicStatus VectLS[l_HMI_LS];

//Here you can give a name to the variable in the vect, for an easier use in the program. Only Logic status type is allowed in this array.
struct db_HMI_LS {
	udtLogicStatus *Door0 = &VectLS[0];
	udtLogicStatus *Door1 = &VectLS[1];
	udtLogicStatus *Door2 = &VectLS[2];
	udtLogicStatus *Door3 = &VectLS[3];
	udtLogicStatus *Door4 = &VectLS[4];  
};

db_HMI_LS _HMI_LS, *HMI_LS = &_HMI_LS;




//Button vars. lVecB is the lenght of the Button variables array.
udtLogicButton VectLB[l_HMI_LB];

//Here you can give a name to the variable in the vect, for an easier use in the program. Only Button type is allowed in this array.
struct db_HMI_LB {
	udtLogicButton *Jog0 = &VectLB[0];
	udtLogicButton *Jog1 = &VectLB[1];
	udtLogicButton *Jog2 = &VectLB[2];
	udtLogicButton *Jog3 = &VectLB[3];
	udtLogicButton *Jog4 = &VectLB[4];  
};

db_HMI_LB _HMI_LB, *HMI_LB = &_HMI_LB;




//Setpoint vars. lVecS is the lenght of the Setpoint variables array.
udtAnalogicSet VectAS[l_HMI_AS];

//Here you can give a name to the variable in the vect, for an easier use in the program. Only Set type is allowed in this array.
struct db_HMI_AS {
	udtAnalogicSet *Speed0 = &VectAS[0];
	udtAnalogicSet *Speed1 = &VectAS[1];
	udtAnalogicSet *Speed2 = &VectAS[2];
	udtAnalogicSet *Speed3 = &VectAS[3];
	udtAnalogicSet *Speed4 = &VectAS[4];  
};

db_HMI_AS _HMI_AS, *HMI_AS = &_HMI_AS;




//Actual vars. lVecS is the lenght of the Setpoint variables array.
udtAnalogicAct VectAA[l_HMI_AA];

//Here you can give a name to the variable in the vect, for an easier use in the program. Only Act type is allowed in this array.
struct db_HMI_AA {
	udtAnalogicAct *Current0 = &VectAA[0];
	udtAnalogicAct *Current1 = &VectAA[1];
	udtAnalogicAct *Micr1 = &VectAA[2];
	udtAnalogicAct *Current3 = &VectAA[3];
	udtAnalogicAct *Current4 = &VectAA[4];
	udtAnalogicAct *CycleTime = &VectAA[5];
};

db_HMI_AA _HMI_AA, *HMI_AA = &_HMI_AA;




//Alarm vars. lVecAl is the lenght of the Alarm variables array.
udtAlarmLogic VectAlL[l_AlarmsL];

//Here you can give a name to the variable in the vect, for an easier use in the program. Only Alarm type is allowed in this array.
struct db_AlarmsL {
	udtAlarmLogic *Alarm0 = &VectAlL[0];
	udtAlarmLogic *Alarm1 = &VectAlL[1];
	udtAlarmLogic *Alarm2 = &VectAlL[2];
	udtAlarmLogic *Alarm3 = &VectAlL[3];
	udtAlarmLogic *Alarm4 = &VectAlL[4];
};

db_AlarmsL _AlarmsL, *AlarmsL = &_AlarmsL;




//Alarm vars. lVecAl is the lenght of the Alarm variables array.
udtAlarmAnalogic VectAlA[l_AlarmsL];

//Here you can give a name to the variable in the vect, for an easier use in the program. Only Alarm type is allowed in this array.
struct db_AlarmsA {
	udtAlarmAnalogic *Alarm0 = &VectAlA[0];
	udtAlarmAnalogic *Alarm1 = &VectAlA[1];
	udtAlarmAnalogic *Alarm2 = &VectAlA[2];
	udtAlarmAnalogic *Alarm3 = &VectAlA[3];
	udtAlarmAnalogic *Alarm4 = &VectAlA[4];
};

db_AlarmsA _AlarmsA, *AlarmsA = &_AlarmsA;




udtMachineReactions _MachineReactions, *MachineReactions = &_MachineReactions;

//Setpoints limits and indexes initialization
void fb_HMIInit(){

  //Inizializzazione indici Logiche
  for(int i=0; i<l_HMI_LL; i++) {
      udtLogicSelection *lVar = &VectLL[i];
      lVar->inIndex = i;
  }
  
  //Inizializzazione indici setpoints
  for(int i=0; i<l_HMI_AS; i++) {
      udtAnalogicSet *sVar = &VectAS[i];
      sVar->inIndex = i;
  }

  //Inizializzazione Limiti Setpoints
	HMI_AS->Speed0->reMin=20;
	HMI_AS->Speed0->reMax=600;
	HMI_AS->Speed1->reMin=20;
	HMI_AS->Speed1->reMax=600;
	HMI_AS->Speed2->reMin=20;
	HMI_AS->Speed2->reMax=600;
	HMI_AS->Speed3->reMin=20;
	HMI_AS->Speed3->reMax=600;
	HMI_AS->Speed4->reMin=20;
	HMI_AS->Speed4->reMax=600;

  //Inizializzazione reazioni Allarmi
	AlarmsL->Alarm0->byReaction = REACT_WARNING;
	AlarmsL->Alarm1->byReaction = REACT_NORMAL_STOP;
	AlarmsL->Alarm2->byReaction = REACT_WARNING;
	AlarmsL->Alarm3->byReaction = REACT_WARNING;
	AlarmsL->Alarm4->byReaction = REACT_NOTIFICATION;
}

#endif