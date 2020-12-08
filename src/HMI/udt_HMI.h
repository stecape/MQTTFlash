#ifndef udt_HMI_h
#define udt_HMI_h

#include <Arduino.h>

struct udtLogicSelection {
  byte byCmd;
  byte bySt;
  byte byDy;
  byte byPrevSt;
  int inIndex;
  bool boInit;
  bool boQ0;
  bool boQ1;
  bool boQ2;
  bool boQ3;
  bool boQ4;
  bool boQ5;
  bool boQ6;
  bool boQ7;
};

struct udtLogicStatus {
  byte byCmd;
  byte bySt;
  byte byDy;
  byte byPrevSt;
  int inIndex;
  bool boInit;
  bool boQ0;
  bool boQ1;
  bool boQ2;
  bool boQ3;
  bool boQ4;
  bool boQ5;
  bool boQ6;
  bool boQ7;
};

struct udtLogicButton {
  byte byCmd;
  byte bySt;
  byte byDy;
  byte byPrevSt;
  int inIndex;
  bool boQ0;
  bool boQ1;
  bool boQ2;
  bool boQ3;
  bool boQ4;
  bool boQ5;
  bool boQ6;
  bool boQ7;
};

struct udtAnalogicSet {
  float reVal;
  float reHMIVal;
  float rePrevVal;
  byte byDy;
  float reMin;
  float reMax;
  int inIndex;
  bool boInit;
};

struct udtAnalogicAct {
  float reVal;
  float rePrevVal;
  byte byDy;
  float reMin;
  float reMax;
  int inIndex;
};

struct udtAlarmLogic {
  int inIndex;
  byte byReaction;
  bool boTrigger;
  bool boQ;
  byte bySt;
  byte byPrevSt;
  byte byLastStSent;
  bool boAck;
};

struct udtAlarmAnalogic {
  int inIndex;
  byte byReaction;
  bool boTrigger;
  bool boQ;
  byte bySt;
  byte byPrevSt;
  byte byLastStSent;
  bool boAck;
};

struct udtMachineReactions {
  bool boNormalStop;
  bool boFastStop;
  bool boWarning;
  bool boSlowSpeed;
  bool boNotification;
};

#endif