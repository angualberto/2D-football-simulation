#include "strategy.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>
#include <iostream>

namespace positioning_passing_strategy {

void Strategy::convertToPolar(const std::vector<cv::Point2f>& cartesianPoints, std::vector<std::pair<float, float>>& polarPoints) {
    polarPoints.clear();
    for (const auto& point : cartesianPoints) {
        float radius = std::sqrt(point.x * point.x + point.y * point.y);
        float angle = std::atan2(point.y, point.x);
        polarPoints.emplace_back(radius, angle);
    }
}

void Strategy::generateDelaunayMesh(const std::vector<cv::Point2f>& points, cv::Subdiv2D& subdiv) {
    subdiv.initDelaunay(cv::Rect(0, 0, 640, 480)); // Assuming a 640x480 image size
    for (const auto& point : points) {
        subdiv.insert(point);
    }
}

void Strategy::optimizeMesh(std::vector<cv::Point2f>& meshPoints) {
    // Implement optimization logic here (e.g., differential evolution)
    // This is a placeholder for the optimization algorithm
    for (auto& point : meshPoints) {
        point.x += (std::rand() % 10 - 5); // Random adjustment for demonstration
        point.y += (std::rand() % 10 - 5);
    }
}

void Strategy::sendPassCommand(const Player& passer, const Player& receiver) {
    std::cout << "Pass from Player " << passer.getId() << " to Player " << receiver.getId() << std::endl;
}

} // namespace positioning_passing_strategy