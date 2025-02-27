import cv2
import numpy as np
import socket
from scipy.spatial import Delaunay

def detect_players(frame):
    # Convertendo para escala de cinza
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    # Aplicando detecção de bordas
    edges = cv2.Canny(gray, 50, 150)
    
    # Detectando contornos
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    player_positions = []
    for contour in contours:
        if cv2.contourArea(contour) > 100:
            M = cv2.moments(contour)
            if M["m00"] != 0:
                cx = int(M["m10"] / M["m00"])
                cy = int(M["m01"] / M["m00"])
                player_positions.append((cx, cy))
    
    return player_positions

def convert_to_polar(x, y, x_ref, y_ref):
    r = np.sqrt((x - x_ref) ** 2 + (y - y_ref) ** 2)
    theta = np.arctan2(y - y_ref, x - x_ref)
    return r, np.degrees(theta)

def optimize_triangulation(points):
    if len(points) < 3:
        return []
    
    tri = Delaunay(points)
    return tri.simplices

def send_udp_message(message, address=('127.0.0.1', 5005)):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(message.encode(), address)

def main():
    cap = cv2.VideoCapture('game_video.mp4')  # Substitua pelo feed ao vivo
    
    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break
        
        players = detect_players(frame)
        triangulation = optimize_triangulation(players)
        
        for triangle in triangulation:
            pts = np.array([players[i] for i in triangle], np.int32)
            cv2.polylines(frame, [pts], isClosed=True, color=(0, 255, 0), thickness=1)
        
        for (x, y) in players:
            r, theta = convert_to_polar(x, y, 0, 0)
            send_udp_message(f'Player at: {x},{y} -> Polar: {r:.2f}, {theta:.2f}')
            cv2.circle(frame, (x, y), 5, (0, 0, 255), -1)
        
        cv2.imshow('Game Analysis', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    
    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
