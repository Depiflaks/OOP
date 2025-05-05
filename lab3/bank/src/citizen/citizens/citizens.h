//
// Created by smmm on 05.05.2025.
//

#ifndef CITIZENS_H
#define CITIZENS_H
#include <Citizen.h>

// CitizenApu
class CitizenApu final : public Citizen
{
public:
	CitizenApu(Bank& bank, IContactList& contacts, Money cash);

private:
	void PayForElectricity() const;
	void DepositCashMoney();
};

// CitizenBart
class CitizenBart final : public Citizen
{
public:
	CitizenBart(Bank& bank, IContactList& contacts, Money cash);

private:
	void BuyCandyFromApu();
};

// CitizenLisa
class CitizenLisa final : public Citizen
{
public:
	CitizenLisa(Bank& bank, IContactList& contacts, Money cash);

private:
	void BuyCandyFromApu();
};

// CitizenHomer
class CitizenHomer final : public Citizen
{
public:
	CitizenHomer(Bank& bank, IContactList& contacts, Money cash);

private:
	void TransferMoneyToMarge() const;
	void PayForElectricity() const;
	void GiveMoneyToChildren();
};

// CitizenMarge
class CitizenMarge final : public Citizen
{
public:
	CitizenMarge(Bank& bank, IContactList& contacts, Money cash);

private:
	void BuyGroceriesFromApu() const;
};

// CitizenMrBurns
class CitizenMrBurns final : public Citizen
{
public:
	CitizenMrBurns(Bank& bank, IContactList& contacts, Money cash);

private:
	void GiveSalaryToHomer() const;
	void GiveSalaryToSmithers() const;
};

// CitizenNelson
class CitizenNelson final : public Citizen
{
public:
	CitizenNelson(Bank& bank, IContactList& contacts, Money cash);

private:
	void StealFromBart();
	void BuyCigarettesFromApu();
};

// CitizenSmithers
class CitizenSmithers final : public Citizen
{
public:
	CitizenSmithers(Bank& bank, IContactList& contacts, Money cash);

private:
	void BuyGroceries() const;
	void ChangeAccount();
};

// CitizenSnake
class CitizenSnake final : public Citizen
{
public:
	CitizenSnake(Bank& bank, IContactList& contacts, Money cash);

private:
	void HackHomerAccount() const;
	void BuyGroceriesFromApu() const;
};

#endif // CITIZENS_H
