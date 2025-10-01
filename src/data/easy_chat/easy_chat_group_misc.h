const u8 gEasyChatWord_Highs[] = _("HAUTS");
const u8 gEasyChatWord_Lows[] = _("BAS");
const u8 gEasyChatWord_Um[] = _("Euh");
const u8 gEasyChatWord_Rear[] = _("ARRIÈRE");
const u8 gEasyChatWord_Things[] = _("CHOSES");
const u8 gEasyChatWord_Thing[] = _("CHOSE");
const u8 gEasyChatWord_Below[] = _("EN DESSOUS");
const u8 gEasyChatWord_Above[] = _("AU-DESSUS");
const u8 gEasyChatWord_Back[] = _("DERRIÈRE");
const u8 gEasyChatWord_High[] = _("HAUT");
const u8 gEasyChatWord_Here[] = _("ICI");
const u8 gEasyChatWord_Inside[] = _("À L'INTÉRIEUR");
const u8 gEasyChatWord_Outside[] = _("À L'EXTÉRIEUR");
const u8 gEasyChatWord_Beside[] = _("À CÔTÉ");
const u8 gEasyChatWord_ThisIsItExcl[] = _("C'EST ÇA !");
const u8 gEasyChatWord_This[] = _("CECI");
const u8 gEasyChatWord_Every[] = _("CHAQUE");
const u8 gEasyChatWord_These[] = _("CES");
const u8 gEasyChatWord_TheseWere[] = _("CEUX-CI ÉTAIENT");
const u8 gEasyChatWord_Down[] = _("BAS");
const u8 gEasyChatWord_That[] = _("ÇA");
const u8 gEasyChatWord_ThoseAre[] = _("CEUX-LÀ SONT");
const u8 gEasyChatWord_ThoseWere[] = _("CEUX-LÀ ÉTAIENT");
const u8 gEasyChatWord_ThatsItExcl[] = _("C'EST TOUT !");
const u8 gEasyChatWord_Am[] = _("SUIS / SUIS");
const u8 gEasyChatWord_ThatWas[] = _("ÇA ÉTAIT");
const u8 gEasyChatWord_Front[] = _("AVANT");
const u8 gEasyChatWord_Up[] = _("HAUT");
const u8 gEasyChatWord_Choice[] = _("CHOIX");
const u8 gEasyChatWord_Far[] = _("LOIN");
const u8 gEasyChatWord_Away[] = _("ÉLOIGNÉ");
const u8 gEasyChatWord_Near[] = _("PRÈS");
const u8 gEasyChatWord_Where[] = _("OÙ");
const u8 gEasyChatWord_When[] = _("QUAND");
const u8 gEasyChatWord_What[] = _("QUOI");
const u8 gEasyChatWord_Deep[] = _("PROFOND");
const u8 gEasyChatWord_Shallow[] = _("PEU PROFOND");
const u8 gEasyChatWord_Why[] = _("POURQUOI");
const u8 gEasyChatWord_Confused[] = _("PERDU");
const u8 gEasyChatWord_Opposite[] = _("OPPOSÉ");
const u8 gEasyChatWord_Left[] = _("GAUCHE");
const u8 gEasyChatWord_Right[] = _("DROITE");

const struct EasyChatWordInfo gEasyChatGroup_Misc[] = {
    [EC_INDEX(EC_WORD_HIGHS)] =
    {
        .text = gEasyChatWord_Highs,
        .alphabeticalOrder = 7,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOWS)] =
    {
        .text = gEasyChatWord_Lows,
        .alphabeticalOrder = 24,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UM)] =
    {
        .text = gEasyChatWord_Um,
        .alphabeticalOrder = 30,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REAR)] =
    {
        .text = gEasyChatWord_Rear,
        .alphabeticalOrder = 8,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINGS)] =
    {
        .text = gEasyChatWord_Things,
        .alphabeticalOrder = 6,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THING)] =
    {
        .text = gEasyChatWord_Thing,
        .alphabeticalOrder = 13,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELOW)] =
    {
        .text = gEasyChatWord_Below,
        .alphabeticalOrder = 28,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOVE)] =
    {
        .text = gEasyChatWord_Above,
        .alphabeticalOrder = 38,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BACK)] =
    {
        .text = gEasyChatWord_Back,
        .alphabeticalOrder = 35,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIGH)] =
    {
        .text = gEasyChatWord_High,
        .alphabeticalOrder = 19,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE)] =
    {
        .text = gEasyChatWord_Here,
        .alphabeticalOrder = 16,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSIDE)] =
    {
        .text = gEasyChatWord_Inside,
        .alphabeticalOrder = 29,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUTSIDE)] =
    {
        .text = gEasyChatWord_Outside,
        .alphabeticalOrder = 26,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BESIDE)] =
    {
        .text = gEasyChatWord_Beside,
        .alphabeticalOrder = 10,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS_IS_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThisIsItExcl,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS)] =
    {
        .text = gEasyChatWord_This,
        .alphabeticalOrder = 0,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVERY)] =
    {
        .text = gEasyChatWord_Every,
        .alphabeticalOrder = 11,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE)] =
    {
        .text = gEasyChatWord_These,
        .alphabeticalOrder = 40,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE_WERE)] =
    {
        .text = gEasyChatWord_TheseWere,
        .alphabeticalOrder = 1,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWN)] =
    {
        .text = gEasyChatWord_Down,
        .alphabeticalOrder = 31,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT)] =
    {
        .text = gEasyChatWord_That,
        .alphabeticalOrder = 39,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_ARE)] =
    {
        .text = gEasyChatWord_ThoseAre,
        .alphabeticalOrder = 12,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_WERE)] =
    {
        .text = gEasyChatWord_ThoseWere,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThatsItExcl,
        .alphabeticalOrder = 41,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AM)] =
    {
        .text = gEasyChatWord_Am,
        .alphabeticalOrder = 36,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_WAS)] =
    {
        .text = gEasyChatWord_ThatWas,
        .alphabeticalOrder = 20,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONT)] =
    {
        .text = gEasyChatWord_Front,
        .alphabeticalOrder = 25,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UP)] =
    {
        .text = gEasyChatWord_Up,
        .alphabeticalOrder = 23,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOICE)] =
    {
        .text = gEasyChatWord_Choice,
        .alphabeticalOrder = 17,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAR)] =
    {
        .text = gEasyChatWord_Far,
        .alphabeticalOrder = 18,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWAY)] =
    {
        .text = gEasyChatWord_Away,
        .alphabeticalOrder = 5,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEAR)] =
    {
        .text = gEasyChatWord_Near,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHERE)] =
    {
        .text = gEasyChatWord_Where,
        .alphabeticalOrder = 15,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN)] =
    {
        .text = gEasyChatWord_When,
        .alphabeticalOrder = 14,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT)] =
    {
        .text = gEasyChatWord_What,
        .alphabeticalOrder = 21,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEEP)] =
    {
        .text = gEasyChatWord_Deep,
        .alphabeticalOrder = 22,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHALLOW)] =
    {
        .text = gEasyChatWord_Shallow,
        .alphabeticalOrder = 2,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHY)] =
    {
        .text = gEasyChatWord_Why,
        .alphabeticalOrder = 27,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONFUSED)] =
    {
        .text = gEasyChatWord_Confused,
        .alphabeticalOrder = 34,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OPPOSITE)] =
    {
        .text = gEasyChatWord_Opposite,
        .alphabeticalOrder = 33,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEFT)] =
    {
        .text = gEasyChatWord_Left,
        .alphabeticalOrder = 32,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIGHT)] =
    {
        .text = gEasyChatWord_Right,
        .alphabeticalOrder = 37,
        .enabled = TRUE,
    },
};
