#pragma once

#include <Arduino.h>

#ifndef OH_UPDATE_URL
#define OH_UPDATE_URL "https://raw.githubusercontent.com/fbernatchez/OpenHaldex-S3/main/version.json"
#endif

struct UpdateInfo {
  String current;
  String latest;
  bool available;
  uint32_t lastCheckMs;
  String error;
  String url;
  String firmwareUrl;
  String filesystemUrl;
  bool installing;
  String installError;
  uint32_t bytesTotal;
  uint32_t bytesDone;
  float speedBps;
  uint32_t progressMs;
  String stage;
};

void updateInit();
void updateCheckNow();
bool updateGetInfo(UpdateInfo& out);
bool updateInstallStart();
