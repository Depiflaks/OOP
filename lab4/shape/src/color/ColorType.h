//
// Created by smmm on 10.05.2025.
//

#ifndef COLOR_TYPE_H
#define COLOR_TYPE_H

#include <cstdint>

class ColorType {
public:
    ColorType();
    ColorType(uint8_t a, uint8_t r, uint8_t g, uint8_t b);
    explicit ColorType(uint32_t argb);

    uint8_t GetAlpha() const;
    uint8_t GetRed() const;
    uint8_t GetGreen() const;
    uint8_t GetBlue() const;
    uint32_t GetARGB() const;

    void SetAlpha(uint8_t a);
    void SetRed(uint8_t r);
    void SetGreen(uint8_t g);
    void SetBlue(uint8_t b);
    void SetARGB(uint8_t a, uint8_t r, uint8_t g, uint8_t b);
    void SetARGB(uint32_t argb);

private:
    uint32_t m_color;
};

#endif // COLOR_TYPE_H
