# Positioning and Passing Strategy Project

This project implements a positioning and passing strategy for a simulated soccer game using OpenCV and polar coordinates. The system is designed to provide players with a 360º vision, enabling them to make informed decisions based on their surroundings.

## Project Structure

The project is organized as follows:

```
positioning-passing-strategy
├── src
│   ├── main.cpp               # Entry point of the application
│   ├── player.cpp             # Implementation of the Player class
│   ├── player.h               # Header file for the Player class
│   ├── strategy.cpp           # Implementation of the Strategy class
│   ├── strategy.h             # Header file for the Strategy class
│   └── utils
│       ├── opencv_utils.cpp   # Utility functions for OpenCV operations
│       └── opencv_utils.h     # Header file for OpenCV utility functions
├── CMakeLists.txt             # CMake configuration file
├── README.md                  # Project documentation
└── config
    └── config.yaml            # Configuration settings for the project
```

## Setup Instructions

1. **Clone the Repository**: 
   Clone this repository to your local machine using:
   ```
   git clone <repository-url>
   ```

2. **Install Dependencies**: 
   Ensure you have OpenCV installed on your system. You can install it using package managers or build it from source.

3. **Build the Project**: 
   Navigate to the project directory and create a build directory:
   ```
   cd positioning-passing-strategy
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Run the Application**: 
   After building, you can run the application using:
   ```
   ./positioning-passing-strategy
   ```

## Usage Examples

- The application initializes the OpenCV camera feed and continuously processes images to update player positions and determine passing strategies.
- Players can make decisions based on their current positions and the positions of other players, the ball, and the goal.

## Overview of Implemented Strategies

- **Positioning**: Players utilize polar coordinates to optimize their positions on the field, ensuring they are in the best location to receive or pass the ball.
- **Passing**: The system evaluates potential pass receivers based on their positions and the current game state, optimizing the passing strategy using Delaunay triangulations and differential evolution techniques.

## Configuration

Configuration settings for the project can be found in `config/config.yaml`. This file includes parameters for camera settings, player attributes, and strategy configurations. Adjust these settings as necessary to fit your specific requirements.

## Acknowledgments

This project utilizes OpenCV for image processing and computer vision tasks, enabling real-time analysis and decision-making in a simulated soccer environment.