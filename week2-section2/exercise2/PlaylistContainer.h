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
	FPlaylistContainer( const int InPlaylistCount ) ;
	bool bAddPlaylist(const FPlaylist InPlaylist);
	FPlaylist GetPlaylist( int InPlaylistCount) const;
	int GetCurrentPlaylistCount() const;
};