//
// Created by smmm on 15.05.2025.
//

#include "TVSet.h"

#include "exception/TVSetError.h"

#include <iostream>
void TVSet::TurnOn()
{
	m_isTurnedOn = true;
	PrintPowerStatus();
}

void TVSet::TurnOff()
{
	m_isTurnedOn = false;
	PrintPowerStatus();
}

void TVSet::SelectChannel(const int channel)
{
	if (m_isTurnedOn)
	{
		CheckChannelInExpectedRange(channel);
		m_channel = channel;
		PrintChannelChange();
	}
	else
	{
		PrintPowerStatus();
	}
}

void TVSet::Info() const
{
	PrintChannelStatus();
	if (m_isTurnedOn)
		PrintChannelStatus();
}

void TVSet::CheckChannelInExpectedRange(const int channel)
{
	if (channel < k_minChannel || channel > k_maxChannel)
		throw ChannelOutOfRangeError();
}

void TVSet::PrintChannelChange() const
{
	std::cout << "Channel switched to: " << m_channel << '\n';
}

void TVSet::PrintChannelStatus() const
{
	std::cout << "Channel is: " << m_channel << '\n';
}

void TVSet::PrintPowerStatus() const
{
	std::cout << "TV is turned " << (m_isTurnedOn ? "on" : "off") << '\n';
}
