#include <iostream>
#include "Song.h"
#include"PlayList.h"

	FPlaylist::FPlaylist()
	{
		PlaylistTitle = "";
		songCount = 0;
	}
	FPlaylist::FPlaylist ( const std::string InPlayListTitle, const int InSongCount )
	{
		PlaylistTitle = InPlayListTitle;
		songCount = InSongCount;
	}
	 bool FPlaylist::bAddSong (const FSong InSong ) 
	{
		 for (int i = 0; i < songCount; i++)
		 {
			 if (Songs[i].GetArtistName() == "")
			 {
				 std::cout << "Song #" << 1 + i << " Added!" << std::endl;
				 Songs[i] = InSong;
				 return true;
			 }
		 }
	};
	bool FPlaylist::bPlaylistValid() const
	{
		if ((PlaylistTitle != "") && (songCount <= 1) && (songCount < MaxSongCount))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	FSong FPlaylist::GetSong (int SongIndex) const
	{
		for (int OutSongIndex = 0; OutSongIndex < songCount; OutSongIndex++)
		{
			if (SongIndex == OutSongIndex) {
				return Songs[SongIndex];
			}
		}
	};
	void FPlaylist::DisplayPlaylist() const
	{
		std::cout << "\nPlaylist: " << PlaylistTitle << std::endl;
		std::cout << "\nSong Title" << "\tArtist Name" << "\tDuration" << std::endl;
		std::cout << "-----------------------------------------------------------------" << std::endl;
		for (int i = 0; i < songCount; i++)
		{
			std::cout << Songs[i].GetSongTitle() << "\t" << Songs[i].GetArtistName() << "\t" << Songs[i].GetFormatedDuration() << std::endl;
		}
	};
	std::string FPlaylist::GetPlaylistTitle() const
	{
		return  PlaylistTitle;
	};
	
