#ifdef USE_NATIVE
#define LGFX_AUTODETECT
#include <LovyanGFX.h>

#include <LGFX_AUTODETECT.hpp>
#else
#include <M5AtomDisplay.h>
#endif

#include <Arduino.h>
// #include <stdlib.h>
#include <string_asukiaaa.h>
#include <unistd.h>

// #include <iostream>

#if defined(USE_NATIVE)
// static LGFX lcd ( 320, 240, 2 );
static LGFX lcd(1080, 1920, 2);
// static LGFX lcd(1920, 1080, 2);
#else
M5AtomDisplay lcd(1920, 1080);
#endif

void setup() {
  lcd.init();
#ifndef USE_NATIVE
  lcd.setRotation(0);
#endif
  lcd.setTextSize(8);
  lcd.setTextColor(TFT_WHITE, TFT_BLACK);
}

void loop() {
#ifdef USE_NATIVE
  auto seconds = time(NULL);
#else
  auto seconds = millis() / 1000;
#endif
  // print(string_asukiaaa::padStart("hi", 4, ' ').c_str());
  // print("\n");
  // // printf("hello\n");
  // fflush(stdout);
  // std::cout << "hello" << std::endl;
  lcd.setCursor(0, 0);
  lcd.println("top left");
  lcd.print("string test ");
  lcd.println(string_asukiaaa::padStart("abcd", 10, '-').c_str());
  lcd.println(("at " + String(seconds)).c_str());
  lcd.drawRightString("bottom right", lcd.width(),
                      lcd.height() - lcd.fontHeight());
#ifdef USE_NATIVE
  sleep(1);
#else
  delay(1000);
  // delay(999);
#endif
}

#if defined(USE_NATIVE)
int user_func(bool* running) {
  setup();
  do {
    loop();
  } while (*running);
  return 0;
}

int main(int, char**) { return lgfx::Panel_sdl::main(user_func); }
#endif
