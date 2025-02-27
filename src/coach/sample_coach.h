// -*-c++-*-

/*
 *Copyright:

 Copyright (C) Hidehisa AKIYAMA

 This code is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3, or (at your option)
 any later version.

 This code is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this code; see the file COPYING.  If not, write to
 the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.

 *EndCopyright:
 */

/////////////////////////////////////////////////////////////////////

#ifndef SAMPLE_COACH_H
#define SAMPLE_COACH_H

#include <rcsc/coach/coach_agent.h>
#include <rcsc/types.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

namespace rcsc {
class PlayerType;
}


class SampleCoach
    : public rcsc::CoachAgent {
private:
    typedef std::vector< const rcsc::PlayerType * > PlayerTypePtrCont;


    int M_opponent_player_types[11];

    rcsc::TeamGraphic M_team_graphic;

public:

    SampleCoach();

    virtual
    ~SampleCoach();


protected:

    /*!
      You can override this method.
      But, CoachAgent::initImpl() must be called in this method.
    */
    virtual
    bool initImpl( rcsc::CmdLineParser & cmd_parser );

    //! main decision making
    virtual
    void actionImpl();


    virtual
    void handleInitMessage();
    virtual
    void handleServerParam();
    virtual
    void handlePlayerParam();
    virtual
    void handlePlayerType();

private:

    void doSubstitute();

    void doFirstSubstitute();
    void doSubstituteTiredPlayers();

    void substituteTo( const int unum,
                       const int type );

    int getFastestType( PlayerTypePtrCont & candidates );

    void sayPlayerTypes();

    void sendTeamGraphic();

    // Function declarations
    std::pair<double, double> cartesian_to_polar(double x, double y, double x_ref, double y_ref);
    void capture_and_detect(cv::Mat &frame, std::vector<cv::Point> &players, cv::Point &ball, cv::Point &goal);
    void configure_360_vision(const std::vector<cv::Point> &players, const cv::Point &ball, const cv::Point &goal);
    void create_positioning_mesh(const std::vector<cv::Point> &players);
    void optimize_mesh();
    int determine_best_agent(const std::vector<cv::Point> &players, const cv::Point &ball, const cv::Point &goal);
    void send_commands(const cv::Point &player, const cv::Point &target);
    void update_game_state();
    void monitor_and_adjust_strategy();

    /*!
      \brief detect players using OpenCV
      \param frame the video frame
    */
    void detectPlayers(cv::Mat frame)
      {
          cv::Mat gray;
          cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
          std::vector<std::vector<cv::Point>> contours;
          cv::findContours(gray, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

          int playerCount = std::min(11, (int)contours.size());
          for (int i = 0; i < playerCount; i++) {
              M_opponent_player_types[i] = i % 5; // Simulação de detecção de tipos
          }
      }

    /*!
      \brief send message via UDP
      \param message the message to send
      \param serverIP the server IP address
      \param port the server port
    */
    void sendMessageUDP(const std::string &message, const char *serverIP, int port)
      {
          int sock = socket(AF_INET, SOCK_DGRAM, 0);
          if (sock < 0) {
              std::cerr << "Erro ao criar socket UDP" << std::endl;
              return;
          }

          sockaddr_in serverAddr;
          memset(&serverAddr, 0, sizeof(serverAddr));
          serverAddr.sin_family = AF_INET;
          serverAddr.sin_port = htons(port);
          serverAddr.sin_addr.s_addr = inet_addr(serverIP);

          sendto(sock, message.c_str(), message.size(), 0, (sockaddr *)&serverAddr, sizeof(serverAddr));
          close(sock);
      }
};

#endif
