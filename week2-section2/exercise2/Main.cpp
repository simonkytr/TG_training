#include <iostream>
#include "Song.h"
#include "PlayList.h"
#include "PlaylistContainer.h"
#include <string>

int main()
{
	FPlaylist FirstPlaylist = FPlaylist("Random", 2);

	FSong FirstSong = FSong("The nights", "Avicii", 164);
	FirstPlaylist.bAddSong(FirstSong);
	FSong SecondSong = FSong("Smooth Criminal", "Michael Jackson", 194);
	FirstPlaylist.bAddSong(SecondSong);
	FirstPlaylist.DisplayPlaylist();

	FPlaylist SecondPlaylist = FPlaylist("My List", 5);
	FSong FourthSong = FSong("Thriller", "Michael Jackson", 124);
	SecondPlaylist.bAddSong(FourthSong);
	FSong ThirdSong = FSong("Bangarang", "Skrillex", 184);
	SecondPlaylist.bAddSong(ThirdSong);
	SecondPlaylist.DisplayPlaylist();

	FPlaylistContainer FirstPlayListConatiner = FPlaylistContainer( 2);
	FirstPlayListConatiner.bAddPlaylist(FirstPlaylist);
	FirstPlayListConatiner.bAddPlaylist(SecondPlaylist);
	FirstPlayListConatiner.GetCurrentPlaylistCount();
	FirstPlayListConatiner.GetPlaylist(1);
	
}