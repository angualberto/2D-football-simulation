#include <opencv2/opencv.hpp>
#include <iostream>
#include "player.h"
#include "strategy.h"

int main() {
    // Initialize OpenCV camera
    cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    // Create player and strategy objects
    Player player;
    Strategy strategy;

    // Main game loop
    while (true) {
        cv::Mat frame;
        camera >> frame; // Capture frame from camera

        if (frame.empty()) {
            std::cerr << "Error: Captured empty frame." << std::endl;
            break;
        }

        // Process player actions and update positions
        player.processSensors(frame);
        player.updatePosition();

        // Determine best passing strategy
        strategy.optimizeMesh(player.getPosition());
        int bestReceiver = player.determineBestPassReceiver();

        // Display the frame with player positions and actions
        cv::imshow("Game Feed", frame);

        // Exit on 'q' key press
        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    camera.release();
    cv::destroyAllWindows();
    return 0;
}