#pragma once

const unsigned long BAUD_RATE = 115200;

const int BUF_SIZE = 6;

const char RESPONSE_SUCCESS[] = "2000";
const char RESPONSE_BAD_REQUEST[] = "4000";
const char RESPONSE_ERROR[] = "5000";

const int BOARD_1_ADDRESS = 0x6A;    // iic address of relay board
const int BOARD_2_ADDRESS = 0x6B;
const int BOARD_3_ADDRESS = 0x6C;
const int BOARD_4_ADDRESS = 0x6D;

const int RELAY_COUNT = 4;

const int RELAY_1_TOGGLE = 0x01;
const int RELAY_2_TOGGLE = 0x02;
const int RELAY_3_TOGGLE = 0x03;
const int RELAY_4_TOGGLE = 0x04;

const int RELAY_1_STATUS = 0x05;
const int RELAY_2_STATUS = 0x06;
const int RELAY_3_STATUS = 0x07;
const int RELAY_4_STATUS = 0x08;

const int TURN_ALL_ON =  0xB;
const int TURN_ALL_OFF = 0xA;
const int TOGGLE_ALL = 0xC; 
