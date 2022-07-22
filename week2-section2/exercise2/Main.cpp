#include <iostream>
#include "Song.h"
#include "PlayList.h"
#include "PlaylistContainer.h"
#include <string>

int main()
{
	FSong FirstSong = FSong("The nights", "Avicii", 164);
	FSong SecondSong = FSong("Smooth Criminal", "Michael Jackson", 194);

	FPlaylist FirstPlaylist = FPlaylist("Random", 2);
	FirstPlaylist.bAddSong(FirstSong);
	FirstPlaylist.bAddSong(SecondSong);
	FirstPlaylist.displayPlaylist();
	
	FPlaylistContainer FirstPlayListConatiner = FPlaylistContainer( 1);
	FirstPlayListConatiner.bAddPlaylist(FirstPlaylist);
	FirstPlayListConatiner.GetCurrentPlaylistCount();
}