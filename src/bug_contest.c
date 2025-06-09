// bug_contest.c
#include "global.h"
#include "script.h"
#include "event_data.h"
#include "fieldmap.h"
#include "overworld.h"
#include "bug_contest.h"
#include "constants/flags.h"
#include "constants/maps.h"

static u32 sBugContestStartTime;
static bool8 sBugContestTimerActive;


bool32 GetBugContestFlag(void)
{
    return FlagGet(FLAG_SYS_BUG_CONTEST_MODE);
}


void BugContestRetirePrompt(void)
{
    ScriptContext_SetupScript(BugContest_EventScript_TimesUp);
}

void EnterBugContestMode(void)
{
    FlagSet(FLAG_SYS_BUG_CONTEST_MODE);
    sBugContestStartTime = gMain.vblankCounter1;
    sBugContestTimerActive = TRUE;
}

void ExitBugContestMode(void)
{
    FlagClear(FLAG_SYS_BUG_CONTEST_MODE);
    sBugContestTimerActive = FALSE;
}

bool8 BugContestCheckTimeLimit(void)
{
    if (!FlagGet(FLAG_SYS_BUG_CONTEST_MODE) || !sBugContestTimerActive)
        return FALSE;

    u32 elapsed = gMain.vblankCounter1 - sBugContestStartTime;
    if (elapsed >= BUG_CONTEST_TIME_LIMIT_FRAMES) // 5 minutes by default
    {
        sBugContestTimerActive = FALSE;
        ScriptContext_SetupScript(BugContest_EventScript_TimesUp);
        return TRUE;
    }

    return FALSE;
}
