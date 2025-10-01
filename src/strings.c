#include "global.h"
#include "strings.h"
#include "battle_pyramid_bag.h"
#include "item_menu.h"

ALIGNED(4)
const u8 gText_ExpandedPlaceholder_Empty[] = _("");
const u8 gText_ExpandedPlaceholder_Kun[] = _("");
const u8 gText_ExpandedPlaceholder_Chan[] = _("");
const u8 gText_ExpandedPlaceholder_Sapphire[] = _("SAPHIR");
const u8 gText_ExpandedPlaceholder_Ruby[] = _("RUBIS");
const u8 gText_ExpandedPlaceholder_Emerald[] = _("EMERAUDE");
const u8 gText_ExpandedPlaceholder_Aqua[] = _("AQUA");
const u8 gText_ExpandedPlaceholder_Magma[] = _("MAGMA");
const u8 gText_ExpandedPlaceholder_Archie[] = _("ARTHUR");
const u8 gText_ExpandedPlaceholder_Maxie[] = _("MAX");
const u8 gText_ExpandedPlaceholder_Kyogre[] = _("KYOGRE");
const u8 gText_ExpandedPlaceholder_Groudon[] = _("GROUDON");
const u8 gText_ExpandedPlaceholder_Brendan[] = _("BRICE");
const u8 gText_ExpandedPlaceholder_May[] = _("FLORA");
const u8 gText_EggNickname[] = _("OEUF");
const u8 gText_Pokemon[] = _("POKéMON");
const u8 gText_ProfBirchMatchCallName[] = _("PROF. SEKO");
const u8 gText_MainMenuNewGame[] = _("NOUVELLE PARTIE");
const u8 gText_MainMenuContinue[] = _("CONTINUER");
const u8 gText_MainMenuOption[] = _("OPTIONS");
const u8 gText_MainMenuMysteryGift[] = _("CADEAU MYST.");
const u8 gText_MainMenuMysteryGift2[] = _("CADEAU MYST.");
const u8 gText_MainMenuMysteryEvents[] = _("EVENEMENTS MYSTERE");
const u8 gText_WirelessNotConnected[] = _("L'adaptateur sans fil GBA n'est
pas connecté.");
const u8 gText_MysteryGiftCantUse[] = _("Ne pas utiliser l'adaptateur sans fil
avec le CADEAU MYST.");
const u8 gText_MysteryEventsCantUse[] = _("Ne pas utiliser l'adaptateur sans fil
avec les EVENEMENTS MYSTERE.");
const u8 gText_UpdatingSaveExternalData[] = _("Updating save file using external
data. Please wait."); // Unused
const u8 gText_SaveFileUpdated[] = _("The save file has been updated."); // Unused
const u8 gText_SaveFileCorrupted[] = _("Fichier de sauvegarde corrompu.
Le fichier précédent sera chargé.");
const u8 gText_SaveFileErased[] = _("The save file has been erased
due to corruption or damage.");
const u8 gJPText_No1MSubCircuit[] = _("1Mサブきばんが ささっていません！");
const u8 gText_BatteryRunDry[] = _("La pile interne est épuisée.
Vous pouvez continuer à jouer.\pMais les évènements dépendant de
l'heure n'auront pas lieu.");
const u8 gText_Player[] = _("PLAYER"); // Unused
const u8 gText_Pokedex[] = _("POKéDEX"); // Unused
const u8 gText_Time[] = _("TIME");
const u8 gText_Badges[] = _("BADGES"); // Unused
const u8 gText_AButton[] = _("A Button"); // Unused
const u8 gText_BButton[] = _("B Button"); // Unused
const u8 gText_RButton[] = _("R Button"); // Unused
const u8 gText_LButton[] = _("L Button"); // Unused
const u8 gText_Start[] = _("START"); // Unused
const u8 gText_Select[] = _("SELECT"); // Unused
const u8 gText_ControlPad[] = _("+ Control Pad"); // Unused
const u8 gText_LButtonRButton[] = _("L Button  R Button"); // Unused
const u8 gText_Controls[] = _("CONTROLS"); // Unused
ALIGNED(4) const u8 gText_PickOk[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}OK"); // Unused
ALIGNED(4) const u8 gText_Next[] = _("{A_BUTTON}NEXT"); // Unused
ALIGNED(4) const u8 gText_NextBack[] = _("{A_BUTTON}NEXT {B_BUTTON}BACK"); // Unused
ALIGNED(4) const u8 gText_PickNextCancel[] = _("{DPAD_UPDOWN}CHOIX {A_BUTTON}SUIV. {B_BUTTON}ANN.");
ALIGNED(4) const u8 gText_PickCancel[] = _("{DPAD_UPDOWN}CHOIX {A_BUTTON}{B_BUTTON}ANNUL.");
ALIGNED(4) const u8 gText_AButtonExit[] = _("{A_BUTTON}RETOUR");
const u8 gText_BirchBoy[] = _("GARÇON");
const u8 gText_BirchGirl[] = _("FILLE");

const u8 gText_DefaultNameGold[] = _("GOLD");
const u8 gText_DefaultNameKris[] = _("KRIS");

const u8 gText_DefaultNameStu[] = _("STEF");
const u8 gText_DefaultNameMilton[] = _("MANUEL");
const u8 gText_DefaultNameTom[] = _("SEB");
const u8 gText_DefaultNameKenny[] = _("GWENN");
const u8 gText_DefaultNameReid[] = _("ARNO");
const u8 gText_DefaultNameJude[] = _("JULES");
const u8 gText_DefaultNameJaxson[] = _("JOHANN");
const u8 gText_DefaultNameEaston[] = _("THIBAUD");
const u8 gText_DefaultNameWalker[] = _("ALEC");
const u8 gText_DefaultNameTeru[] = _("GIBUS");
const u8 gText_DefaultNameJohnny[] = _("JOHNNY");
const u8 gText_DefaultNameBrett[] = _("FABRICE");
const u8 gText_DefaultNameSeth[] = _("DANIEL");
const u8 gText_DefaultNameTerry[] = _("THOMAS");
const u8 gText_DefaultNameCasey[] = _("GARY");
const u8 gText_DefaultNameDarren[] = _("RUDDY");
const u8 gText_DefaultNameLandon[] = _("THIERRY");
const u8 gText_DefaultNameCollin[] = _("COLLIN");
const u8 gText_DefaultNameStanley[] = _("STAN");
const u8 gText_DefaultNameQuincy[] = _("SEVERIN");
const u8 gText_DefaultNameKimmy[] = _("AGNES");
const u8 gText_DefaultNameTiara[] = _("ARIANE");
const u8 gText_DefaultNameBella[] = _("BELLA");
const u8 gText_DefaultNameJayla[] = _("MAEVA");
const u8 gText_DefaultNameAllie[] = _("PAULINE");
const u8 gText_DefaultNameLianna[] = _("CINDY");
const u8 gText_DefaultNameSara[] = _("SOPHIE");
const u8 gText_DefaultNameMonica[] = _("MONICA");
const u8 gText_DefaultNameCamila[] = _("CATHY");
const u8 gText_DefaultNameAubree[] = _("FANNY");
const u8 gText_DefaultNameRuthie[] = _("ROXANE");
const u8 gText_DefaultNameHazel[] = _("EDITH");
const u8 gText_DefaultNameNadine[] = _("NADINE");
const u8 gText_DefaultNameTanja[] = _("TANIA");
const u8 gText_DefaultNameYasmin[] = _("JANYCE");
const u8 gText_DefaultNameNicola[] = _("CLAIRE");
const u8 gText_DefaultNameLillie[] = _("LILLY");
const u8 gText_DefaultNameTerra[] = _("SOLENE");
const u8 gText_DefaultNameLucy[] = _("CYNTHIA");
const u8 gText_DefaultNameHalie[] = _("MAUD");
const u8 gText_ThisIsAPokemon[] = _("Voici ce qu'on appelle un «POKéMON».{PAUSE 96}\p");
const u8 gText_5MarksPokemon[] = _("????? POKéMON");
const u8 gText_UnkHeight[] = _("{CLEAR_TO 0x0C}???,? m");
const u8 gText_UnkWeight[] = _("???,? kg");
const u8 gText_EmptyPkmnCategory[] = _("                       POKéMON"); // Unused
const u8 gText_EmptyHeight[] = _("{CLEAR_TO 0x0C}    '    »"); // Unused
const u8 gText_EmptyWeight[] = _("        .   lbs."); // Unused
const u8 gText_EmptyPokedexInfo1[] = _(""); // Unused
const u8 gText_CryOf[] = _("CRI DE");
const u8 gText_EmptyPokedexInfo2[] = _(""); // Unused
const u8 gText_SizeComparedTo[] = _("TAILLE COMPAREE A ");
const u8 gText_PokedexRegistration[] = _("Enregistrement du POKéDEX terminé.");
const u8 gText_HTHeight[] = _("HAUT.");
const u8 gText_WTWeight[] = _("POIDS");
const u8 gText_SearchingPleaseWait[] = _("Recherche en cours…
Veuillez patienter.");
const u8 gText_SearchCompleted[] = _("Recherche terminée.");
const u8 gText_NoMatchingPkmnWereFound[] = _("Aucun POKéMON correspondant trouvé.");
const u8 gText_SearchForPkmnBasedOnParameters[] = _("Recherche de POKéMON selon certains
critères.");
const u8 gText_SwitchPokedexListings[] = _("Changer le classement du POKéDEX.");
const u8 gText_ReturnToPokedex[] = _("Revenir au POKéDEX.");
const u8 gText_SelectPokedexMode[] = _("Choisir le mode du POKéDEX.");
const u8 gText_SelectPokedexListingMode[] = _("Choisir le mode de classement du POKéDEX.");
const u8 gText_ListByFirstLetter[] = _("Recherche par la première lettre du nom:
POKéMON vus.");
const u8 gText_ListByBodyColor[] = _("Recherche par la couleur:
POKéMON vus.");
const u8 gText_ListByType[] = _("Recherche par le type:
POKéMON pris uniquement.");
const u8 gText_ExecuteSearchSwitch[] = _("Exécuter recherche/changement.");
const u8 gText_DexHoennTitle[] = _("DEX HOENN");
const u8 gText_DexNatTitle[] = _("DEX NATIONAL");
const u8 gText_DexSortNumericalTitle[] = _("MODE NUMERIQUE");
const u8 gText_DexSortAtoZTitle[] = _("MODE A à Z");
const u8 gText_DexSortHeaviestTitle[] = _("MODE + - LOURD");
const u8 gText_DexSortLightestTitle[] = _("MODE + - LEGER");
const u8 gText_DexSortTallestTitle[] = _("MODE + - GRAND");
const u8 gText_DexSortSmallestTitle[] = _("MODE + - PETIT");
const u8 gText_DexSearchAlphaABC[] = _("ABC");
const u8 gText_DexSearchAlphaDEF[] = _("DEF");
const u8 gText_DexSearchAlphaGHI[] = _("GHI");
const u8 gText_DexSearchAlphaJKL[] = _("JKL");
const u8 gText_DexSearchAlphaMNO[] = _("MNO");
const u8 gText_DexSearchAlphaPQR[] = _("PQR");
const u8 gText_DexSearchAlphaSTU[] = _("STU");
const u8 gText_DexSearchAlphaVWX[] = _("VWX");
const u8 gText_DexSearchAlphaYZ[] = _("YZ");
const u8 gText_DexSearchColorRed[] = _("ROUGE");
const u8 gText_DexSearchColorBlue[] = _("BLEU");
const u8 gText_DexSearchColorYellow[] = _("JAUNE");
const u8 gText_DexSearchColorGreen[] = _("VERT");
const u8 gText_DexSearchColorBlack[] = _("NOIR");
const u8 gText_DexSearchColorBrown[] = _("MARRON");
const u8 gText_DexSearchColorPurple[] = _("VIOLET");
const u8 gText_DexSearchColorGray[] = _("GRIS");
const u8 gText_DexSearchColorWhite[] = _("BLANC");
const u8 gText_DexSearchColorPink[] = _("ROSE");
const u8 gText_DexHoennDescription[] = _("POKéDEX de la région HOENN");
const u8 gText_DexNatDescription[] = _("POKéDEX édition nationale");
const u8 gText_DexSortNumericalDescription[] = _("POKéMON classés selon leur numéro.");
const u8 gText_DexSortAtoZDescription[] = _("POKéMON vus et pris, classés par ordre
alphabétique.");
const u8 gText_DexSortHeaviestDescription[] = _("POKéMON pris, classés du plus lourd au
plus léger.");
const u8 gText_DexSortLightestDescription[] = _("POKéMON pris, classés du plus léger au
plus lourd.");
const u8 gText_DexSortTallestDescription[] = _("POKéMON pris, classés du plus grand au
plus petit.");
const u8 gText_DexSortSmallestDescription[] = _("POKéMON pris, classés du plus petit au
plus grand.");
const u8 gText_DexEmptyString[] = _("");
const u8 gText_DexSearchDontSpecify[] = _("INDIFFERENT");
const u8 gText_DexSearchTypeNone[] = _("AUCUN");
const u8 gText_SelectorArrow[] = _("▶");
const u8 gText_EmptySpace[] = _(" "); // Unused
const u8 gText_WelcomeToHOF[] = _("Bienvenue au PANTHEON!");
const u8 gText_HOFDexRating[] = _("Spotted POKéMON: {STR_VAR_1}!
Owned POKéMON: {STR_VAR_2}!\pPROF. BIRCH's POKéDEX rating!\pPROF. BIRCH: Let's see…\p");
const u8 gText_HOFDexSaving[] = _("SAVING…
DON'T TURN OFF THE POWER.");
const u8 gText_HOFCorrupted[] = _("Données du PANTHEON corrompues.");
const u8 gText_HOFNumber[] = _("PANTHEON Nº {STR_VAR_1}");
const u8 gText_LeagueChamp[] = _("MAITRE DE LA LIGUE!
FELICITATIONS!");
const u8 gText_Number[] = _("Nº");
const u8 gText_Level[] = _("N.");
const u8 gText_IdNumberSlash[] = _("IDNo. /"); // Unused
const u8 gText_Name[] = _("NAME");
const u8 gText_IDNumber[] = _("IDNo.");
const u8 gText_BirchInTrouble[] = _("Le PROF. SEKO a des ennuis!
Choisis un POKéMON et sauve-le!");
const u8 gText_ConfirmStarterChoice[] = _("Prendre ce POKéMON?");
const u8 gText_Pokemon4[] = _("POKéMON"); // Unused
const u8 gText_FlyToWhere[] = _("VOLER où?");
const u8 gMenuText_Use[] = _("USE");
const u8 gMenuText_Toss[] = _("TOSS");
const u8 gMenuText_Register[] = _("REGISTER");
const u8 gMenuText_Give[] = _("GIVE");
const u8 gMenuText_CheckTag[] = _("CHECK TAG");
const u8 gMenuText_Confirm[] = _("CONFIRM");
const u8 gMenuText_Walk[] = _("WALK");
const u8 gText_Cancel[] = _("SORTIR");
const u8 gText_Cancel2[] = _("RETOUR");
const u8 gMenuText_Show[] = _("SHOW");
const u8 gText_EmptyString2[] = _("");
const u8 gText_Cancel7[] = _("CANCEL"); // Unused
const u8 gText_Item[] = _("OBJET");
const u8 gText_Mail[] = _("LETTRE");
const u8 gText_Take[] = _("PRENDR.");
const u8 gText_Store[] = _("DEPOSER");
const u8 gMenuText_Check[] = _("CHECK");
const u8 gText_None[] = _("AUCUN");
const u8 gMenuText_Deselect[] = _("DESELECT");
const u8 gText_ThreeMarks[] = _("???");
const u8 gText_FiveMarks[] = _("?????");
const u8 gText_Slash[] = _("/");
const u8 gText_OneDash[] = _("-");
const u8 gText_TwoDashes[] = _("--");
const u8 gText_ThreeDashes[] = _("---");
const u8 gText_MaleSymbol[] = _("♂");
const u8 gText_FemaleSymbol[] = _("♀");
const u8 gText_LevelSymbol[] = _("N.");
const u8 gText_NumberClear01[] = _("{NO}{CLEAR 0x01}");
const u8 gText_PlusSymbol[] = _("+"); // Unused
const u8 gText_RightArrow[] = _("{RIGHT_ARROW}"); // Unused
const u8 gText_IDNumber2[] = _("{NO}{ID}");
const u8 gText_Space[] = _(" ");
const u8 gText_SelectorArrow2[] = _("▶");
const u8 gText_GoBackPrevMenu[] = _("Retourner au menu
précédent.");
const u8 gText_WhatWouldYouLike[] = _("Que voulez-vous faire?");
const u8 gMenuText_Give2[] = _("GIVE");
const u8 gText_xVar1[] = _("×{STR_VAR_1}");
const u8 gText_Berry2[] = _(" BERRY"); // Unused
const u8 gText_Coins[] = _("{STR_VAR_1} JETONS");
const u8 gText_CloseBag[] = _("FERMER LE SAC");
const u8 gText_Var1IsSelected[] = _("{STR_VAR_1} est
sélectionné.");
const u8 gText_CantWriteMail[] = _("Vous ne pouvez pas
écrire de LETTRE ici.");
const u8 gText_NoPokemon[] = _("Il n'y a pas de
POKéMON.");
const u8 gText_MoveVar1Where[] = _("Où voulez-vous
placer
{STR_VAR_1}?");
const u8 gText_Var1CantBeHeld[] = _("Impossible de tenir {STR_VAR_1}!");
const u8 gText_Var1CantBeHeldHere[] = _("Impossible de tenir {STR_VAR_1} ici.");
const u8 gText_DepositHowManyVar1[] = _("Vous voulez en
déposer combien?");
const u8 gText_DepositedVar2Var1s[] = _("{STR_VAR_1}:
déposé {STR_VAR_2}.");
const u8 gText_NoRoomForItems[] = _("Plus de place pour
stocker des objets.");
const u8 gText_CantStoreImportantItems[] = _("Objets importants
impossibles à
stocker sur le PC!");
const u8 gText_TooImportantToToss[] = _("Cet objet est
trop important
pour le jeter!");
const u8 gText_TossHowManyVar1s[] = _("En jeter combien?");
const u8 gText_ThrewAwayVar2Var1s[] = _("{STR_VAR_1}:
jeté {STR_VAR_2}.");
const u8 gText_ConfirmTossItems[] = _("{STR_VAR_1}:
en jeter {STR_VAR_2}?");

const u8 gText_OakTalk_Clefairy[] = _(
    "MARY: Tonight on POKéMON TALK,\n"
    "a rare moonlight moment!\l"
    "OAK: We're spotlighting the\l"
    "mystical CLEFAIRY!\l"
    "Trainers say they gather at\l"
    "MT. MOON under full moons.\l"
    "MARY: They DANCE in circles!\l"
    "So adorably weird!\l"
    "OAK: A timeless mystery\l"
    "and a sight to behold!\l"
    "MARY: Don't miss the chance!\l"
    "Bring a camera!{PAUSE_UNTIL_PRESS}");

const u8 gText_OakTalk_Lapras[] = _(
    "MARY: A gentle giant takes the\n"
    "stage on today's show!\l"
    "OAK: It's the ocean ferry,\l"
    "our beloved LAPRAS!\l"
    "Seen in UNION CAVE, but only\l"
    "on Evenings. How curious!\l"
    "MARY: So rare and peaceful!\l"
    "And it sings, too!\l"
    "OAK: Some say its songs calm\l"
    "the soul of the sea.\l"
    "MARY: We love you, LAPRAS!\l"
    "Don't ever change!{PAUSE_UNTIL_PRESS}");

const u8 gText_OakTalk_Ampharos[] = _(
    "MARY: Welcome back, everyone!\n"
    "Time for POKéMON TALK!\l"
    "OAK: Let's shine a light on\l"
    "our friend AMPHAROS!\l"
    "Its bright tail glows through\l"
    "fog to guide lost folks.\l"
    "MARY: It's powerful, elegant,\l"
    "and undeniably friendly!\l"
    "OAK: And it's a key part of\l"
    "many lighthouse stories!\l"
    "MARY: More tales soon!\l"
    "Don't touch that dial!{PAUSE_UNTIL_PRESS}");

const u8 gText_OakTalk_Sudowoodo[] = _(
    "MARY: Up next is a real oddball\n"
    "on ROUTE 36...\l"
    "OAK: SUDOWOODO! Looks like a\l"
    "tree, but isn't one!\l"
    "It blocks the road and won't\l"
    "budge without water.\l"
    "MARY: Trainers report it reacts\l"
    "only to a SQUIRTBOTTLE!\l"
    "OAK: That's no bush it's a\l"
    "rock - type in disguise!\l"
    "MARY: Don't be fooled!\l"
    "Give it a splash!{PAUSE_UNTIL_PRESS}");

const u8 gText_OakTalk_RedGyarados[] = _(
    "MARY: Today's story is a\n"
    "shocking one from JOHTO!\l"
    "OAK: Trainers spotted a RED\l"
    "GYARADOS at LAKE OF RAGE!\l"
    "Unlike the usual blue ones,\l"
    "this one's bright crimson!\l"
    "MARY: People say it's linked to\l"
    "some strange radio waves!\l"
    "OAK: A mysterious evolution...\l"
    "Possibly unnatural.\l"
    "MARY: Whatever the cause,\l"
    "it's making waves!{PAUSE_UNTIL_PRESS}");

const u8 gText_OakTalk_Unown[] = _(
    "MARY: Ever visited the RUINS\n"
    "OF ALPH? Spooky stuff!\l"
    "OAK: Strange symbols line the\l"
    "walls - like ancient runes.\l"
    "Inside, you'll find UNOWN...\l"
    "each shaped like letters!\l"
    "MARY: They spell things, maybe?\l"
    "Or just freak us out!\l"
    "OAK: A true puzzle of nature,\l"
    "still unsolved to this day.\l"
    "MARY: Let us know what you\l"
    "think they mean!{PAUSE_UNTIL_PRESS}");

const u8 gText_OakTalk_Snubbull[] = _(
    "MARY: GOLDENROD residents are\n"
    "searching high and low!\l"
    "OAK: A SNUBBULL has gone rogue\l"
    "and is on the run!\l"
    "Usually shy and fussy, it's\l"
    "been seen near the station.\l"
    "MARY: Maybe it's chasing love...\l"
    "or just adventure!\l"
    "OAK: Either way, keep your eyes\l"
    "peeled - and your leash ready.\l"
    "MARY: SNUBBULL, come home!\l"
    "We miss you!{PAUSE_UNTIL_PRESS}");

const u8 gText_OakTalk_Slowpoke[] = _(
    "MARY: Big news from AZALEA\n"
    "TOWN this week!\l"
    "OAK: SLOWPOKE have returned to\l"
    "their well after a crisis!\l"
    "Team ROCKET had been cutting\l"
    "off their tails - horrible!\l"
    "MARY: But a brave young trainer\l"
    "shut them down!\l"
    "OAK: The SLOWPOKE are safe now\l"
    "and happily dozing again.\l"
    "MARY: Justice served and nap\l"
    "time restored!{PAUSE_UNTIL_PRESS}");

const u8 gText_OakTalk_LavenderTower[] = _(
    "MARY: LAVENDER TOWN's tower\n"
    "has changed tunes!\l"
    "OAK: The old ghost tower is\l"
    "now a RADIO STATION!\l"
    "Some locals say it still\l"
    "feels... spooky.\l"
    "MARY: I swear I saw a GASTLY\l"
    "near the mic booth!\l"
    "OAK: Might be static... or\l"
    "specters!\l"
    "MARY: Either way, great music!\l"
    "Probably. Eep!{PAUSE_UNTIL_PRESS}");

const u8 gText_OakTalk_TentacruelWhirl[] = _(
    "MARY: Weird news from the\n"
    "WHIRL ISLANDS today!\l"
    "OAK: TENTACRUEL have been seen\l"
    "surrounding cave entrances!\l"
    "They're massive - and acting\l"
    "almost territorial.\l"
    "MARY: Trainers say they block\l"
    "the way without attacking...\l"
    "OAK: As if guarding something\l"
    "deep beneath the waves.\l"
    "MARY: What are they hiding?\l"
    "Or protecting?{PAUSE_UNTIL_PRESS}");


const u8 gText_RocketRadio[] = _("... ... Ahem, we are
TEAM ROCKET!\lAfter three years of preparation,\lwe have risen again from the ashes!\lGIOVANNI! Can you hear us?\lWe did it!\lWhere is our boss?\lIs he listening?{PAUSE_UNTIL_PRESS}");
const u8 gText_RadioNoSignal[] = _("There's no signal here, try
 somewhere else.{PAUSE_UNTIL_PRESS}");
const u8 gText_UnownMessage[] = _("??????????????????????????????????\l??????????????????????????????????\l??????????????????????????????????\l??????????????????????????????????{PAUSE_UNTIL_PRESS}");
const u8 gText_RadioKantoPokeFlute[] = _("POKé FLUTE RADIO.{PAUSE_UNTIL_PRESS}");

const u8 gText_DadsAdvice[] = _("Conseil de PAPA…
{PLAYER}, chaque chose en son temps!{PAUSE_UNTIL_PRESS}");
const u8 gText_CantDismountBike[] = _("Impossible de descendre de VELO ici.{PAUSE_UNTIL_PRESS}");
const u8 gText_ItemFinderNearby[] = _("Oh!
L'appareil réagit!\pIl doit y avoir un objet enterré
par ici!{PAUSE_UNTIL_PRESS}");
const u8 gText_ItemFinderOnTop[] = _("L'appareil indique qu'il y a
quelque chose juste en dessous!{PAUSE_UNTIL_PRESS}");
const u8 gText_ItemFinderNothing[] = _("… … … … Non!
Pas de réaction.{PAUSE_UNTIL_PRESS}");
const u8 gText_CoinCase[] = _("JETONS:
{STR_VAR_1}{PAUSE_UNTIL_PRESS}");
const u8 gText_BootedUpTM[] = _("CT activée.");
const u8 gText_BootedUpHM[] = _("CS activée.");
const u8 gText_TMHMContainedVar1[] = _("Elle contient
{STR_VAR_1}.\pApprendre {STR_VAR_1}
à un POKéMON?");
const u8 gText_PlayerUsedVar2[] = _("{PLAYER} utilise
{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_RepelEffectsLingered[] = _("Mais le REPOUSSE précédent est
toujours actif.{PAUSE_UNTIL_PRESS}");
const u8 gText_UsedVar2WildLured[] = _("{PLAYER} utilise
{STR_VAR_2}.\pÇa va attirer les POKéMON sauvages.{PAUSE_UNTIL_PRESS}");
const u8 gText_UsedVar2WildRepelled[] = _("{PLAYER} utilise
{STR_VAR_2}.\pÇa va repousser les POKéMON
sauvages.{PAUSE_UNTIL_PRESS}");
const u8 gText_BoxFull[] = _("Les BOITES sont pleines.{PAUSE_UNTIL_PRESS}");
const u8 gText_PowderQty[] = _("QUANT. POUDRE: {STR_VAR_1}{PAUSE_UNTIL_PRESS}");
const u8 gText_TheField[] = _("au jeu");
const u8 gText_TheBattle[] = _("au combat");
const u8 gText_ThePokemonList[] = _("à la LISTE POKéMON");
const u8 gText_TheShop[] = _("au magasin");
const u8 gText_ThePC[] = _("au PC");

const u8 *const gBagMenu_ReturnToStrings[] =
{
    [ITEMMENULOCATION_FIELD]               = gText_TheField,
    [ITEMMENULOCATION_BATTLE]              = gText_TheBattle,
    [ITEMMENULOCATION_PARTY]               = gText_ThePokemonList,
    [ITEMMENULOCATION_SHOP]                = gText_TheShop,
    [ITEMMENULOCATION_BERRY_TREE]          = gText_TheField,
    [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] = gText_TheField,
    [ITEMMENULOCATION_ITEMPC]              = gText_ThePC,
    [ITEMMENULOCATION_FAVOR_LADY]          = gText_TheField,
    [ITEMMENULOCATION_QUIZ_LADY]           = gText_TheField,
    [ITEMMENULOCATION_APPRENTICE]          = gText_TheField,
    [ITEMMENULOCATION_WALLY]               = gText_TheBattle,
    [ITEMMENULOCATION_PCBOX]               = gText_ThePC
};

const u8 *const gPyramidBagMenu_ReturnToStrings[] =
{
    [PYRAMIDBAG_LOC_FIELD]       = gText_TheField,
    [PYRAMIDBAG_LOC_BATTLE]      = gText_TheBattle,
    [PYRAMIDBAG_LOC_PARTY]       = gText_ThePokemonList,
    [PYRAMIDBAG_LOC_CHOOSE_TOSS] = gText_TheField
};

const u8 gText_ReturnToVar1[] = _("Retourner
{STR_VAR_1}.");
const u8 gText_ItemsPocket[] = _("OBJETS");
const u8 gText_PokeBallsPocket[] = _("POKé BALLS");
const u8 gText_TMHMPocket[] = _("CT & CS");
const u8 gText_BerriesPocket[] = _("BAIES");
const u8 gText_KeyItemsPocket[] = _("OBJ. RARES");

const u8 *const gPocketNamesStringsTable[] =
{
    [ITEMS_POCKET] = gText_ItemsPocket,
    [BALLS_POCKET] = gText_PokeBallsPocket,
    [TMHM_POCKET]  = gText_TMHMPocket,
    [BERRIES_POCKET] = gText_BerriesPocket,
    [KEYITEMS_POCKET] = gText_KeyItemsPocket
};

const u8 gText_NumberItem_TMBerry[] = _("{NO}{STR_VAR_1}{CLEAR 0x07}{STR_VAR_2}");
const u8 gText_NumberItem_HM[] = _("{CLEAR_TO 0x11}{STR_VAR_1}{CLEAR 0x05}{STR_VAR_2}");
const u8 gText_SizeSlash[] = _("DIM.:");
const u8 gText_FirmSlash[] = _("FERM.:");
const u8 gText_Var1DotVar2[] = _("{STR_VAR_1},{STR_VAR_2} cm");

// Berry firmness strings
const u8 gBerryFirmnessString_VerySoft[] = _("Very soft");
const u8 gBerryFirmnessString_Soft[] = _("Soft");
const u8 gBerryFirmnessString_Hard[] = _("Hard");
const u8 gBerryFirmnessString_VeryHard[] = _("Very hard");
const u8 gBerryFirmnessString_SuperHard[] = _("Super hard");

const u8 gText_NumberVar1Var2[] = _("{NO}{STR_VAR_1} {STR_VAR_2}");
const u8 gText_BerryTag[] = _("ETIQUETTE");
const u8 gText_RedPokeblock[] = _("{POKEBLOCK} ROUGE");
const u8 gText_BluePokeblock[] = _("{POKEBLOCK} BLEU");
const u8 gText_PinkPokeblock[] = _("{POKEBLOCK} ROSE");
const u8 gText_GreenPokeblock[] = _("{POKEBLOCK} VERT");
const u8 gText_YellowPokeblock[] = _("{POKEBLOCK} JAUNE");
const u8 gText_PurplePokeblock[] = _("{POKEBLOCK} VIOLET");
const u8 gText_IndigoPokeblock[] = _("{POKEBLOCK} INDIGO");
const u8 gText_BrownPokeblock[] = _("{POKEBLOCK} MARRON");
const u8 gText_LiteBluePokeblock[] = _("{POKEBLOCK} BLEU CIEL");
const u8 gText_OlivePokeblock[] = _("{POKEBLOCK} OLIVE");
const u8 gText_GrayPokeblock[] = _("{POKEBLOCK} GRIS");
const u8 gText_BlackPokeblock[] = _("{POKEBLOCK} NOIR");
const u8 gText_WhitePokeblock[] = _("{POKEBLOCK} BLANC");
const u8 gText_GoldPokeblock[] = _("{POKEBLOCK} OR");
const u8 gText_Spicy[] = _("EPICE");
const u8 gText_Dry[] = _("SEC");
const u8 gText_Sweet[] = _("SUCRE");
const u8 gText_Bitter[] = _("AMER");
const u8 gText_Sour[] = _("ACIDE");
const u8 gText_Tasty[] = _("GOUT"); // Unused
const u8 gText_Feel[] = _("FEEL"); // Unused
const u8 gText_StowCase[] = _("Ranger BOITE.");
const u8 gText_LvVar1[] = _("{LV}{STR_VAR_1}");
const u8 gText_ThrowAwayVar1[] = _("Jeter {STR_VAR_1}?");
const u8 gText_Var1ThrownAway[] = _("{STR_VAR_1} a été jeté.");
const u8 gText_Var1AteTheVar2[] = _("{STR_VAR_1} a mangé
{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_Var1HappilyAteVar2[] = _("{STR_VAR_1} a mangé
{STR_VAR_2} joyeusement.{PAUSE_UNTIL_PRESS}");
const u8 gText_Var1DisdainfullyAteVar2[] = _("{STR_VAR_1} a mangé
{STR_VAR_2} à contrecœur.{PAUSE_UNTIL_PRESS}");
const u8 gText_ShopBuy[] = _("ACHETER");
const u8 gText_ShopSell[] = _("VENDRE");
const u8 gText_ShopQuit[] = _("QUITTER");
const u8 gText_SoldOut[] = _("I'm sorry, but that item is sold out.\p");
const u8 gText_SoldOut2[] = _("SOLD OUT");
const u8 gText_InBagVar1[] = _("SAC: {STR_VAR_1}");
const u8 gText_QuitShopping[] = _("Arrêter d'acheter.");
const u8 gText_Var1CertainlyHowMany[] = _("{STR_VAR_1}? Bien sûr.
Combien en voulez-vous?");
const u8 gText_Var1CertainlyHowMany2[] = _("{STR_VAR_2} de {STR_VAR_1}?
Bien sûr. Combien en voulez-vous?");
const u8 gText_Var1AndYouWantedVar2[] = _("{STR_VAR_1}? Vous en voulez {STR_VAR_2}?
Ça fera {STR_VAR_3}¥.");
const u8 gText_Var1IsItThatllBeVar2[] = _("{STR_VAR_1}, n'est-ce pas?
Ça fera {STR_VAR_2}¥. Ça vous convient?");
const u8 gText_YouWantedVar1ThatllBeVar2[] = _("Vous voulez {STR_VAR_1}?
Ça fera {STR_VAR_2}¥. Ça vous convient?");
const u8 gText_HereYouGoThankYou[] = _("Tenez!
Merci infiniment.");
const u8 gText_ThankYouIllSendItHome[] = _("Merci!
Je l'envoie sur votre PC.");
const u8 gText_ThanksIllSendItHome[] = _("Merci!
Je l'envoie sur votre PC à la maison.");
const u8 gText_YouDontHaveMoney[] = _("Vous n'avez pas assez d'argent.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoMoreRoomForThis[] = _("Vous n'avez plus de place pour cela.{PAUSE_UNTIL_PRESS}");
const u8 gText_YouAlreadyHaveThis[] = _("You already have this item.{PAUSE_UNTIL_PRESS}");
const u8 gText_SpaceForVar1Full[] = _("La place pour {STR_VAR_1}
est prise.{PAUSE_UNTIL_PRESS}");
const u8 gText_AnythingElseICanHelp[] = _("Je peux faire quelque chose d'autre?");
const u8 gText_CanIHelpWithAnythingElse[] = _("Vous avez besoin d'autre chose?");
const u8 gText_ThrowInPremierBall[] = _("Je mets une HONOR BALL en plus.{PAUSE_UNTIL_PRESS}");
const u8 gText_ThrowInPremierBalls[] = _("I'll throw in some PREMIER BALLS, too.{PAUSE_UNTIL_PRESS}");
const u8 gText_CantBuyKeyItem[] = _("{STR_VAR_2}? Oh, non.
Je ne peux pas acheter ça.{PAUSE_UNTIL_PRESS}");
const u8 gText_HowManyToSell[] = _("{STR_VAR_2}?
Combien voulez-vous en vendre?");
const u8 gText_ICanPayVar1[] = _("Je peux vous en donner {STR_VAR_1}¥.
Ça vous va?");
const u8 gText_TurnedOverVar1ForVar2[] = _("Obtenu {STR_VAR_1}¥
pour cette vente.");
const u8 gText_PokedollarVar1[] = _("{STR_VAR_1}¥");
const u8 gText_Shift[] = _("ECHANGER");
const u8 gText_SendOut[] = _("ENVOYER");
const u8 gText_Switch2[] = _("ORDRE");
const u8 gText_Summary5[] = _("RESUME");
const u8 gText_Moves[] = _("MOVES"); // Unused
const u8 gText_Enter[] = _("INSCRIRE");
const u8 gText_NoEntry[] = _("RETIRER");
const u8 gText_Take2[] = _("PRENDRE");
const u8 gText_Read2[] = _("LIRE");
const u8 gText_Trade4[] = _("ECHANGE");
const u8 gText_HP3[] = _("PV");
const u8 gText_SpAtk3[] = _("ATQ. SPE.");
const u8 gText_SpDef3[] = _("DEF. SPE.");
const u8 gText_WontHaveEffect[] = _("Ça n'aura aucun effet.{PAUSE_UNTIL_PRESS}");
const u8 gText_CantBeUsedOnPkmn[] = _("C'est inutilisable
sur ce POKéMON.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCantSwitchOut[] = _("{STR_VAR_1} ne peut pas être
échangé!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadyInBattle[] = _("{STR_VAR_1} est déjà au
combat!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadySelected[] = _("{STR_VAR_1} est déjà
sélectionné.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnHasNoEnergy[] = _("{STR_VAR_1} n'a plus d'énergie
pour combattre!{PAUSE_UNTIL_PRESS}");
const u8 gText_CantSwitchWithAlly[] = _("Impossible d'échanger POKéMON
de {STR_VAR_1} avec un des vôtres!{PAUSE_UNTIL_PRESS}");
const u8 gText_EggCantBattle[] = _("Un OEUF ne se bat pas, voyons!{PAUSE_UNTIL_PRESS}");
const u8 gText_CantUseUntilNewBadge[] = _("Impossible de l'utiliser jusqu'à
l'obtention du prochain BADGE.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoMoreThanVar1Pkmn[] = _("Seuls {STR_VAR_1} POKéMON
peuvent participer.{PAUSE_UNTIL_PRESS}");
const u8 gText_SendMailToPC[] = _("Envoyer la LETTRE enlevée
sur votre PC?");
const u8 gText_MailSentToPC[] = _("La LETTRE a été envoyée
sur votre PC.{PAUSE_UNTIL_PRESS}");
const u8 gText_PCMailboxFull[] = _("La BOITE AUX LETTRES
du PC est pleine.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailMessageWillBeLost[] = _("Si la LETTRE est enlevée,
le message sera perdu. D'accord?");
const u8 gText_RemoveMailBeforeItem[] = _("Il faut enlever la LETTRE pour 
pouvoir garder un objet.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnWasGivenItem[] = _("{STR_VAR_1} doit tenir
{STR_VAR_2}!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadyHoldingItemSwitch[] = _("{STR_VAR_1} tient déjà
{STR_VAR_2}!\pEchanger les deux objets?");
const u8 gText_PkmnNotHolding[] = _("{STR_VAR_1} ne tient rien.{PAUSE_UNTIL_PRESS}");
const u8 gText_ReceivedItemFromPkmn[] = _("Reçu {STR_VAR_2} de
{STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailTakenFromPkmn[] = _("La LETTRE a été prise
au POKéMON.{PAUSE_UNTIL_PRESS}");
const u8 gText_SwitchedPkmnItem[] = _("{STR_VAR_1} a remplacé
{STR_VAR_2}!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnHoldingItemCantHoldMail[] = _("Ce POKéMON tient un objet.
Il ne peut pas tenir une LETTRE.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailTransferredFromMailbox[] = _("La LETTRE vient de la
BOITE AUX LETTRES.");
const u8 gText_BagFullCouldNotRemoveItem[] = _("Le SAC est plein. Impossible
d'enlever l'objet au POKéMON.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnLearnedMove3[] = _("{STR_VAR_1} apprend
{STR_VAR_2}!");
const u8 gText_PkmnCantLearnMove[] = _("{STR_VAR_1} et {STR_VAR_2}
ne sont pas compatibles.\pImpossible de l'enseigner.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnNeedsToReplaceMove[] = _("{STR_VAR_1} veut apprendre
{STR_VAR_2}.\pMais {STR_VAR_1} connaît déjà
quatre capacités.\pRemplacer une capacité
par {STR_VAR_2}?");
const u8 gText_StopLearningMove2[] = _("Arrêter d'enseigner
{STR_VAR_2}?");
const u8 gText_MoveNotLearned[] = _("{STR_VAR_1} n'a pas appris la
capacité {STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_WhichMoveToForget[] = _("Oublier quelle capacité?{PAUSE_UNTIL_PRESS}");
const u8 gText_12PoofForgotMove[] = _("1, {PAUSE 15}2, et{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Tadaa!\p{STR_VAR_1} ne sait plus
comment utiliser {STR_VAR_2}.\pEt…{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadyKnows[] = _("{STR_VAR_1} connaît déjà
{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnHPRestoredByVar2[] = _("Les PV de {STR_VAR_1} sont res-
taurés de {STR_VAR_2} points.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCuredOfPoison[] = _("{STR_VAR_1} n'est plus
empoisonné.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCuredOfParalysis[] = _("{STR_VAR_1} n'est plus
paralysé.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnWokeUp2[] = _("{STR_VAR_1} se réveille.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnBurnHealed[] = _("{STR_VAR_1} n'est plus brûlé.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnThawedOut[] = _("{STR_VAR_1} est décongelé.{PAUSE_UNTIL_PRESS}");
const u8 gText_PPWasRestored[] = _("Les PP sont restaurés.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnRegainhedHealth[] = _("{STR_VAR_1} regained health.{PAUSE_UNTIL_PRESS}"); // Unused
const u8 gText_PkmnBecameHealthy[] = _("{STR_VAR_1} retrouve la forme.{PAUSE_UNTIL_PRESS}");
const u8 gText_MovesPPIncreased[] = _("Les PP de {STR_VAR_1}
augmentent.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnElevatedToLvVar2[] = _("{STR_VAR_1} monte au N. {STR_VAR_2}.");
const u8 gText_PkmnBaseVar2StatIncreased[] = _("{STR_VAR_2} de
{STR_VAR_1} augmente.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnFriendlyBaseVar2Fell[] = _("{STR_VAR_1} est devenu amical.
{STR_VAR_2} de base en baisse!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAdoresBaseVar2Fell[] = _("{STR_VAR_1} vous adore!
{STR_VAR_2} de base en baisse!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnFriendlyBaseVar2CantFall[] = _("{STR_VAR_1} est devenu amical.
{STR_VAR_2} de base ne peut pas baisser!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnSnappedOutOfConfusion[] = _("{STR_VAR_1} n'est plus confus.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnGotOverInfatuation[] = _("{STR_VAR_1} n'est plus
amoureux.{PAUSE_UNTIL_PRESS}");
const u8 gText_ThrowAwayItem[] = _("Jeter {STR_VAR_1}?");
const u8 gText_ItemThrownAway[] = _("{STR_VAR_1} a été jeté.{PAUSE_UNTIL_PRESS}");
const u8 gText_TeachWhichPokemon2[] = _("Teach which POKéMON?"); // Unused
const u8 gText_ChoosePokemon[] = _("Choisir un POKéMON.");
const u8 gText_MoveToWhere[] = _("Le mettre où?");
const u8 gText_TeachWhichPokemon[] = _("Enseigner à quel POKéMON?");
const u8 gText_UseOnWhichPokemon[] = _("Utiliser sur quel POKéMON?");
const u8 gText_GiveToWhichPokemon[] = _("Donner à quel POKéMON?");
const u8 gText_DoWhatWithPokemon[] = _("Que faire avec ce PKMN?");
const u8 gText_NothingToCut[] = _("Il n'y a rien à COUPER.");
const u8 gText_CantSurfHere[] = _("On ne peut pas SURFER ici.");
const u8 gText_AlreadySurfing[] = _("Vous SURFEZ déjà.");
const u8 gText_CantUseHere[] = _("Impossible ici.");
const u8 gText_RestoreWhichMove[] = _("Laquelle restaurer?");
const u8 gText_BoostPp[] = _("Augmenter quels PP?");
const u8 gText_DoWhatWithItem[] = _("Que faire avec un objet?");
const u8 gText_NoPokemonForBattle[] = _("Aucun POKéMON utilisable!");
const u8 gText_ChoosePokemon2[] = _("Choisir un POKéMON.");
const u8 gText_NotEnoughHp[] = _("Pas assez de PV…");
const u8 gText_PokemonAreNeeded[] = _("Il faut {STR_VAR_1} POKéMON.");
const u8 gText_PokemonCantBeSame[] = _("Pas les mêmes POKéMON.");
const u8 gText_NoIdenticalHoldItems[] = _("Pas d'objets identiques.");
const u8 gText_CurrentIsTooFast[] = _("Le courant est trop rapide!");
const u8 gText_DoWhatWithMail[] = _("Que faire avec LETTRE?");
const u8 gText_ChoosePokemonCancel[] = _("Choisir un PKMN ou annuler.");
const u8 gText_ChoosePokemonConfirm[] = _("Choisir un PKMN et confirmer.");
const u8 gText_EnjoyCycling[] = _("C'est parti pour une balade!");
const u8 gText_InUseAlready_PM[] = _("Déjà en cours d'utilisation.");
const u8 gText_AlreadyHoldingOne[] = _("{STR_VAR_1} tient déjà
{STR_VAR_2}!");
const u8 gText_NoUse[] = _("Pas utilis.");
const u8 gText_Able[] = _("APTE");
const u8 gText_First_PM[] = _("PREMIER");
const u8 gText_Second_PM[] = _("DEUXIEME");
const u8 gText_Third_PM[] = _("TROISIEME");
const u8 gText_Able2[] = _("APTE");
const u8 gText_NotAble[] = _("PAS APTE");
const u8 gText_Able3[] = _("APTE");
const u8 gText_NotAble2[] = _("PAS APTE");
const u8 gText_Learned[] = _("APPRIS");
const u8 gText_Have[] = _("PORTE");
const u8 gText_DontHave[] = _("PAS D'OBJET");
const u8 gText_Fourth[] = _("QUATRIEME");
const u8 gText_PkmnCantParticipate[] = _("Ce POKéMON ne peut pas participer.{PAUSE_UNTIL_PRESS}");
const u8 gText_CancelParticipation[] = _("Annuler la participation?");
const u8 gText_CancelBattle[] = _("Annuler le combat?");
const u8 gText_ReturnToWaitingRoom[] = _("Retourner à la SALLE D'ATTENTE?");
const u8 gText_CancelChallenge[] = _("Annuler le défi?");
const u8 gText_EscapeFromHere[] = _("Fuir d'ici et retourner à
{STR_VAR_1}?");
const u8 gText_ReturnToHealingSpot[] = _("Retourner au dernier lieu
de soins?");
const u8 gText_PauseUntilPress[] = _("{PAUSE_UNTIL_PRESS}");
const u8 gJPText_AreYouSureYouWantToSpinTradeMon[] = _("{STR_VAR_1}を ぐるぐるこうかんに\nだして よろしいですか？");
ALIGNED(4) const u8 gText_OnlyPkmnForBattle[] = _("C'est votre seul
POKéMON pour combattre.");
ALIGNED(4) const u8 gText_PkmnCantBeTradedNow[] = _("That POKéMON can't be traded
now.");
ALIGNED(4) const u8 gText_EggCantBeTradedNow[] = _("Un OEUF ne peut pas être
échangé maintenant.");
ALIGNED(4) const u8 gText_OtherTrainersPkmnCantBeTraded[] = _("Le POKéMON du DRESSEUR
ne peut pas être échangé.");
ALIGNED(4) const u8 gText_OtherTrainerCantAcceptPkmn[] = _("L'autre DRESSEUR ne peut pas
accepter ce POKéMON maintenant.");
ALIGNED(4) const u8 gText_CantTradeWithTrainer[] = _("Impossible d'échanger avec
ce DRESSEUR maintenant.");
ALIGNED(4) const u8 gText_NotPkmnOtherTrainerWants[] = _("Le DRESSEUR ne cherche
pas ce type de POKéMON.");
ALIGNED(4) const u8 gText_ThatIsntAnEgg[] = _("Ce n'est pas un OEUF.");
const u8 gText_Register[] = _("ENREG.");
const u8 gText_Attack3[] = _("ATTAQUE");
const u8 gText_Defense3[] = _("DEFENSE");
const u8 gText_SpAtk4[] = _("ATQ SP");
const u8 gText_SpDef4[] = _("DEF SP");
const u8 gText_Speed2[] = _("VIT.");
const u8 gText_HP4[] = _("PV");
const u8 gText_EmptyString8[] = _(""); // Unused
const u8 gText_OTSlash[] = _("DO/");
const u8 gText_RentalPkmn[] = _("POKéMON A LOUER");
const u8 gText_TypeSlash[] = _("TYPE/");
const u8 gText_Power[] = _("POUVOIR");
const u8 gText_Accuracy2[] = _("PRECIS.");
const u8 gText_Appeal[] = _("CHARME");
const u8 gText_Jam[] = _("BLOCAG.");
const u8 gText_Status[] = _("STATUT");
const u8 gText_ExpPoints[] = _("POINTS EXP.");
const u8 gText_NextLv[] = _("N. SUIVANT");
const u8 gText_RibbonsVar1[] = _("RUBANS: {STR_VAR_1}");
const u8 gText_EmptyString5[] = _("");
const u8 gText_Events[] = _("EVENTS"); // Unused
const u8 gText_Switch[] = _("CHANG.");
const u8 gText_PkmnInfo[] = _("INFOS POKéMON");
const u8 gText_PkmnSkills[] = _("APTITU. POKéMON");
const u8 gText_BattleMoves[] = _("CAPACITES COMB.");
const u8 gText_ContestMoves[] = _("CAPACITES CONC.");
const u8 gText_Info[] = _("INFO");
const u8 gText_EggWillTakeALongTime[] = _("Cet OEUF va sûrement
mettre du temps à éclore.");
const u8 gText_EggWillTakeSomeTime[] = _("Qu'est-ce qui va en sortir?
Ça va mettre du temps.");
const u8 gText_EggWillHatchSoon[] = _("Il bouge de temps en temps.
Il devrait bientôt éclore.");
const u8 gText_EggAboutToHatch[] = _("Il fait du bruit.
Il va éclore!");
const u8 gText_EggReadyToHatch_Nuzlocke[] = _("Ready to hatch, but blocked
by Nuzlocke encounter!");
const u8 gText_HMMovesCantBeForgotten2[] = _("Impossible d'oublier les
capacités CS maintenant.");
const u8 gText_XNatureMetAtYZ[] = _(
    "{DYNAMIC 0x00}{DYNAMIC 0x02}{DYNAMIC 0x01}{DYNAMIC 0x05}{DYNAMIC 0x06}{DYNAMIC 0x07} nature,\n"
    "met at {LV_2}{DYNAMIC 0x00}{DYNAMIC 0x03}{DYNAMIC 0x01},\n{DYNAMIC 0x00}{DYNAMIC 0x04}{DYNAMIC 0x01}.");

const u8 gText_XNatureHatchedAtYZ[] = _(
    "{DYNAMIC 0x00}{DYNAMIC 0x02}{DYNAMIC 0x01}{DYNAMIC 0x05}{DYNAMIC 0x06}{DYNAMIC 0x07} nature,\n"
    "hatched at {LV_2}{DYNAMIC 0x00}{DYNAMIC 0x03}{DYNAMIC 0x01},\n{DYNAMIC 0x00}{DYNAMIC 0x04}{DYNAMIC 0x01}.");

const u8 gText_XNatureObtainedInTrade[] = _(
    "{DYNAMIC 0x00}{DYNAMIC 0x02}{DYNAMIC 0x01}{DYNAMIC 0x05}{DYNAMIC 0x06}{DYNAMIC 0x07} nature,\n"
    "obtained in a trade.");

const u8 gText_XNatureFatefulEncounter[] = _(
    "{DYNAMIC 0x00}{DYNAMIC 0x02}{DYNAMIC 0x01}{DYNAMIC 0x05}{DYNAMIC 0x06}{DYNAMIC 0x07} nature,\n"
    "obtained in a fateful\nencounter at {LV_2}{DYNAMIC 0x00}{DYNAMIC 0x03}{DYNAMIC 0x01}.");

const u8 gText_XNatureProbablyMetAt[] = _(
    "{DYNAMIC 0x00}{DYNAMIC 0x02}{DYNAMIC 0x01}{DYNAMIC 0x05}{DYNAMIC 0x06}{DYNAMIC 0x07} nature,\n"
    "probably met at {LV_2}{DYNAMIC 0x00}{DYNAMIC 0x03}{DYNAMIC 0x01},\n{DYNAMIC 0x00}{DYNAMIC 0x04}{DYNAMIC 0x01}.");

const u8 gText_XNature[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} de nature");

const u8 gText_XNatureMetSomewhereAt[] = _(
    "{DYNAMIC 0x00}{DYNAMIC 0x02}{DYNAMIC 0x01}{DYNAMIC 0x05}{DYNAMIC 0x06}{DYNAMIC 0x07} nature,\n"
    "met somewhere at {LV_2}{DYNAMIC 0x00}{DYNAMIC 0x03}{DYNAMIC 0x01}.");

const u8 gText_XNatureHatchedSomewhereAt[] = _(
    "{DYNAMIC 0x00}{DYNAMIC 0x02}{DYNAMIC 0x01}{DYNAMIC 0x05}{DYNAMIC 0x06}{DYNAMIC 0x07} nature,\n"
    "hatched somewhere at {LV_2}{DYNAMIC 0x00}{DYNAMIC 0x03}{DYNAMIC 0x01}.");

const u8 gText_OddEggFoundByCouple[] = _("Drôle d'OEUF de PKMN trouvé
par le couple de la PENSION.");
const u8 gText_PeculiarEggNicePlace[] = _("Drôle d'OEUF de PKMN
obtenu dans un bel endroit.");
const u8 gText_PeculiarEggTrade[] = _("Drôle d'OEUF de PKMN
obtenu lors d'un échange.");
const u8 gText_EggFromHotSprings[] = _("Drôle d'OEUF de PKMN obtenu
aux sources chaudes.");
const u8 gText_EggFromTraveler[] = _("Drôle d'OEUF de PKMN
reçu d'un voyageur.");
const u8 gText_ApostropheSBase[] = _("BASE DE {STR_VAR_1}");
const u8 gText_OkayToDeleteFromRegistry[] = _("Supprimer {STR_VAR_1} du
REGISTRE?");
const u8 gText_RegisteredDataDeleted[] = _("Données enregistrées effacées.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoRegistry[] = _("Il n'y a pas de REGISTRE.{PAUSE_UNTIL_PRESS}");
const u8 gText_DelRegist[] = _("EFF. REGIST.");
const u8 gText_Var3Var1SlashVar2[] = _("{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}"); // Unused
const u8 gText_Decorate[] = _("DECORER");
const u8 gText_PutAway[] = _("RANGER");
const u8 gText_Toss2[] = _("JETER");
const u8 gText_Color161Shadow161[] = _("{COLOR 161}{SHADOW 161}");
const u8 gText_PutOutSelectedDecorItem[] = _("Retirer une décoration.");
const u8 gText_StoreChosenDecorInPC[] = _("Stocker une décoration dans le PC.");
const u8 gText_ThrowAwayUnwantedDecors[] = _("Jeter les décorations indésirables.");
const u8 gText_NoDecorations[] = _("Pas de décorations.{PAUSE_UNTIL_PRESS}");
const u8 gText_Desk[] = _("BUREAU");
const u8 gText_Chair[] = _("CHAISE");
const u8 gText_Plant[] = _("PLANTE");
const u8 gText_Ornament[] = _("ORNEMENT");
const u8 gText_Mat[] = _("TAPIS");
const u8 gText_Poster[] = _("POSTER");
const u8 gText_Doll[] = _("POUPEE");
const u8 gText_Cushion[] = _("COUSSIN");
const u8 gText_Gold[] = _("or");
const u8 gText_Silver[] = _("argent");
const u8 gText_PlaceItHere[] = _("Placer ici?");
const u8 gText_CantBePlacedHere[] = _("Impossible ici.");
const u8 gText_CancelDecorating[] = _("Annuler décoration?");
const u8 gText_InUseAlready[] = _("Déjà en cours d'utilisation.");
const u8 gText_NoMoreDecorations[] = _("Impossible de placer plus de
décorations. Le maximum est de {STR_VAR_1}.");
const u8 gText_NoMoreDecorations2[] = _("Impossible de placer plus de
décorations. Le maximum est de {STR_VAR_1}.");
const u8 gText_MustBePlacedOnDesk[] = _("This can't be placed here.
It must be on a DESK, etc."); // Unused
const u8 gText_CantPlaceInRoom[] = _("Vous ne pouvez pas mettre
cette décoration dans votre chambre.");
const u8 gText_CantThrowAwayInUse[] = _("Cette décoration est utilisée.
Elle ne peut pas être jetée.");
const u8 gText_DecorationWillBeDiscarded[] = _("Jeter {STR_VAR_1}.
OK?");
const u8 gText_DecorationThrownAway[] = _("Cette décoration a été jetée.");
const u8 gText_StopPuttingAwayDecorations[] = _("Arrêter de ranger les décorations?");
const u8 gText_NoDecorationHere[] = _("Il n'y a pas de décoration ici.");
const u8 gText_ReturnDecorationToPC[] = _("Ranger cette décoration dans le PC?");
const u8 gText_DecorationReturnedToPC[] = _("Cette décoration est rangée dans le PC.");
const u8 gText_NoDecorationsInUse[] = _("Aucune décoration n'est utilisée.");
const u8 gText_Tristan[] = _("FRANCK");
const u8 gText_Philip[] = _("AYMERIC");
const u8 gText_Dennis[] = _("GILLES");
const u8 gText_Roberto[] = _("ROBERTO");
const u8 gText_TurnOff[] = _("ETEINDRE");
const u8 gText_Decoration[] = _("DECORATION");
const u8 gText_ItemStorage[] = _("STOCKAGE OBJ.");
const u8 gText_Mailbox[] = _("BOITE LETTRE");
const u8 gText_DepositItem[] = _("DEPOSER OBJET");
const u8 gText_WithdrawItem[] = _("RETIRER OBJET");
const u8 gText_TossItem[] = _("JETER OBJET");
const u8 gText_StoreItemsInPC[] = _("Déposer des objets dans le PC.");
const u8 gText_TakeOutItemsFromPC[] = _("Retirer des objets du PC.");
const u8 gText_ThrowAwayItemsInPC[] = _("Jeter des objets stockés dans le PC.");
const u8 gText_NoItems[] = _("Il n'y a pas d'objets.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoRoomInBag[] = _("Il n'y a plus de
place dans le SAC.");
const u8 gText_WithdrawHowManyItems[] = _("Vous voulez en
retirer combien?");
const u8 gText_WithdrawXItems[] = _("{STR_VAR_1}:
retiré {STR_VAR_2}..");
const u8 gText_Read[] = _("LIRE");
const u8 gText_MoveToBag[] = _("METTRE DANS SAC");
const u8 gText_Give2[] = _("DONNER");
const u8 gText_NoMailHere[] = _("Pas de LETTRE ici.{PAUSE_UNTIL_PRESS}");
const u8 gText_WhatToDoWithVar1sMail[] = _("Que faire avec la
LETTRE de {STR_VAR_1}?");
const u8 gText_MessageWillBeLost[] = _("Le message sera perdu.
Continuer?");
const u8 gText_BagIsFull[] = _("Le SAC est plein.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailToBagMessageErased[] = _("La LETTRE a été remise dans le SAC
et son message a été effacé.{PAUSE_UNTIL_PRESS}");
const u8 gText_Dad[] = _("PAPA");
const u8 gText_Mom[] = _("MAMAN");
const u8 gText_Wallace[] = _("MARC");
const u8 gText_Steven[] = _("PIERRE");
const u8 gText_Brawly[] = _("BASTIEN");
const u8 gText_Winona[] = _("ALIZEE");
const u8 gText_Phoebe[] = _("SPECTRA");
const u8 gText_Glacia[] = _("GLACIA");
const u8 gText_Petalburg[] = _("CLEMENTI-VILLE");
const u8 gText_Slateport[] = _("POIVRESSEL");
const u8 gText_Littleroot[] = _("LITTLEROOT"); // Unused. Given the context, Briney may at one point have been able to sail the player here
const u8 gText_Lilycove[] = _("LILYCOVE");     // Unused. Given the context, Briney may at one point have been able to sail the player here
const u8 gText_Dewford[] = _("VILLAGE MYOKARA");
const u8 gText_Enter2[] = _("INSCRI.");
const u8 gText_Info2[] = _("INFO");
const u8 gText_WhatsAContest[] = _("Le CONCOURS");
const u8 gText_TypesOfContests[] = _("Types de CONCOURS");
const u8 gText_Ranks[] = _("Catégories");
const u8 gText_Judging[] = _("Judging"); //unused
const u8 gText_CoolnessContest[] = _("SANG-FROID");
const u8 gText_BeautyContest[] = _("BEAUTE");
const u8 gText_CutenessContest[] = _("GRACE");
const u8 gText_SmartnessContest[] = _("INTELLIGENCE");
const u8 gText_ToughnessContest[] = _("ROBUSTESSE");
const u8 gText_Decoration2[] = _("DECORATION");
const u8 gText_PackUp[] = _("PLIER BAGAGE");
const u8 gText_Count[] = _("COUNT"); //unused
const u8 gText_Registry[] = _("REGISTRE");
const u8 gText_Information[] = _("INFORMATION");
const u8 gText_Mach[] = _("COURSE");
const u8 gText_Acro[] = _("CROSS");
const u8 gText_Psn[] = _("PSN");
const u8 gText_Par[] = _("PAR");
const u8 gText_Slp[] = _("SOM");
const u8 gText_Brn[] = _("BRU");
const u8 gText_Frz[] = _("GEL");
const u8 gText_Toxic[] = _("TOXIC"); // Unused
const u8 gText_Ok3[] = _("OK"); // Unused
const u8 gText_Quit[] = _("QUIT"); // Unused
const u8 gText_SawIt[] = _("Oui");
const u8 gText_NotYet[] = _("Pas encore");
const u8 gText_Yes[] = _("OUI");
const u8 gText_No[] = _("NON");
const u8 gText_Info4[] = _("INFO"); // Unused
const u8 gText_SingleBattle[] = _("COMBAT SOLO");
const u8 gText_DoubleBattle[] = _("COMBAT DUO");
const u8 gText_MultiBattle[] = _("COMBAT MULTI");
const u8 gText_MrBriney[] = _("MR. BRINEY"); // Unused
const u8 gText_Challenge[] = _("RELEVER LE DEFI");
const u8 gText_Info3[] = _("INFORMATIONS");
const u8 gText_Lv50[] = _("NIVEAU 50");
const u8 gText_OpenLevel[] = _("NIVEAU LIBRE");
const u8 gText_FreshWaterAndPrice[] = _("EAU FRAICHE{CLEAR_TO 0x48}200¥");
const u8 gText_SodaPopAndPrice[] = _("SODA COOL{CLEAR_TO 0x48}300¥");
const u8 gText_LemonadeAndPrice[] = _("LIMONADE{CLEAR_TO 0x48}350¥");
const u8 gText_HowToRide[] = _("FAIRE DU VELO");
const u8 gText_HowToTurn[] = _("VIRAGES");
const u8 gText_SandySlopes[] = _("VERSANTS DE SABLE");
const u8 gText_Wheelies[] = _("ROUES ARRIERE");
const u8 gText_BunnyHops[] = _("BUNNY HOPS");
const u8 gText_Jump[] = _("SAUTS");
const u8 gText_Satisfied[] = _("Satisfait");
const u8 gText_Dissatisfied[] = _("Insatisfait");
const u8 gText_DeepSeaTooth[] = _("DENT OCEAN");
const u8 gText_DeepSeaScale[] = _("ECAILLEOCEAN");
const u8 gText_BlueFlute2[] = _("FLUTE BLEUE");
const u8 gText_YellowFlute2[] = _("FLUTE JAUNE");
const u8 gText_RedFlute2[] = _("FLUTE ROUGE");
const u8 gText_WhiteFlute2[] = _("FLUTEBLANCHE");
const u8 gText_BlackFlute2[] = _("FLUTE NOIRE");
const u8 gText_GlassChair[] = _("CHAISE VERRE");
const u8 gText_GlassDesk[] = _("BUREAU VERRE");
const u8 gText_TreeckoDollAndPrice[] = _("POUPEE ARCKO 1000 JETONS");
const u8 gText_TorchicDollAndPrice[] = _("POUP. POUSSIFEU 1000 JET.");
const u8 gText_MudkipDollAndPrice[] = _("POUPEE GOBOU   1000 JETONS");
const u8 gText_RegirockDollAndPrice[] = _("REGIROCK DOLL   9,000 C.");
const u8 gText_RegiceDollAndPrice[] = _("REGICE DOLL       9,000 C.");
const u8 gText_RegisteelDollAndPrice[] = _("REGISTEEL DOLL 9,000 C.");
const u8 gText_50CoinsAndPrice[] = _("  50 COINS      ¥500");
const u8 gText_500CoinsAndPrice[] = _("500 JETONS  10000¥");
const u8 gText_Excellent2[] = _("Excellent!");
const u8 gText_NotSoGood[] = _("Bof.");
const u8 gText_RedShard[] = _("TESSON ROUGE");
const u8 gText_YellowShard[] = _("TESSON JAUNE");
const u8 gText_BlueShard[] = _("TESSON BLEU");
const u8 gText_GreenShard[] = _("TESSON VERT");
const u8 gText_BattleFrontier[] = _("ZONE DE COMBAT");
const u8 gText_Right[] = _("Droite");
const u8 gText_Left[] = _("Gauche");
const u8 gText_TM32AndPrice[] = _("CT32{CLEAR_TO 0x48}1500 JETONS");
const u8 gText_TM29AndPrice[] = _("CT29{CLEAR_TO 0x48}3500 JETONS");
const u8 gText_TM35AndPrice[] = _("CT35{CLEAR_TO 0x48}4000 JETONS");
const u8 gText_TM24AndPrice[] = _("CT24{CLEAR_TO 0x48}4000 JETONS");
const u8 gText_TM13AndPrice[] = _("CT13{CLEAR_TO 0x48}4000 JETONS");
const u8 gText_Cool[] = _("SG-FD");
const u8 gText_Beauty[] = _("BEAUTE");
const u8 gText_Cute[] = _("GRACE");
const u8 gText_Smart[] = _("INTEL.");
const u8 gText_Tough[] = _("ROBUS.");
const u8 gText_Normal[] = _("NORMAL");
const u8 gText_Super[] = _("SUPER");
const u8 gText_Hyper[] = _("HYPER");
const u8 gText_Master[] = _("MASTER");
const u8 gText_Cool2[] = _("SG-FD");
const u8 gText_Beauty2[] = _("BEAUTE");
const u8 gText_Cute2[] = _("GRACE");
const u8 gText_Smart2[] = _("INTEL.");
const u8 gText_Tough2[] = _("ROBUS.");
const u8 gText_Items[] = _("OBJETS");
const u8 gText_Key_Items[] = _("OBJ. RARES");
const u8 gText_Poke_Balls[] = _("BALLS");
const u8 gText_TMs_Hms[] = _("CT & CS");
const u8 gText_Berries2[] = _("BAIES");
const u8 gText_SomeonesPC[] = _("PC de ???");
const u8 gText_BillsPC[] = _("BILL'S PC");
const u8 gText_PlayersPC[] = _("PC de {PLAYER}");
const u8 gText_HallOfFame[] = _("PANTHEON");
const u8 gText_LogOff[] = _("DECONNEXION");
const u8 gText_Opponent[] = _("ADVERSAIRE");
const u8 gText_Tourney_Tree[] = _("TOURNEY TREE");
const u8 gText_ReadyToStart[] = _("READY TO START");
const u8 gText_NormalRank[] = _("CATEGORIE NORMAL");
const u8 gText_SuperRank[] = _("CATEGORIE SUPER");
const u8 gText_HyperRank[] = _("CATEGORIE HYPER");
const u8 gText_MasterRank[] = _("CATEGORIE MASTER");
const u8 gText_Single2[] = _("SOLO");
const u8 gText_Double2[] = _("DUO");
const u8 gText_Multi[] = _("MULTI");
const u8 gText_MultiLink[] = _("MULTI LINK");
const u8 gText_BattleBag[] = _("SAC DE COMBAT");
const u8 gText_HeldItem[] = _("OBJET TENU");
const u8 gText_LinkContest[] = _("CONCOURS EN LINK");
const u8 gText_AboutE_Mode[] = _("A PROPOS DU MODE-E");
const u8 gText_AboutG_Mode[] = _("A PROPOS DU MODE-G");
const u8 gText_E_Mode[] = _("MODE-E");
const u8 gText_G_Mode[] = _("MODE-G");
const u8 gText_MenuOptionPokedex[] = _("POKéDEX");
const u8 gText_MenuOptionPokemon[] = _("POKéMON");
const u8 gText_MenuOptionBag[] = _("SAC");
const u8 gText_MenuOptionPokenav[] = _("POKéNAV");
const u8 gText_Blank[] = _("");
const u8 gText_MenuOptionSave[] = _("SAUVER");
const u8 gText_MenuOptionOption[] = _("OPTIONS");
const u8 gText_MenuOptionExit[] = _("RETOUR");
const u8 gText_5BP[] = _("  5Pco");
const u8 gText_10BP[] = _("10Pco");
const u8 gText_15BP[] = _("15Pco");
const u8 gText_RedTent[] = _("TENTE ROUGE");
const u8 gText_BlueTent[] = _("TENTE BLEUE");
const u8 gText_SouthernIsland[] = _("ILE DU SUD");
const u8 gText_BirthIsland[] = _("ILE AURORE");
const u8 gText_FarawayIsland[] = _("ILE LOINTAINE");
const u8 gText_NavelRock[] = _("ROC NOMBRI");
const u8 gText_Vermilion[] = _("VERMILION");
const u8 gText_Olivine[] = _("OLIVINE");
const u8 gText_ClawFossil[] = _("FOSS. GRIFFE");
const u8 gText_RootFossil[] = _("FOSS. RACINE");
const u8 gText_HelixFossil[] = _("HELIX FOSSIL");
const u8 gText_DomeFossil[] = _("DOME FOSSIL");
const u8 gText_OldAmber[] = _("OLD AMBER");
const u8 gText_No4[] = _("NON");
const u8 gText_IllBattleNow[] = _("Préparation");
const u8 gText_IWon[] = _("Victoire");
const u8 gText_ILost[] = _("Défaite");
const u8 gText_IWontTell[] = _("J'dirai rien!");
const u8 gText_NormalTagMatch[] = _("MATCH NORMAL");
const u8 gText_VarietyTagMatch[] = _("MATCH VARIE");
const u8 gText_UniqueTagMatch[] = _("MATCH UNIQUE");
const u8 gText_ExpertTagMatch[] = _("MATCH EXPERT");
const u8 gText_TradeCenter[] = _("CENTRE TROC");
const u8 gText_Colosseum[] = _("COLISEE");
const u8 gText_RecordCorner[] = _("CENTRE DE DONNEES");
const u8 gText_BerryCrush3[] = _("BROYEUR DE BAIES");
const u8 gText_EmptyLinkService[] = _(""); // Maybe Spin Trade?
const u8 gText_PokemonJump[] = _("SAUT POKéMON");
const u8 gText_DodrioBerryPicking[] = _("ATTRAPE-BAIES DODRIO");
const u8 gText_BecomeLeader[] = _("MENEUR");
const u8 gText_JoinGroup[] = _("JOINDRE");
const u8 gText_TwoStyles[] = _("DEUX STYLES");
const u8 gText_Lv50_3[] = _("NIVEAU 50");
const u8 gText_OpenLevel2[] = _("NIVEAU LIBRE");
const u8 gText_MonTypeAndNo[] = _("TYPE ET Nº DU PKMN");
const u8 gText_HoldItems[] = _("OBJETS TENUS");
const u8 gText_Symbols2[] = _("SYMBOLES");
const u8 gText_Record3[] = _("ENREG.");
const u8 gText_BattlePts[] = _("PTS COMBAT");
const u8 gText_TowerInfo[] = _("INFORMATIONS");
const u8 gText_BattleMon[] = _("POKéMON");
const u8 gText_BattleSalon[] = _("SALON DE COMBAT");
const u8 gText_MultiLink2[] = _("MULTI LINK");
const u8 gText_BattleRules[] = _("REGLES");
const u8 gText_JudgeMind[] = _("JUGE: MENTAL");
const u8 gText_JudgeSkill[] = _("JUGE: TECHNIQUE");
const u8 gText_JudgeBody[] = _("JUGE: PHYSIQUE");
const u8 gText_Matchup[] = _("RENCONTRES");
const u8 gText_TourneyTree[] = _("TABLEAU");
const u8 gText_DoubleKO[] = _("DOUBLE K.O.");
const u8 gText_BasicRules[] = _("REGLES DE BASE");
const u8 gText_SwapPartners[] = _("ECHANGE: POKéMON");
const u8 gText_SwapNumber[] = _("ECHANGE: NOMBRE");
const u8 gText_SwapNotes[] = _("ECHANGE: NOTES");
const u8 gText_OpenLevel3[] = _("NIVEAU LIBRE");
const u8 gText_BattleBasics[] = _("REGLES DE BASE");
const u8 gText_PokemonNature[] = _("NATURE");
const u8 gText_PokemonMoves[] = _("CAPACITES");
const u8 gText_Underpowered[] = _("POTENTIEL");
const u8 gText_WhenInDanger[] = _("EN DANGER");
const u8 gText_PyramidPokemon[] = _("POKéMON SAUVAGES");
const u8 gText_PyramidTrainers[] = _("DRESSEURS");
const u8 gText_PyramidMaze[] = _("LABYRINTHES");
const u8 gText_BattleBag2[] = _("SAC DE COMBAT");
const u8 gText_PokenavAndBag[] = _("POKéNAV ET SAC");
const u8 gText_HeldItems[] = _("OBJETS TENUS");
const u8 gText_PokemonOrder[] = _("ORDRE");
const u8 gText_BattlePokemon[] = _("POKéMON");
const u8 gText_BattleTrainers[] = _("DRESSEURS");
const u8 gText_GoOn[] = _("CONTINUER");
const u8 gText_Record2[] = _("ENREGISTRER");
const u8 gText_Rest[] = _("REPOS");
const u8 gText_Retire[] = _("PARTIR");
const u8 gText_99TimesPlus[] = _("plus de 99");
const u8 gText_1MinutePlus[] = _("plus d'1 min");
const u8 gText_SpaceSeconds[] = _(" secondes");
const u8 gText_SpaceTimes[] = _("");
const u8 gText_Dot[] = _("."); // Unused
const u8 gText_BigGuy[] = _("");
const u8 gText_BigGirl[] = _("");
const u8 gText_Son[] = _("fils");
const u8 gText_Daughter[] = _("fille");
const u8 gText_BlueFlute[] = _("FLUTE BLEUE");
const u8 gText_YellowFlute[] = _("FLUTE JAUNE");
const u8 gText_RedFlute[] = _("FLUTE ROUGE");
const u8 gText_WhiteFlute[] = _("FLUTE BLANCHE");
const u8 gText_BlackFlute[] = _("FLUTE NOIRE");
const u8 gText_PrettyChair[] = _("JOLIE CHAISE");
const u8 gText_PrettyDesk[] = _("JOLI BUREAU");
const u8 gText_1F[] = _("RC");
const u8 gText_2F[] = _("1{SUPER_ER}");
const u8 gText_3F[] = _("2{SUPER_E}");
const u8 gText_4F[] = _("3{SUPER_E}");
const u8 gText_5F[] = _("4{SUPER_E}");
const u8 gText_6F[] = _("5{SUPER_E}");
const u8 gText_7F[] = _("6{SUPER_E}");
const u8 gText_8F[] = _("7{SUPER_E}");
const u8 gText_9F[] = _("8{SUPER_E}");
const u8 gText_10F[] = _("9{SUPER_E}");
const u8 gText_11F[] = _("10{SUPER_E}");
const u8 gText_B1F[] = _("1 SS");
const u8 gText_B2F[] = _("2 SS");
const u8 gText_B3F[] = _("3 SS");
const u8 gText_B4F[] = _("4 SS");
const u8 gText_Rooftop[] = _("TOIT");
const u8 gText_ElevatorNowOn[] = _("Etage:");
const u8 gText_BP[] = _("Pco");
const u8 gText_EnergyPowder50[] = _("POUDRENERGIE{CLEAR_TO 114}{FONT_SMALL}50");
const u8 gText_EnergyRoot80[] = _("RACINENERGIE{CLEAR_TO 114}{FONT_SMALL}80");
const u8 gText_HealPowder50[] = _("POUDRE SOIN{CLEAR_TO 114}{FONT_SMALL}50");
const u8 gText_RevivalHerb300[] = _("HERBE RAPPEL{CLEAR_TO 108}{FONT_SMALL}300");
const u8 gText_Protein1000[] = _("PROTEINE{CLEAR_TO 99}{FONT_SMALL}1000");
const u8 gText_Iron1000[] = _("FER{CLEAR_TO 99}{FONT_SMALL}1000");
const u8 gText_Carbos1000[] = _("CARBONE{CLEAR_TO 99}{FONT_SMALL}1000");
const u8 gText_Calcium1000[] = _("CALCIUM{CLEAR_TO 99}{FONT_SMALL}1000");
const u8 gText_Zinc1000[] = _("ZINC{CLEAR_TO 99}{FONT_SMALL}1000");
const u8 gText_HPUp1000[] = _("PV PLUS{CLEAR_TO 99}{FONT_SMALL}1000");
const u8 gText_PPUp3000[] = _("PP PLUS{CLEAR_TO 99}{FONT_SMALL}3000");
const u8 gText_RankingHall[] = _("CLASSEMENT");
const u8 gText_ExchangeService[] = _("ECHANGE");
const u8 gText_LilycoveCity[] = _("NENUCRIQUE");
const u8 gText_SlateportCity[] = _("POIVRESSEL");
const u8 gText_CaveOfOrigin[] = _("GROTTE ORIGINE");
const u8 gText_MtPyre[] = _("MONT MEMORIA");
const u8 gText_SkyPillar[] = _("PILIER CELESTE");
const u8 gText_DontRemember[] = _("Aucun souvenir");
const u8 gText_Exit[] = _("ANNULER");
const u8 gText_ExitFromBox[] = _("Sortir de la BOITE?");
const u8 gText_WhatDoYouWantToDo[] = _("Que voulez-vous faire?");
const u8 gText_PleasePickATheme[] = _("Choisissez une catégorie.");
const u8 gText_PickTheWallpaper[] = _("Choisissez un fond.");
const u8 gText_PkmnIsSelected[] = _("{DYNAMIC 0} sélectionné.");
const u8 gText_JumpToWhichBox[] = _("Aller dans quelle BOITE?");
const u8 gText_DepositInWhichBox[] = _("Déposer dans quelle BOITE?");
const u8 gText_PkmnWasDeposited[] = _("{DYNAMIC 0} a été déposé.");
const u8 gText_BoxIsFull2[] = _("BOITE pleine.");
const u8 gText_ReleaseThisPokemon[] = _("Relâcher ce POKéMON?");
const u8 gText_PkmnWasReleased[] = _("{DYNAMIC 0} a été relâché.");
const u8 gText_ByeByePkmn[] = _("Bye-bye, {DYNAMIC 0}!");
const u8 gText_MarkYourPkmn[] = _("Marquez votre POKéMON.");
const u8 gText_ThatsYourLastPkmn[] = _("Votre dernier POKéMON!");
const u8 gText_YourPartysFull[] = _("L'équipe est pleine!");
const u8 gText_YoureHoldingAPkmn[] = _("Vous tenez un POKéMON!");
const u8 gText_WhichOneWillYouTake[] = _("Lequel prenez-vous?");
const u8 gText_YouCantReleaseAnEgg[] = _("OEUF impossible à relâcher.");
const u8 gText_ContinueBoxOperations[] = _("Continuer gestion BOITE?");
const u8 gText_PkmnCameBack[] = _("{DYNAMIC 0} est revenu!");
const u8 gText_WasItWorriedAboutYou[] = _("Il s'est inquiété?");
const u8 gText_FourEllipsesExclamation[] = _("… … … … !");
const u8 gText_PleaseRemoveTheMail[] = _("Veuillez enlever la LETTRE.");
const u8 gText_GiveToAPkmn[] = _("DONNER à un POKéMON?");
const u8 gText_PlacedItemInBag[] = _("Objet placé dans le SAC.");
const u8 gText_BagIsFull2[] = _("Le SAC est plein.");
const u8 gText_PutItemInBag[] = _("Placer objet dans le SAC?");
const u8 gText_ItemIsNowHeld[] = _("{DYNAMIC 0} tenu.");
const u8 gText_ChangedToNewItem[] = _("Changé pour {DYNAMIC 0}.");
const u8 gText_MailCantBeStored[] = _("Impossible à ranger!");
const u8 gText_NuzlockeFainted[] = _("{PKMN} fainted in Nuzlocke!");
const u8 gText_DeadPokemon[] = _("This {PKMN} has passed away!");
const u8 gPCText_Cancel[] = _("ANNULER");
const u8 gPCText_Store[] = _("RANGER");
const u8 gPCText_Withdraw[] = _("RETIRER");
const u8 gPCText_Shift[] = _("DÉCALER");
const u8 gPCText_Move[] = _("DÉPLACER");
const u8 gPCText_Place[] = _("PLACER");
const u8 gPCText_Summary[] = _("RÉSUMÉ");
const u8 gPCText_Release[] = _("RELÂCHER");
const u8 gPCText_Mark[] = _("MARQUER");
const u8 gPCText_Name[] = _("NOM");
const u8 gPCText_Jump[] = _("SAUTER");
const u8 gPCText_Wallpaper[] = _("FOND D'ÉCRAN");
const u8 gPCText_Take[] = _("PRENDRE");
const u8 gPCText_Give[] = _("DONNER");
const u8 gPCText_Switch[] = _("ÉCHANGER");
const u8 gPCText_Bag[] = _("BAG");
const u8 gPCText_Info[] = _("INFO");
const u8 gPCText_Scenery1[] = _("SCENERY 1");
const u8 gPCText_Scenery2[] = _("SCENERY 2");
const u8 gPCText_Scenery3[] = _("SCENERY 3");
const u8 gPCText_Etcetera[] = _("ETCETERA");
const u8 gPCText_Friends[] = _("FRIENDS");
const u8 gPCText_Forest[] = _("FOREST");
const u8 gPCText_City[] = _("CITY");
const u8 gPCText_Desert[] = _("DESERT");
const u8 gPCText_Savanna[] = _("SAVANNA");
const u8 gPCText_Crag[] = _("CRAG");
const u8 gPCText_Volcano[] = _("VOLCANO");
const u8 gPCText_Snow[] = _("SNOW");
const u8 gPCText_Cave[] = _("CAVE");
const u8 gPCText_Beach[] = _("BEACH");
const u8 gPCText_Seafloor[] = _("SEAFLOOR");
const u8 gPCText_River[] = _("RIVER");
const u8 gPCText_Sky[] = _("SKY");
const u8 gPCText_PolkaDot[] = _("POLKA-DOT");
const u8 gPCText_Pokecenter[] = _("POKéCENTER");
const u8 gPCText_Machine[] = _("MACHINE");
const u8 gPCText_Simple[] = _("SIMPLE");
const u8 gText_WhatWouldYouLikeToDo[] = _("What would you like to do?"); // Unused
const u8 gText_WithdrawPokemon[] = _("RETIRER POKéMON");
const u8 gText_DepositPokemon[] = _("DEPOSER POKéMON");
const u8 gText_MovePokemon[] = _("DEPLACER POKéMON");
const u8 gText_MoveItems[] = _("DEPLACER OBJETS");
const u8 gText_SeeYa[] = _("SALUT!");
const u8 gText_WithdrawMonDescription[] = _("Intégrer dans l'équipe des POKéMON se
trouvant dans les BOITES.");
const u8 gText_DepositMonDescription[] = _("Déposer des POKéMON de l'équipe
dans des BOITES.");
const u8 gText_MoveMonDescription[] = _("Organiser les POKéMON dans les BOITES
et dans l'équipe.");
const u8 gText_MoveItemsDescription[] = _("Déplacer des objets tenus
dans une BOITE ou par l'équipe.");
const u8 gText_SeeYaDescription[] = _("Retour au menu précédent.");
const u8 gText_JustOnePkmn[] = _("Vous n'avez qu'un POKéMON avec vous.");
const u8 gText_PartyFull[] = _("L'équipe est pleine!");
const u8 gText_Box[] = _("BOITE ");
const u8 gText_CheckMapOfHoenn[] = _("Carte de la région HOENN.");
const u8 gText_CheckPokemonInDetail[] = _("Informations sur les POKéMON.");
const u8 gText_CallRegisteredTrainer[] = _("Appareil pour appeler les DRESSEURS.");
const u8 gText_CheckObtainedRadio[] = _("Tune into the RADIO.");
const u8 gText_PutAwayPokenav[] = _("Ranger le POKéNAV.");
const u8 gText_NoRibbonWinners[] = _("Personne n'a gagné de RUBAN.");
const u8 gText_NoTrainersRegistered[] = _("No TRAINERS are registered."); // Unused
const u8 gText_CheckPartyPokemonInDetail[] = _("Informations sur l'équipe POKéMON.");
const u8 gText_CheckAllPokemonInDetail[] = _("Informations sur tous les POKéMON.");
const u8 gText_ReturnToPokenavMenu[] = _("Retour au menu POKéNAV.");
const u8 gText_FindCoolPokemon[] = _("Chercher POKéMON à sang-froid.");
const u8 gText_FindBeautifulPokemon[] = _("Chercher beaux POKéMON.");
const u8 gText_FindCutePokemon[] = _("Chercher POKéMON gracieux.");
const u8 gText_FindSmartPokemon[] = _("Chercher POKéMON intelligents.");
const u8 gText_FindToughPokemon[] = _("Chercher POKéMON robustes.");
const u8 gText_ReturnToConditionMenu[] = _("Retour au menu CONDITION.");
const u8 gText_NumberRegistered[] = _("Nb dresseurs:");
const u8 gText_NumberOfBattles[] = _("Nb combats:");
const u8 gText_Detail[] = _("DETAIL"); // Unused
const u8 gText_Call2[] = _("CALL"); // Unused
const u8 gText_UnusedExit[] = _("EXIT"); // Unused
const u8 gText_CantCallOpponentHere[] = _("Can't call opponent here."); // Unused
const u8 gText_PokenavMatchCall_Strategy[] = _("STRATEGIE");
const u8 gText_PokenavMatchCall_TrainerPokemon[] = _("POKéMON DU DRESSEUR");
const u8 gText_PokenavMatchCall_SelfIntroduction[] = _("PRESENTATION");
const u8 gText_Pokenav_ClearButtonList[] = _("{CLEAR 0x80}");
const u8 gText_PokenavMap_ZoomedOutButtons[] = _("{A_BUTTON}ZOOM + {B_BUTTON}RETOUR");
extern const u8 gText_PokenavMap_CancelOnly[] = _("{B_BUTTON} Cancel");
const u8 gText_PokenavMap_ZoomedInButtons[] = _("{A_BUTTON}ZOOM - {B_BUTTON}RETOUR");
const u8 gText_PokenavCondition_MonListButtons[] = _("{A_BUTTON}CONDITION {B_BUTTON}RETOUR");
const u8 gText_PokenavCondition_MonStatusButtons[] = _("{A_BUTTON}MARQUAGE {B_BUTTON}RETOUR");
const u8 gText_PokenavCondition_MarkingButtons[] = _("{A_BUTTON}CHOIX {B_BUTTON}RETOUR");
const u8 gText_PokenavMatchCall_TrainerListButtons[] = _("{A_BUTTON}MENU {B_BUTTON}RETOUR");
const u8 gText_PokenavMatchCall_CallMenuButtons[] = _("{A_BUTTON}OK {B_BUTTON}RETOUR");
const u8 gText_PokenavMatchCall_CheckTrainerButtons[] = _("{B_BUTTON}RETOUR");
const u8 gText_PokenavRibbons_MonListButtons[] = _("{A_BUTTON}RUBANS {B_BUTTON}RETOUR");
const u8 gText_PokenavRibbons_RibbonListButtons[] = _("{A_BUTTON}DETAILS {B_BUTTON}RETOUR");
const u8 gText_PokenavRibbons_RibbonCheckButtons[] = _("{B_BUTTON}RETOUR");
const u8 gText_NatureSlash[] = _("NATURE/");
const u8 gText_TrainerCloseBy[] = _("Le DRESSEUR est proche.
Parlez-lui directement.");
const u8 gText_InParty[] = _("DE L'EQUIPE");
const u8 gText_Number2[] = _("Nº ");
const u8 gText_Ribbons[] = _("RIBBONS"); // Unused
const u8 gText_PokemonMaleLv[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}"); // Unused
const u8 gText_PokemonFemaleLv[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}"); // Unused
const u8 gText_PokemonNoGenderLv[] = _("{DYNAMIC 0}/{LV}{DYNAMIC 1}"); // Unused
const u8 gText_Unknown[] = _("INCONNU");
const u8 gText_Call[] = _("APPELS");
const u8 gText_Check[] = _("DETAILS");
const u8 gText_Cancel6[] = _("RETOUR");
const u8 gText_NumberIndex[] = _("Nº {DYNAMIC 0}");
const u8 gText_RibbonsF700[] = _("RUBANS: {DYNAMIC 0}");
const u8 gText_PokemonMaleLv2[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
const u8 gText_PokemonFemaleLv2[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
const u8 gText_PokemonNoGenderLv2[] = _("{DYNAMIC 0}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
const u8 gText_CombineFourWordsOrPhrases[] = _("Combinez 4 mots ou groupes");
const u8 gText_AndMakeYourProfile[] = _("de mots et créez votre profil.");
const u8 gText_CombineSixWordsOrPhrases[] = _("Créez un message avec six mots.");
const u8 gText_AndMakeAMessage[] = _("Max. deux (groupes de) mots/ligne.");
const u8 gText_FindWordsThatDescribeYour[] = _("Choisissez des mots qui");
const u8 gText_FeelingsRightNow[] = _("décrivent votre opinion.");
const u8 gText_WithFourPhrases[] = _("With four phrases,"); // Unused
const u8 gText_CombineNineWordsOrPhrases[] = _("Avec neuf (groupes de) mots,");
const u8 gText_AndMakeAMessage2[] = _("créez un message.");
const u8 gText_ChangeJustOneWordOrPhrase[] = _("Changez un mot ou groupe de mots");
const u8 gText_AndImproveTheBardsSong[] = _("de la chanson de CAPELO.");
const u8 gText_YourProfile[] = _("Votre profil");
const u8 gText_YourFeelingAtTheBattlesStart[] = _("Votre sentiment avant le combat ");
const u8 gText_WhatYouSayIfYouWin[] = _("Ce que vous dites si vous gagnez ");
const u8 gText_WhatYouSayIfYouLose[] = _("Ce que vous dites si vous perdez ");
const u8 gText_TheAnswer[] = _("La réponse");
const u8 gText_TheMailMessage[] = _("Le message de la LETTRE ");
const u8 gText_TheMailSalutation[] = _("The MAIL salutation"); // Unused
const u8 gText_TheBardsSong2[] = _("La nouvelle chanson ");
const u8 gText_CombineTwoWordsOrPhrases[] = _("Avec deux (groupes de) mots,");
const u8 gText_AndMakeATrendySaying[] = _("créez une expression cool.");
const u8 gText_TheTrendySaying[] = _("L'expression cool");
const u8 gText_IsAsShownOkay[] = _("est comme ceci. OK?");
const u8 gText_CombineTwoWordsOrPhrases2[] = _("Avec deux (groupes de) mots,");
const u8 gText_ToTeachHerAGoodSaying[] = _("apprenez-lui une expression.");
const u8 gText_FindWordsWhichFit[] = _("Trouvez des mots pour décrire");
const u8 gText_TheTrainersImage[] = _("l'image du DRESSEUR.");
const u8 gText_TheImage[] = _("L'image");
const u8 gText_OutOfTheListedChoices[] = _("Parmi les choix proposés,");
const u8 gText_SelectTheAnswerToTheQuiz[] = _("sélectionnez la réponse!");
const u8 gText_AndCreateAQuiz[] = _("vous devez créer un quiz!");
const u8 gText_PickAWordOrPhraseAnd[] = _("Choisissez un mot ou un groupe");
const u8 gText_SetTheQuizAnswer[] = _("de mots pour créer la réponse.");
const u8 gText_TheAnswerColon[] = _("La réponse:");
const u8 gText_TheQuizColon[] = _("The quiz:"); // Unused
const u8 gText_ApprenticePhrase[] = _("L'expression de l'apprenti");
const u8 gText_QuitEditing[] = _("Quitter?");
const u8 gText_StopGivingPkmnMail[] = _("Ne plus donner LETTRE à PKMN?");
const u8 gText_AndFillOutTheQuestionnaire[] = _("de mots pour remplir le sondage.");
const u8 gText_LetsReplyToTheInterview[] = _("de mots pour répondre.");
const u8 gText_AllTextBeingEditedWill[] = _("Tout votre texte sera effacé.");
const u8 gText_BeDeletedThatOkay[] = _("D'accord?");
const u8 gText_QuitEditing2[] = _("Quit editing?"); // Unused
const u8 gText_EditedTextWillNotBeSaved[] = _("The edited text will not be saved."); // Unused
const u8 gText_IsThatOkay[] = _("Is that okay?"); // Unused
const u8 gText_PleaseEnterPhraseOrWord[] = _("Please enter a phrase or word."); // Unused
const u8 gText_EntireTextCantBeDeleted[] = _("The entire text can't be deleted.");
const u8 gText_OnlyOnePhrase[] = _("Un seul groupe de mots modifiable.");
const u8 gText_OriginalSongWillBeUsed[] = _("La chanson originale sera reprise.");
const u8 gText_ThatsTrendyAlready[] = _("That's trendy already!"); // Unused
const u8 gText_CombineTwoWordsOrPhrases3[] = _("Combinez deux mots.");
const u8 gText_QuitGivingInfo[] = _("Quit giving information?"); // Unused
const u8 gText_StopGivingPkmnMail2[] = _("Stop giving the POKéMON MAIL?"); // Unused
const u8 gText_CreateAQuiz2[] = _("Create a quiz!"); // Unused
const u8 gText_SetTheAnswer[] = _("Set the answer!"); // Unused
const u8 gText_CancelSelection[] = _("Cancel the selection?"); // Unused
const u8 gText_Profile[] = _("PROFIL");
const u8 gText_AtTheBattlesStart[] = _("Avant le combat.");
const u8 gText_UponWinningABattle[] = _("Après une victoire.");
const u8 gText_UponLosingABattle[] = _("Après une défaite.");
const u8 gText_TheBardsSong[] = _("La chanson de CAPELO");
const u8 gText_WhatsHipAndHappening[] = _("C'est quoi la dernière chose à la mode?");
const u8 gText_Interview[] = _("Interview");
const u8 gText_GoodSaying[] = _("Expression");
const u8 gText_FansQuestion[] = _("Question du fan");
const u8 gJPText_WhatIsTheQuizAnswer[] = _("クイズの こたえは？"); // Unused
const u8 gText_ApprenticesPhrase[] = _("Expression de l'apprenti");
const u8 gText_Questionnaire[] = _("SONDAGE");
const u8 gText_YouCannotQuitHere[] = _("Vous ne pouvez pas quitter ici.");
const u8 gText_SectionMustBeCompleted[] = _("Il faut terminer cette section.");
const u8 gText_F700sQuiz[] = _("Quiz de {DYNAMIC 0}");
const u8 gText_Lady[] = _("DAME QUIZ");
const u8 gText_AfterYouHaveReadTheQuiz[] = _("Après avoir lu la question");
const u8 gText_QuestionPressTheAButton[] = _("du quiz, appuyez sur le bouton A.");
const u8 gText_TheQuizAnswerIs[] = _("La réponse est?");
const u8 gText_LikeToQuitQuiz[] = _("Voulez-vous quitter le défi");
const u8 gText_ChallengeQuestionMark[] = _("du quiz?");
const u8 gText_IsThisQuizOK[] = _("Est-ce que ce quiz est OK?");
const u8 gText_CreateAQuiz[] = _("Créez un quiz!");
const u8 gText_SelectTheAnswer[] = _("Sélectionnez la réponse!");
const u8 gText_LyricsCantBeDeleted[] = _("Impossible d'effacer les paroles.");
const u8 gText_PokemonLeague[] = _("LIGUE POKéMON");
const u8 gText_PokemonCenter[] = _("CENTRE POKéMON");
const u8 gText_GetsAPokeBlockQuestion[] = _(" reçoit un {POKEBLOCK}?");
const u8 gText_Coolness[] = _("Son sang-froid ");
const u8 gText_Beauty3[] = _("Sa beauté ");
const u8 gText_Cuteness[] = _("Sa grâce ");
const u8 gText_Smartness[] = _("Son intelligence ");
const u8 gText_Toughness[] = _("Sa robustesse ");
const u8 gText_WasEnhanced[] = _("a augmenté!");
const u8 gText_NothingChanged[] = _("Rien n'a changé!");
const u8 gText_WontEatAnymore[] = _("Il ne mangera plus…");
const u8 gText_SaveFailedCheckingBackup[] = _("Echec de la sauvegarde.
Vérification de la mémoire de
sauvegarde… Veuillez patienter.
Ç«Durée nécessaire: 1 minute»");
const u8 gText_BackupMemoryDamaged[] = _("Mémoire de sauvegarde endommagée
ou pile interne vide. La progression
ne sera pas sauvegardée.");
const u8 gText_GamePlayCannotBeContinued[] = _("{COLOR RED}«Impossible de continuer à jouer.
Retour à l'écran titre…»");
const u8 gText_CheckCompleted[] = _("Vérification terminée.
Sauvegarde en cours…
Veuillez patienter.");
const u8 gText_SaveCompleteGameCannotContinue[] = _("Sauvegarde terminée.
{COLOR RED}«Impossible de continuer à jouer.
Retour à l'écran titre.»");
const u8 gText_SaveCompletePressA[] = _("Save completed.
{COLOR RED}«Veuillez appuyer sur le bouton A.»");
const u8 gText_Ferry[] = _("FERRY");
const u8 gText_SecretBase[] = _("BASE SECRETE");
const u8 gText_Hideout[] = _("PLANQUE");
const u8 gText_ResetRTCConfirmCancel[] = _("Régler l'heure?
A: Confirmer, B: Annuler");
const u8 gText_PresentTime[] = _("Heure actuelle du jeu");
const u8 gText_PreviousTime[] = _("Heure précédente du jeu");
const u8 gText_PleaseResetTime[] = _("Veuillez régler l'heure.");
const u8 gText_ClockHasBeenReset[] = _("L'horloge a été réglée.
Sauvegarde en cours…");
const u8 gText_SaveCompleted[] = _("Sauvegarde terminée.");
const u8 gText_SaveFailed[] = _("Echec de la sauvegarde…");
const u8 gText_NoSaveFileCantSetTime[] = _("Il n'y a pas de fichier de sauvegarde,
donc l'heure ne peut pas être réglée.");
const u8 gText_InGameClockUsable[] = _("Vous pouvez maintenant régler l'heure.");
const u8 gText_Slots[] = _("MACHINE A SOUS");
const u8 gText_Roulette[] = _("ROULETTE");
const u8 gText_Good[] = _("bon");
const u8 gText_VeryGood[] = _("très bon");
const u8 gText_Excellent[] = _("excellent");
const u8 gText_SoSo[] = _("moyen");
const u8 gText_Bad[] = _("mauvais");
const u8 gText_TheWorst[] = _("immangeable");
const u8 gText_Spicy2[] = _("épicé");
const u8 gText_Dry2[] = _("sec");
const u8 gText_Sweet2[] = _("doux");
const u8 gText_Bitter2[] = _("amer");
const u8 gText_Sour2[] = _("aigre");
const u8 gText_Single[] = _("SOLO");
const u8 gText_Double[] = _("DUO");
const u8 gText_Jackpot[] = _("super prix");
const u8 gText_First[] = _("premier prix");
const u8 gText_Second[] = _("deuxième prix");
const u8 gText_Third[] = _("troisième prix");
const u8 gText_0Pts[] = _("0 pts");
const u8 gText_10Pts[] = _("10 pts");
const u8 gText_20Pts[] = _("20 pts");
const u8 gText_30Pts[] = _("30 pts");
const u8 gText_40Pts[] = _("40 pts");
const u8 gText_50Pts[] = _("50 pts");
const u8 gText_60Pts[] = _("60 pts");
const u8 gText_70Pts[] = _("70 pts");
const u8 gText_80Pts[] = _("80 pts");
const u8 gText_90Pts[] = _("90 pts");
const u8 gText_100Pts[] = _("100 pts");
const u8 gText_QuestionMark[] = _("?");
const u8 gText_KissPoster16BP[] = _("POSTER BAISER{CLEAR_TO 0x5E}16BP");
const u8 gText_KissCushion32BP[] = _("COUSSIN BAISER{CLEAR_TO 0x5E}32BP");
const u8 gText_SmoochumDoll32BP[] = _("POUPEE LIPPOUTI{CLEAR_TO 0x5E}32BP");
const u8 gText_TogepiDoll48BP[] = _("POUPEE TOGEPI{CLEAR_TO 0x5E}48BP");
const u8 gText_MeowthDoll48BP[] = _("POUPEE MIAOUSS{CLEAR_TO 0x5E}48BP");
const u8 gText_ClefairyDoll48BP[] = _("POUPEE MELOFEE{CLEAR_TO 0x5E}48BP");
const u8 gText_DittoDoll48BP[] = _("POUP. METAMORPH{CLEAR_TO 0x5E}48BP");
const u8 gText_CyndaquilDoll80BP[] = _("POUP.HERICENDRE{CLEAR_TO 0x5E}80BP");
const u8 gText_ChikoritaDoll80BP[] = _("POUP. GERMIGNON{CLEAR_TO 0x5E}80BP");
const u8 gText_TotodileDoll80BP[] = _("POUPEE KAIMINUS{CLEAR_TO 0x5E}80BP");
const u8 gText_LaprasDoll128BP[] = _("POUPEE LOKHLASS{CLEAR_TO 0x58}128BP");
const u8 gText_SnorlaxDoll128BP[] = _("POUPEE RONFLEX{CLEAR_TO 0x58}128BP");
const u8 gText_VenusaurDoll256BP[] = _("POUP.FLORIZARRE{CLEAR_TO 0x58}256BP");
const u8 gText_CharizardDoll256BP[] = _("POUP. DRACAUFEU{CLEAR_TO 0x58}256BP");
const u8 gText_BlastoiseDoll256BP[] = _("POUPEE TORTANK{CLEAR_TO 0x58}256BP");
const u8 gText_Protein1BP[] = _("PROTEINE{CLEAR_TO 0x64}1BP");
const u8 gText_Calcium1BP[] = _("CALCIUM{CLEAR_TO 0x64}1BP");
const u8 gText_Iron1BP[] = _("FER{CLEAR_TO 0x64}1BP");
const u8 gText_Zinc1BP[] = _("ZINC{CLEAR_TO 0x64}1BP");
const u8 gText_Carbos1BP[] = _("CARBONE{CLEAR_TO 0x64}1BP");
const u8 gText_HpUp1BP[] = _("PV PLUS{CLEAR_TO 0x64}1BP");
const u8 gText_Leftovers48BP[] = _("RESTES{CLEAR_TO 0x5E}48BP");
const u8 gText_WhiteHerb48BP[] = _("HERBEBLANCHE{CLEAR_TO 0x5E}48BP");
const u8 gText_QuickClaw48BP[] = _("VIVE GRIFFE{CLEAR_TO 0x5E}48BP");
const u8 gText_MentalHerb48BP[] = _("HERBE MENTAL{CLEAR_TO 0x5E}48BP");
const u8 gText_BrightPowder64BP[] = _("POUDRECLAIRE{CLEAR_TO 0x5E}64BP");
const u8 gText_ChoiceBand64BP[] = _("BAND. CHOIX{CLEAR_TO 0x5E}64BP");
const u8 gText_KingsRock64BP[] = _("ROCHE ROYALE{CLEAR_TO 0x5E}64BP");
const u8 gText_FocusBand64BP[] = _("BANDEAU{CLEAR_TO 0x5E}64BP");
const u8 gText_ScopeLens64BP[] = _("LENTILSCOPE{CLEAR_TO 0x5E}64BP");
const u8 gText_Softboiled16BP[] = _("E-COQUE{CLEAR_TO 0x4E}16BP");
const u8 gText_SeismicToss24BP[] = _("FRAPPE ATLAS{CLEAR_TO 0x4E}24BP");
const u8 gText_DreamEater24BP[] = _("DEVOREVE{CLEAR_TO 0x4E}24BP");
const u8 gText_MegaPunch24BP[] = _("ULTIMAPOING{CLEAR_TO 0x4E}24BP");
const u8 gText_MegaKick48BP[] = _("ULTIMAWASHI{CLEAR_TO 0x4E}48BP");
const u8 gText_BodySlam48BP[] = _("PLAQUAGE{CLEAR_TO 0x4E}48BP");
const u8 gText_RockSlide48BP[] = _("EBOULEMENT{CLEAR_TO 0x4E}48BP");
const u8 gText_Counter48BP[] = _("RIPOSTE{CLEAR_TO 0x4E}48BP");
const u8 gText_ThunderWave48BP[] = _("CAGE-ECLAIR{CLEAR_TO 0x4E}48BP");
const u8 gText_SwordsDance48BP[] = _("DANSE-LAMES{CLEAR_TO 0x4E}48BP");
const u8 gText_DefenseCurl16BP[] = _("BOUL'ARMURE{CLEAR_TO 0x4E}16BP");
const u8 gText_Snore24BP[] = _("RONFLEMENT{CLEAR_TO 0x4E}24BP");
const u8 gText_MudSlap24BP[] = _("COUD'BOUE{CLEAR_TO 0x4E}24BP");
const u8 gText_Swift24BP[] = _("METEORES{CLEAR_TO 0x4E}24BP");
const u8 gText_IcyWind24BP[] = _("VENT GLACE{CLEAR_TO 0x4E}24BP");
const u8 gText_Endure48BP[] = _("TENACITE{CLEAR_TO 0x4E}48BP");
const u8 gText_PsychUp48BP[] = _("BOOST{CLEAR_TO 0x4E}48BP");
const u8 gText_IcePunch48BP[] = _("POINGLACE{CLEAR_TO 0x4E}48BP");
const u8 gText_ThunderPunch48BP[] = _("POING-ECLAIR{CLEAR_TO 0x4E}48BP");
const u8 gText_FirePunch48BP[] = _("POING DE FEU{CLEAR_TO 0x4E}48BP");
const u8 gText_FrenzyPlant64BP[] = _("FRENZY PLANT{CLEAR_TO 0x4E}64BP");
const u8 gText_BlastBurn64BP[] = _("BLAST BURN{CLEAR_TO 0x4E}64BP");
const u8 gText_HydroCannon64BP[] = _("HYDRO CANNON{CLEAR_TO 0x4E}64BP");
const u8 gText_PkmnFainted_FldPsn[] = _("{STR_VAR_1} fainted…\p
");
const u8 gText_PkmnSurvived_FldPsn[] = _("{STR_VAR_1} survived the poisoning.
The poison faded away!\p");
const u8 gText_Marco[] = _("MARCUS");
const u8 gText_TrainerCardName[] = _("NOM ");
const u8 gText_TrainerCardIDNo[] = _("NºID /");
const u8 gText_TrainerCardMoney[] = _("ARGENT");
const u8 gText_PokeDollar[] = _("¥"); // Unused
const u8 gText_TrainerCardPokedex[] = _("POKéDEX");
const u8 gText_EmptyString6[] = _("");
const u8 gText_Colon2[] = _(":");
const u8 gText_Points[] = _(" points"); // Unused
const u8 gText_TrainerCardTime[] = _("DUREE JEU");
const u8 gJPText_BattlePoints[] = _("ゲ-ムポイント"); // Unused. Name presumed, translation is Game Points
const u8 gText_Var1sTrainerCard[] = _("CARTE DE DRESSEUR de {STR_VAR_1}");
const u8 gText_HallOfFameDebut[] = _("PANTHEON Nº 1");
const u8 gText_LinkBattles[] = _("COMBATS EN LINK");
const u8 gText_LinkCableBattles[] = _("COMBATS CABLE LINK");
const u8 gText_WinsLosses[] = _("V:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  D:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
const u8 gText_PokemonTrades[] = _("ECHANGES DE POKéMON");
const u8 gText_UnionTradesAndBattles[] = _("ECHANGE UNION & COMBATS");
const u8 gText_BerryCrush[] = _("BROYEUR DE BAIES");
const u8 gText_WaitingTrainerFinishReading[] = _("En attente… L'autre DRESSEUR doit
finir de lire votre CARTE DE DRESSEUR.");
const u8 gText_PokeblocksWithFriends[] = _("{POKEBLOCK}S EN LINK");
const u8 gText_NumPokeblocks[] = _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
const u8 gText_WonContestsWFriends[] = _("CONCOURS EN LINK GAGNES");
const u8 gText_BattlePtsWon[] = _("POINT(S) DE COMBAT GAGNE(S)");
const u8 gText_NumBP[] = _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Pco");
const u8 gText_BattleTower[] = _("BATTLE TOWER");
const u8 gText_WinsStraight[] = _("W/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  STRAIGHT/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}");
const u8 gText_BattleTower2[] = _("TOUR DE COMBAT");
const u8 gText_BattleDome[] = _("DOME DE COMBAT");
const u8 gText_BattlePalace[] = _("PALACE DE COMBAT");
const u8 gText_BattleFactory[] = _("USINE DE COMBAT");
const u8 gText_BattleArena[] = _("DOJO DE COMBAT");
const u8 gText_BattlePike[] = _("REPTILE DE COMBAT");
const u8 gText_BattlePyramid[] = _("PYRAMIDE DE COMBAT");
const u8 gText_Easy[] = _("EASY");
const u8 gText_Hard[] = _("HARD");
const u8 gText_Modern[] = _("MODERN");
const u8 gText_Classic[] = _("CLASSIC");
//HnS texts
const u8 gText_Sunday[] = _("SUNDAY");
const u8 gText_Monday[] = _("MONDAY");
const u8 gText_Tuesday[] = _("TUESDAY");
const u8 gText_Wednesday[] = _("WEDNESDAY");
const u8 gText_Thursday[] = _("THURSDAY");
const u8 gText_Friday[] = _("FRIDAY");
const u8 gText_Saturday[] = _("SATURDAY");

const u8 gText_LoveBall[] =     _("LOVE    / PECHA  / (FRY/PSY)");
const u8 gText_Lure[] =         _("LURE    / RAWST  / (WTR/DRG)");
const u8 gText_FriendBall[] =   _("FRIEND / CHERI  / (BUG/GRS)");
const u8 gText_Heavy[] =        _("HEAVY   / ORAN   / (RCK/GND/STL)");
const u8 gText_Moon[] =         _("MOON    / CHESTO / (DRK/GST/PSN)");
const u8 gText_Fast[] =         _("FAST    / ASPEAR / (ELC/FIG/FIR)");
const u8 gText_LevelBall[] =    _("LEVEL  / PERSIM / (NRM/FLY/ICE)");

const u8 gText_Abra[] = _("ABRA 120 COINS");
const u8 gText_Clefairy[] = _("CLEFAIRY 500 COINS");
const u8 gText_Munchlax[] = _("MUNCHLAX 2800 COINS");
const u8 gText_Dratini[] = _("DRATINI 5500 COINS");
const u8 gText_Porygon[] = _("PORYGON 6500 COINS");

const u8 gText_Pal[] = _("Pal");
const u8 gText_Underling[] = _("Underling");

const u8 gText_Strategy[] = _("Strategy");
const u8 gText_Training[] = _("Training");
const u8 gText_Cheating[] = _("Cheating");

const u8 gText_WeakPerson[] = _("Weak person");
const u8 gText_ToughPerson[] = _("Tough person");
const u8 gText_Anybody[] = _("Anybody");

const u8 gText_Love2[] = _("Love");
const u8 gText_Violence[] = _("Violence");
const u8 gText_Knowledge[] = _("Knowledge");

const u8 gText_Tough3[] = _("Tough");
const u8 gText_Weak[] = _("Weak");
const u8 gText_Both[] = _("Both");

const u8 gText_BlueStone[] = _("BLUE STONE");
const u8 gText_GreenStone[] = _("GREEN STONE");
const u8 gText_RedStone[] = _("RED STONE");

ALIGNED(4) const u8 gText_FacilitySingle[] = _("{STR_VAR_1} SOLO");
ALIGNED(4) const u8 gText_FacilityDouble[] = _("{STR_VAR_1} DUO");
ALIGNED(4) const u8 gText_FacilityMulti[] = _("{STR_VAR_1} MULTI");
ALIGNED(4) const u8 gText_FacilityLink[] = _("{STR_VAR_1} LINK");
ALIGNED(4) const u8 gText_Facility[] = _("{STR_VAR_1}");

const u8 gText_Give[] = _("Montrer");
const u8 gText_NoNeed[] = _("Pas besoin");
const u8 gText_ColorLightShadowDarkGray[] = _("{COLOR LIGHT_GRAY}{SHADOW DARK_GRAY}");
const u8 gText_ColorBlue[] = _("{COLOR BLUE}");
const u8 gText_ColorTransparent[] = _("{HIGHLIGHT TRANSPARENT}{COLOR TRANSPARENT}");
const u8 gText_CDot[] = _("C.");
const u8 gText_BDot[] = _("B.");
const u8 gText_AnnouncingResults[] = _("Annonce des résultats!");
const u8 gText_PreliminaryResults[] = _("Résultats du premier tour!");
const u8 gText_Round2Results[] = _("Résultats du second tour!");
const u8 gText_ContestantsMonWon[] = _("{STR_VAR_2} de {STR_VAR_1} a gagné!");
const u8 gText_CommunicationStandby[] = _("Connexion en cours…");
const u8 gText_ColorDarkGray[] = _("{COLOR DARK_GRAY}");
const u8 gText_ColorDynamic6WhiteDynamic5[] = _("{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR6 WHITE DYNAMIC_COLOR5}"); // Unused
const u8 gText_HealthboxNickname[] = _("{HIGHLIGHT DARK_GRAY}");
const u8 gText_EmptySpace2[] = _(" "); // Unused
const u8 gText_HealthboxGender_Male[] = _("{COLOR DYNAMIC_COLOR2}♂");
const u8 gText_HealthboxGender_Female[] = _("{COLOR DYNAMIC_COLOR1}♀");
const u8 gText_HealthboxGender_None[] = _("{COLOR DYNAMIC_COLOR2}");
const u8 gText_Upper[] = _("MAJ.");
const u8 gText_Lower[] = _("min.");
const u8 gText_Others[] = _("OTHERS");
const u8 gText_Symbols[] = _("SYMBOLES");
const u8 gText_Register2[] = _("ENREG.");
const u8 gText_Exit2[] = _("RETOUR");
const u8 gText_QuitChatting[] = _("Quitter le tchat?");
const u8 gText_RegisterTextWhere[] = _("Où enregistrer le texte?");
const u8 gText_RegisterTextHere[] = _("Enregistrer le texte ici?");
const u8 gText_InputText[] = _("Entrer le texte.");
const u8 gText_F700JoinedChat[] = _("{DYNAMIC 0} rejoint le tchat!");
const u8 gText_F700LeftChat[] = _("{DYNAMIC 0} quitte le tchat.");
const u8 gJPText_PlayersXPokemon[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめ:"); // Unused
const u8 gJPText_PlayersXPokmonDoesNotExist[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめは いません"); // Unused
const u8 gText_ExitingChat[] = _("Départ du tchat…");
const u8 gText_LeaderLeftEndingChat[] = _("Le MENEUR, {DYNAMIC 0}, part
et met fin au tchat.");
const u8 gText_RegisteredTextChangedOKToSave[] = _("Le texte enregistré a été modifié.
Sauvegarder la partie?");
const u8 gText_AlreadySavedFile_Chat[] = _("Ecraser les données de
sauvegarde existantes?");
const u8 gText_SavingDontTurnOff_Chat[] = _("SAUVEGARDE EN COURS…
NE PAS ETEINDRE.");
const u8 gText_PlayerSavedGame_Chat[] = _("{DYNAMIC 0} a sauvegardé la partie.");
const u8 gText_IfLeaderLeavesChatEnds[] = _("Si le MENEUR part, le forum
se termine. OK?");
const u8 gText_Hello[] = _("SALUT");
const u8 gText_Pokemon2[] = _("POKéMON");
const u8 gText_Trade[] = _("ECHANGE");
const u8 gText_Battle[] = _("COMBAT");
const u8 gText_Lets[] = _("ÇA VA?");
const u8 gText_Ok[] = _("OK!");
const u8 gText_Sorry[] = _("DESOLE");
const u8 gText_YaySmileEmoji[] = _("OUAIS{EMOJI_BIGSMILE}");
const u8 gText_ThankYou[] = _("MERCI");
const u8 gText_ByeBye[] = _("BYE-BYE!");
const u8 gText_MatchCallSteven_Strategy[] = _("Attaquer les points faibles!");
const u8 gText_MatchCallSteven_Pokemon[] = _("POKéMON ACIER ultime.");
const u8 gText_MatchCallSteven_Intro1_BeforeMeteorFallsBattle[] = _("Je franchirais des cascades");
const u8 gText_MatchCallSteven_Intro2_BeforeMeteorFallsBattle[] = _("pour des pierres rares!");
const u8 gText_MatchCallSteven_Intro1_AfterMeteorFallsBattle[] = _("Je suis le plus fort et");
const u8 gText_MatchCallSteven_Intro2_AfterMeteorFallsBattle[] = _("le plus énergique!");
const u8 gText_MatchCallBrendan_Strategy[] = _("Il faut utiliser son savoir!");
const u8 gText_MatchCallBrendan_Pokemon[] = _("J'utiliserai divers POKéMON.");
const u8 gText_MatchCallBrendan_Intro1[] = _("Je serai un meilleur prof");
const u8 gText_MatchCallBrendan_Intro2[] = _("POKéMON que mon père!");
const u8 gText_MatchCallMay_Strategy[] = _("Je ne suis pas si bonne!");
const u8 gText_MatchCallMay_Pokemon[] = _("Je t'aurai avec mes POKéMON!");
const u8 gText_MatchCallMay_Intro1[] = _("Avec mes POKéMON, j'aide mon");
const u8 gText_MatchCallMay_Intro2[] = _("père dans ses recherches.");
const u8 gText_HatchedFromEgg[] = _("{STR_VAR_1} vient de sortir de l'OEUF!");
const u8 gText_NicknameHatchPrompt[] = _("Voulez-vous donner un surnom
au {STR_VAR_1} nouveau-né?");
ALIGNED(4) const u8 gText_ReadyPickBerry[] = _("Sélectionnez une BAIE pour utiliser
le BROYEUR DE BAIES.\p");
ALIGNED(4) const u8 gText_WaitForAllChooseBerry[] = _("Patientez le temps que tous les
participants aient choisi une BAIE.");
ALIGNED(4) const u8 gText_EndedWithXUnitsPowder[] = _("{PAUSE_MUSIC}{PLAY_BGM MUS_LEVEL_UP}Vous terminez avec {STR_VAR_1} unités de
fine POUDRE BAIE.\pVotre quantité totale de POUDRE
BAIE est {STR_VAR_2}.\p");
ALIGNED(4) const u8 gText_RecordingGameResults[] = _("Sauvegarde de vos résultas en
cours. Veuillez patienter.");
ALIGNED(4) const u8 gText_PlayBerryCrushAgain[] = _("Voulez-vous encore utiliser le
BROYEUR DE BAIES?");
ALIGNED(4) const u8 gText_YouHaveNoBerries[] = _("Vous n'avez pas de BAIES.
La partie est annulée.");
ALIGNED(4) const u8 gText_MemberDroppedOut[] = _("Un participant est parti. Le jeu
va se terminer.");
ALIGNED(4) const u8 gText_TimesUpNoGoodPowder[] = _("Le temps est écoulé.\pVous n'avez pas pu faire une
bonne POUDRE BAIE…\p");
ALIGNED(4) const u8 gText_CommunicationStandby2[] = _("Connexion en cours…");
ALIGNED(4) const u8 gText_1DotBlueF700[] = _("1. {COLOR BLUE}{SHADOW LIGHT_BLUE}{DYNAMIC 0}");
ALIGNED(4) const u8 gText_1DotF700[] = _("1. {DYNAMIC 0}");
ALIGNED(4) const u8 gText_SpaceTimes2[] = _(" ");
ALIGNED(4) const u8 gText_XDotY[] = _("{STR_VAR_1},{STR_VAR_2}");
ALIGNED(4) const u8 gText_Var1Berry[] = _("BAIE {STR_VAR_1}");
ALIGNED(4) const u8 gText_TimeColon[] = _("Temps:");
ALIGNED(4) const u8 gText_PressingSpeed[] = _("Vitesse:");
ALIGNED(4) const u8 gText_Silkiness[] = _("Finesse:");
ALIGNED(4) const u8 gText_StrVar1[] = _("{STR_VAR_1}");
ALIGNED(4) const u8 gText_SpaceMin[] = _(" MIN ");
ALIGNED(4) const u8 gText_XDotY2[] = _("{STR_VAR_1},{STR_VAR_2}");
ALIGNED(4) const u8 gText_SpaceSec[] = _(" secondes");
ALIGNED(4) const u8 gText_XDotY3[] = _("{STR_VAR_1},{STR_VAR_2}");
ALIGNED(4) const u8 gText_TimesPerSec[] = _(" Fois/s");
ALIGNED(4) const u8 gText_Var1Percent[] = _("{STR_VAR_1}%");
ALIGNED(4) const u8 gText_PressesRankings[] = _("Nº de pressages");
ALIGNED(4) const u8 gText_CrushingResults[] = _("Résultats");
ALIGNED(4) const u8 gText_NeatnessRankings[] = _("Finesse");
ALIGNED(4) const u8 gText_CoopRankings[] = _("En coopération");
ALIGNED(4) const u8 gText_PressingPowerRankings[] = _("Force du pressage");
const u8 gText_BerryCrush2[] = _("BROYEUR DE BAIES");
const u8 gText_PressingSpeedRankings[] = _("Vitesse du pressage");
const u8 gText_Var1Players[] = _("{STR_VAR_1} JOUEURS");
const u8 gText_SymbolsEarned[] = _("Symboles");
const u8 gText_BattleRecord[] = _("Enregistrement");
const u8 gText_BattlePoints[] = _("Points de combat");
const u8 gText_UnusedCancel[] = _("CANCEL"); // Unused
const u8 gText_EmptyString7[] = _("");
const u8 gText_CheckFrontierMap[] = _("Voir la CARTE de la ZONE DE COMBAT.");
const u8 gText_CheckTrainerCard[] = _("Voir la CARTE DE DRESSEUR.");
const u8 gText_ViewRecordedBattle[] = _("Voir le combat enregistré.");
const u8 gText_PutAwayFrontierPass[] = _("Quitter le PASSE ZONE.");
const u8 gText_CurrentBattlePoints[] = _("Vos points de combat actuels.");
const u8 gText_CollectedSymbols[] = _("Les symboles que vous avez collectés.");
const u8 gText_BattleTowerAbilitySymbol[] = _("Tour de combat - Symbole capacité");
const u8 gText_BattleDomeTacticsSymbol[] = _("Dôme de combat - Symbole tactique");
const u8 gText_BattlePalaceSpiritsSymbol[] = _("Palace de combat - Symbole esprit");
const u8 gText_BattleArenaGutsSymbol[] = _("Dojo de combat - Symbole cran");
const u8 gText_BattleFactoryKnowledgeSymbol[] = _("Usine de combat - Symbole savoir");
const u8 gText_BattlePikeLuckSymbol[] = _("Reptile de combat - Symbole chance");
const u8 gText_BattlePyramidBraveSymbol[] = _("Pyramide de combat - Symbole bravoure");
const u8 gText_ThereIsNoBattleRecord[] = _("Pas d'enregistrement.");
const u8 gText_BattleTower3[] = _("TOUR");
const u8 gText_BattleDome2[] = _("DOME");
const u8 gText_BattlePalace2[] = _("PALACE");
const u8 gText_BattleArena2[] = _("DOJO");
const u8 gText_BattleFactory2[] = _("USINE");
const u8 gText_BattlePike2[] = _("REPTILE");
const u8 gText_BattlePyramid2[] = _("PYRAMIDE");
const u8 gText_BattleTowerDesc[] = _("Eliminez vos adversaires pour aller
au sommet et prouver votre talent.");
const u8 gText_BattleDomeDesc[] = _("Enchaînez les victoires en
faisant preuve de tactique.");
const u8 gText_BattlePalaceDesc[] = _("Regardez vos POKéMON se battre
et mettez votre esprit à l'épreuve.");
const u8 gText_BattleArenaDesc[] = _("Gagnez avec des équipes de POKéMON
pour prouver que vous avez du cran.");
const u8 gText_BattleFactoryDesc[] = _("Visez la victoire en louant des
POKéMON pour prouver votre savoir.");
const u8 gText_BattlePikeDesc[] = _("Choisissez un des trois chemins pour
combattre et testez votre chance.");
const u8 gText_BattlePyramidDesc[] = _("Partez à l'aventure et rendez-vous au
sommet pour prouver votre bravoure.");
const u8 gText_ContinueMenuPlayer[] = _("JOUEUR");
const u8 gText_ContinueMenuTime[] = _("DUREE JEU");
const u8 gText_ContinueMenuPokedex[] = _("POKéDEX");
const u8 gText_ContinueMenuBadges[] = _("BADGES");
const u8 gText_Powder[] = _("POUDRE");
const u8 gText_BerryPickingRecords[] = _("RECORDS D'ATTRAPE-BAIES DODRIO");
const u8 gText_BerriesPicked[] = _("Baies attrapées:");
const u8 gText_BestScore[] = _("Meilleur score:");
const u8 gText_BerriesInRowFivePlayers[] = _("Baies attrapées à la suite
avec cinq joueurs:");
const u8 gText_BerryPickingResults[] = _("Annonce des résultats!");
const u8 gText_10P30P50P50P[] = _("{CLEAR_TO 0x03}10P{CLEAR_TO 0x2B}30P{CLEAR_TO 0x53}50P{CLEAR_TO 0x77}{EMOJI_MINUS}50P");
const u8 gText_AnnouncingRankings[] = _("Annonce du classement!");
const u8 gText_AnnouncingPrizes[] = _("Remise des prix!");
const u8 gText_1Colon[] = _("1:");
const u8 gText_2Colon[] = _("2:");
const u8 gText_3Colon[] = _("3:");
const u8 gText_4Colon[] = _("4:");
const u8 gText_5Colon[] = _("5:");
const u8 gText_FirstPlacePrize[] = _("La première place remporte
{DYNAMIC 0}!");
const u8 gText_CantHoldAnyMore[] = _("Vous ne pouvez plus rien tenir!");
const u8 gText_FilledStorageSpace[] = _("Le prix est rangé à sa place.");
const u8 gText_WantToPlayAgain[] = _("Rejouer?");
const u8 gText_SomeoneDroppedOut[] = _("Quelqu'un est parti.
La connexion va se terminer.");
const u8 gText_SpacePoints[] = _(" points");
const u8 gText_CommunicationStandby3[] = _("Communication standby…");
const u8 gText_SpacePoints2[] = _(" points");
const u8 gText_SpaceTimes3[] = _("");
const u8 gText_PkmnJumpRecords[] = _("RECORDS DE SAUTS POKéMON");
const u8 gText_JumpsInARow[] = _("Sauts consécutifs:");
const u8 gText_BestScore2[] = _("Meilleur score:");
const u8 gText_ExcellentsInARow[] = _("EXCELLENTS consécutifs:");
const u8 gText_AwesomeWonF701F700[] = _("Score incroyable! Tu as
gagné {DYNAMIC 1} {DYNAMIC 0}!");
const u8 gText_FilledStorageSpace2[] = _("Il n'y a plus de place.");
const u8 gText_CantHoldMore[] = _("Vous ne pouvez plus rien tenir!");
const u8 gText_WantToPlayAgain2[] = _("Rejouer?");
const u8 gText_SomeoneDroppedOut2[] = _("Quelqu'un est parti.
La connexion va se terminer.");
const u8 gText_CommunicationStandby4[] = _("Connexion en cours…");
const u8 gText_LinkContestResults[] = _("Résultats du concours link de {PLAYER}");
const u8 gText_1st[] = _("1{SUPER_ER}");
const u8 gText_2nd[] = _("2{SUPER_E}");
const u8 gText_3rd[] = _("3{SUPER_E}");
const u8 gText_4th[] = _("4{SUPER_E}");
const u8 gText_Friend[] = _("Friend");
const u8 gText_Pokemon3[] = _("POKeMON"); // Unused
const u8 gJPText_MysteryGift[] = _("ふしぎなもらいもの");
const u8 gJPText_DecideStop[] = _("{A_BUTTON}けってい {B_BUTTON}やめる");
const u8 gJPText_ReceiveMysteryGiftWithEReader[] = _("カードeリーダー{PLUS}　で\nふしぎなもらいものを　よみこみます");
const u8 gJPText_SelectConnectFromEReaderMenu[] = _("カードeリーダー{PLUS}の　メニューから\n‘つうしん'を　えらび");
const u8 gJPText_SelectConnectWithGBA[] = _("‘ゲームボーイアドバンスとつうしん'\nを　せんたく　してください");
const u8 gJPText_SelectConnectAndPressA[] = _("カードeリーダー{PLUS}の　‘つうしん'を\nえらんで　Aボタンを　おしてください"); // Unused
const u8 gJPText_LinkIsIncorrect[] = _("せつぞくが　まちがっています");
const u8 gJPText_CardReadingHasBeenHalted[] = _("カードの　よみこみを\nちゅうし　しました");
const u8 gJPText_UnableConnectWithEReader[] = _("カードeリーダー{PLUS}と\nつうしん　できません"); // Unused
const u8 gJPText_Connecting[] = _("つうしん　ちゅう　です");
const u8 gJPText_ConnectionErrorCheckLink[] = _("つうしん　エラーです\nせつぞくを　たしかめて　ください");
const u8 gJPText_ConnectionErrorTryAgain[] = _("つうしん　エラーです\nはじめから　やりなおして　ください"); // Link error
const u8 gJPText_AllowEReaderToLoadCard[] = _("カードeリーダー{PLUS}　に\nカードを　よみこませて　ください");
const u8 gJPText_ConnectionComplete[] = _("つうしん　しゅうりょう！");
const u8 gJPText_NewTrainerHasComeToHoenn[] = _("あらたな　トレーナーが\nホウエンに　やってきた！");
const u8 gJPText_PleaseWaitAMoment[] = _("しばらく　おまちください");
const u8 gJPText_WriteErrorUnableToSaveData[] = _("かきこみ　エラー　です\nデータが　ほぞん　できませんでした");
const u8 gText_Red[] = _("ROUGE");
const u8 gText_Blue[] = _("BLEU");
const u8 gText_3Dashes[] = _("---"); // Unused
const u8 gText_SingleBattleRoomResults[] = _("Combats solo de {PLAYER}");
const u8 gText_DoubleBattleRoomResults[] = _("Combats duo de {PLAYER}");
const u8 gText_MultiBattleRoomResults[] = _("Combats multi de {PLAYER}");
const u8 gText_LinkMultiBattleRoomResults[] = _("Combats multi link de {PLAYER}");
const u8 gText_SingleBattleTourneyResults[] = _("Tournois de combat solo de {PLAYER}");
const u8 gText_DoubleBattleTourneyResults[] = _("Tournois de combat duo de {PLAYER}");
const u8 gText_SingleBattleHallResults[] = _("Combats solo de {PLAYER}");
const u8 gText_DoubleBattleHallResults[] = _("Combats duo de {PLAYER}");
const u8 gText_BattleChoiceResults[] = _("Combats hasard de {PLAYER}");
const u8 gText_SetKOTourneyResults[] = _("Tournoi K.O. de {PLAYER}");
const u8 gText_BattleSwapSingleResults[] = _("Combats échange solo de {PLAYER}");
const u8 gText_BattleSwapDoubleResults[] = _("Combats échange duo de {PLAYER}");
const u8 gText_BattleQuestResults[] = _("Combats quête de {PLAYER}");
const u8 gText_Lv502[] = _("N. 50");
const u8 gText_OpenLv[] = _("N. LIBRE");
const u8 gText_WinStreak[] = _("Victoires: {STR_VAR_1}");
const u8 gText_Current[] = _("ACTUEL");
const u8 gText_Record[] = _("RECORD");
const u8 gText_Prev[] = _("PRECED.");
const u8 gText_RentalSwap[] = _("Loc./Ech.");
const u8 gText_Total[] = _("Total");
const u8 gText_ClearStreak[] = _("Séries: {STR_VAR_1}");
const u8 gText_Championships[] = _("Championnats: {STR_VAR_1}");
const u8 gText_RoomsCleared[] = _("Salles: {STR_VAR_1}");
const u8 gText_TimesCleared[] = _("Réussites:{CLEAR 0x05}{STR_VAR_1}");
const u8 gText_KOsInARow[] = _("K.O.s: {STR_VAR_1}");
const u8 gText_TimesVar1[] = _("Nombre: {STR_VAR_1}");
const u8 gText_FloorsCleared[] = _("Niveaux: {STR_VAR_1}");

ALIGNED(4) const u8 gText_RecordsLv50[] = _("NIVEAU 50");
ALIGNED(4) const u8 gText_RecordsOpenLevel[] = _("NIVEAU LIBRE");
ALIGNED(4) const u8 gText_FrontierFacilityWinStreak[] = _("Victoires: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityClearStreak[] = _("Séries: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityRoomsCleared[] = _("Séries: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityKOsStreak[] = _("Salles: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityFloorsCleared[] = _("Niveaux: {STR_VAR_2}");
ALIGNED(4) const u8 gText_123Dot[][3] = {_("1."), _("2."), _("3.")};

const u8 gText_SavingDontTurnOff2[] = _("SAUVEGARDE EN COURS…
NE PAS ETEINDRE.");
const u8 gText_BlenderMaxSpeedRecord[] = _("MIXEUR
RECORDS DE VITESSE!");
const u8 gText_234Players[] = _("2 JOUEURS
3 JOUEURS
4 JOUEURS");
const u8 gText_YesNo[] = _("OUI
NON");
const u8 gText_SelectorArrow3[] = _("▶");
const u8 gText_Peekaboo[] = _("PIKABOUH!");
const u8 gText_CommErrorCheckConnections[] = _("Erreur de communication…
Veuillez vérifier toutes les connexions
puis éteignez et rallumez les consoles.");
const u8 gText_CommErrorEllipsis[] = _("Erreur de connexion…");
const u8 gText_MoveCloserToLinkPartner[] = _("Rapprochez-vous de vos partenaires.
Evitez tout obstacle entre vous.");
const u8 gText_ABtnRegistrationCounter[] = _("Bouton A: Comptoir d'enregistrement");
const u8 gText_ABtnTitleScreen[] = _("Bouton A: Ecran titre");
const u8 gText_Option[] = _("OPTIONS");
const u8 gText_TextSpeed[] = _("VIT. TEXTE");
const u8 gText_BattleScene[] = _("ANIMAT. COMBAT");
const u8 gText_BattleStyle[] = _("STYLE COMBAT");
const u8 gText_Autorun[] = _("AUTORUN");
const u8 gText_Sound[] = _("SON");
const u8 gText_Frame[] = _("FENETRE");
const u8 gText_OptionMenuCancel[] = _("RETOUR");
const u8 gText_FollowerEnable[] = _("{PKMN} FOLLOWER");  //tx_optionsPlus
const u8 gText_AutorunEnable[] = _("AUTORUN");  //tx_optionsPlus
const u8 gText_OptionMatchCalls[] = _("MATCH CALLS");  //tx_optionsPlus
const u8 gText_OptionMenuSave[] = _("SAVE");  //tx_optionsPlus
const u8 gText_OptionStyle[] = _("MOVE SPLIT");  //tx_optionsPlus
const u8 gText_OptionDifficulty[] = _("DIFFICULTY");  //tx_optionsPlus
const u8 gText_ButtonMode[] = _("MODE BOUTONS");
const u8 gText_TextSpeedSlow[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}1");
const u8 gText_TextSpeedMid[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}2");
const u8 gText_TextSpeedFast[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}3");
const u8 gText_BattleSceneOn[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OUI");
const u8 gText_BattleSceneOff[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NON");
const u8 gText_BattleStyleShift[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}CHOIX");
const u8 gText_BattleStyleSet[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}DEFINI");
const u8 gText_SoundMono[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}MONO");
const u8 gText_SoundStereo[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}STEREO");
const u8 gText_FrameType[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}TYPE ");
const u8 gText_FrameTypeNumber[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}");
const u8 gText_ButtonTypeNormal[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL");
const u8 gText_ButtonTypeLR[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LR");
const u8 gText_ButtonTypeLEqualsA[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A");
const u8 gText_AutorunOff[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF"); //OLD
const u8 gText_AutorunOn[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON"); //OLD
const u8 gText_NumPlayerLink[] = _("LINK {STR_VAR_1}");
const u8 gText_BronzeCard[] = _("BRONZE");
const u8 gText_CopperCard[] = _("CUIVRE");
const u8 gText_SilverCard[] = _("ARGENT");
const u8 gText_GoldCard[] = _("OR");
const u8 gText_Day[] = _("JOUR");
const u8 gText_Colon3[] = _(":");
const u8 gText_Confirm2[] = _("CONFIR.");
const u8 gText_Days[] = _("Jours"); // Unused
const u8 gText_TimeColon2[] = _("Temps:"); // Unused
const u8 gText_GameTime[] = _("Temps de jeu"); // Unused
const u8 gText_RTCTime[] = _("Temps réel"); // Unused
const u8 gText_UpdatedTime[] = _("Mise à jour"); // Unused
const u8 gText_MenuPokedex[] = _("POKéDEX");
const u8 gText_MenuPokemon[] = _("POKéMON");
const u8 gText_MenuBag[] = _("SAC");
const u8 gText_MenuPokenav[] = _("POKéNAV");
const u8 gText_MenuPlayer[] = _("{PLAYER}");
const u8 gText_MenuSave[] = _("SAUVER");
const u8 gText_MenuOption[] = _("OPTIONS");
const u8 gText_MenuExit[] = _("RETOUR");
const u8 gText_MenuRetire[] = _("PARTIR");
const u8 gText_MenuRest[] = _("REPOS");
const u8 gText_SafariBallStock[] = _("SAFARI BALLS
Nb: {STR_VAR_1}");
const u8 gText_BattlePyramidFloor[] = _("Pyramide
{STR_VAR_1}");
const u8 gText_Floor0[] = _("Floor 0");
const u8 gText_Floor1[] = _("Niveau 1");
const u8 gText_Floor2[] = _("Niveau 2");
const u8 gText_Floor3[] = _("Niveau 3");
const u8 gText_Floor4[] = _("Niveau 4");
const u8 gText_Floor5[] = _("Niveau 5");
const u8 gText_Floor6[] = _("Niveau 6");
const u8 gText_Floor7[] = _("Niveau 7");
const u8 gText_Peak[] = _("Sommet");
const u8 gText_LinkStandby2[] = _("Connexion en cours…
Bouton B: Annuler");
const u8 gText_PressAToLoadEvent[] = _("Bouton A: Charger évènement.
Bouton B: Annuler");
const u8 gText_LoadingEvent[] = _("Chargement évènement…");
const u8 gText_DontRemoveCableTurnOff[] = _("Ne pas retirer le câble Game Link.
Ne pas éteindre.");
const u8 gText_EventSafelyLoaded[] = _("Chargement de l'évènement achevé.");
const u8 gText_LoadErrorEndingSession[] = _("Erreur de chargement.
Fermeture de la session.");
const u8 gJPText_Player[] = _("プレイヤー"); // Unused
const u8 gJPText_Sama[] = _("さま"); // Unused
const u8 gText_DexHoenn[] = _("HOENN");
const u8 gText_DexNational[] = _("NATIONAL");
const u8 gText_PokedexDiploma[] = _("Joueur: {CLEAR 0x10}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}

POKéDEX {STR_VAR_1}
Ce document certifie
que vous avez complété
votre POKéDEX.

{CLEAR_TO 0x42}{COLOR RED}{SHADOW LIGHT_RED}GAME FREAK");
const u8 gJPText_GameFreak[] = _("{COLOR RED}{SHADOW LIGHT_RED}ゲ-ムフリ-ク"); // Unused
const u8 gText_DiplomaEmpty[] = _("{COLOR RED}{SHADOW LIGHT_RED}"); // Unused
const u8 gText_Hoenn[] = _("HOENN");
const u8 gText_OhABite[] = _("Oh! Ça mord!");
const u8 gText_PokemonOnHook[] = _("Un POKéMON a mordu à l'hameçon!{PAUSE_UNTIL_PRESS}");
const u8 gText_NotEvenANibble[] = _("Rien de rien…{PAUSE_UNTIL_PRESS}");
const u8 gText_ItGotAway[] = _("Il est reparti…{PAUSE_UNTIL_PRESS}");
const u8 gText_XWillBeSentToY[] = _("{STR_VAR_2} sera envoyé à {STR_VAR_1}.");
const u8 gText_ByeByeVar1[] = _("Ciao, {STR_VAR_2}!");
const u8 gText_XSentOverY[] = _("{STR_VAR_1} a envoyé {STR_VAR_3}.");
const u8 gText_TakeGoodCareOfX[] = _("Prends bien soin de {STR_VAR_3}!");

// Easy chat group names
const u8 gEasyChatGroupName_Pokemon[] = _("POKéMON");
const u8 gEasyChatGroupName_Trainer[] = _("TRAINER");
const u8 gEasyChatGroupName_Status[] = _("STATUS");
const u8 gEasyChatGroupName_Battle[] = _("BATTLE");
const u8 gEasyChatGroupName_Greetings[] = _("GREETINGS");
const u8 gEasyChatGroupName_People[] = _("PEOPLE");
const u8 gEasyChatGroupName_Voices[] = _("VOICES");
const u8 gEasyChatGroupName_Speech[] = _("SPEECH");
const u8 gEasyChatGroupName_Endings[] = _("ENDINGS");
const u8 gEasyChatGroupName_Feelings[] = _("FEELINGS");
const u8 gEasyChatGroupName_Conditions[] = _("CONDITIONS");
const u8 gEasyChatGroupName_Actions[] = _("ACTIONS");
const u8 gEasyChatGroupName_Lifestyle[] = _("LIFESTYLE");
const u8 gEasyChatGroupName_Hobbies[] = _("HOBBIES");
const u8 gEasyChatGroupName_Time[] = _("TIME");
const u8 gEasyChatGroupName_Misc[] = _("MISC.");
const u8 gEasyChatGroupName_Adjectives[] = _("ADJECTIVES");
const u8 gEasyChatGroupName_Events[] = _("EVENTS");
const u8 gEasyChatGroupName_Move1[] = _("MOVE 1");
const u8 gEasyChatGroupName_Move2[] = _("MOVE 2");
const u8 gEasyChatGroupName_TrendySaying[] = _("TRENDY SAYING");
const u8 gEasyChatGroupName_Pokemon2[] = _("POKéMON2");

const u8 gText_ThreeQuestionMarks[] = _("???");
const u8 gText_MaxHP[] = _("PV MAX.");
const u8 gText_Attack[] = _("ATTAQUE");
const u8 gText_Defense[] = _("DEFENSE");
const u8 gText_Speed[] = _("VITESSE");
const u8 gText_SpAtk[] = _("ATQ. SPE.");
const u8 gText_SpDef[] = _("DEF. SPE.");
const u8 gText_Plus[] = _("{PLUS}");
const u8 gText_Dash[] = _("-");
const u8 gText_FromSpace[] = _("");
const u8 gText_MixingRecords[] = _("Echange de données…");
const u8 gText_RecordMixingComplete[] = _("Echange de données terminé.
Merci d'avoir patienté.");
const u8 gText_YourName[] = _("VOTRE NOM?");
const u8 gText_BoxName[] = _("NOM BOITE?");
const u8 gText_PkmnsNickname[] = _("Surnom de {STR_VAR_1}?");
const u8 gText_TellHimTheWords[] = _("Lui dire les mots.");
const u8 gText_MoveOkBack[] = _("{DPAD_NONE}DEPL.  {A_BUTTON}OK  {B_BUTTON}RET.");
const u8 gText_CallCantBeMadeHere[] = _("Impossible d'appeler d'ici.");
const u8 gText_ContestLady_Handsome[] = _("LE SUBLIME");
const u8 gText_ContestLady_Vinny[] = _("L'ENORME");
const u8 gText_ContestLady_Moreme[] = _("L'UNIQUE");
const u8 gText_ContestLady_Ironhard[] = _("LE SOLIDE");
const u8 gText_ContestLady_Muscle[] = _("LE MUSCLE");
const u8 gText_ContestLady_Coolness[] = _("sang-froid");
const u8 gText_ContestLady_Beauty[] = _("beauté");
const u8 gText_ContestLady_Cuteness[] = _("grâce");
const u8 gText_ContestLady_Smartness[] = _("intelligence");
const u8 gText_ContestLady_Toughness[] = _("robustesse");
const u8 gText_QuizLady_Lady[] = _("moi");
const u8 gText_FavorLady_Slippery[] = _("glissant");
const u8 gText_FavorLady_Roundish[] = _("rond");
const u8 gText_FavorLady_Whamish[] = _("bruyant");
const u8 gText_FavorLady_Shiny[] = _("brillant");
const u8 gText_FavorLady_Sticky[] = _("collant");
const u8 gText_FavorLady_Pointy[] = _("pointu");
const u8 gText_RentalPkmn2[] = _("LOCATION");
const u8 gText_SelectFirstPkmn[] = _("Sélectionnez le premier.");
const u8 gText_SelectSecondPkmn[] = _("Sélectionnez le deuxième.");
const u8 gText_SelectThirdPkmn[] = _("Sélectionnez le troisième.");
const u8 gText_Rent[] = _("LOUER");
const u8 gText_Summary[] = _("RESUME");
const u8 gText_Others2[] = _("RETOUR");
const u8 gText_Deselect[] = _("ANNULER");
const u8 gText_TheseThreePkmnOkay[] = _("OK avec ces trois POKéMON?");
const u8 gText_Yes2[] = _("OUI");
const u8 gText_No2[] = _("NON");
const u8 gText_CantSelectSamePkmn[] = _("Impossible de sélec. le même.");
const u8 gText_PkmnSwap[] = _("ECHANGE");
const u8 gText_SelectPkmnToSwap[] = _("Choisir un PKMN à échanger.");
const u8 gText_SelectPkmnToAccept[] = _("Choisir un PKMN à recevoir.");
const u8 gText_Swap[] = _("ECHANGER");
const u8 gText_Summary2[] = _("RESUME");
const u8 gText_Rechoose[] = _("RETOUR");
const u8 gText_QuitSwapping[] = _("Quitter l'échange?");
const u8 gText_Yes3[] = _("OUI");
const u8 gText_No3[] = _("NON");
const u8 gText_PkmnForSwap[] = _("{PKMN} A ECHANGER");
const u8 gText_Cancel3[] = _("ANNULER");
const u8 gText_Swap2[] = _("SWAP"); // Unused
const u8 gText_Accept[] = _("ACCEPT"); // Unused
const u8 gText_AcceptThisPkmn[] = _("Accepter ce POKéMON?");
const u8 gText_4Spaces[] = _("    "); // Unused
const u8 gText_SamePkmnInPartyAlready[] = _("Ce {PKMN} est déjà dans l'équipe.");
const u8 gText_DecimalPoint[] = _(".");
const u8 gText_SavingPlayer[] = _("JOUEUR");
const u8 gText_SavingBadges[] = _("BADGES");
const u8 gText_SavingPokedex[] = _("POKéDEX");
const u8 gText_SavingTime[] = _("DUREE JEU");
const u8 gText_WirelessCommStatus[] = _("Statut de la communication sans fil");
const u8 gText_PeopleTrading[] = _("Personnes pour échanges:");
const u8 gText_PeopleBattling[] = _("Personnes pour combats:");
const u8 gText_PeopleInUnionRoom[] = _("Personnes dans SALLE UNION:");
const u8 gText_PeopleCommunicating[] = _("Personnes en communication:");
const u8 gText_F700Players[] = _("{DYNAMIC 0} JOUEURS");
const u8 gText_F701Players[] = _("{DYNAMIC 1} JOUEURS");
const u8 gText_F702Players[] = _("{DYNAMIC 2} JOUEURS");
const u8 gText_F703Players[] = _("{DYNAMIC 3} JOUEURS");

const u8 *const gTextTable_Players[] = {
    gText_F700Players,
    gText_F701Players,
    gText_F702Players,
    gText_F703Players
};

ALIGNED(4) const u8 gText_WonderCards[] = _("CARTES MIRACLE");
ALIGNED(4) const u8 gText_WonderNews[] = _("INFOS MIRACLE");
ALIGNED(4) const u8 gText_WirelessCommunication[] = _("COMMUNICATION SANS FIL");
ALIGNED(4) const u8 gText_Friend2[] = _("AMI");
ALIGNED(4) const u8 gText_Exit3[] = _("RETOUR");
ALIGNED(4) const u8 gText_Receive[] = _("RECEVOIR");
ALIGNED(4) const u8 gText_Send[] = _("ENVOYER");
ALIGNED(4) const u8 gText_Toss[] = _("JETER");
ALIGNED(4) const u8 gText_VarietyOfEventsImportedWireless[] = _("Différents évènements seront
importés en transmission sans fil.");
ALIGNED(4) const u8 gText_WonderCardsInPossession[] = _("Lire les CARTES MIRACLE en
votre possession.");
ALIGNED(4) const u8 gText_ReadNewsThatArrived[] = _("Lire les INFOS qui sont
arrivées.");
ALIGNED(4) const u8 gText_ReturnToTitle[] = _("Retourner à l'écran titre.");
ALIGNED(4) const u8 gText_DontHaveCardNewOneInput[] = _("Vous n'avez pas de CARTE MIRACLE.
Une nouvelle carte va être ajoutée.");
ALIGNED(4) const u8 gText_DontHaveNewsNewOneInput[] = _("Vous n'avez pas d'INFOS MIRACLE.
De nouvelles infos vont être ajoutées.");
ALIGNED(4) const u8 gText_WhereShouldCardBeAccessed[] = _("D'où accéder à la CARTE MIRACLE?");
ALIGNED(4) const u8 gText_WhereShouldNewsBeAccessed[] = _("D'où accéder aux INFOS MIRACLE?");
ALIGNED(4) const u8 gText_CommunicationStandbyBButtonCancel[] = _("Communication standby…
B Button: Cancel"); // Unused
ALIGNED(4) const u8 gText_Communicating[] = _("Transmission…");
ALIGNED(4) const u8 gText_CommunicationCompleted[] = _("Fin de la connexion.");
ALIGNED(4) const u8 gText_CommunicationError[] = _("Erreur de transmission…");
ALIGNED(4) const u8 gText_CommunicationCanceled[] = _("La connexion a été annulée.");
ALIGNED(4) const u8 gText_ThrowAwayWonderCard[] = _("Jeter la CARTE MIRACLE et
entrer une nouvelle carte?");
ALIGNED(4) const u8 gText_HaventReceivedCardsGift[] = _("Vous n'avez pas encore reçu le cadeau de la CARTE.
Entrer une nouvelle CARTE quand même ?");
ALIGNED(4) const u8 gText_WonderCardReceivedFrom[] = _("Une CARTE MIRACLE a été reçue
de {STR_VAR_1}.");
ALIGNED(4) const u8 gText_WonderNewsReceivedFrom[] = _("Une INFO MIRACLE a été reçue
de {STR_VAR_1}.");
ALIGNED(4) const u8 gText_WonderCardReceived[] = _("Une nouvelle CARTE MIRACLE a été
reçue.");
ALIGNED(4) const u8 gText_WonderNewsReceived[] = _("Une nouvelle INFO MIRACLE a été
reçue.");
ALIGNED(4) const u8 gText_NewStampReceived[] = _("Un nouveau TAMPON a été reçu.");
ALIGNED(4) const u8 gText_NewTrainerReceived[] = _("Un nouveau DRESSEUR est arrivé.");
ALIGNED(4) const u8 gText_AlreadyHadCard[] = _("Vous aviez déjà cette
CARTE MIRACLE.");
ALIGNED(4) const u8 gText_AlreadyHadNews[] = _("Vous aviez déjà cette
INFO MIRACLE.");
ALIGNED(4) const u8 gText_AlreadyHadStamp[] = _("Vous aviez déjà ce
TAMPON.");
ALIGNED(4) const u8 gText_NoMoreRoomForStamps[] = _("Il n'y a plus de place pour ajouter
des TAMPONS.");
ALIGNED(4) const u8 gText_RecordUploadedViaWireless[] = _("Votre record a été envoyé via la
COMMUNICATION SANS FIL.");
ALIGNED(4) const u8 gText_CantAcceptCardFromTrainer[] = _("Vous ne pouvez pas accepter de CARTE MIRACLE
de ce DRESSEUR.");
ALIGNED(4) const u8 gText_CantAcceptNewsFromTrainer[] = _("Vous ne pouvez pas accepter d'INFO MIRACLE
de ce DRESSEUR.");
ALIGNED(4) const u8 gText_NothingSentOver[] = _("Rien n'a été envoyé…");
ALIGNED(4) const u8 gText_WhatToDoWithCards[] = _("Que voulez-vous faire
avec les CARTES MIRACLE ?");
ALIGNED(4) const u8 gText_WhatToDoWithNews[] = _("Que voulez-vous faire
avec les INFOS MIRACLE ?");
ALIGNED(4) const u8 gText_SendingWonderCard[] = _("Envoi de votre CARTE MIRACLE…");
ALIGNED(4) const u8 gText_SendingWonderNews[] = _("Envoi de votre INFO MIRACLE…");
ALIGNED(4) const u8 gText_WonderCardSentTo[] = _("Votre CARTE MIRACLE a été envoyée
à {STR_VAR_1}.");
ALIGNED(4) const u8 gText_WonderNewsSentTo[] = _("Votre INFO MIRACLE a été envoyée
à {STR_VAR_1}.");
ALIGNED(4) const u8 gText_StampSentTo[] = _("Un TAMPON a été envoyé à {STR_VAR_1}.");
ALIGNED(4) const u8 gText_GiftSentTo[] = _("Un CADEAU a été envoyé à {STR_VAR_1}.");
ALIGNED(4) const u8 gText_OtherTrainerHasCard[] = _("L'autre DRESSEUR a déjà la même
CARTE MIRACLE.");
ALIGNED(4) const u8 gText_OtherTrainerHasNews[] = _("L'autre DRESSEUR a déjà la même
INFO MIRACLE.");
ALIGNED(4) const u8 gText_OtherTrainerHasStamp[] = _("L'autre DRESSEUR a déjà le même
TAMPON.");
ALIGNED(4) const u8 gText_OtherTrainerCanceled[] = _("L'autre DRESSEUR a annulé
la communication.");
ALIGNED(4) const u8 gText_CantSendGiftToTrainer[] = _("Vous ne pouvez pas envoyer de CADEAU MYSTÈRE
à ce DRESSEUR.");
ALIGNED(4) const u8 gText_IfThrowAwayCardEventWontHappen[] = _("Si vous jetez la CARTE,
l'évènement ne se produira pas. OK ?");
ALIGNED(4) const u8 gText_OkayToDiscardNews[] = _("Êtes-vous sûr de vouloir jeter
cette INFO ?");
ALIGNED(4) const u8 gText_HaventReceivedGiftOkayToDiscard[] = _("Vous n'avez pas reçu le
CADEAU. Voulez-vous vraiment jeter ?");
ALIGNED(4) const u8 gText_DataWillBeSaved[] = _("Les données vont être sauvegardées.
Veuillez patienter.");
ALIGNED(4) const u8 gText_SaveCompletedPressA[] = _("Sauvegarde terminée.
Appuyez sur le bouton A.");
ALIGNED(4) const u8 gText_WonderCardThrownAway[] = _("La CARTE MIRACLE a été jetée.");
ALIGNED(4) const u8 gText_WonderNewsThrownAway[] = _("L'INFO MIRACLE a été jetée.");
ALIGNED(4) const u8 gText_MysteryGift[] = _("CADEAU MYSTÈRE");
ALIGNED(4) const u8 gText_PickOKExit[] = _("{DPAD_UPDOWN}CHOIX {A_BUTTON}OK {B_BUTTON}RETOUR");
ALIGNED(4) const u8 gText_PickOKCancel[] = _("{DPAD_UPDOWN}CHOIX {A_BUTTON}OK {B_BUTTON}ANNULER");
const u8 gText_PlayersBattleResults[] = _("RESULTATS DE COMBAT de {PLAYER}");
const u8 gText_TotalRecordWLD[] = _("RECORD TOTAL V:{STR_VAR_1} D:{STR_VAR_2} N:{STR_VAR_3}");
const u8 gText_WinLoseDraw[] = _("{CLEAR_TO 0x53}VICTOIRE{CLEAR_TO 0x80}DEFAITE{CLEAR_TO 0xB0}NUL");
const u8 gText_CommunicationStandby5[] = _("En attente de communication…");
const u8 gText_QuitTheGame[] = _("Quitter le jeu ?");
const u8 gText_YouveGot9999Coins[] = _("Vous avez 9 999 JETONS.");
const u8 gText_YouveRunOutOfCoins[] = _("Vous n'avez plus de JETONS.
Partie terminée !");
const u8 gText_YouDontHaveThreeCoins[] = _("Vous n'avez pas trois JETONS.");
const u8 gText_ReelTimeHelp[] = _("REEL TIME
C'est votre chance de viser
et de toucher les marques !
Le Reel Time continue pour le
nombre de tours attribué.
Tout se termine sur un Big Bonus.");
const u8 gDaycareText_GetAlongVeryWell[] = _("The two seem to get along\nvery well.");
const u8 gDaycareText_GetAlong[] = _("The two seem to get along.");
const u8 gDaycareText_DontLikeOther[] = _("The two don't seem to like\neach other much.");
const u8 gDaycareText_PlayOther[] = _("The two prefer to play with other\nPOKéMON than each other.");
const u8 gText_NewLine2[] = _("
");
const u8 gText_Exit4[] = _("EXIT");
const u8 gText_Lv[] = _("{LV}");
const u8 gText_TimeBoard[] = _("TIME BOARD");
const u8 gText_TimeCleared[] = _("TIME CLEARED ");
const u8 gText_XMinYDotZSec[] = _("{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.");
const u8 gText_TrainerHill1F[] = _("1{SUPER_ER}");
const u8 gText_TrainerHill2F[] = _("2{SUPER_E}");
const u8 gText_TrainerHill3F[] = _("3{SUPER_E}");
const u8 gText_TrainerHill4F[] = _("4{SUPER_E}");
const u8 gText_TeachWhichMoveToPkmn[] = _("Enseigner quoi à {STR_VAR_1}?");
const u8 gText_MoveRelearnerTeachMoveConfirm[] = _("Enseigner {STR_VAR_2}?");
const u8 gText_MoveRelearnerPkmnLearnedMove[] = _("{STR_VAR_1} apprend
{STR_VAR_2}!");
const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] = _("{STR_VAR_1} tente d'apprendre
{STR_VAR_2}.\pMais {STR_VAR_1} ne peut pas ap-
prendre plus de 4 capacités.\pEffacer une capacité 
pour {STR_VAR_2}?");
const u8 gText_MoveRelearnerStopTryingToTeachMove[] = _("Arrêter d'apprendre
{STR_VAR_2}?");
const u8 gText_MoveRelearnerAndPoof[] = _("{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Tadaa!\p");
const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] = _("{STR_VAR_1} oublie
{STR_VAR_3}.\pEt…\p{STR_VAR_1}
apprend {STR_VAR_2}.");
const u8 gText_MoveRelearnedPkmnDidNotLearnMove[] = _("{STR_VAR_1} did not learn the
move {STR_VAR_2}."); // Unused
const u8 gText_MoveRelearnerGiveUp[] = _("Arrêter d'enseigner la nouvelle
capacité à {STR_VAR_1}?");
const u8 gText_MoveRelearnerWhichMoveToForget[] = _("Oublier quelle capacité?\p");
const u8 gText_MoveRelearnerBattleMoves[] = _("CAPACITES COMB.");
const u8 gText_MoveRelearnerContestMovesTitle[] = _("CAPACITES CONC.");
const u8 gText_MoveRelearnerType[] = _("TYPE/"); // Unused
const u8 gText_MoveRelearnerPP[] = _("PP/");
const u8 gText_MoveRelearnerPower[] = _("POUVOIR/");
const u8 gText_MoveRelearnerAccuracy[] = _("PRECIS./");
const u8 gText_MoveRelearnerAppeal[] = _("CHARME/");
const u8 gText_MoveRelearnerJam[] = _("BLOCAG./");
const u8 gText_Kira[] = _("RITA");
const u8 gText_Amy[] = _("EVE");
const u8 gText_John[] = _("JOHN");
const u8 gText_Roy[] = _("SAM");
const u8 gText_Gabby[] = _("INES");
const u8 gText_Anna[] = _("ANNA");
const u8 gText_ClearAllSaveData[] = _("Effacer toutes les données?");
const u8 gText_ClearingData[] = _("Effacement des données en cours…
Veuillez patienter.");
const u8 gText_IsThisTheCorrectTime[] = _("Est-ce la bonne heure?");
const u8 gText_Confirm3[] = _("CONFIR.");
const u8 gText_Cancel4[] = _("SORTIR");
const u8 gText_MrStoneMatchCallDesc[] = _("DIR. DEVON");
const u8 gText_MrStoneMatchCallName[] = _("M. ROCHARD");
const u8 gText_StevenMatchCallDesc[] = _("COMME UN ROC");
const u8 gText_StevenMatchCallName[] = _("PIERRE");
const u8 gText_MayBrendanMatchCallDesc[] = _("LE VOISIN");
const u8 gText_NormanMatchCallDesc[] = _("RELIABLE ONE");
const u8 gText_MomMatchCallDesc[] = _("CALM & KIND");
const u8 gText_BaobaMatchCallDesc[] = _("SAFARI WARDEN");
const u8 gText_WallyMatchCallDesc[] = _("{PKMN} LOVER");
const u8 gText_NormanMatchCallName[] = _("PAPA");
const u8 gText_MomMatchCallName[] = _("MAMAN");
const u8 gText_BaobaMatchCallName[] = _("BAOBA");
const u8 gText_ScottMatchCallDesc[] = _("REGARD NOIR");
const u8 gText_ScottMatchCallName[] = _("SCOTT");
const u8 gText_RoxanneMatchCallDesc[] = _("ROCKIN' WHIZ");
const u8 gText_BrawlyMatchCallDesc[] = _("THE BIG HIT");
const u8 gText_WattsonMatchCallDesc[] = _("SWELL SHOCK");
const u8 gText_FlanneryMatchCallDesc[] = _("PASSION BURN");
const u8 gText_WinonaMatchCallDesc[] = _("SKY TAMER");
const u8 gText_TateLizaMatchCallDesc[] = _("MYSTIC DUO");
const u8 gText_JuanMatchCallDesc[] = _("DANDY CHARM");
const u8 gText_EliteFourMatchCallDesc[] = _("ELITE FOUR");
const u8 gText_ChampionMatchCallDesc[] = _("CHAMPION");
const u8 gText_ProfBirchMatchCallDesc[] = _("PROF. {PKMN}");
const u8 gText_CommStandbyAwaitingOtherPlayer[] = _("Communication en attente du
choix d'un participant.");
const u8 gText_BattleWasRefused[] = _("Le combat a été refusé.{PAUSE 60}");
const u8 gText_RefusedBattle[] = _("A refusé le combat.{PAUSE 60}");
const u8 gText_NoWeather[] = _("NO WEATHER"); // Below are unused debug names for weather types
const u8 gText_Sunny[] = _("SUNNY"); // Unused
const u8 gText_Sunny2[] = _("SUNNY2"); // Unused
const u8 gText_Rain[] = _("RAIN"); // Unused
const u8 gText_Snow[] = _("SNOW"); // Unused
const u8 gText_Lightning[] = _("LIGHTNING"); // Unused
const u8 gText_Fog[] = _("FOG"); // Unused
const u8 gText_VolcanoAsh[] = _("VOLCANO ASH"); // Unused
const u8 gText_Sandstorm[] = _("SANDSTORM"); // Unused
const u8 gText_Fog2[] = _("FOG2"); // Unused
const u8 gText_Seafloor[] = _("SEAFLOOR"); // Unused
const u8 gText_Cloudy[] = _("CLOUDY"); // Unused
const u8 gText_Sunny3[] = _("SUNNY3"); // Unused
const u8 gText_HeavyRain[] = _("HEAVY RAIN"); // Unused
const u8 gText_Seafloor2[] = _("SEAFLOOR2"); // Unused
const u8 gText_DelAll[] = _("TOUT EF.");
const u8 gText_Cancel5[] = _("ANNULER");
const u8 gText_Ok2[] = _("OK");
const u8 gText_Quiz[] = _("QUIZ");
const u8 gText_Answer[] = _("REPONSE");
const u8 gText_PokeBalls[] = _("POKé BALLS");
const u8 gText_Berry[] = _("BAIE");
const u8 gText_Berries[] = _("BAIES");
const u8 gText_AshQty[] = _("ASH QTY:
{STR_VAR_1}{PAUSE_UNTIL_PRESS}");

// Exp. Share
const u8 gText_ExpShareOn[] = _("Le Multi Exp. est activé.\pL'équipe gagnera désormais une partie
des Points d'Expérience.{PAUSE_UNTIL_PRESS}");
const u8 gText_ExpShareOff[] = _("Le Multi Exp. est désactivé.\pL'équipe ne gagnera plus de Points
d'Expérience supplémentaires.{PAUSE_UNTIL_PRESS}");
// Inf. Repel
const u8 gText_infiniteRepelOn[] = _("Repousse Infini activé.{PAUSE_UNTIL_PRESS}");
const u8 gText_infiniteRepelOff[] = _("Repousse Infini désactivé.{PAUSE_UNTIL_PRESS}");
// Inf. Candies
const u8 gText_infiniteCandies[] = _("Vous avez obtenu 999 BONBONS
RARES !{PAUSE_UNTIL_PRESS}");

//tx_randomizer_and_challenges
const u8 gText_NuzlockeCantThrowPokeBallRoute[]             = _("You have already used your encounter\nfor this area!{PAUSE_UNTIL_PRESS}");
const u8 gText_NuzlockeCantThrowPokeBallSpeciesClause[]     = _("You have already caught a POKéMON\nin this evolution line!{PAUSE_UNTIL_PRESS}");
const u8 gText_NuzlockeCantThrowPokeBallAlreadyCaught[]     = _("You have already caught this POKéMON!{PAUSE_UNTIL_PRESS}");
const u8 gText_OneTypeChallengeCantThrowPokeBall[]          = _("One Type Challenge active, capture\nblocked!{PAUSE_UNTIL_PRESS}");
const u8 gText_BattleRules_NoItems_Player[]                 = _("Competitive rules!\nNo items in battle!{PAUSE_UNTIL_PRESS}");


//HGSS_Ui PokedexPlus
const u8 gText_Stats_Buttons[]  = _("{A_BUTTON}TOGGLE   {DPAD_UPDOWN}MOVES");
const u8 gText_Stats_Buttons_Decapped[]  = _("{A_BUTTON}Toggle   {DPAD_UPDOWN}Moves");
const u8 gText_Stats_HP[]       = _("HP");
const u8 gText_Stats_Attack[]   = _("ATK");
const u8 gText_Stats_Defense[]  = _("DEF");
const u8 gText_Stats_Speed[]    = _("SPE");
const u8 gText_Stats_SpAttack[]    = _("SP.A");
const u8 gText_Stats_SpDefense[]    = _("SP.D");
const u8 gText_Stats_EV_Plus1[]     = _("{UP_ARROW_2}");
const u8 gText_Stats_EV_Plus2[]     = _("{UP_ARROW_2}{UP_ARROW_2}");
const u8 gText_Stats_EV_Plus3[]     = _("{UP_ARROW_2}{UP_ARROW_2}{UP_ARROW_2}");
const u8 gText_Stats_EvStr1Str2[]   = _("{STR_VAR_1}{STR_VAR_2}");
const u8 gText_Stats_MoveSelectedMax[]      = _("{STR_VAR_1} / {STR_VAR_2}");
const u8 gText_Stats_MoveLevel[]     = _("LVL");
const u8 gText_Stats_Gender_0[]      = _("♂");
const u8 gText_Stats_Gender_12_5[]   = _("♀ 1/7 ♂"); //_("♀ 12.5 / 87.5 ♂");
const u8 gText_Stats_Gender_25[]     = _("♀ 1/3 ♂");     //_("♀ 25 / 75 ♂");
const u8 gText_Stats_Gender_50[]     = _("♀ 1/1 ♂");     //_("♀ 50 / 50 ♂");
const u8 gText_Stats_Gender_75[]     = _("♀ 3/1 ♂");     //_("♀ 75 / 25 ♂");
const u8 gText_Stats_Gender_87_5[]   = _("♀ 7/1 ♂");
const u8 gText_Stats_Gender_100[]    = _("♀");
const u8 gText_Stats_CatchRate[]     = _("CATCH{0x5B}: ");
const u8 gText_Stats_CatchRate_Legend[]         = _("LEGENDARY");
const u8 gText_Stats_CatchRate_VeryHard[]       = _("VERY HARD");
const u8 gText_Stats_CatchRate_Difficult[]      = _("DIFFICULT");
const u8 gText_Stats_CatchRate_Medium[]         = _("MEDIUM");
const u8 gText_Stats_CatchRate_Relaxed[]        = _("RELAXED");
const u8 gText_Stats_CatchRate_Easy[]           = _("EASY");
const u8 gText_Stats_ExpYield[]      = _("EXP YIELD: ");
const u8 gText_Stats_EggCycles[]     = _("HATCH STEPS:");
const u8 gText_Stats_EggCycles_VeryFast[]   = _("{EMOJI_BOLT}{EMOJI_DIZZYEGG}");
const u8 gText_Stats_EggCycles_Fast[]       = _("{EMOJI_DIZZYEGG}");
const u8 gText_Stats_EggCycles_Normal[]     = _("{EMOJI_DIZZYEGG}{EMOJI_DIZZYEGG}");
const u8 gText_Stats_EggCycles_Slow[]       = _("{EMOJI_DIZZYEGG}{EMOJI_DIZZYEGG}{EMOJI_DIZZYEGG}");
const u8 gText_Stats_Growthrate[]    = _("GROW: ");
const u8 gText_Stats_Friendship[]    = _("FRIENDSHIP:");
const u8 gText_Stats_Friendship_BigAnger[]      = _("{EMOJI_BIGANGER}");
const u8 gText_Stats_Friendship_Neutral[]       = _("{EMOJI_NEUTRAL}");
const u8 gText_Stats_Friendship_Happy[]         = _("{EMOJI_HAPPY}");
const u8 gText_Stats_Friendship_BigSmile[]      = _("{EMOJI_BIGSMILE}");
const u8 gText_Stats_MEDIUM_FAST[]   = _("MED. FAST");
const u8 gText_Stats_ERRATIC[]       = _("ERRATIC");
const u8 gText_Stats_FLUCTUATING[]   = _("FLUCTUATING");
const u8 gText_Stats_MEDIUM_SLOW[]   = _("MED. SLOW");
const u8 gText_Stats_FAST[]          = _("FAST");
const u8 gText_Stats_SLOW[]          = _("SLOW");
const u8 gText_Stats_ContestHeart[]  = _("H");
const u8 gText_Stats_Minus[] = _("-");
const u8 gText_Stats_eggGroup[]             = _("EGG G1:");
const u8 gText_Stats_eggGroup_Groups[]      = _("{STR_VAR_1}/{STR_VAR_2}");
const u8 gText_Stats_eggGroup_MONSTER[]     = _("MONSTER");
const u8 gText_Stats_eggGroup_WATER_1[]     = _("WATER {CIRCLE_1}");
const u8 gText_Stats_eggGroup_BUG[]         = _("BUG");
const u8 gText_Stats_eggGroup_FLYING[]      = _("FLYING");
const u8 gText_Stats_eggGroup_FIELD[]       = _("FIELD");
const u8 gText_Stats_eggGroup_FAIRY[]       = _("FAIRY");
const u8 gText_Stats_eggGroup_GRASS[]       = _("GRASS");
const u8 gText_Stats_eggGroup_HUMAN_LIKE[]  = _("HUMANE");
const u8 gText_Stats_eggGroup_WATER_3[]     = _("WATER {CIRCLE_3}");
const u8 gText_Stats_eggGroup_MINERAL[]     = _("MINERAL");
const u8 gText_Stats_eggGroup_AMORPHOUS[]   = _("AMORPHOUS");
const u8 gText_Stats_eggGroup_WATER_2[]     = _("WATER {CIRCLE_2}");
const u8 gText_Stats_eggGroup_DITTO[]       = _("DITTO");
const u8 gText_Stats_eggGroup_DRAGON[]      = _("DRAGON");
const u8 gText_Stats_eggGroup_UNDISCOVERED[]= _("---");
const u8 gText_Dex_SEEN[]   = _("SEEN");
const u8 gText_Dex_OWN[]    = _("OWN");

const u8 gText_EVO_Buttons[]                        = _("{DPAD_UPDOWN}EVOs  {A_BUTTON}CHECK");
const u8 gText_EVO_Buttons_Decapped[]               = _("{DPAD_UPDOWN}Evos  {A_BUTTON}Check");
const u8 gText_EVO_Buttons_PE[]                     = _("{DPAD_UPDOWN}EVOs  {A_BUTTON}CHECK  {START_BUTTON}FORMs");
const u8 gText_EVO_Buttons_Decapped_PE[]            = _("{DPAD_UPDOWN}Evos  {A_BUTTON}Check  {START_BUTTON}Froms");
const u8 gText_EVO_Name[]                           = _("{STR_VAR_3}:");
const u8 gText_EVO_PreEvo[]                         = _("{STR_VAR_1} evolves from {STR_VAR_2}");
const u8 gText_EVO_PreEvo_PE_Mega[]                 = _("{STR_VAR_1} mega evolves with {STR_VAR_2}");
const u8 gText_EVO_FRIENDSHIP[]                     = _("LvlUp, high friendship");
const u8 gText_EVO_FRIENDSHIP_DAY[]                 = _("LvlUp, high friendship, day");
const u8 gText_EVO_FRIENDSHIP_NIGHT[]               = _("LvlUp, high friendship, night");
const u8 gText_EVO_LEVEL[]                          = _("LvlUp to {STR_VAR_2}");
const u8 gText_EVO_TRADE[]                          = _("Trading");
const u8 gText_EVO_TRADE_ITEM[]                     = _("Trading, holding {STR_VAR_2}");
const u8 gText_EVO_ITEM[]                           = _("{STR_VAR_2} is used");
const u8 gText_EVO_LEVEL_ATK_GT_DEF[]               = _("LvlUp to {STR_VAR_2}, Atk > Def");
const u8 gText_EVO_LEVEL_ATK_EQ_DEF[]               = _("LvlUp to {STR_VAR_2}, Atk = Def");
const u8 gText_EVO_LEVEL_ATK_LT_DEF[]               = _("LvlUp to {STR_VAR_2}, Atk < Def");
const u8 gText_EVO_LEVEL_SILCOON[]                  = _("LvlUp to {STR_VAR_2}, Silcoon personality");
const u8 gText_EVO_LEVEL_CASCOON[]                  = _("LvlUp to {STR_VAR_2}, Cascoon personality");
const u8 gText_EVO_LEVEL_NINJASK[]                  = _("LvlUp to {STR_VAR_2}");
const u8 gText_EVO_LEVEL_SHEDINJA[]                 = _("LvlUp to {STR_VAR_2}, party<6, 1x POKéBALL");
const u8 gText_EVO_BEAUTY[]                         = _("LvlUp, high beauty");
const u8 gText_EVO_LEVEL_FEMALE[]                   = _("LvlUp to {STR_VAR_2}, is female");
const u8 gText_EVO_LEVEL_MALE[]                     = _("LvlUp to {STR_VAR_2}, is male");
const u8 gText_EVO_LEVEL_NIGHT[]                    = _("LvlUp to {STR_VAR_2}, night");
const u8 gText_EVO_LEVEL_DAY[]                      = _("LvlUp to {STR_VAR_2}, day");
const u8 gText_EVO_LEVEL_DUSK[]                     = _("LvlUp to {STR_VAR_2}, morning (6-9AM)");
const u8 gText_EVO_ITEM_HOLD_DAY[]                  = _("LvlUp, holds {STR_VAR_2}, day");
const u8 gText_EVO_ITEM_HOLD_NIGHT[]                = _("LvlUp, holds {STR_VAR_2}, night");
const u8 gText_EVO_ITEM_HOLD[]                      = _("LvlUp, holds {STR_VAR_2}");
const u8 gText_EVO_MOVE[]                           = _("LvlUp, knows {STR_VAR_2}");
const u8 gText_EVO_MOVE_TYPE[]                      = _("LvlUp, knows {STR_VAR_2} move");
const u8 gText_EVO_MAPSEC[]                         = _("LvlUp on {STR_VAR_2}");
const u8 gText_EVO_ITEM_MALE[]                      = _("{STR_VAR_2} used on male");
const u8 gText_EVO_ITEM_FEMALE[]                    = _("{STR_VAR_2} used on female");
const u8 gText_EVO_LEVEL_RAIN[]                     = _("LvlUp to {STR_VAR_2} while raining");
const u8 gText_EVO_SPECIFIC_MON_IN_PARTY[]          = _("LvlUp with {STR_VAR_2} in party");
const u8 gText_EVO_LEVEL_DARK_TYPE_MON_IN_PARTY[]   = _("LvlUp with dark type in party");
const u8 gText_EVO_TRADE_SPECIFIC_MON[]             = _("Traded for {STR_VAR_2}");
const u8 gText_EVO_SPECIFIC_MAP[]                   = _("LvlUp on {STR_VAR_2}");
const u8 gText_EVO_UNKNOWN[]                        = _("Method unknown");
const u8 gText_EVO_NONE[]                           = _("{STR_VAR_1} has no evolution.");
const u8 gText_EVO_LEVEL_LOCATION[]                 = _("Level up at {STR_VAR_2}");

const u8 gText_FORMS_Buttons_PE[]                   = _("{A_BUTTON}FORM MODE  {START_BUTTON}EVOs");
const u8 gText_FORMS_Buttons_Decapped_PE[]          = _("{START_BUTTON}Evos");
const u8 gText_FORMS_Buttons_Submenu_PE[]           = _("{DPAD_NONE}FORMs {A_BUTTON}CHECK {START_BUTTON}EVOs");
const u8 gText_FORMS_Buttons_Submenu_Decapped_PE[]  = _("{START_BUTTON}Evos");
const u8 gText_FORMS_NONE[]                         = _("{STR_VAR_1} has no alternate forms.");
const u8 gText_Var1DotVar2_Metric[]                 = _("{STR_VAR_1}.{STR_VAR_2}cm");