#pragma once
#include "PlaylistContainer.h"
class FSpotify
{
private:
	//Initialiting the playlist container
	FPlaylistContainer PlaylistContainer;
	void OpenMainMenu();
	void OpenBrowsePlaylistsMenu();
	void OpenCreatePlaylistMenu();
	enum class EMenuCommand
	{
		MainMenu, CreatePlaylist, BrowsePlaylists, Exit
	};
	EMenuCommand ActiveMenuCommand;
public:
	FSpotify();
	void RunApp();
};

