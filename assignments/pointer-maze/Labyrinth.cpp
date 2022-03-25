#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    MazeCell * curr = start;
    bool has_spellbook, has_potion, has_wand = false;

    for (int i = 0; i < moves.length(); i++){
        if (moves[i] == 'N') curr = curr->north;
        else if (moves[i] == 'E') curr = curr->east;
        else if (moves[i] == 'S') curr = curr->south;
        else if (moves[i] == 'W') curr = curr->west;
        else return false;

        if (curr == nullptr) return false;

        if (curr->whatsHere == Item::SPELLBOOK) has_spellbook = true;
        else if (curr->whatsHere == Item::WAND) has_wand = true;
        else if (curr->whatsHere == Item::POTION) has_potion = true;
    }

    if (has_potion && has_spellbook && has_wand) return true;
    return false;
}
