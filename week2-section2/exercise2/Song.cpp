#include "Song.h"
#include <iostream>
#include <string>

	FSong::FSong()
	{
		SongTitle = "";
		ArtistName = "";
		Duration = 0;
	}

	FSong::FSong(const std::string InSongTitle, const std::string InArtistName, const int InDuration)
	{
		SongTitle = InSongTitle;
		ArtistName = InArtistName;
		Duration = InDuration;
	}

	std::string FSong::GetSongTitle() const
	{
		return SongTitle;
	};

	std::string FSong::GetArtistName() const
	{
		return ArtistName;
	};
	
	std::string FSong::GetFormatedDuration() const
	{
		const int Minutes = Duration / 60;
		const int Seconds = Duration % 60;
		if (Seconds > 10)
		{
			return std::to_string(Minutes) + ":" + std::to_string(Seconds);
		}
		else
		{
			return std::to_string(Minutes) + ":" +"0" + std::to_string(Seconds);
		}
		
	};

	bool FSong::IsValid() const
	{
			return (Duration > 0) && (ArtistName != "") && (SongTitle != "");
	};
