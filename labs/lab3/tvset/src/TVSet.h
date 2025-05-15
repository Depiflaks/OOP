//
// Created by smmm on 15.05.2025.
//

#ifndef TVSET_H
#define TVSET_H

constexpr int k_minChannel = 1;
constexpr int k_maxChannel = 99;

class TVSet
{
public:
	TVSet() = default;
	void TurnOn();
	void TurnOff();
	void SelectChannel(int channel);
	void Info() const;

private:
	bool m_isTurnedOn{false};
	bool m_channel{ 0 };

	static void CheckChannelInExpectedRange(int channel);

	void PrintChannelChange() const;
	void PrintChannelStatus() const;
	void PrintPowerStatus() const;
};

#endif // TVSET_H
