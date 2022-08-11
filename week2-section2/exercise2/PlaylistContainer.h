#pragma once
#include "PlayList.h"
class FPlaylistContainer
{
private:
	const static int MaxPlaylistCount = 6;
	FPlaylist Playlists[MaxPlaylistCount];
	int PlaylistCount;
public:
	FPlaylistContainer();
	bool AddPlaylist(const FPlaylist InPlaylist);
	FPlaylist GetPlaylist( int InPlaylistIndex) const;
	int GetCurrentPlaylistCount() const;
	void PrintPlaylistTitle() const;
};