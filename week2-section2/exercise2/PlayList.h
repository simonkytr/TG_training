#pragma once
#include <iostream>
#include "Song.h"
#include <string>

class FPlaylist
{
private:
	const static int MaxSongCount = 6;
	std::string PlaylistTitle;
	FSong Songs[MaxSongCount];
	int SongCount;
public:
	FPlaylist();
	FPlaylist(const std::string InPlayListTitle, const int InSongCount);
	bool AddSong(const FSong InSong);
	FSong GetSong(const int songIndex) const;
	bool PlaylistValid() const;
	void DisplayPlaylist() const;
	std::string GetPlaylistTitle() const;
};
