#include <iostream>
#include "PlaylistContainer.h"

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

	bool FPlaylistContainer::AddPlaylist (const FPlaylist InPlaylist) 
	{
		if (PlaylistCount < MaxPlaylistCount)
		{
			Playlists[PlaylistCount] = InPlaylist;
			PlaylistCount++;
			return true;
		}
		else
		{
			std::cout << "The playlist can't be created, The memory is full" << std::endl;
			return false;
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
			std::cout << "Invalid Playlist" << std::endl;
			return  Playlists[InPlaylistIndex];
		}
	};

	 int FPlaylistContainer::GetCurrentPlaylistCount() const
	{
		 int Count = 0;
		 for (int i = 0; i < MaxPlaylistCount; i++)
		 { 
			 if (Playlists[i].GetPlaylistTitle() != "")
			 {
				 Count++;
			 }
			 std::cout << "playlist " << i + 1 << "- " << Playlists[i].GetPlaylistTitle() << std::endl;
		 }
		 std::cout << "\nYou have saved: " << Count << " Playlist(s)" << std::endl;
		 return Count;
	};