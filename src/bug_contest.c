#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "field_player_avatar.h"
#include "overworld.h"
#include "main.h"
#include "pokeblock.h"
#include "safari_zone.h"
#include "script.h"
#include "string_util.h"
#include "tv.h"
#include "constants/game_stat.h"
#include "field_screen_effect.h"

u16 gBugContestStepCounter = 0;
bool8 gBugContestActive = FALSE;
u16 gBugContestSteps = 0;
struct Pokemon gBugContestCaughtMon;

//start
void StartBugContest(void)
{
    gBugContestActive = TRUE;
    gBugContestSteps = 0;
    ZeroMonData(&gBugContestCaughtMon);
}

void EndBugContest(void)
{
    gBugContestActive = FALSE;
}

//steps
bool8 BugContest_TakeStep(void)
{
    if (!FlagGet(FLAG_SYS_BUG_CONTEST_MODE)) // You'll need to define this flag
        return FALSE;

    if (gBugContestStepCounter > 0)
        gBugContestStepCounter--;

    if (gBugContestStepCounter == 0)
    {
        ScriptContext_SetupScript(BugContest_EventScript_TimesUp);
        return TRUE;
    }

    return FALSE;
}

bool8 SetBugContestSteps(struct ScriptContext *ctx)
{
    gBugContestStepCounter = VarGet(VAR_BUG_CONTEST_STEPS);
    return FALSE;
}



//judge
bool8 BugContestJudgeWinner(void)
{
    if (gBugContestCaughtMon.box.level >= 20)
    {
        AddBagItem(ITEM_FIRE_STONE, 1);
        return TRUE;
    }
    else
    {
        AddBagItem(ITEM_WATER_STONE, 1);
        return FALSE;
    }
}
