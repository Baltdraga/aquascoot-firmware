# - ESP32mini - Display ERC128128 (ST7571) test

## Назначение
Графический LCD ERC128128FS02-3, контроллер ST7571, режим I²C, ESP32-C3.

## Подключение питания
VDD (17–20) → 3.3V
VSS (21–24) → GND

## Фиксация I²C режима
PS0 → GND
PS1 → GND
PS2 → 3.3V
CSB → GND
A0  → GND

## Подключение к ESP32-C3
DB7 (SDA) → GPIO8
DB6 (SCL) → GPIO9
RST       → GPIO7

## Примечания
- Контроллер: ST7571
- Интерфейс: I²C
- Библиотека: U8g2
