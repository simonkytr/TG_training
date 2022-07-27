#include "Spotify.h"
#include "PlaylistContainer.h"
#include <string>

FSpotify::FSpotify()
{
	ActiveMenuCommand = EMenuCommand::MainMenu;
	PlaylistContainer = FPlaylistContainer();
};

//------------------------------------------------------
void FSpotify::OpenMainMenu() 
{
	std::system("cls");
	std::cout << "Welcome to Spotify! What would you like to do?\n1 - Create a Playlist\n2 - Browse Playlists\n3 - Exit" << std::endl;
	int UserInput;
	std::cin >> UserInput;
	while (std::cin.fail() || (UserInput <= 0) || (UserInput >= 4))
	{
			std::system("cls");
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid Option, Insert a valid option" << std::endl;
			std::cout << "Welcome to Spotify! What would you like to do?\n1 - Create a Playlist\n2 - Browse Playlists\n3 - Exit" << std::endl;
			std::cin >> UserInput;
	}

	ActiveMenuCommand = (EMenuCommand)UserInput;
	std::system("cls");
};

//--------------------------------------------------------
void  FSpotify::OpenCreatePlaylistMenu() 
{
	//Creating the playlist
	std::system("cls");
	std::cout << "Please enter a name for the playlist: " << std::endl;
	char TitlePlaylist[500];
	std::cin.getline(TitlePlaylist, 500,'\n');
	std::cin >> TitlePlaylist;
	FPlaylist Playlist = FPlaylist(TitlePlaylist);
	
	std::cout << "Let's add a song to " << TitlePlaylist << std::endl;
	//Creating the song loop

	bool bWantToAddASong = true;
	while (bWantToAddASong)
	{
		std::cout << "Please enter the song title: " << std::endl;
		char TitleSong[500];
		std::cin.getline(TitleSong, 500, '\n');
		std::cin >> TitleSong;

		std::cout << "Please enter the artist name: " << std::endl;
		char ArtistName[500];
		std::cin.getline(ArtistName, 500, '\n');
		std::cin >> ArtistName;

		std::cout << "Please enter the duration (in seconds) of the song: " << std::endl;
		int DurationSong;
		std::cin >> DurationSong;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid Option, insert the duration in seconds " << std::endl;
			std::cin >> DurationSong;
		}
		
		FSong Song = FSong(TitleSong, ArtistName, DurationSong);
		
		//adding the song in playlist
		Playlist.AddSong(Song);

		//menu
		std::cout << "1 - Enter another song\n2 - Go back to main menu" << std::endl;
		int MenuSelection;
		std::cin >> MenuSelection;
		while (std::cin.fail() || (MenuSelection < 1) || (MenuSelection > 2))
		{
			std::system("cls");
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid Option, Insert a valid option" << std::endl;
			std::cout << "1 - Enter another song\n2 - Go back to main menu" << std::endl;
			std::cin >> MenuSelection;
		}
		
		if (MenuSelection == 1) {
			std::system("cls");
			bWantToAddASong = true;
		}
		else
		{
			//adding the playlist in container
			PlaylistContainer.AddPlaylist(Playlist);
			bWantToAddASong = false;
			ActiveMenuCommand = EMenuCommand::MainMenu;
		}
	}
};

//----------------------------------------------------------
void FSpotify::OpenBrowsePlaylistsMenu() 
{
	std::system("cls");
	std::cout << "You have saved " << PlaylistContainer.GetCurrentPlaylistCount() << " playlists" << std::endl;
	std::cout << "Here are your playlist(s):" << std::endl;

	//Looking the playlists saved
	PlaylistContainer.PrintPlaylistTitle();
	std::cout << "\nWhich playlist do you want to see: " << std::endl;

	//choosing the playlist
	int UserInput;
	std::cin >> UserInput;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option " << std::endl;

		std::system("cls");
		std::cout << "You have saved " << PlaylistContainer.GetCurrentPlaylistCount() << " playlists" << std::endl;
		std::cout << "Here are your playlist(s):" << std::endl;

		//Looking the playlists saved
		
		PlaylistContainer.PrintPlaylistTitle();
		std::cout << "\nWhich playlist do you want to see: " << std::endl;
		std::cin >> UserInput;
	}
	std::system("cls");
	PlaylistContainer.GetPlaylist(UserInput - 1);

	//Menu
	std::cout << "1 - Pick another playlist\n2 - Go back to main menu" << std::endl;
	int MenuSelection;
	std::cin >> MenuSelection;
	while (std::cin.fail() || (MenuSelection < 1) || (MenuSelection > 2))
	{
		std::system("cls");
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option, Insert a valid option" << std::endl;
		std::cout << "1 - Pick another playlist\n2 - Go back to main menu" << std::endl;
		std::cin >> MenuSelection;
	}
	if (MenuSelection == 1)
	{
		std::system("cls");
		ActiveMenuCommand = EMenuCommand::BrowsePlaylists;
	}
	else
	{
		std::system("cls");
		ActiveMenuCommand = EMenuCommand::MainMenu;
	}
};

//-----------------------------------------------------------------------
void FSpotify::RunApp() 
{
	while (ActiveMenuCommand != EMenuCommand::Exit)
	{
		if (ActiveMenuCommand == EMenuCommand::MainMenu)
		{
			OpenMainMenu();
		}
		else if (ActiveMenuCommand == EMenuCommand::CreatePlaylist)
		{
			FSpotify::OpenCreatePlaylistMenu();
		}
		else if (ActiveMenuCommand == EMenuCommand::BrowsePlaylists)
		{
			OpenBrowsePlaylistsMenu();
		}
	}
};