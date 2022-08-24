#include <iostream>
#include "PlaylistContainer.h"
#include "PlayList.h"

FPlaylistContainer::FPlaylistContainer()
{
	Playlists[MaxPlaylistCount] = {};
	PlaylistCount;
};
FPlaylistContainer::FPlaylistContainer(const std::string InPlayList, const int InPlaylistCount)
{

};
bool FPlaylistContainer::bAddPlaylist(const FPlaylist)
{

};
FPlaylist FPlaylistContainer::GetPlaylist(const int InPlaylistCount)
{

};
const int FPlaylistContainer::GetCurrentPlaylistConunt()
{

};
