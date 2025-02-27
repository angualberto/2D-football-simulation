#include <vector>
#include <iostream>

struct Player {
    int id;
    double x;
    double y;
};

void applyFormation(std::vector<Player>& players, bool isLeftSide, bool hasPossession) {
    if (isLeftSide || hasPossession) {
        // 3-4-3 formation
        players = {
            {-1, 0, 0},   // Goalkeeper
            {-2, -10, 10}, {-3, -10, 0}, {-4, -10, -10}, // Defenders
            {-5, -5, 15}, {-6, -5, 5}, {-7, -5, -5}, {-8, -5, -15}, // Midfielders
            {-9, 0, 20}, {-10, 0, 10}, {-11, 0, 0} // Forwards
        };
    } else {
        // 5-1-4 formation
        players = {
            {1, 0, 0},   // Goalkeeper
            {2, 10, 15}, {3, 10, 10}, {4, 10, 5}, {5, 10, 0}, {6, 10, -5}, // Defenders
            {7, 5, 0}, // Defensive Midfielder
            {8, 0, 20}, {9, 0, 10}, {10, 0, 0}, {11, 0, -10} // Forwards
        };
    }
}

int main() {
    std::vector<Player> players;
    bool isLeftSide = true; // Example: team starts on the left side
    bool hasPossession = true; // Example: team has possession

    applyFormation(players, isLeftSide, hasPossession);

    for (const auto& player : players) {
        std::cout << "Player " << player.id << ": (" << player.x << ", " << player.y << ")\n";
    }

    return 0;
}
