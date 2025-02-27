// filepath: /positioning-passing-strategy/positioning-passing-strategy/src/player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <opencv2/core.hpp>
#include <vector>

class Player {
public:
    Player(int id, const cv::Point2f& initialPosition);

    void updatePosition(const cv::Point2f& newPosition);
    void processSensors(const std::vector<cv::Point2f>& detectedObjects);
    int determineBestPassReceiver(const std::vector<Player>& teammates) const;

    int getId() const;
    cv::Point2f getPosition() const;

private:
    int id;
    cv::Point2f position;
};

#endif // PLAYER_H