#include <iostream>
#include "Song.h"
#include"PlayList.h"

	FPlaylist::FPlaylist()
	{
		PlaylistTitle = "";
		Songs[MaxSongCount];
		songCount = 0;
	}
	FPlaylist::FPlaylist ( const std::string InPlayListTitle, const int InSongCount )
	{
		PlaylistTitle = InPlayListTitle;
		Songs[MaxSongCount];
		songCount = InSongCount;
	}
	 bool FPlaylist::bAddSong (const FSong InSong ) 
	{
		 for (int i = 0; i < MaxSongCount; i++)
		 {
			 if (InSong.bIsValid())
			 {
				 std::cout << "Song Added!" << i << std::endl;
				 Songs[i];
				 return true;
			 }
			 else {
				 std::cout << "Invalid Song" << std::endl;
				 return false;
			 }
		 }
	};
	bool FPlaylist::bPlaylistValid() const
	{
		if (PlaylistTitle != "" && songCount <= 1)
		{
			return true;
		}
		else
		{
			std::cout << "Invalid Playlist" << std::endl;
			return false;
		}
	}
	FSong FPlaylist::GetSong (int SongIndex) const
	{
		for (SongIndex = 0; SongIndex < MaxSongCount; SongIndex++)
		{
			return Songs[SongIndex];
		}
	};
	void FPlaylist::displayPlaylist()
	{
		std::cout << "\nSong Title" << "\tArtist Name" << "\tDuration" << std::endl;
		for (int i = 0; i < MaxSongCount; i++)
		{
			std::cout << Songs[i].GetSongTitle() << "\t" << Songs[i].GetArtistName() << "\t" << Songs[i].GetFormatedDuration() << std::endl;
		}
	};
