#pragma once

// serial baud rate
const unsigned long BAUD_RATE = 115200;

// input buffer size
const int BUF_SIZE = 6;

// responses
const char RESPONSE_SUCCESS[] = "2000";
const char RESPONSE_BAD_REQUEST[] = "4000";
const char RESPONSE_ERROR[] = "5000";

// iic addresses of relay boards
const int BOARD_1_ADDRESS = 0x6A;
const int BOARD_2_ADDRESS = 0x6B;
const int BOARD_3_ADDRESS = 0x6C;
const int BOARD_4_ADDRESS = 0x6D;

// relay toggle commands
const int RELAY_1_TOGGLE = 0x01;
const int RELAY_2_TOGGLE = 0x02;
const int RELAY_3_TOGGLE = 0x03;
const int RELAY_4_TOGGLE = 0x04;

// relay status commands
const int RELAY_1_STATUS = 0x05;
const int RELAY_2_STATUS = 0x06;
const int RELAY_3_STATUS = 0x07;
const int RELAY_4_STATUS = 0x08;

// commands for all relays
const int TURN_ALL_ON =  0xB;
const int TURN_ALL_OFF = 0xA;
const int TOGGLE_ALL = 0xC; 

// relay statuses
const int RELAY_STATUS_ERROR = -1;
const int RELAY_STATUS_OFF = 0;
const int RELAY_STATUS_ON = 15;
