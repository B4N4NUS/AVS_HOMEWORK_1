#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <cstring>

//---------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных предложений в диапазоне от 0 до 1000 слов.
//---------------------------------------------------------------------------------
const string sourceText[] = {"Alvarez", "on", "the", "open", "door", "and", "stepped", "into", "the", "office",
                       "You", "asked", "for", "me,", "sir?", "Dr.", "Gears", "looked", "up", "from", "the", "files",
                       "on", "his", "desk,", "fixing", "his", "gaze", "on", "the", "young", "security", "guard.",
                       "Yes,", "Ive", "been", "trying", "to", "contact", "Dr.", "Clef", "all", "evening,", "but",
                       "hes", "not", "answering", "his", "phone.", "Id", "like", "you", "to", "locate", "him", "to",
                       "make", "sure", "hes", "all", "right,", "and", "tell", "him", "I", "have", "something",
                       "urgent", "to", "discuss", "with", "him.", "But", "sir,", "its", "Friday", "night,",
                       "Alvarez", "said,", "suddenly", "uncomfortable.",  "If", "youll", "recall…", "Oh,", "I",
                       "see.", "Its", "his…", "yes.And", "he", "cant…", "Hes", "left", "instructions", "that",
                       "hes", "not", "to", "be", "disturbed", "under", "any", "circumstances,", "thats", "right,",
                       "sir.", "Well,", "I", "suppose", "things", "can", "wait", "until", "tomorrow", "morning,",
                       "then.", "Very", "well,", "sir.", "Alvarez", "left", "the", "office.Dr.", "Alto", "Clef", "sat",
                       "in", "the", "dining", "room", "of", "his", "Site-19", "suite.", "The", "place", "was",
                       "lavish,", "by", "any", "standards", "–", "gold-embossed", "wallpaper,", "ornate", "oak",
                       "paneling,", "18th", "century", "furniture,", "the", "table", "set", "with", "priceless",
                       "china", "and", "the", "finest", "silver.", "An", "antique", "Ming", "vase", "sat", "on", "a",
                       "pedestal", "nearby,", "gleaming", "in", "the", "warm", "glow", "of", "the", "crystal",
                       "chandelier;", "an", "original", "Caravaggio", "hung", "on", "one", "wall,", "a", "Vermeer",
                       "on", "the", "other.", "Barry", "White", "played", "softly", "in", "the", "background.Mmmh!",
                       "Clef", "exclaimed,", "setting", "down", "his", "spoon", "and", "wiping", "his", "mouth", "with",
                       "his", "napkin.", "The", "fennel", "soup", "was", "exquisite.", "D-12130", "really", "outdid",
                       "himself", "tonight", "He", "gestured", "to", "one", "of", "the", "several", "D-class",
                       "personnel", "in", "attendance.", "More", "wine,", "D-23897.", "Right", "away,", "Dr.", "Clef,",
                       "the", "man", "in", "the", "orange", "jumpsuit", "said,", "nervously", "stepping", "up", "to",
                       "the", "table", "and", "refilling", "his", "glass", "with", "a", "particularly", "crisp",
                       "Chardonnay.Clef", "lifted", "the", "glass", "to", "his", "mouth,", "took", "a", "sip,", "and",
                       "sighed", "with", "satisfaction.",  "This", "is", "nice,",  "he", "said,", "smiling", "at",
                       "his", "guest.",  "We", "should", "do", "this", "more", "often,", "dont", "you", "agree?",
                       "Across", "the", "table,", "SCP-173", "stared", "back", "at", "him,", "unmoving,", "silent.Five",
                       "D-class", "personnel", "were", "positioned", "around", "the", "living", "statue,", "their",
                       "eyes", "fixed", "on", "it,", "cold", "sweat", "dripping", "down", "their", "faces", "as",
                       "they", "struggled", "not", "to", "blink,", "not", "to", "break", "eye", "contact,", "not",
                       "even", "for", "a", "second;", "a", "sixth", "man", "stood", "directly", "next", "to", "173,",
                       "trembling", "with", "terror", "as", "he", "lifted", "spoonfuls", "of", "fennel", "soup", "up",
                       "to", "its", "face,", "smearing", "the", "contents", "where", "its", "mouth", "should", "have",
                       "been.May", "I", "just", "say", "how", "lovely", "you", "look", "tonight,", "darling,",
                       "Clef", "said,", "his", "eyes", "moving", "appreciatively", "over", "the", "black", "evening",
                       "dress", "covering", "the", "statues", "curves,", "the", "blonde,", "lustrous", "hair", "of",
                       "the", "wig", "on", "its", "head,", "its", "rouged", "stone", "cheeks…",  "I", "was", "going",
                       "to", "wait", "until", "later,", "but", "seeing", "you", "like", "this,", "I", "just,", "I…",
                       "Heh,", "look", "at", "me,", "you", "have", "me", "babbling", "like", "a", "schoolboy.", "I",
                       "dont", "know", "what", "it", "is", "about", "you.", "Youve", "always", "had", "that",
                       "effect", "on", "me."};

inline auto Random() {
    string textLine = "";
    for (int i = 1; i < rand() % 1000+1; i++) {
        textLine += sourceText[rand() % 460];
        textLine += " ";
    }
    return textLine;
}

#endif //__rnd__\
