#include "CTRPluginFramework.hpp"
#include "cheats.hpp"
#include "csvc.h"

namespace CTRPluginFramework
{
	const std::string NewLINE = "\n";//改行
	std::string CTRPFname = "try again noob";//3gx名前
	std::string about1 = "勉強しろ";//about1行目
	std::string about2 = "";//about2行目
	std::string about3 = "";//about3行目
	std::string about4 = "";//about4行目
	std::string about5 = "";//about5行目
	static MenuEntry *AddArg(void *arg, MenuEntry *entry)
	{
		if (entry != nullptr)
			entry->SetArg(arg);
		return (entry);
	}

	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const Hotkey& hotkey)
	{
		if (entry != nullptr)
		{
			entry->Hotkeys += hotkey;
			entry->SetArg(new std::string(entry->Name()));
			entry->Name() += " " + hotkey.ToString();
			entry->Hotkeys.OnHotkeyChangeCallback([](MenuEntry *entry, int index)
				{
					std::string *name = reinterpret_cast<std::string*>(entry->GetArg());

					entry->Name() = *name + " " + entry->Hotkeys[0].ToString();
				});
		}
		return (entry);
	}

	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const std::vector<Hotkey>& hotkeys)
	{
		if (entry != nullptr)
		{
			for (const Hotkey& hotkey : hotkeys)
				entry->Hotkeys += hotkey;
		}
		return (entry);
	}

	static MenuEntry *EnabledEntry(MenuEntry *entry)
	{
		if (entry != nullptr) entry->Enable();
		return (entry);
	}

	PluginMenu *Pmenu;

	void InitMenu()
	{
		MenuFolder *folderA = new MenuFolder("キャラクター関係");
		*folderA += new MenuEntry("なんでも拾える",Number1,"なんでも拾えるようになる");
		//Number1は識別子である、日本語不可・英語可
		*Pmenu += folderA;
		//メニューにフォルダーAを入れる記述
	}

		int main(void)
	{
		Pmenu = new PluginMenu(CTRPFname, 0, 0, 2, about1 + NewLINE + about2 + NewLINE + about3 + NewLINE + about4 + NewLINE + about5);
		Pmenu->SynchronizeWithFrame(true);
		OSD::Notify("Hello mother fucker!");
		InitMenu();
		Pmenu->Run();
		delete Pmenu;
		return 0;
	}

}
