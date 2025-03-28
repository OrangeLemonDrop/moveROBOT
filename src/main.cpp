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
}

// Основной цикл программы МК
void loop()
{
    // Вывод по UART (в монитор порта, если подключено к ПК)
    Serial.println("Forward...");
    // Запуск вращения в одну сторону
    mDriver_func.forward(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(100);
    // Вывод по UART (в монитор порта, если подключено к ПК)
    Serial.println("Backward...");
    // Запуск вращения в другую сторону
    mDriver_func.backward(&mDriver_dat);
    // Бездействие в течении указанных мс
    delay(100);
}