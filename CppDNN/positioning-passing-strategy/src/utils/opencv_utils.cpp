#include "opencv_utils.h"
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;

namespace utils {

Mat captureImage(VideoCapture &cap) {
    Mat frame;
    cap >> frame; // Capture a new frame from the camera
    return frame;
}

std::vector<Rect> detectObjects(const Mat &frame, const CascadeClassifier &classifier) {
    std::vector<Rect> objects;
    classifier.detectMultiScale(frame, objects, 1.1, 3, 0, Size(30, 30));
    return objects;
}

Mat filterImage(const Mat &frame) {
    Mat gray, blurred, edges;
    cvtColor(frame, gray, COLOR_BGR2GRAY); // Convert to grayscale
    GaussianBlur(gray, blurred, Size(5, 5), 0); // Apply Gaussian blur
    Canny(blurred, edges, 50, 150); // Detect edges
    return edges;
}

} // namespace utils