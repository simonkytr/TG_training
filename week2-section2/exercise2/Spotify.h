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

public:
	FSpotify();
	enum class EMenuCommand 
	{ 
		MainMenu, CreatePlaylist, BrowsePlaylists, Exit 
	};
	EMenuCommand ActiveMenuCommand;
	int RunApp();
};

