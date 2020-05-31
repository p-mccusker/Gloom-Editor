#ifndef LISTS_H
#define LISTS_H

#include <string>
#include <vector>
#include <random>
#include <chrono>

using uint = unsigned int;

enum ENTITY_TYPE { HUMAN, HUMANOID, CRITTER, MONSTER, DEMON, LEGENDARY_ITEM };

uint randNum(const uint& start, const uint& end);
uint randNum(const uint& max);

struct Lists {

    static std::vector<std::string> adjectives;
    static std::vector<std::string> humanFN;
    static std::vector<std::string> humanLN;
    static std::vector<std::string> critterNames;
    static std::vector<std::string> monsterFN;
    static std::vector<std::string> monsterLN;
    static std::vector<std::string> vileAdj;
    static std::vector<std::string> vileNoun;
    static std::vector<std::string> animals;
    Lists() { }
    ~Lists() { }
    static std::string randomName(ENTITY_TYPE type);
};
//Original Lists courtesy of J. Munger
 /*static std::vector<std::string> colors = {
    "Cornsilk", "Azure", "Slate", "Gray", "Crimson", "Dark", "Red", "Medium", "Violet", "Red", "Seashell", "Lemon", "Chiffon", "Midnight", "Blue", "Silver", "Peach", "Puff", "Dark", "Magenta",
    "Old", "Lace", "Medium", "Sea", "Green", "Dark", "Orchid", "Pale", "Violet", "Red", "Orange", "Deep", "Pink", "Gold", "Orchid", "Light", "Steel", "Blue", "Cadet", "Blue", "Medium", "Slate",
    "Blue", "Violet", "Green", "Pale", "Turquoise", "Dark", "Cyan", "Green", "Yellow", "Dark", "Salmon", "Navajo", "White", "Antique", "White", "Cornflower", "Blue", "Dark", "Olive", "Green",
    "Light", "Sea", "Green", "Teal", "Blue", "Sandy", "Brown", "Magenta", "Lawn", "Green", "Dark", "Goldenrod", "Olive", "Forest", "Green", "Light", "Pink", "Aqua", "Dark", "Slate", "Gray",
    "Honeydew", "Powder", "Blue", "White", "Blanched", "Almond", "Thistle", "Pale", "Green", "Olive", "Drab", "Brown", "Plum", "Black", "Chocolate", "Mint", "Cream", "Fire", "Brick", "Dark",
    "Violet", "Orange", "Red", "Lavender", "Dark", "Sea", "Green", "Medium", "Slate", "Blue", "Amethyst", "Lime", "Dark", "Blue", "Light", "Salmon", "Saddle", "Brown", "Light","Yellow", "Medium",
    "Spring", "Green", "Light", "Cyan", "Medium", "Blue", "Lavender", "Blush", "Dark", "Khaki", "Yellow", "Dark", "Green", "Medium", "Aquamarine", "Bisque", "Snow", "Khaki", "Ivory", "Sienna",
    "Turquoise", "Goldenrod", "Chartreuse", "White", "Smoke", "Pink", "Misty", "Rose", "Cyan", "Medium", "Purple", "Red", "Navy", "Tan", "Spring", "Green", "Floral", "White", "Blue", "Violet",
    "Steel", "Blue", "Linen", "Rosy", "Brown"};



    static std::vector<std::string>  topics = { "pipes", "pharmacy", "coffee", "typewriters", "vaccines", "Napoleon", "magicians", "prisons", "newspapers", "elephants", "sewing", "machines", "prostitution", "tennis",
    "potatoes", "skull", "muppets", "cheese", "post", "office", "dogs", "goats", "hurricanes", "gorillas", "barbers","jewellery", "whales", "murderers", "windmills", "billiards", "zebras", "dance", "breweries",
    "earthquake", "banking", "Boy", "Scouts", "vanilla", "freaks", "Red", "Cross", "tattoos", "carousels", "motorcycles", "communism", "insects","ostriches", "seesaws", "veterinarians", "frogs", "baseball",
    "balloons", "shipping", "airports", "typewriter", "tigers", "monkeys", "fencing", "sports", "shoes", "oil", "archery", "Disney", "movies", "Native", "Americans", "cats", "royalty", "railroads", "hunting",
    "apes", "pilots", "milk", "mummies", "sheep", "football", "sharks", "basketball", "skating", "laundry", "bats", "women", "in", "the", "army", "mining", "nurses", "airplanes", "coal", "circus", "North", "Africa",
    "astronomy", "vegetables", "volcanoes", "athletics", "accordions", "telephone", "giraffes", "puppets", "army","water", "skiing", "cactus", "agriculture", "shovels", "printing", "parachuting", "cigarettes",
    "World", "War" };
    */

std::vector<std::string> Lists::monsterFN = { "Grobak", "Snaga", "Bil-grosh", "Vilimek" };
std::vector<std::string> Lists::monsterLN = { "Ognish", "Orbuk", "Orbo" };
std::vector<std::string> Lists::vileAdj = { "deprived", "small", "slimy", "hairy", "unshaven", "stanky", "putrid", "vile", "unwashed", "ragged", "slimy", "dank", "lubed", "abysmal","adverse","alarming","angry", "annoying", "anxious", "apathetic", "appalling",
        "atrocious", "awful", "banal", "barbed", "belligerent", "bemoaning", "broken", "callous", "clumsy", "coarse", "cold-hearted", "confused", "contradictory", "corrosive", "corrupted", "crazy",
         "cruel", "dastardly", "decaying", "deformed", "deplorable", "depressed", "deprived", "despicable", "dirty", "disease", "disgusting", "disheveled", "dreadful", "dreary", "enraged", "eroding", "evil", "feeble", "filthy",
         "foul", "frightful", "ghastly", "grave", "greedy", "grim", "gross", "grotesque", "gruesome", "guilty", "haggard", "hard-hearted", "hateful", "hideous", "horrendous", "horrible" };
std::vector<std::string> Lists::vileNoun = { "Sewage", "Bidet", "Plunger", "Sponge", "Eviscerator", "thug", "assassin", "maniac", "sludge" };
std::vector<std::string> Lists::adjectives = { "functional", "kaput", "standing", "filthy", "damp", "tedious", "fretful", "ruddy", "furtive", "perfect", "calculating", "heavy", "halting", "disgusting", "fluttering",
        "second-hand", "demonic", "repulsive", "erratic", "dapper", "silent", "sulky", "sloppy", "deeply", "belligerent", "unequaled", "chilly", "equable", "guarded", "sore", "quiet", "romantic", "hideous",
        "sweltering", "parsimonious", "scintillating", "nifty", "quarrelsome", "harsh", "parallel", "milky","superb", "tidy", "teeny-tiny", "brainy", "fallacious", "cooperative", "racial", "opposite",
        "untidy", "fair", "imaginary", "freezing", "lucky", "distinct", "courageous", "cut", "bored", "bewildered", "determined", "hysterical", "absorbing", "well-groomed", "high", "knowing", "rainy",
        "zippy","meaty", "merciful", "condemned", "average", "tranquil", "crowded", "mountainous", "hot", "apathetic", "alcoholic", "silly", "wistful", "bouncy", "nonstop", "aboard", "defective", "watery",
        "auspicious", "last", "dysfunctional", "sad","gabby", "talented", "shaky", "truculent", "false", "excellent", "square", "loutish", "brawny", "excited", "jumbled","nimble" };
std::vector<std::string> Lists::humanFN = { "Jean", "Prince", "Vanessa", "Shea", "Magdalena", "Roselyn", "Jeffrey", "Campbell", "Yasmine", "Lyric", "Braxton","Timothy", "Elisabeth", "Alan", "Hana", "Rodrigo", "Cael",
        "Ivan", "Isai", "Jan", "Raquel", "Fernanda", "Kasey", "Jayvon", "Mohammad", "Zayne", "Lia", "Chad", "Jadon", "Cason","Dylan", "Zain", "Helena", "Clay", "Marco", "Terrance", "Alexzander", "Ayana", "Kelsie",
        "Kaitlyn", "Asher", "Xavier", "Judah", "Zaniyah", "Erik", "Desmond", "Orlando", "Kristen", "Addyson", "Briley", "Melissa", "Roger", "Ulises", "Amiyah", "Aiden", "Todd", "Melvin", "Ada", "Jovanny", "Jamison",
        "Itzel", "Ignacio", "Gabriella", "Moshe", "Gabrielle", "Camille", "Reyna", "Ryan", "Juan", "Litzy", "Kamren", "Roy", "Ashanti", "Desirae", "Connor", "Julio", "Thaddeus", "Anabella", "Norah", "Bruno", "Micaela",
        "Riley", "Nasir", "Larry", "Nathalia", "Preston", "Taniyah", "Bridger", "Karley","Ricardo", "Darius", "Matteo", "Stacy", "Kaliyah", "Will","Mike", "Brendon", "Warren", "Osvaldo", "Julianna" };
std::vector<std::string> Lists::humanLN = { "Levy", "Lam", "Mcdaniel", "Ramirez", "Wyatt", "Stafford", "Patterson", "Lutz", "Serrano", "Mayo", "Shea", "Ibarra", "Weber", "Middleton", "Landry", "Howe", "Garrett", "Cooley",
        "Willis", "Boyle" };
std::vector<std::string> Lists::animals = { "mole", "rhinoceros", "duckbill platypus", "chamois", "elephant", "koala", "llama", "toad", "kitten", "fawn", "okapi", "rabbit", "weasel", "crow", "panda", "bumble bee",
        "dung beetle", "stallion", "beaver", "quagga", "rat" };

std::string Lists::randomName(ENTITY_TYPE type) {

    switch (type) {
    case HUMAN:
        return humanFN[randNum(humanFN.size() - 1)] + " \"" + adjectives[randNum(adjectives.size() - 1)] + " " + animals[randNum(animals.size() - 1)] + "\" " + humanLN[randNum(humanLN.size() - 1)];
    case HUMANOID:
        break;
    case CRITTER:
        return "a " + vileAdj[randNum(vileAdj.size() - 1)] + " " + animals[animals.size() - 1]; //Assume critter is a rat
        break;
    case MONSTER:
        return monsterFN[randNum(monsterFN.size() - 1)] + " \"The " + vileAdj[randNum(vileAdj.size() - 1)] + " " + vileNoun[randNum(vileNoun.size() - 1)] + "\" " + monsterLN[randNum(monsterLN.size() - 1)];
        break;
    case DEMON:

        break;
    case LEGENDARY_ITEM:

        break;
    }
}


#endif
