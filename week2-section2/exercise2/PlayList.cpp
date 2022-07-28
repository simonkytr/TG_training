#include <iostream>
#include"PlayList.h"

	FPlaylist::FPlaylist()
	{
		PlaylistTitle = "";
		SongCount = 0;
	}

	//------------------------------------------------------------
	FPlaylist::FPlaylist(const std::string InPlayListTitle)
	{
		PlaylistTitle = InPlayListTitle;
		SongCount = 0;
	}

	//------------------------------------------------------------
	bool FPlaylist::AddSong(const FSong InSong) 
	{
		 if (SongCount < MaxSongCount)
		 {
			 Songs[SongCount] = InSong;
			 std::cout << "The song " << Songs[SongCount].GetSongTitle() << " was added succesfully!" << std::endl;
			 SongCount++;
			 return true;
		 }
		 else
		 {
			 std::cout << "The song can't be added, The playlist is full" << std::endl;
			 return false;
		 }
	};

	//------------------------------------------------------------
	bool FPlaylist::IsPlaylistValid() const
	{
		return (PlaylistTitle != "") && (SongCount <= 1) && (SongCount <= MaxSongCount);
	};

	//------------------------------------------------------------
	FSong FPlaylist::GetSong(int SongIndex) const
	{
		return Songs[SongIndex];
	};

	//------------------------------------------------------------
	void FPlaylist::DisplayPlaylist() const
	{
		std::cout << "\nPlaylist: " << PlaylistTitle << std::endl;
		std::cout << "\nSong Title" << "\tArtist Name" << "\tDuration" << std::endl;
		std::cout << "-----------------------------------------------------------------" << std::endl;
		for (int i = 0; i < MaxSongCount; i++)
		{
			std::cout << Songs[i].GetSongTitle() << "\t" << Songs[i].GetArtistName() << "\t" << Songs[i].GetFormatedDuration() << std::endl;
		}
	};

	//------------------------------------------------------------
	std::string FPlaylist::GetPlaylistTitle() const
	{
		return  "Playlist: " + PlaylistTitle;
	};
	
