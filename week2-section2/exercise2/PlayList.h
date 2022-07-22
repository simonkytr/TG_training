#pragma once
#include <iostream>
#include "Song.h"


class FPlaylist
{
private:
	const static int MaxSongCount = 6;
	std::string PlaylistTitle;
	FSong Songs[MaxSongCount];
	int songCount;
public:
	FPlaylist();
	FPlaylist(const std::string InPlayListTitle, const int InSongCount);
	bool bAddSong(const FSong InSong);
	FSong GetSong(const int songIndex) const;
	bool bPlaylistValid() const;
	void displayPlaylist();
};
