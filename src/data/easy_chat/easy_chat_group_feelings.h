const u8 gEasyChatWord_Meet[] = _("RENCONTRER");
const u8 gEasyChatWord_Play[] = _("JOUER");
const u8 gEasyChatWord_Hurried[] = _("PRESSÉ");
const u8 gEasyChatWord_Goes[] = _("VA");
const u8 gEasyChatWord_Giddy[] = _("ÉTOURDI");
const u8 gEasyChatWord_Happy[] = _("HEUREUX");
const u8 gEasyChatWord_Happiness[] = _("BONHEUR");
const u8 gEasyChatWord_Excite[] = _("EXCITER");
const u8 gEasyChatWord_Important[] = _("IMPORTANT");
const u8 gEasyChatWord_Funny[] = _("DRÔLE");
const u8 gEasyChatWord_Got[] = _("OBTENU");
const u8 gEasyChatWord_GoHome[] = _("RENTRE CHEZ TOI");
const u8 gEasyChatWord_Disappointed[] = _("DÉÇU");
const u8 gEasyChatWord_Disappoints[] = _("DÉÇOIT");
const u8 gEasyChatWord_Sad[] = _("TRISTE");
const u8 gEasyChatWord_Try[] = _("ESSAYER");
const u8 gEasyChatWord_Tries[] = _("ESSAIS");
const u8 gEasyChatWord_Hears[] = _("ENTEND");
const u8 gEasyChatWord_Think[] = _("PENSER");
const u8 gEasyChatWord_Hear[] = _("ENTENDRE");
const u8 gEasyChatWord_Wants[] = _("VEUT");
const u8 gEasyChatWord_Misheard[] = _("MAL ENTENDU");
const u8 gEasyChatWord_Dislike[] = _("DÉTESTER");
const u8 gEasyChatWord_Angry[] = _("EN COLÈRE");
const u8 gEasyChatWord_Anger[] = _("COLÈRE");
const u8 gEasyChatWord_Scary[] = _("EFFRAYANT");
const u8 gEasyChatWord_Lonesome[] = _("SEUL");
const u8 gEasyChatWord_Disappoint[] = _("DÉCEVOIR");
const u8 gEasyChatWord_Joy[] = _("JOIE");
const u8 gEasyChatWord_Gets[] = _("REÇOIT");
const u8 gEasyChatWord_Never[] = _("JAMAIS");
const u8 gEasyChatWord_Darn[] = _("MINCE");
const u8 gEasyChatWord_Downcast[] = _("DÉCOURAGÉ");
const u8 gEasyChatWord_Incredible[] = _("INCROYABLE");
const u8 gEasyChatWord_Likes[] = _("AIME");
const u8 gEasyChatWord_Dislikes[] = _("N'AIME PAS");
const u8 gEasyChatWord_Boring[] = _("ENNUYEUX");
const u8 gEasyChatWord_Care[] = _("SE SOUCIE");
const u8 gEasyChatWord_Cares[] = _("SE SOUCIE");
const u8 gEasyChatWord_AllRight[] = _("TRÈS BIEN");
const u8 gEasyChatWord_Adore[] = _("ADORER");
const u8 gEasyChatWord_Disaster[] = _("DÉSASTRE");
const u8 gEasyChatWord_Enjoy[] = _("APPRÉCIER");
const u8 gEasyChatWord_Enjoys[] = _("APPRÉCIE");
const u8 gEasyChatWord_Eat[] = _("MANGER");
const u8 gEasyChatWord_Lacking[] = _("MANQUANT");
const u8 gEasyChatWord_Bad[] = _("MAL");
const u8 gEasyChatWord_Hard[] = _("DIFFICILE");
const u8 gEasyChatWord_Terrible[] = _("ÉNORME / TERRIBLE");
const u8 gEasyChatWord_Should[] = _("DEVRAIT");
const u8 gEasyChatWord_Nice[] = _("AGRÉABLE");
const u8 gEasyChatWord_Drink[] = _("BOIRE");
const u8 gEasyChatWord_Surprise[] = _("SURPRISE");
const u8 gEasyChatWord_Fear[] = _("PEUR");
const u8 gEasyChatWord_Want[] = _("VOULOIR");
const u8 gEasyChatWord_Wait[] = _("ATTENDRE");
const u8 gEasyChatWord_Satisfied[] = _("SATISFAIT");
const u8 gEasyChatWord_See[] = _("VOIR");
const u8 gEasyChatWord_Rare[] = _("RARE");
const u8 gEasyChatWord_Negative[] = _("NÉGATIF");
const u8 gEasyChatWord_Done[] = _("TERMINE");
const u8 gEasyChatWord_Danger[] = _("DANGER");
const u8 gEasyChatWord_Defeated[] = _("VICTOIRE DÉFAITE / BATTU");
const u8 gEasyChatWord_Beat[] = _("BATTRE");
const u8 gEasyChatWord_Great[] = _("GÉNIAL");
const u8 gEasyChatWord_Romantic[] = _("ROMANTIQUE");
const u8 gEasyChatWord_Question[] = _("QUESTION");
const u8 gEasyChatWord_Understand[] = _("COMPRENDRE");
const u8 gEasyChatWord_Understands[] = _("COMPREND");

const struct EasyChatWordInfo gEasyChatGroup_Feelings[] = {
    [EC_INDEX(EC_WORD_MEET)] =
    {
        .text = gEasyChatWord_Meet,
        .alphabeticalOrder = 40,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAY)] =
    {
        .text = gEasyChatWord_Play,
        .alphabeticalOrder = 39,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HURRIED)] =
    {
        .text = gEasyChatWord_Hurried,
        .alphabeticalOrder = 24,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOES)] =
    {
        .text = gEasyChatWord_Goes,
        .alphabeticalOrder = 23,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIDDY)] =
    {
        .text = gEasyChatWord_Giddy,
        .alphabeticalOrder = 46,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPY)] =
    {
        .text = gEasyChatWord_Happy,
        .alphabeticalOrder = 63,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPINESS)] =
    {
        .text = gEasyChatWord_Happiness,
        .alphabeticalOrder = 36,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCITE)] =
    {
        .text = gEasyChatWord_Excite,
        .alphabeticalOrder = 37,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMPORTANT)] =
    {
        .text = gEasyChatWord_Important,
        .alphabeticalOrder = 38,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FUNNY)] =
    {
        .text = gEasyChatWord_Funny,
        .alphabeticalOrder = 61,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOT)] =
    {
        .text = gEasyChatWord_Got,
        .alphabeticalOrder = 31,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_HOME)] =
    {
        .text = gEasyChatWord_GoHome,
        .alphabeticalOrder = 62,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPOINTED)] =
    {
        .text = gEasyChatWord_Disappointed,
        .alphabeticalOrder = 27,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPOINTS)] =
    {
        .text = gEasyChatWord_Disappoints,
        .alphabeticalOrder = 12,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAD)] =
    {
        .text = gEasyChatWord_Sad,
        .alphabeticalOrder = 13,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRY)] =
    {
        .text = gEasyChatWord_Try,
        .alphabeticalOrder = 41,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRIES)] =
    {
        .text = gEasyChatWord_Tries,
        .alphabeticalOrder = 22,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEARS)] =
    {
        .text = gEasyChatWord_Hears,
        .alphabeticalOrder = 35,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINK)] =
    {
        .text = gEasyChatWord_Think,
        .alphabeticalOrder = 60,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEAR)] =
    {
        .text = gEasyChatWord_Hear,
        .alphabeticalOrder = 32,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANTS)] =
    {
        .text = gEasyChatWord_Wants,
        .alphabeticalOrder = 51,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISHEARD)] =
    {
        .text = gEasyChatWord_Misheard,
        .alphabeticalOrder = 44,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISLIKE)] =
    {
        .text = gEasyChatWord_Dislike,
        .alphabeticalOrder = 42,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGRY)] =
    {
        .text = gEasyChatWord_Angry,
        .alphabeticalOrder = 43,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGER)] =
    {
        .text = gEasyChatWord_Anger,
        .alphabeticalOrder = 7,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCARY)] =
    {
        .text = gEasyChatWord_Scary,
        .alphabeticalOrder = 53,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LONESOME)] =
    {
        .text = gEasyChatWord_Lonesome,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPOINT)] =
    {
        .text = gEasyChatWord_Disappoint,
        .alphabeticalOrder = 29,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JOY)] =
    {
        .text = gEasyChatWord_Joy,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GETS)] =
    {
        .text = gEasyChatWord_Gets,
        .alphabeticalOrder = 11,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEVER)] =
    {
        .text = gEasyChatWord_Never,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DARN)] =
    {
        .text = gEasyChatWord_Darn,
        .alphabeticalOrder = 10,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWNCAST)] =
    {
        .text = gEasyChatWord_Downcast,
        .alphabeticalOrder = 64,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INCREDIBLE)] =
    {
        .text = gEasyChatWord_Incredible,
        .alphabeticalOrder = 6,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIKES)] =
    {
        .text = gEasyChatWord_Likes,
        .alphabeticalOrder = 5,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISLIKES)] =
    {
        .text = gEasyChatWord_Dislikes,
        .alphabeticalOrder = 47,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BORING)] =
    {
        .text = gEasyChatWord_Boring,
        .alphabeticalOrder = 19,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CARE)] =
    {
        .text = gEasyChatWord_Care,
        .alphabeticalOrder = 17,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CARES)] =
    {
        .text = gEasyChatWord_Cares,
        .alphabeticalOrder = 2,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALL_RIGHT)] =
    {
        .text = gEasyChatWord_AllRight,
        .alphabeticalOrder = 8,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ADORE)] =
    {
        .text = gEasyChatWord_Adore,
        .alphabeticalOrder = 33,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISASTER)] =
    {
        .text = gEasyChatWord_Disaster,
        .alphabeticalOrder = 28,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENJOY)] =
    {
        .text = gEasyChatWord_Enjoy,
        .alphabeticalOrder = 45,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENJOYS)] =
    {
        .text = gEasyChatWord_Enjoys,
        .alphabeticalOrder = 34,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EAT)] =
    {
        .text = gEasyChatWord_Eat,
        .alphabeticalOrder = 26,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LACKING)] =
    {
        .text = gEasyChatWord_Lacking,
        .alphabeticalOrder = 0,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BAD)] =
    {
        .text = gEasyChatWord_Bad,
        .alphabeticalOrder = 21,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HARD)] =
    {
        .text = gEasyChatWord_Hard,
        .alphabeticalOrder = 59,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TERRIBLE)] =
    {
        .text = gEasyChatWord_Terrible,
        .alphabeticalOrder = 30,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOULD)] =
    {
        .text = gEasyChatWord_Should,
        .alphabeticalOrder = 50,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NICE)] =
    {
        .text = gEasyChatWord_Nice,
        .alphabeticalOrder = 1,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DRINK)] =
    {
        .text = gEasyChatWord_Drink,
        .alphabeticalOrder = 66,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SURPRISE)] =
    {
        .text = gEasyChatWord_Surprise,
        .alphabeticalOrder = 58,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEAR)] =
    {
        .text = gEasyChatWord_Fear,
        .alphabeticalOrder = 65,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANT)] =
    {
        .text = gEasyChatWord_Want,
        .alphabeticalOrder = 14,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAIT)] =
    {
        .text = gEasyChatWord_Wait,
        .alphabeticalOrder = 56,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SATISFIED)] =
    {
        .text = gEasyChatWord_Satisfied,
        .alphabeticalOrder = 25,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEE)] =
    {
        .text = gEasyChatWord_See,
        .alphabeticalOrder = 57,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RARE)] =
    {
        .text = gEasyChatWord_Rare,
        .alphabeticalOrder = 49,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEGATIVE)] =
    {
        .text = gEasyChatWord_Negative,
        .alphabeticalOrder = 52,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DONE)] =
    {
        .text = gEasyChatWord_Done,
        .alphabeticalOrder = 48,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DANGER)] =
    {
        .text = gEasyChatWord_Danger,
        .alphabeticalOrder = 18,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEFEATED)] =
    {
        .text = gEasyChatWord_Defeated,
        .alphabeticalOrder = 16,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEAT)] =
    {
        .text = gEasyChatWord_Beat,
        .alphabeticalOrder = 15,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GREAT)] =
    {
        .text = gEasyChatWord_Great,
        .alphabeticalOrder = 67,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROMANTIC)] =
    {
        .text = gEasyChatWord_Romantic,
        .alphabeticalOrder = 68,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUESTION)] =
    {
        .text = gEasyChatWord_Question,
        .alphabeticalOrder = 55,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNDERSTAND)] =
    {
        .text = gEasyChatWord_Understand,
        .alphabeticalOrder = 54,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNDERSTANDS)] =
    {
        .text = gEasyChatWord_Understands,
        .alphabeticalOrder = 20,
        .enabled = TRUE,
    },
};
