//
// Created by smmm on 15.05.2025.
//

#ifndef TVSET_H
#define TVSET_H

class TVSet
{
public:
	TVSet() = default;
	void TurnOn();
	void TurnOff();
	void SelectChannel(int channel);
	void Info() const;
	// todo: вынести info -> геттеры и отдельный класс под сбор в логи

private:
	bool m_isTurnedOn{false};
	int m_channel{ 0 };

	static void CheckChannelInExpectedRange(int channel);

	void PrintChannelChange() const;
	void PrintChannelStatus() const;
	void PrintPowerStatus() const;
};

#endif // TVSET_H
