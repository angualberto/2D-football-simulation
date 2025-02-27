#ifndef OPENCV_UTILS_H
#define OPENCV_UTILS_H

#include <opencv2/opencv.hpp>
#include <vector>

// Function to capture an image from the camera
cv::Mat captureImage(int cameraIndex = 0);

// Function to detect objects in the image (ball, goal, players)
std::vector<cv::Rect> detectObjects(const cv::Mat& image);

// Function to apply image filtering techniques
cv::Mat filterImage(const cv::Mat& image, int filterType);

#endif // OPENCV_UTILS_H