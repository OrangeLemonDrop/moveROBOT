/**
 * \file main.cpp
 * \author AMasterov
 * \brief Основной файл программы
 * \version 0.1
 * \date 2025-02-11
 *
 * \copyright Copyright (c) 2025
 *
 */

// Подключение фенкций и данных фреймворка Arduino
#include <Arduino.h>
// Подключение библиотеки
#include "../lib/smif_test/src/smif_func_test.h"

// Функция предварительной настройки МК
void setup()
{
    // Установка скорости UART 115200 бит/с
    Serial.begin(115200);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    Serial.println("Initing...");
    // Включение buid-in RGB-LED
    neopixelWrite(48, 0x7F, 0x7F, 0x7F);
    // Бездействие в течении указанных мс
    delay(1000);
    // Инициализация данных управления ДПТ
    mDriver_func.init(&mDriver_dat, &bts7960_func);

    // save pins state in flash memory
    EEPROM.write(1, 9);
    EEPROM.write(2, 46);
/*     EEPROM.write(3, 0xFF);
    EEPROM.write(4, 0xFF);
    EEPROM.write(5, 0xFF);
    EEPROM.write(6, 0xFF); */
    EEPROM.write(7, 42);
    EEPROM.write(8, 1);
/*     EEPROM.write(9, 0xFF);
    EEPROM.write(10, 0xFF);
    EEPROM.write(11, 0xFF);
    EEPROM.write(12, 0xFF); */
    EEPROM.write(13, 36);
    EEPROM.write(14, 37);
/*     EEPROM.write(15, 0xFF);
    EEPROM.write(16, 0xFF);
    EEPROM.write(17, 0xFF);
    EEPROM.write(18, 0xFF); */
    EEPROM.write(19, 6);
    EEPROM.write(20, 7);
/*     EEPROM.write(21, 0xFF);
    EEPROM.write(22, 0xFF);
    EEPROM.write(23, 0xFF);
    EEPROM.write(24, 0xFF); */
    EEPROM.commit();
}

// Основной цикл программы МК
void loop()
{
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Forward...");
    // Запуск движения вперёд
    mDriver_func.forward(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(1000);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Backward...");
    // Запуск движения назад
    mDriver_func.backward(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(1000);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Spin Left...");
    // Запуск вращения робота вокруг своей оси против часовой
    mDriver_func.spin_left(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(1000);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Spin Right...");
    // Запуск робота вокруг своей оси по часовой
    mDriver_func.spin_right(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(1000);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Turn Left Forward...");
    // Поворот робота по заданному радиусу влево-вперёд
    mDriver_func.turn_left_forward(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(1000);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Turn Right Forward...");
    // Поворот робота по заданному радиусу вправо-вперёд
    mDriver_func.turn_right_forward(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(1000);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Turn Left Backward...");
    // Поворот робота по заданному радиусу влево-назад
    mDriver_func.turn_left_backward(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(1000);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Turn Right Backward...");
    // Поворот робота по заданному радиусу вправо-назад
    mDriver_func.turn_right_backward(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(1000);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Omni Left...");
    // Движение робота влево боком
    mDriver_func.omni_left(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(1000);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    //Serial.println("Omni Right...");
    // Движение робота вправо боком
    mDriver_func.omni_right(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(3000);
    mDriver_func.stop(&mDriver_dat);
    delay(3000);
}