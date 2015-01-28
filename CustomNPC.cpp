#include "ScriptPCH.h"

class CustomNPC : public CreatureScript
{
public:
	CustomNPC()
		: CreatureScript("CustomNPC")
	{}

	void CreatureWhisperBasedOnBool(const char *text, Creature *creature, Player *player, bool value)
	{
		if (value)
			creature->Whisper(text, LANG_UNIVERSAL, player, false);
	}

	void MainMenu(Player *player, Creature *creature)
	{
		player->ADD_GOSSIP_ITEM(6, "[VIEW SHOP]", GOSSIP_SENDER_MAIN, 0);
		player->SEND_GOSSIP_MENU(907, creature->GetGUID());
	}

	bool OnGossipHello(Player* player, Creature* creature)
	{
		MainMenu(player, creature);

		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
	{
		player->PlayerTalkClass->ClearMenus();

		switch (uiAction)
		{
		case 0:
			player->GetSession()->SendListInventory(creature->GetGUID());
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			break;
		}
		return true;
	}
};
void AddSC_CustomNPC()
{
	new CustomNPC();
}