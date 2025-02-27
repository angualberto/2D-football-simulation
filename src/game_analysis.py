import cv2
import numpy as np
from scipy.spatial import Voronoi, voronoi_plot_2d

def capture_game_frame(video_source):
    cap = cv2.VideoCapture(video_source)
    ret, frame = cap.read()
    cap.release()
    return frame if ret else None

def apply_voronoi(points, frame):
    vor = Voronoi(points)
    voronoi_plot_2d(vor, show_vertices=False, line_colors='orange', line_width=2, line_alpha=0.6, point_size=2)
    return frame

def cartesian_to_polar(x, y, ref_x, ref_y):
    r = np.sqrt((x - ref_x)**2 + (y - ref_y)**2)
    theta = np.arctan2(y - ref_y, x - ref_x)
    return r, theta

def polar_to_cartesian(r, theta, ref_x, ref_y):
    x = r * np.cos(theta) + ref_x
    y = r * np.sin(theta) + ref_y
    return x, y

def optimize_positions(players, goal, F=0.5):
    new_positions = []
    for i in range(len(players)):
        r1, r2, r3 = np.random.choice(len(players), 3, replace=False)
        new_r = players[r3][0] + F * (players[r1][0] - players[r2][0])
        new_theta = players[r3][1] + F * (players[r1][1] - players[r2][1])
        new_positions.append(polar_to_cartesian(new_r, new_theta, goal[0], goal[1]))
    return new_positions

def define_formation(players, ball_position, side):
    if side == 'left' or ball_position[0] < 0:
        # Formation 3-4-3
        formation = [(0, 0), (-20, 10), (-20, -10), (-10, 20), (-10, 0), (-10, -20), (0, 30), (0, 10), (0, -10), (0, -30)]
    else:
        # Formation 5-1-4
        formation = [(0, 0), (-30, 10), (-30, -10), (-20, 20), (-20, 0), (-20, -20), (-10, 0), (0, 20), (0, 10), (0, -10), (0, -20)]
    return formation

def main():
    video_source = 'path_to_video.mp4'
    frame = capture_game_frame(video_source)
    if frame is None:
        print("Failed to capture game frame.")
        return

    players = [(100, 150), (200, 250), (300, 350)]  # Example player positions
    goal = (500, 0)  # Opponent's goal position
    ball_position = (0, 0)  # Example ball position
    side = 'left'  # Example side

    polar_positions = [cartesian_to_polar(x, y, goal[0], goal[1]) for x, y in players]
    optimized_positions = optimize_positions(polar_positions, goal)
    formation = define_formation(players, ball_position, side)

    for pos in optimized_positions:
        cv2.circle(frame, (int(pos[0]), int(pos[1])), 5, (0, 255, 0), -1)

    cv2.imshow('Optimized Positions', frame)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
