#include "Spotify.h"
#include "PlaylistContainer.h"
#include <string>

FSpotify::FSpotify()
{
	ActiveMenuCommand = EMenuCommand::MainMenu;
	PlaylistContainer = FPlaylistContainer(3);
};

//------------------------------------------------------
void FSpotify::OpenMainMenu() 
{
	std::system("cls");
	std::cout << "Welcome to Spotify! What would you like to do?\n1 - Create a Playlist\n2 - Browse Playlists\n3 - Exit" << std::endl;
	int InputConverter;
	std::cin >> InputConverter;
	while (std::cin.fail() || (InputConverter <= 0) || (InputConverter >= 4))
	{
			std::system("cls");
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid Option, Insert a valid option" << std::endl;
			std::cout << "Welcome to Spotify! What would you like to do?\n1 - Create a Playlist\n2 - Browse Playlists\n3 - Exit" << std::endl;
			std::cin >> InputConverter;
	}

	ActiveMenuCommand = (EMenuCommand)InputConverter;
	std::system("cls");
	FSpotify::RunApp();
};

//--------------------------------------------------------
void  FSpotify::OpenCreatePlaylistMenu() 
{
	std::system("cls");
	std::cout << "Please enter a name for the playlist: " << std::endl;
	char TitlePlaylist[500];
	std::cin.getline(TitlePlaylist, 500,'\n');
	std::cin >> TitlePlaylist;
	//Creating the playlist
	FPlaylist Playlist = FPlaylist(TitlePlaylist, 4);
	
	std::cout << "Let's add a song to " << TitlePlaylist << std::endl;
	//Creating the song loop

	bool bWantToAddASong = true;
	while (bWantToAddASong = true)
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
		Playlist.bAddSong(Song);

		//std::system("cls");
		std::cout << "1 - Enter another song\n2 - Go back to main menu" << std::endl;
		
		//menu
		int MenuSelection;
		std::cin >> MenuSelection;
		while (std::cin.fail() || (MenuSelection <= 0) || (MenuSelection >= 3))
		{
			std::system("cls");
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid Option, Insert a valid option" << std::endl;
			std::cout << "1 - Enter another song\n2 - Go back to main menu" << std::endl;
			std::cin >> MenuSelection;
		}
		if (MenuSelection == 2)
		{
			//adding the playlist in container
			PlaylistContainer.bAddPlaylist(Playlist);
			bWantToAddASong = false;
			FSpotify::OpenMainMenu();
		}
		else if (MenuSelection == 1) {
			std::system("cls");
			bWantToAddASong = true;
		}
	}
};

//----------------------------------------------------------
void FSpotify::OpenBrowsePlaylistsMenu() 
{
	std::system("cls");
	std::cout << "Here are your playlist(s):" << std::endl;
	
	//Looking the playlists saved
	PlaylistContainer.GetCurrentPlaylistCount();
	std::cout << "\nWhich playlist do you want to see: " << std::endl;

	//choosing the playlist
	int InputConverter;
	std::cin >> InputConverter;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option " << std::endl;

		std::system("cls");
		std::cout << "Here are your playlist(s):" << std::endl;

		//Looking the playlists saved
		PlaylistContainer.GetCurrentPlaylistCount();
		std::cout << "\nWhich playlist do you want to see: " << std::endl;

		std::cin >> InputConverter;
	}
	std::system("cls");
	PlaylistContainer.GetPlaylist(InputConverter - 1);

	//Menu
	std::cout << "1 - Pick another playlist\n2 - Go back to main menu" << std::endl;
	int MenuSelection;
	std::cin >> MenuSelection;
	while (std::cin.fail() || (MenuSelection <= 0) || (MenuSelection >= 3))
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
		FSpotify::OpenBrowsePlaylistsMenu();
	}
	else
	{
		std::system("cls");
		FSpotify::OpenMainMenu();
	}
};

//-----------------------------------------------------------------------
void FSpotify::RunApp() 
{
	while (ActiveMenuCommand != FSpotify::EMenuCommand::Exit)
	{
		if (ActiveMenuCommand == FSpotify::EMenuCommand::MainMenu)
		{
			FSpotify::OpenMainMenu();
		}
		else if (ActiveMenuCommand == FSpotify::EMenuCommand::CreatePlaylist)
		{
			FSpotify::OpenCreatePlaylistMenu();
		}
		else if (ActiveMenuCommand == FSpotify::EMenuCommand::BrowsePlaylists)
		{
			FSpotify::OpenBrowsePlaylistsMenu();
		}
	}
	if (ActiveMenuCommand == FSpotify::EMenuCommand::Exit)
	{
		exit;
	}
	
};