//
// Created by smmm on 10.05.2025.
//

#include "ColorType.h"

ColorType::ColorType()
	: m_color(0xFF000000)
{
}

ColorType::ColorType(const uint8_t a, const uint8_t r, const uint8_t g, const uint8_t b)
	: m_color(0)
{
	SetARGB(a, r, g, b);
}

ColorType::ColorType(const uint32_t argb)
	: m_color(argb)
{
}

uint8_t ColorType::GetAlpha() const { return (m_color >> 24) & 0xFF; }
uint8_t ColorType::GetRed() const { return (m_color >> 16) & 0xFF; }
uint8_t ColorType::GetGreen() const { return (m_color >> 8) & 0xFF; }
uint8_t ColorType::GetBlue() const { return m_color & 0xFF; }
uint32_t ColorType::GetARGB() const { return m_color; }

void ColorType::SetAlpha(const uint8_t a) { m_color = (m_color & 0x00FFFFFF) | (a << 24); }
void ColorType::SetRed(const uint8_t r) { m_color = (m_color & 0xFF00FFFF) | (r << 16); }
void ColorType::SetGreen(const uint8_t g) { m_color = (m_color & 0xFFFF00FF) | (g << 8); }
void ColorType::SetBlue(const uint8_t b) { m_color = (m_color & 0xFFFFFF00) | b; }

void ColorType::SetARGB(const uint8_t a, const uint8_t r, const uint8_t g, const uint8_t b)
{
	m_color = (a << 24) | (r << 16) | (g << 8) | b;
}

void ColorType::SetARGB(const uint32_t argb)
{
	m_color = argb;
}
