#include "player.h"
#include <opencv2/opencv.hpp>
#include <vector>

Player::Player(int id) : playerId(id), position(0, 0) {}

void Player::updatePosition(double x, double y) {
    position = cv::Point2d(x, y);
}

void Player::processSensors(const std::vector<cv::Point2d>& detectedObjects) {
    // Process sensor data to update player state
    for (const auto& obj : detectedObjects) {
        // Example processing logic (e.g., update player awareness of objects)
    }
}

cv::Point2d Player::determineBestPassReceiver(const std::vector<Player>& teammates) {
    // Logic to determine the best teammate to pass to
    cv::Point2d bestReceiver;
    double maxScore = -1;

    for (const auto& teammate : teammates) {
        double score = evaluatePassPotential(teammate);
        if (score > maxScore) {
            maxScore = score;
            bestReceiver = teammate.getPosition();
        }
    }

    return bestReceiver;
}

double Player::evaluatePassPotential(const Player& teammate) const {
    // Evaluate the potential of passing to a teammate based on distance and angle
    double distance = cv::norm(position - teammate.getPosition());
    // Additional scoring logic can be added here
    return 1.0 / (distance + 1); // Example scoring function
}

cv::Point2d Player::getPosition() const {
    return position;
}