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
		for (int i = 0; i < PlaylistCount; i++)
		{
			if (Playlists[i].GetPlaylistTitle() == "")
			{
				std::cout << "PlayList Added! " << i << std::endl;
				Playlists[i] = InPlaylist;
				return true;
			}
		}
	};

	FPlaylist FPlaylistContainer::GetPlaylist ( int InPlaylistIndex) const
	{
		std::cout << "\nResults: " << std::endl;
		if (Playlists[InPlaylistIndex].GetPlaylistTitle() != "")
		{
			Playlists[InPlaylistIndex].DisplayPlaylist();
			return Playlists[InPlaylistIndex];
		}
		else
		{
			std::cout << "Playlist invalid" << std::endl;
			return  Playlists[InPlaylistIndex];
		}
	};

	 int FPlaylistContainer::GetCurrentPlaylistCount() const
	{
		 int Count = 0;
		 for (int i = 0; i < PlaylistCount; i++)
		 { 
			 if (Playlists[i].GetPlaylistTitle() != "")
			 {
				 Count++;
			 }
		 }
		 std::cout << "\nYou have saved: " << Count << " Playlist(s)" << std::endl;
		 return Count;
	};