#pragma once

#include <string>
#include <thread>

#include "ble_lib_board.h"


class Muse2 : public BLELibBoard
{

private:
    volatile bool keep_alive;
    bool initialized;
    std::thread streaming_thread;

    void read_thread ();

public:
    Muse2 (struct BrainFlowInputParams params);
    ~Muse2 ();

    int prepare_session ();
    int start_stream (int buffer_size, const char *streamer_params);
    int stop_stream ();
    int release_session ();
    int config_board (std::string config, std::string &response);
};