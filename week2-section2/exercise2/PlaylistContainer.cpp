#include <iostream>
#include "PlaylistContainer.h"
#include "PlayList.h"

FPlaylistContainer::FPlaylistContainer()
{
	Playlists[MaxPlaylistCount];
	PlaylistCount = 0;
};

FPlaylistContainer::FPlaylistContainer ( const int InPlaylistCount)
{
	Playlists[MaxPlaylistCount];
	PlaylistCount = InPlaylistCount;
};

bool FPlaylistContainer::bAddPlaylist (const FPlaylist InPlaylist) 
{
	for (int i = 0; i < MaxPlaylistCount; i++)
	{
		if (InPlaylist.bPlaylistValid())
		{
			std::cout << "PlayList Added!" << std::endl;
			return true;
		}
		else {
			std::cout << "Invalid PlayList" << std::endl;
			return false;
		}
	}
};

FPlaylist FPlaylistContainer::GetPlaylist ( int InPlaylistCount) const
{
	for (InPlaylistCount = 0; InPlaylistCount < MaxPlaylistCount; InPlaylistCount++)
	{
		return Playlists[InPlaylistCount];
	}
};

 int FPlaylistContainer::GetCurrentPlaylistCount() const
{
	 std::cout << "entro" << std::endl;
	 for (int i = 0; i < MaxPlaylistCount; i++)
	 {
		 while (Playlists[i].bPlaylistValid() == true)
		 {
			 std::cout << "Your playlist contains: " << i << "songs." << std::endl; 
			 return i;
			 break;
		 }
		 
		 
	 }
};