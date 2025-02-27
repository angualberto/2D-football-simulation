#include "coach/sample_coach.h"

int main() {
    VideoCapture cap(0); // Captura de vídeo da câmera
    if (!cap.isOpened()) {
        cerr << "Erro ao abrir a câmera" << endl;
        return -1;
    }

    SampleCoach coach;
    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break;

        coach.detectPlayers(frame);
        std::string message = "(pt ";
        for (int i = 0; i < 11; ++i) {
            message += (coach.M_opponent_player_types[i] == -1) ? '-' : ('A' + coach.M_opponent_player_types[i]);
        }
        message += ")";
        cout << "Mensagem enviada: " << message << endl;

        coach.sendMessageUDP(message, "127.0.0.1", 6000); // Envia para o servidor UDP
        imshow("Detecção de Jogadores", frame);
        if (waitKey(30) >= 0) break;
    }
    return 0;
}
