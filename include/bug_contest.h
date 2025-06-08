#ifndef GUARD_BUG_CONTEST_H
#define GUARD_BUG_CONTEST_H

extern bool8 gBugContestActive;
extern u16 gBugContestSteps;
extern u16 gBugContestStepCounter;
extern struct Pokemon gBugContestCaughtMon;
bool8 BugContestTakeStep(void);


