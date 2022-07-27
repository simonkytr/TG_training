#pragma once
#include <iostream>
class FSong {
private:
	std::string SongTitle;
	std::string ArtistName;
	int Duration;
public:
	FSong();
	FSong(const std::string InSongTitle, const std::string InArtistName, const int InDuration);
	std::string GetSongTitle() const;
	std::string GetFormatedDuration() const;
	std::string GetArtistName() const;
	bool IsValid() const;
};