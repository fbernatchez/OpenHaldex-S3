#pragma once

// Board selection:
// - OH_BOARD_T2CAN: LilyGo T-2CAN (MCP2515 CAN 2.0B)
// - OH_BOARD_T2CAN_FD: LilyGo T-2CAN-FD (MCP2518FD CAN FD controller)
#if !defined(OH_BOARD_T2CAN) && !defined(OH_BOARD_T2CAN_FD)
#define OH_BOARD_T2CAN 1
#endif

#if defined(OH_BOARD_T2CAN_FD) && OH_BOARD_T2CAN_FD
#define OH_CAN_HALDEX_MCP2518FD 1
#define OH_CAN_HALDEX_MCP2515 0
#else
#ifndef OH_CAN_HALDEX_MCP2515
#define OH_CAN_HALDEX_MCP2515 1
#endif
#define OH_CAN_HALDEX_MCP2518FD 0
#endif

#if !OH_BOARD_T2CAN && !OH_BOARD_T2CAN_FD
#error "This project targets the LilyGo T-2CAN or T-2CAN-FD (ESP32-S3)."
#endif

// LilyGo T-2CAN / T-2CAN-FD common CAN pins:
// Chassis bus uses internal ESP32-S3 TWAI on CAN1 pins (GPIO 7 TX, GPIO 6 RX)
#define CAN0_RS -1
#define CAN0_RX -1
#define CAN0_TX -1
#define CAN1_RS -1
#define CAN1_RX 6
#define CAN1_TX 7

#if OH_BOARD_T2CAN_FD
// LilyGo T-2CAN-FD (ESP32-S3) MCP2518FD SPI pin map
#define MCP2518_CS 10
#define MCP2518_SCLK 12
#define MCP2518_MOSI 11
#define MCP2518_MISO 13
#define MCP2518_INT 8
#define MCP2518_INT_0 9
#define MCP2518_INT_1 3
#else
// LilyGo T-2CAN (ESP32-S3) MCP2515 SPI pin map
#define MCP2515_CS 10
#define MCP2515_SCLK 12
#define MCP2515_MOSI 11
#define MCP2515_MISO 13
#define MCP2515_RST 9
#define MCP2515_INT 8
#endif
