#include <iostream>
#include "PlaylistContainer.h"

	FPlaylistContainer::FPlaylistContainer()
	{
		PlaylistCount = 0;
	};
	
	//------------------------------------------------------------
	bool FPlaylistContainer::AddPlaylist(const FPlaylist InPlaylist) 
	{
		if (PlaylistCount < MaxPlaylistCount)
		{
			Playlists[PlaylistCount] = InPlaylist;
			std::cout << "The playlist " << Playlists[PlaylistCount].GetPlaylistTitle() << " was added succesfully!" << std::endl;
			PlaylistCount++;
			return true;
		}
		else
		{
			std::cout << "The playlist can't be created, The memory is full" << std::endl;
			return false;
		}
	};

	//------------------------------------------------------------
	FPlaylist FPlaylistContainer::GetPlaylist(int InPlaylistIndex) const
	{
		std::cout << "\nResults: " << std::endl;
		if (Playlists[InPlaylistIndex].IsPlaylistValid()  == true)
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

	//------------------------------------------------------------
	 int FPlaylistContainer::GetCurrentPlaylistCount() const
	{
		 return PlaylistCount;
	};

	 //-------------------------------------------------------------
	 void FPlaylistContainer::PrintPlaylistTitle() const
	 {
		 for (int i = 0; i < MaxPlaylistCount; i++)
		 {
			 std::cout << "#" << i + 1 << " - " << Playlists[i].GetPlaylistTitle() << std::endl;
		 }
	 };