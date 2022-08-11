#include "Song.h"
#include <iostream>

class FSong
{
private:
	std::string SongTitle;
	std::string ArtistName;
	int Duration;

public:
	FSong() 
	{
		SongTitle = "";
		ArtistName = "";
		Duration = 0;
	}
	FSong(const std::string InSongTitle, const std::string InArtistName, const int InDuration)
	{
		SongTitle = InSongTitle;
		ArtistName = InArtistName;
		Duration = InDuration;
	}
	const std::string GetFormatedDuration()
	{	
	 std::cout << Duration / 60;
	};
	const bool bIsValid()
	{
		if (( Duration != 0 ) && ( ArtistName != "" ) && ( SongTitle != "" )) return true;
		else return false;
	};
};